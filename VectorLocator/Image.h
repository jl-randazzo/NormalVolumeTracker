#pragma once
#include "ProjectLogger.h"
#include "ImageLoader.h"

enum ImageType {
	GRAYSCALE, RGB, RGBA
};

class pixel {};

class gs_pixel : public pixel {
public:
	gs_pixel(char luminance) : lum(luminance) {}
	const char lum;
};

class rgba_pixel: public pixel {
public:
	const char r;
	const char b;
	const char g;
	const char a;

	rgba_pixel(char red, char blue, char green, char alpha) : r(red), b(blue), g(green), a(alpha) {}
	gs_pixel ToGrayScale() {
		float rcomp = r * .2989;
		float gcomp = g * .5870;
		float bcomp = b * .1140;
		return gs_pixel((char)(rcomp + gcomp + bcomp));
	}
};

class Image: public LogReporter {
	friend ImageLoader;
private:
	char* _pixelData;
	const ImageType _type;
	const int _w;
	const int _h;
	void operator delete(void*);
	~Image();
	
public:
	Image(char * pixelData, ImageType type, int w, int h);

	pixel operator() (int row, int column) const;
	void Convolution(const Image filter);

	//Accessors
	const ImageType GetType() const;
	const char* Report() const;
};

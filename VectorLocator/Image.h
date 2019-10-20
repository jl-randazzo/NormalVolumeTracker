#pragma once
#include "ProjectLogger.h"

enum ImageType {
	GRAYSCALE, RGB, RGBA
};

struct rgba_pixel: pixel {
	rgba_pixel(char red, char blue, char green, char alpha) : r(red), b(blue), g(green), a(alpha) {}
	char r;
	char b;
	char g;
	char a;

	gs_pixel ToGrayScale() {
		float rcomp = r * .2989;
		float gcomp = g * .5870;
		float bcomp = b * .1140;
		return gs_pixel((char)(rcomp + gcomp + bcomp));
	}
};

struct gs_pixel : pixel {
	gs_pixel(char luminance) : lum(luminance) {}
	char lum;
};

struct pixel {};

class Image: public LogReporter {
private:
	char const* _pixelData;
	const ImageType _type;
	const int _w;
	const int _h;
	
public:
	Image(char const* pixelData, ImageType type, int w, int h);

	pixel operator() (int row, int column) const;
	void Convolution(const Image filter);

	//Accessors
	const ImageType GetType() const;
	const char* Report() const;
};

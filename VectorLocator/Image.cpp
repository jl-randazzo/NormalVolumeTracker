#include "Image.h"
#include "ProjectLogger.h"

Image::Image(char* pixelData, ImageType type, int w, int h) : _pixelData(pixelData), _type(type), _w(w), _h(h) {}

pixel Image::operator() (int row, int column) const {
	LOGGER_ASSERT(row < _h && column < _w, this, "indexing out of image array", "successfully slotted into image");
	int index = (row * _w) + column;
	return rgba_pixel( _pixelData[index], _pixelData[(index + 1)], _pixelData[index + 2], _pixelData[index + 3] );
}

void Image::operator delete(void* ptr) {
	delete ((Image*)ptr)->_pixelData;
	free(ptr);
}

Image::~Image() {
	delete _pixelData;
}

const char* Image::Report() const {
	const char* report = "{Image}";
	return report;
}

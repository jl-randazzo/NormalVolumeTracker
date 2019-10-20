#pragma once
#include "lodepng.h"

class ImageLoader {
public:
	static ImageLoader GetInstance();
	//static const 
private:
	static ImageLoader _instance;
};

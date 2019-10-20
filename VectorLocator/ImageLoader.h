#pragma once
#include "lodepng.h"
#include "ispc_texcomp/ispc_texcomp.h"

class ImageLoader {
public:
	static ImageLoader GetInstance();
	//static const 
private:
	static ImageLoader _instance;
};

#pragma once
#include <wtypes.h>
#include "Image.h"
#include "lodepng.h"
#include "ispc_texcomp/ispc_texcomp.h"

class ImageLoader {
public:
	static ImageLoader* GetInstance();
	//static const 
private:
	static ImageLoader* _instance;
	std::map<char*, Image*>* _image_dictionary;
	ImageLoader() { }
	errno_t LoadPNGImage(LPSTR file_name, Image* im_handle);
};

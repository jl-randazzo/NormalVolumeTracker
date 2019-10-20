#include "ImageLoader.h"

ImageLoader* ImageLoader::_instance;

ImageLoader* ImageLoader::GetInstance() {
	if (_instance == nullptr) {
		_instance = new ImageLoader();
	}
}

errno_t ImageLoader::LoadPNGImage(LPSTR file_name, Image* im_handle) {
	return 0;
}

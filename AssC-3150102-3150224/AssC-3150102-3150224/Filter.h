#pragma once
#include "image.h"
using namespace image;
class Filter{
	virtual Image operator <<(const Image & image) = 0;
};


class FilterGamma :public Filter {
	float gamma;
public:
	FilterGamma(float y) {
		gamma = y;
	}

	Image operator <<(const Image & image);
};


class FilterLinear :public Filter {
	col a, c;
public:
	FilterLinear(col x, col y) {
		a = x;
		c = y;
	}
	Image operator <<(const Image & image);
};



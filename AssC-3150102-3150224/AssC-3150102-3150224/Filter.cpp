#include <iostream>
#include "Filter.h"
#include <math.h>
#include <vector>
using namespace std;

Image FilterLinear::operator <<(const Image & image) {
	Image imgLinear(image);
	col * data = imgLinear.getRawDataPtr();
	
	int bufSize = imgLinear.getHeight() * imgLinear.getWidth();
	for (int i = 0; i < bufSize; i++) {
		data[i].r = (a.x * data[i].r + c.x);
		data[i].g = (a.y * data[i].g + c.y);
		data[i].b = (a.z * data[i].b + c.z);

	}
	
	

	for (int j = 0; j < bufSize; j++) {
		data[j]=data[j].clampToLowerBound(0);
		data[j]=data[j].clampToUpperBound(1);
	}
	
	return imgLinear;
}

Image FilterGamma::operator<<(const Image & image) {
	Image imgGamma(image);
	col * data = imgGamma.getRawDataPtr();

	int bufSize = imgGamma.getHeight() * imgGamma.getWidth();
	for (int i = 0; i < bufSize; i++) {
		data[i].x = pow (data[i].x,gamma);
		data[i].y = pow(data[i].y, gamma);
		data[i].z = pow(data[i].z, gamma);
	}

	return imgGamma;
}

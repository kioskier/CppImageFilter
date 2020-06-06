#include <iostream>
#include <string>
#include <locale>
#include "image.h"

namespace image
{
		bool Image::load(const string & filename, const string & format) {
			string nameCheck = filename.substr(filename.find(".") + 1);

			string nameCheckLower;
			locale loc;
			for (size_t i = 0; i < nameCheck.length(); ++i) {
				nameCheckLower = nameCheckLower + tolower(nameCheck[i], loc);
			}

			if (nameCheckLower == format) {
				int w, h;
				const char * name;
				name = filename.c_str();
				float * readTempBuf = ReadPPM(name, &w, &h);
				if (readTempBuf == NULL) {
					cout << "Buffer size = 0 " << endl;
					return false;
				}
				width = w;
				height = h;
				buffer.resize(width*height);
				int j = 0;
				int index = 0;
				int sizeBuf = 3 * width*height;
				for (int i = 0; i < sizeBuf; i = i + 3) {
					buffer[j].r = readTempBuf[i];
					buffer[j].g = readTempBuf[i + 1];
					buffer[j].b = readTempBuf[i + 2];
					j++;
					index = i;
					
				}
				cout << "Image loaded" << endl;
				return true;
			}
			else {
				cout << "Could not read file because format is different " << endl;
				return false;
			}

		}

		bool Image::save(const string & filename, const string & format) {
			string nameCheck = filename.substr(filename.find(".") + 1);

			string nameCheckLower;
			locale loc;
			for (size_t i = 0; i < nameCheck.length(); ++i) {
				nameCheckLower = nameCheckLower + tolower(nameCheck[i], loc);
			}

			if (nameCheckLower == format) {
				const char* name = filename.c_str();

				float *writeTempBuf = new float[3 * width*height];
				int j = 0;
				int sizeBuf = width * height;
				if (buffer.size() == 0) {
					cout << "Buffer size = 0 " << endl;
					return false;
				}
				for (int i = 0; i < sizeBuf; i++) {
					writeTempBuf[j] = buffer[i].r;
					writeTempBuf[j + 1] = buffer[i].g;
					writeTempBuf[j + 2] = buffer[i].b;
					j = j + 3;
				}


				WritePPM(writeTempBuf, width, height, name);
				cout << "Image saved " << endl;
				return true;
			}
			else {
				cout << "Could not write file because format is different " << endl;
				return false;
			}
		}
}
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "ppm.h"

using namespace std;
using namespace image;


float * image::ReadPPM(const char * filename, int * w, int * h) {
		string ppmformat;
		int width;
		int height;
		int size;
		int maxValue;


		ifstream ifile(filename, ios::binary| ios::in);
		

		if (!ifile) {
			cout << "FILENAME2 = " << filename << endl;
			cout << "Cannot find or open the file!" << endl;
			return NULL;
		}
			

		ifile >> ppmformat;
		if (ppmformat != "P6") {
			cout << "Format is not acceptable ";
			return NULL;
		}

		if (ifile.fail()) {
			cerr << "Could not read data EDW" << endl;
			return NULL;
		}

		ifile >> width;
		if (width <= 0) {
			cout << "Wrong width value " << endl;
			return NULL;
		}
		ifile >> height;
		if (height <= 0) {
			cout << "Wrong height value " << endl;
			return NULL;
		}

		*w = width;
		*h = height;

		ifile >> maxValue;
		if (maxValue > 255) {
			cout << "Fail to read max storage value or max storage value per pixel should be greater than 255" << endl;
			return NULL;
		}

		size = 3 * width*height;
		//cout << "Size of buffer =" << size << endl;

		float * buffer = new float[size] ;
		if (!buffer) {
			cout << "Error allocating memory" << endl;
		}

	

		char c;
		ifile.get(c);
		float newchar;
		for(int i=0; i<size; i++){
			ifile.get(c); 
			buffer[i] = (unsigned char)c / 255.0f;
		}


		cout << "Image succesfully read!" << endl;
		ifile.clear();
		ifile.seekg(0, ios_base::beg);
		ifile.close();
		return buffer;
			
	}

bool image::WritePPM(const float * data, int w, int h, const char * filename) {

	if (data == nullptr) {
		cout << " Empty buffer!!! " << endl;
		return false;
	}

	ofstream ofile(filename, ios::binary|ios::out);

	if (!ofile) {
		cout << "Cannot open the file " << endl;
		return false;
	}

	string format = "P6";
	ofile << "P6";
	ofile.put(char(10));
	ofile.flush();
	
	ofile<<to_string(w);
	ofile.put(char(10));
	ofile.flush();

	ofile<<to_string(h);
	ofile.put(char(10));
	ofile.flush();

	int maxValue = 255;
	ofile<<to_string(maxValue);
	ofile.put(char(10));
	ofile.flush();
	
	
	int size = 3 * w* h;
	char * f = new  char[size];

	for (int i = 0; i < size; i++) {
		f[i] = data[i] * 255.0f;
	}

	ofile.write(reinterpret_cast<char*>(f), size);
	ofile.flush();

	if (ofile.fail()) {
		cerr << "Could not write data" << endl;
	}

	cout << "File was written successfully" << endl;

	
	ofile.clear();
	ofile.close();
	delete[] f;
	return true;
}
	



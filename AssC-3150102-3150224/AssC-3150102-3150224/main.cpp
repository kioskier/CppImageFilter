//Zisi Michalaris 3150224
//Alexandros Melis 3150102

#include <iostream>
#include <array>
#include "Filter.h"
#include <stdlib.h>
#include <sstream>
#include <string>
using namespace image;
using namespace std;
using namespace math;

int main(int argc, char* argv[]) {

	if (argc == 1) {
		cout << "Please give the image name and the filters with parameters: " << endl;
		string line;
		getline(cin, line);

		vector <string> inputVec;
		stringstream splitStr(line);
		string intermediate;
		// Tokenizing w.r.t. space ' ' 
		while (getline(splitStr, intermediate, ' '))
		{
			inputVec.push_back(intermediate);
		}

		Image image(0, 0);
		string firstArg = "filter";
		string format = "ppm";
		string gamma = "gamma";
		string linear = "linear";
		string f = "-f";
		string filtered = "filtered_";
		if (inputVec.size() < 5) {
			cout << "Not enough arguments" << endl;
			system("PAUSE");
			return 0;
		}
		if (inputVec[0] != firstArg) {
			cout << "First word must be filter " << endl;
			system("PAUSE");
			return 0;
		}

		string filename = inputVec[inputVec.size() - 1];

		string fName = filtered + filename;
		bool load = image.load(filename, format); 
		if (load == false) {
			system("PAUSE"); 
			return 0;
		}
		int i = 1;
		while (inputVec[i] == f) {
			if (inputVec[i + 1] == linear) { //FILTER LINEAR 
				cout << "Linear filter is going to be adjusted..." << endl;

					col a;
					col c;

					a.x = (atof(inputVec[i + 2].c_str()));
					a.y = (atof(inputVec[i + 3].c_str()));
					a.z = (atof(inputVec[i + 4].c_str()));

					c.x = (atof(inputVec[i + 5].c_str()));
					c.y = (atof(inputVec[i + 6].c_str()));
					c.z = (atof(inputVec[i + 7].c_str()));

					FilterLinear  filterlinear(a, c);

					image = filterlinear << image;

					image.save(fName, format);
					i = i + 8;
			}
			else if (inputVec[i + 1] == gamma) { //FILTER GAMMA
				cout << "Gamma filter is going to be adjusted..." << endl;
				if (!((atof)(inputVec[i + 2].c_str()))) {
					cout << "Wrong input: Gamma has only one parameter" << endl;
					system("PAUSE");
					return 0;
				}
				if ((atof)(inputVec[i + 2].c_str())) { 

					if (!(atof(inputVec[i + 2].c_str()) >= 0.5) && !(atof(inputVec[i + 2].c_str()) <= 2.0)) { 
						cout << "Gamma number must be between 0.5 and 2.0" << endl;
						system("PAUSE");
						return 0;
					}

					FilterGamma  gamma(atof(inputVec[i + 2].c_str())); 

					image = Image(gamma << (image));

					image.save(fName, format);
					i = i + 3;
				}
				else {
					cout << "You have not give 1 double number" << endl;
					system("PAUSE");
					return 0;

				}

			}
			else {
				cout << "Wrong Filter name" << endl;
				system("PAUSE");
				return 0;
			}
			
		}//end while
		cout << "Everything works great!!\n";
		system("PAUSE");
	}
	else {//if you have arguments
		Image image(0, 0);
		string firstArg = "filter";
		string ppm = "ppm";
		string gamma = "gamma";
		string linear = "linear";
		string f = "-f";
		string filtered = "filtered_";
		if (argc < 5) {
			cout << "Not enough arguments";
			system("pause");
			return 0;
		}
		if (argv[1] != firstArg) {
			cout << "First word must be filter " << endl;
			system("PAUSE");
			return 0;
		}
		string filename = argv[argc - 1];
		string fName = filtered + filename;
		bool load = image.load(filename, ppm);
		if (load == false) {
			system("pause");
			return 0;
		}

		int i = 2;
		while (argv[i] == f) {
			if (argv[i+1] == linear) {
				cout << "Linear filter is going to be adjusted..." << endl;
				if ((int)(argv[i + 2]) && (int)(argv[i + 3]) && (int)(argv[i + 4])
					&& (int)(argv[i + 5]) && (int)(argv[i + 6]) && (int)(argv[i + 7])) {
					Vec3<float> a;
					Vec3<float> c;
					a.x = (atof(argv[i + 2]));
					a.y = (atof(argv[i + 3]));
					a.z = (atof(argv[i + 4]));

					c.x = (atof(argv[i + 5]));
					c.y = (atof(argv[i + 6]));
					c.z = (atof(argv[i + 7]));
					
					FilterLinear  filterlinear(a, c);
					image = filterlinear << image;
					image.save(fName, ppm);

					i = i + 8;
				}
				else {
					cout << "You have not give 6 numbers" << endl;
					system("pause");
					return 0;
				}

			}
			else if (argv[i+1] == gamma) {
				cout << "Gamma filter is going to be adjusted..." << endl;
				if ((atof)(argv[i + 2])) {

					if (!(atof(argv[i + 2]) >= 0, 5) && !(atof(argv[i + 2]) <= 2, 0)) {
						cout << "Gamma number must be between 0.5 and 2.0" << endl;
						system("pause");
						return 0;
					}

					FilterGamma  gamma(atof(argv[i + 2]));
					image = gamma << (image);
					image.save(fName, ppm);
					i = i + 3;
				}
				else {
					cout << "You have not give 1 double number" << endl;
					system("pause");
					return 0;

				}

			}else {
				cout << "Wrong Filter name" << endl;
				system("PAUSE");
				return 0;
			}
		}//end while

		cout << "Everything works great!!\n";

		system("pause");
		return 0;
	}
	return 0;
}
	
 































	//MAIN MELI============================
	/*
	col a(2, 2, 2);
	col c(0, 0, 0);
	float g = 2;

	Image img(0, 0);
	FilterLinear linear(a,c);
	FilterGamma gam(g);

	string format = "ppm";
	string filename = "Image01.ppm";
	string filteredname = "filtered" + filename;

	img.load(filename, format);

	col * beforeFiltData = img.getRawDataPtr();

	img = linear << img;

	col * afterFiltData = img.getRawDataPtr();
	img.save(filteredname, format);
	*/



	




	//dokimi gia image///////
	/*
	string filename = "Image02.ppm";
	string format = "ppm";
	float * ptr = nullptr;
	Image a(0,0);
	a.load(filename, format);
	string newfilename = "filtered_" + filename;
	a.save(newfilename, format);
	*/


	///////////// main gia dokimi ppm.cpp /////////////////////
	/*
	const char* filename ="Image03.ppm";

	int width = 0;
	int height = 0;
	float *arr;
	arr=ReadPPM(filename, &width, &height);

	cout << "Width = " << width << " height = " << height << endl ;

	int size = 3 * width*height;
	//cout << "arr[size+1]" << arr[size=1]<<endl;


	const char * name = "ImageNew.ppm";

	WritePPM(arr, width, height, name);

	delete[] arr;
	//delete[] name;
	*/



	///////dokimi gia array2D//////
	//float arr[3] = { 1.0,2.0,3.0 };
	//float * ptr = arr;


	//Array2D<float> a(3,1,ptr);

	//Array2D<float> b = a;
	
	//cout << "b HEIGHT = " << b.getHeight() << endl;
	//cout << "b WIDTH = " << b.getWidth() << endl;
	


	


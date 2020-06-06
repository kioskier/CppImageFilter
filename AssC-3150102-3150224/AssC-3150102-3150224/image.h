#include <string>
#include "array2d.h"
#include "imageio.h"
#include "vec3.h"
#include "../PPM/ppm.h"

using namespace math;
using namespace std;

namespace image
{
	typedef math::Vec3<float> col;
	class Image :public Array2D <col>, public ImageIO {

	public:

		bool load(const string & filename, const string & format) override; 
		bool save(const string & filename, const string & format) override;
		Image(int width,int height) : Array2D(width, height) {}


	};
}
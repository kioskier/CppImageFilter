using namespace std;
namespace math
{

	template <typename T>
	const unsigned int Array2D<T>::getWidth() const {
		return width;
	}

		/*! Returns the height of the array
		 */
	template <typename T>
	const unsigned int Array2D<T>::getHeight() const {
			return height;
	}

		// data accessors and mutators

		/*! Obtains a pointer to the internal data.
		 *
		 *  This is NOT a copy of the internal array data, but rather a pointer
		 *  to the internally allocated space, so DO NOT attempt to delete the pointer.
		 */

	// varaei giati o copy constructor pernei san orisma (const Array2D &src) enw i methodos den einai const!!!
	template <typename T>
		T * Array2D<T>::getRawDataPtr(){
			return buffer.data();
	}

		/*! Copies the array data from an external raw buffer to the internal array buffer.
		 *
		 *  The member function ASSUMES that the input buffer is of a size compatible with the internal storage of the
		 *  Array2D object. If the array buffer cannot be properly resized or the width or height of the array are 0,
		 *  the method should exit immediately.
		 *
		 *  \param data_ptr is the reference to the preallocated buffer from where to copy the data to the Array2D object.
		 */
		template <typename T>
		void Array2D<T>::setData(const T * const & data_ptr) {
			unsigned int size = width * height;
			for (int i = 0; i < size; i++) {
				buffer.push_back(data_ptr[i]);
			}
		}

		/*! Returns a reference to the stored item at location (x,y).
		 *
		 *	\param x is the horizontal coordinate of the item.
		 *  \param y is the vertical coordinate of the item.
		 *
		 *  \return a reference to the item at location (x,y).
		 */
		template <typename T>
		T  & Array2D<T>::operator () (unsigned int x, unsigned int y) {
			return &buffer[width*y * 3 + x * 3];
		}

		// constructors and destructor

		/*! Constructor with data initialization.
		 *
		 * Default parameters let it also be used as a default constructor.
		 *
		 * \param width is the desired width of the new array.
		 * \param height is the desired height of the new array.
		 * \param data_ptr is the source of the data to copy to the internal array buffer.
		 * If none is provided, but the width and height are non-zero, the buffer is initialized to default values (all zero - black).
		 *
		 * \see setData
		 */

		template <typename T>
		Array2D<T>::Array2D(unsigned int width, unsigned int height, const T * data_ptr) {
			this->width = width;
			this->height = height;
			int size = this->width* this->height;
			if (data_ptr == nullptr && width != 0 && height != 0) {

				/*for (int i = 0; i < size; i++) {
					cout << "ALL black " << endl;
					buffer[i].r = 0.0f;
					buffer[i].g = 0.0f;
					buffer[i].b = 0.0f;
					//cout << " dataptr [] = " << data_ptr[i];
				}*/
			}
			setData(data_ptr);
		} 

		/*! Copy constructor.
		 *
		 * \param src is the source array to replicate in this object.
		 */

		template <typename T>
		Array2D<T>::Array2D(const Array2D &src) {
			this->width = src.getWidth();
			this->height = src.getHeight();

			setData(src.buffer.data());
		}

		/*! The Array2D destructor.
		 */
		template <typename T>
		Array2D<T>::~Array2D() {
		}

		/*! Copy assignment operator.
		 *
		 * \param right is the source array.
		 */
		template <typename T>
		Array2D<T> & Array2D<T>::operator = (const Array2D & right) {
			this->width = right.getWidth();
			this->height = right.getHeight();
			const T * ptr = right.buffer.data();
			unsigned int size = width * height;
			for (int i = 0; i < size; i++) {
				buffer[i]=ptr[i];
			}
			return *this;
		}

	

} //namespace math




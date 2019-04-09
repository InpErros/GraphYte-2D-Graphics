#ifndef TEXT_H_
#define TEXT_H_

#include "Shape.h"

class Text: public Shape
{
	public:
		Text();

		Text(const uint& X, const uint& Y,
		     const uint& L, const uint& W);

		~Text();

		void SetValues(const uint& X, const uint& Y,
			     	   const uint& L, const uint& W);

		uint Area() const{return length*width;}

		uint Perimeter() const{return((2*length) + (2*width));}

	private:
		uint length;
		uint width;
};

#endif /* TEXT_H_ */

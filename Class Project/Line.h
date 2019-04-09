#ifndef LINE_H_
#define LINE_H_

#include "Shape.h"

class Line: public Shape
{
	public:
		Line(); //default constructor

		//non-default constructor
		Line(const uint& X, const uint& Y, const uint& X2, const uint& Y2);

		~Line();// deconstructor

		void SetValues(const uint& X,  const uint& Y,
					   const uint& X2, const uint& Y2);

		uint Area() const{return 0;}
		uint Perimeter() const{return 0;}

	private:
		uint x2;
		uint y2;
};

#endif /* LINE_H_ */

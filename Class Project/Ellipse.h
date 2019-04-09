#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "Shape.h"
#include <math.h>

const float PI = 3.142;

class Ellipse: public Shape {
	public:
		Ellipse(); //Default constructor

		Ellipse(const uint& X,  const uint& Y,
				const uint& A, const uint& B); //Non-Default constructor

		Ellipse(const uint& X, const uint& Y, //Non-Default Circle
				const uint& A);

		~Ellipse(); //Deconstuctor

		//Set values of an Ellipse
		void SetValues(const uint& X,  const uint& Y,
				       const uint& A, const uint& B);

		//Set values of a Circle
		void SetValues(const uint& X, const uint& Y,
					   const uint& A);

		unsigned float Area() const;

		//Calc Perimeter of an Ellipse
		unsigned float Perimeter() const;

	private:
		uint a;
		uint b;
		bool circle;
};

#endif /* ELLIPSE_H_ */

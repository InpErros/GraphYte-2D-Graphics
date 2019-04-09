#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle: public Shape
{
	public:
		Rectangle(); //Default Constructor

		Rectangle(const uint& X, const uint& Y,
				  const uint& L, const uint& W); //Non-Default Constructor

		Rectangle(const uint& X, const uint& Y,
				  const uint& L);//Non-Default Square Constructor

		~Rectangle(); //Deconstructor

		//Set values of an Rectangle
		void SetInitialValues(const uint& X, const uint& Y,
							  const uint& L, const uint& W);

		//Set values of a Square
		void SetInitialValues(const uint& X, const uint& Y,
							  const uint& L);

		uint Area() const;

		uint Perimeter() const;

	private:
		uint length;
		uint width;
		bool square;
};

#endif /* RECTANGLE_H_ */

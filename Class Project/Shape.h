#ifndef SHAPE_H_
#define SHAPE_H_

typedef unsigned int uint;

class Shape //Base Class
{
	public:
		Shape(){_x=0; _y=0;}
		Shape(const uint& x,const uint& y){_x=x; _y=y;}
		virtual Shape* clone() const = 0;   // The Virtual (Copy) Constructor
		virtual ~Shape() {}; // deconstructor

		virtual void Move() const = 0;
		virtual void Draw() const = 0;
		virtual uint  Perimeter() const = 0;
		virtual uint  Area() const = 0;

		void SetValues(const uint& x, const uint& y){_x=x; _y=y;}

	private:
		uint _x; //The width of the shape
		uint _y; //The height of the shape
};

#endif /* SHAPE_H_ */

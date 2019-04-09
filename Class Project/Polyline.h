#ifndef POLYLINE_H_
#define POLYLINE_H_

#include "Shape.h"
#include <vector>
using std::vector;

class Polyline: public Shape
{
	public:
		Polyline(); //Default Constructor

		Polyline(const vector<uint>& SEGMENTS); //Non-Default Constructor

		~Polyline(); //Deconstructor

		void SetValues(const vector<uint>& SEGMENTS);

		uint Area() const{return 0;}
		uint Perimeter() const{return 0;}

	private:
		vector<uint> segments;
};

#endif /* POLYLINE_H_ */

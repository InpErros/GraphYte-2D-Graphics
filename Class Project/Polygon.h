#ifndef POLYGON_H_
#define POLYGON_H_

#include "Shape.h"
#include <vector>
using std::vector;

class Polygon: public Shape
{
	public:
		Polygon(); //Default constructor

		Polygon(const vector<uint>& SIDES); //Non-Default constructor

		~Polygon(); //Deconstructor

		void SetValues(const vector<uint>& SIDES);
	private:
		vector<uint> sides;
};

#endif /* POLYGON_H_ */

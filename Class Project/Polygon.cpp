#include "Polygon.h"

Polygon::Polygon()
{
	sides.clear();
}

Polygon::Polygon(const vector<uint>& SIDES)
	:Shape(SIDES[0], SIDES[1])
{
	sides.reserve(SIDES.size());
	for(uint index = 2; index < SIDES.size(); index++)
	{
		sides[index] = SIDES[index];
	}
}

Polygon::~Polygon()
{
	sides.clear();
	vector<uint>().swap(sides);
}

void Polygon::SetValues(const vector<uint>& SIDES)
{
	sides.reserve(SIDES.size());

	Shape::SetValues(SIDES[0], SIDES[1]);

	for(uint index = 2; index < SIDES.size(); index++)
	{
		sides[index] = SIDES[index];
	}
}

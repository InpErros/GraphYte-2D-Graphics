#include "Polyline.h"

Polyline::Polyline()
{
	segments.clear();
}

Polyline::Polyline(const vector<uint>& SEGMENTS)
	:Shape(SEGMENTS[0], SEGMENTS[1])
{
	segments.reserve(SEGMENTS.size());
	for(uint index = 2; index < SEGMENTS.size(); index++)
	{
		segments[index] = SEGMENTS[index];
	}
}

Polyline::~Polyline()
{
}

void Polyline::SetValues(const vector<uint>& SEGMENTS)
{
	segments.reserve(SEGMENTS.size());
	Shape::SetValues(SEGMENTS[0], SEGMENTS[1]);
	for(uint index = 2; index < SEGMENTS.size(); index++)
	{
		segments[index] = SEGMENTS[index];
	}
}

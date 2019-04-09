#include "Text.h"

Text::Text()
{
	length = 0;
	width  = 0;
}

Text::Text(const uint& X, const uint& Y,
		   const uint& L, const uint& W)
	:Shape(X, Y)
{
	length = L;
	width = W;
}

Text::~Text()
{

}

void Text::SetValues(const uint& X, const uint& Y,
		   	   	     const uint& L, const uint& W)
{
	Shape::SetValues(X, Y);

	length = L;
	width = W;
}

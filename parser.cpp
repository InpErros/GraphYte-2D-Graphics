#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

enum ID
{
	LINE = 1,
	POLYLINE = 2,
	POLYGON = 3,
	RECTANGLE = 4,
	SQUARE = 5,
	ELLIPSE = 6,
	CIRCLE = 7,
	TEXT = 8
};

struct BasicShape
{
	int id;
	string type;
	vector<int> dimensions;
};

struct Shape
{
	BasicShape basicInfo;
	string penColor;
	int penWidth;
	string penStyle;
	string penCapStyle;
	string penJoinStyle;
	string brushColor;
	string brushStyle;
};

struct Text
{
	BasicShape basicInfo;
	string textString;
	string textColor;
	string textAlignment;
	int textPointSize;
	string textFontFamily;
	string textFontStyle;
	string textFontWeight;
};

ostream& operator<<(ostream& os, Shape& s); // testing purposes


int main()
{
	ifstream fin("C:\\Users\\zotaz\\OneDrive\\Desktop\\shapes.txt");
	string temp;
	
	BasicShape bShape;
	Shape *pShape = new Shape;
	Text *pText = new Text;

	vector<Shape> shapes;
	vector<Text>  texts;

	int count = 0;
	int shapeId;
	string type;
	//vector<int> dimensions;
	vector<int> dimensions1;
	string penColor;
	int penWidth;
	string penStyle;
	string penCapStyle;
	string penJoinStyle;
	string brushColor;
	string brushStyle;
	string textString;
	string textColor;
	string textAlignment;
	int textPointSize;
	string textFontFamily;
	string textFontStyle;
	string textFontWeight;
	string type1;
	
	int index;
	int dim;

	Shape newShape;
	Text newText;

	//Shape 1: Line
	getline(fin, temp, ' ');
	fin >> shapeId;						//ShapeId
	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, type1);				    //ShapeType
	getline(fin, temp, ' ');

	for(index = 0; index < 4; index++)	//ShapeDimensions
	{
		fin >> dim;
		dimensions1.push_back(dim);
		
		count++;

		if(index < 3)
		{
			getline(fin, temp, ' ');
		}
	}

	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, penColor);				//PenColor

	getline(fin, temp, ' ');
	fin >> penWidth;					//PenWidth

	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, penStyle);				//PenStyle

	getline(fin, temp, ' ');
	getline(fin, penCapStyle);					//PenCapStyle

	getline(fin, temp, ' ');
	getline(fin, penJoinStyle);					//PenJoinStyle

	fin.ignore(1000, '\n');
	
	pShape->basicInfo.id = shapeId;
	pShape->basicInfo.type = type1; 
	for(int i = 0; i < count; i++)
	{
		pShape->basicInfo.dimensions.push_back(dimensions1[i]);
	}
	
	pShape->penColor = penColor;
	pShape->penWidth = penWidth;
	pShape->penStyle = penStyle;
	pShape->penCapStyle = penCapStyle;
	pShape->penJoinStyle = penJoinStyle;
	
	
	shapes.push_back(*pShape);
	
	
	count = 0;

	//Shape 2: Polyline
	getline(fin, temp, ' ');
	fin >> shapeId;						//ShapeId
	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, type);				    //ShapeType
	getline(fin, temp, ' ');

	for(index = 0; index < 8; index++)	//ShapeDimensions
	{
		fin >> dim;
		dimensions1.push_back(dim);
		
		count++;

		if(index < 7)
		{
			getline(fin, temp, ' ');
		}
	}

	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, penColor);				//PenColor

	getline(fin, temp, ' ');
	fin >> penWidth;					//PenWidth

	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, penStyle);				//PenStyle

	getline(fin, temp, ' ');
	getline(fin, penCapStyle);					//PenCapStyle

	getline(fin, temp, ' ');
	getline(fin, penJoinStyle);					//PenJoinStyle

	fin.ignore(1000, '\n');
	
	pShape->basicInfo.id = shapeId;
	pShape->basicInfo.type = type1; 

	for(int i = 0; i < count; i++)
	{
		pShape->basicInfo.dimensions.push_back(dimensions1[i]);
	}
	
	pShape->penColor = penColor;
	pShape->penWidth = penWidth;
	pShape->penStyle = penStyle;
	pShape->penCapStyle = penCapStyle;
	pShape->penJoinStyle = penJoinStyle;
	
	
	shapes.push_back(*pShape);
	
	count = 0;

	//Shape 3: Polygon
	getline(fin, temp, ' ');
	fin >> shapeId;						//ShapeId
	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, type);				    //ShapeType
	getline(fin, temp, ' ');

	for(index = 0; index < 8; index++)	//ShapeDimensions
	{
		fin >> dim;
		dimensions1.push_back(dim);
		
		count++;

		if(index < 7)
		{
			getline(fin, temp, ' ');
		}
	}

	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, penColor);				//PenColor

	getline(fin, temp, ' ');
	fin >> penWidth;					//PenWidth

	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, penStyle);				//PenStyle

	getline(fin, temp, ' ');
	getline(fin, penCapStyle);					//PenCapStyle

	getline(fin, temp, ' ');
	getline(fin, penJoinStyle);					//PenJoinStyle

	getline(fin, temp, ' ');
	getline(fin, brushColor);					//Brush Color

	getline(fin, temp, ' ');
	getline(fin, brushStyle);					//Brush Style

	fin.ignore(1000, '\n');

	pShape->basicInfo.id = shapeId;
	pShape->basicInfo.type = type1; 

	for(int i = 0; i < count; i++)
	{
		pShape->basicInfo.dimensions.push_back(dimensions1[i]);
	}
	
	pShape->penColor = penColor;
	pShape->penWidth = penWidth;
	pShape->penStyle = penStyle;
	pShape->penCapStyle = penCapStyle;
	pShape->penJoinStyle = penJoinStyle;
	pShape->brushColor = brushColor;
	pShape->brushStyle = brushStyle;
	
	shapes.push_back(*pShape);
	
	count = 0;
	
	//Shape 4: Rectangle
	getline(fin, temp, ' ');
	fin >> shapeId;						//ShapeId
	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, type);				    //ShapeType
	getline(fin, temp, ' ');

	for(index = 0; index < 4; index++)	//ShapeDimensions
	{
		fin >> dim;
		dimensions1.push_back(dim);
		
		count++;

		if(index < 3)
		{
			getline(fin, temp, ' ');
		}
	}

	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, penColor);				//PenColor

	getline(fin, temp, ' ');
	fin >> penWidth;					//PenWidth

	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, penStyle);				//PenStyle

	getline(fin, temp, ' ');
	getline(fin, penCapStyle);					//PenCapStyle

	getline(fin, temp, ' ');
	getline(fin, penJoinStyle);					//PenJoinStyle

	getline(fin, temp, ' ');
	getline(fin, brushColor);					//Brush Color

	getline(fin, temp, ' ');
	getline(fin, brushStyle);					//Brush Style

	fin.ignore(1000, '\n');
	
	pShape->basicInfo.id = shapeId;
	pShape->basicInfo.type = type1; 

	for(int i = 0; i < count; i++)
	{
		pShape->basicInfo.dimensions.push_back(dimensions1[i]);
	}
	
	pShape->penColor = penColor;
	pShape->penWidth = penWidth;
	pShape->penStyle = penStyle;
	pShape->penCapStyle = penCapStyle;
	pShape->penJoinStyle = penJoinStyle;
	pShape->brushColor = brushColor;
	pShape->brushStyle = brushStyle;
	
	
	shapes.push_back(*pShape);
	
	count = 0;

	//Shape 5: Square
	getline(fin, temp, ' ');
	fin >> shapeId;						//ShapeId
	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, type);				    //ShapeType
	getline(fin, temp, ' ');

	for(index = 0; index < 3; index++)	//ShapeDimensions
	{
		fin >> dim;
		dimensions1.push_back(dim);
		
		count++;

		if(index < 2)
		{
			getline(fin, temp, ' ');
		}
	}

	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, penColor);				//PenColor

	getline(fin, temp, ' ');
	fin >> penWidth;					//PenWidth

	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, penStyle);				//PenStyle

	getline(fin, temp, ' ');
	getline(fin, penCapStyle);					//PenCapStyle

	getline(fin, temp, ' ');
	getline(fin, penJoinStyle);					//PenJoinStyle

	getline(fin, temp, ' ');
	getline(fin, brushColor);					//Brush Color

	getline(fin, temp, ' ');
	getline(fin, brushStyle);					//Brush Style

	fin.ignore(1000, '\n');

	pShape->basicInfo.id = shapeId;
	pShape->basicInfo.type = type1; 

	for(int i = 0; i < count; i++)
	{
		pShape->basicInfo.dimensions.push_back(dimensions1[i]);
	}
	
	pShape->penColor = penColor;
	pShape->penWidth = penWidth;
	pShape->penStyle = penStyle;
	pShape->penCapStyle = penCapStyle;
	pShape->penJoinStyle = penJoinStyle;
	pShape->brushColor = brushColor;
	pShape->brushStyle = brushStyle;
	
	
	shapes.push_back(*pShape);
	
	count = 0;
	
	//Shape 6: Ellipse
	getline(fin, temp, ' ');
	fin >> shapeId;						//ShapeId
	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, type);				    //ShapeType
	getline(fin, temp, ' ');

	for(index = 0; index < 4; index++)	//ShapeDimensions
	{
		fin >> dim;
		dimensions1.push_back(dim);
		
		count++;

		if(index < 3)
		{
			getline(fin, temp, ' ');
		}
	}

	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, penColor);				//PenColor

	getline(fin, temp, ' ');
	fin >> penWidth;					//PenWidth

	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, penStyle);				//PenStyle

	getline(fin, temp, ' ');
	getline(fin, penCapStyle);					//PenCapStyle

	getline(fin, temp, ' ');
	getline(fin, penJoinStyle);					//PenJoinStyle

	getline(fin, temp, ' ');
	getline(fin, brushColor);					//Brush Color

	getline(fin, temp, ' ');
	getline(fin, brushStyle);					//Brush Style

	fin.ignore(1000, '\n');
	
	pShape->basicInfo.id = shapeId;
	pShape->basicInfo.type = type1; 

	for(int i = 0; i < count; i++)
	{
		pShape->basicInfo.dimensions.push_back(dimensions1[i]);
	}
	
	pShape->penColor = penColor;
	pShape->penWidth = penWidth;
	pShape->penStyle = penStyle;
	pShape->penCapStyle = penCapStyle;
	pShape->penJoinStyle = penJoinStyle;
	pShape->brushColor = brushColor;
	pShape->brushStyle = brushStyle;
	
	
	shapes.push_back(*pShape);
	
	count = 0;

	//Shape 7: Circle
	getline(fin, temp, ' ');
	fin >> shapeId;						//ShapeId
	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, type);				    //ShapeType
	getline(fin, temp, ' ');

	for(index = 0; index < 3; index++)	//ShapeDimensions
	{
		fin >> dim;
		dimensions1.push_back(dim);
		
		count++;

		if(index < 2)
		{
			getline(fin, temp, ' ');
		}
	}

	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, penColor);				//PenColor

	getline(fin, temp, ' ');
	fin >> penWidth;					//PenWidth

	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, penStyle);				//PenStyle

	getline(fin, temp, ' ');
	getline(fin, penCapStyle);					//PenCapStyle

	getline(fin, temp, ' ');
	getline(fin, penJoinStyle);					//PenJoinStyle

	getline(fin, temp, ' ');
	getline(fin, brushColor);					//Brush Color

	getline(fin, temp, ' ');
	getline(fin, brushStyle);					//Brush Style

	fin.ignore(1000, '\n');
	
	pShape->basicInfo.id = shapeId;
	pShape->basicInfo.type = type1; 

	for(int i = 0; i < count; i++)
	{
		pShape->basicInfo.dimensions.push_back(dimensions1[i]);
	}
	
	pShape->penColor = penColor;
	pShape->penWidth = penWidth;
	pShape->penStyle = penStyle;
	pShape->penCapStyle = penCapStyle;
	pShape->penJoinStyle = penJoinStyle;
	pShape->brushColor = brushColor;
	pShape->brushStyle = brushStyle;
	
	
	shapes.push_back(*pShape);
	
	count = 0;

	//Shape 8: Text
	getline(fin, temp, ' ');
	fin >> shapeId;						//ShapeId
	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, type);				    //ShapeType
	getline(fin, temp, ' ');

	for(index = 0; index < 4; index++)	//ShapeDimensions
	{
		fin >> dim;
		dimensions1.push_back(dim);
		
		count++;

		if(index < 3)
		{
			getline(fin, temp, ' ');
		}
	}

	fin.ignore(1000, '\n');
	getline(fin, temp, ' ');
	getline(fin, textString);				//TextString

	getline(fin, temp, ' ');
	getline(fin, textColor);					//TextColor

	getline(fin, temp, ' ');
	getline(fin, textAlignment);				//TextAlignment

	getline(fin, temp, ' ');
	fin >> textPointSize;
	fin.ignore(1000, '\n');						//TextPointSize

	getline(fin, temp, ' ');
	getline(fin, textFontFamily);					//TextFontFamily

	getline(fin, temp, ' ');
	getline(fin, textFontStyle);					//TextFontStyle

	getline(fin, temp, ' ');
	getline(fin, textFontWeight);					//TextFontWeight

	fin.ignore(1000, '\n');
	
	pText->basicInfo.id = shapeId;
	pText->basicInfo.type = type1; 

	for(int i = 0; i < count; i++)
	{
		pText->basicInfo.dimensions.push_back(dimensions1[i]);
	}
	
	pText->textString = textString;
	pText->textColor = textColor;
	pText->textAlignment = textAlignment;
	pText->textPointSize = textPointSize;
	pText->textFontFamily = textFontFamily;
	pText->textFontStyle = textFontStyle;
	pText->textFontWeight = textFontWeight;
	
	
	texts.push_back(*pText);

	fin.close();

	return 0;
}
ostream& operator<<(ostream& os, Shape& s) // this was for testing purposes, I don't know how to output all of the shapes to the screen at once considering the dimension sizes are all different
{
	os << s.basicInfo.id << endl;
	os << s.basicInfo.type << endl;
	for(int i = 0; i < 4; i++)
	{
		os << s.basicInfo.dimensions[i] << ' ';
	}
	
	os << endl;
	os << s.penColor << endl;
	os << s.penWidth << endl;
	os << s.penStyle << endl;
	os << s.penCapStyle << endl;
	os << s.penJoinStyle << endl;
	
	return os;
	
}

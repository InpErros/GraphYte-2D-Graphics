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
	//string temp;                          //We don't need to allocate memory for temp anymore
                                            //changes have been made as seen on the code down below. 
	
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
    fin.ignore(9, '\n');
    fin.ignore(9, '\n');
    fin >> shapeId;                        //ShapeId
    
    fin.ignore();
    fin.ignore(11, '\n');
    getline(fin, type);                    //ShapeType
    
    fin.ignore(17, '\n');
    
    for(index = 0; index < 4; index++)    //ShapeDimensions
    {
        fin >> dim;
        dimensions1.push_back(dim);
        
        if(index < 3)
        {
            fin.ignore ();
        }
    }
    
    fin.ignore ();
    fin.ignore ();
    fin.ignore(10, '\n');
    
    getline(fin, penColor);                //PenColor
    
    fin.ignore(10, '\n');
    fin >> penWidth;                    //PenWidth
    
    fin.ignore();
    fin.ignore();
    fin.ignore(10, '\n');
    getline(fin, penStyle);                //PenStyle
    
    fin.ignore(13, '\n');
    getline(fin, penCapStyle);                    //PenCapStyle
    
    fin.ignore(14, '\n');
    getline(fin, penJoinStyle);                    //PenJoinStyle
    

	
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
    fin.ignore(9, '\n');
    fin.ignore(9, '\n');
    
    fin >> shapeId;                        //ShapeId
    
    fin.ignore();
    fin.ignore();
    fin.ignore(11, '\n');
    getline(fin, type);                    //ShapeType
    
    fin.ignore(17, '\n');
    
    for(index = 0; index < 8; index++)    //ShapeDimensions
    {
        fin >> dim;
        dimensions1.push_back(dim);
        
        if(index < 7)
        {
            fin.ignore ();
        }
    }
    
    fin.ignore();
    fin.ignore();
    fin.ignore(10, '\n');
    getline(fin, penColor);                //PenColor
    
    fin.ignore(10, '\n');
    fin >> penWidth;                    //PenWidth
    
    
    fin.ignore();
    fin.ignore();
    fin.ignore(10, '\n');
    getline(fin, penStyle);                //PenStyle
    
    fin.ignore(13, '\n');
    getline(fin, penCapStyle);                    //PenCapStyle
    
    
    fin.ignore(14, '\n');
    getline(fin, penJoinStyle);                    //PenJoinStyle
	
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
    fin.ignore(9, '\n');
    fin.ignore(9, '\n');
    fin >> shapeId;                        //ShapeId
    
    fin.ignore();
    fin.ignore();
    fin.ignore(11, '\n');
    getline(fin, type);                    //ShapeType
    
    fin.ignore(17, '\n');
    
    
    for(index = 0; index < 8; index++)    //ShapeDimensions
    {
        fin >> dim;
        dimensions1.push_back(dim);
        
        if(index < 7)
        {
            fin.ignore ();
        }
    }
    
    fin.ignore();
    fin.ignore();
    fin.ignore(10, '\n');
    getline(fin, penColor);                //PenColor
    
    fin.ignore(10, '\n');
    fin >> penWidth;                    //PenWidth
    
    fin.ignore();
    fin.ignore();
    fin.ignore(10, '\n');
    getline(fin, penStyle);                //PenStyle
    
    fin.ignore(13, '\n');
    getline(fin, penCapStyle);                    //PenCapStyle
    
    fin.ignore(14, '\n');
    getline(fin, penJoinStyle);                    //PenJoinStyle
    
    fin.ignore(12, '\n');
    getline(fin, brushColor);                    //Brush Color
    
    
    fin.ignore(12, '\n');
    getline(fin, brushStyle);                    //Brush Style
    


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
    fin.ignore(9, '\n');
    fin.ignore(9, '\n');
    
    fin >> shapeId;                        //ShapeId
    
    fin.ignore();
    fin.ignore();
    fin.ignore(11, '\n');
    getline(fin, type);                    //ShapeType
    
    fin.ignore(17, '\n');
    
    for(index = 0; index < 4; index++)    //ShapeDimensions
    {
        fin >> dim;
        dimensions1.push_back(dim);
        
        
        if(index < 3)
        {
            fin.ignore ();
        }
    }
    
    fin.ignore();
    fin.ignore();
    fin.ignore(10, '\n');
    getline(fin, penColor);                //PenColor
    
    fin.ignore(10, '\n');
    fin >> penWidth;                    //PenWidth
    
    fin.ignore();
    fin.ignore();
    fin.ignore(10, '\n');
    getline(fin, penStyle);                //PenStyle
    
    fin.ignore(13, '\n');
    getline(fin, penCapStyle);                    //PenCapStyle
    
    fin.ignore(14, '\n');
    getline(fin, penJoinStyle);                    //PenJoinStyle
    
    fin.ignore(12, '\n');
    getline(fin, brushColor);                    //Brush Color
    
    
    fin.ignore(12, '\n');
    getline(fin, brushStyle);                    //Brush Style
	
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
    fin.ignore(9, '\n');
    fin.ignore(9, '\n');
    fin >> shapeId;                        //ShapeId
    
    fin.ignore();
    fin.ignore();
    fin.ignore(11, '\n');
    getline(fin, type);                    //ShapeType
    
    fin.ignore(17, '\n');
    
    for(index = 0; index < 3; index++)    //ShapeDimensions
    {
        fin >> dim;
        dimensions1.push_back(dim);
        
        
        if(index < 2)
        {
            fin.ignore ();
        }
    }
    
    fin.ignore ();
    fin.ignore ();
    fin.ignore(10, '\n');
    getline(fin, penColor);                //PenColor
    
    fin.ignore(10, '\n');
    fin >> penWidth;                    //PenWidth
    
    fin.ignore();
    fin.ignore();
    fin.ignore(10, '\n');
    getline(fin, penStyle);                //PenStyle
    
    fin.ignore(13, '\n');
    getline(fin, penCapStyle);                    //PenCapStyle
    
    fin.ignore(14, '\n');
    getline(fin, penJoinStyle);                    //PenJoinStyle
    
    fin.ignore(12, '\n');
    getline(fin, brushColor);                    //Brush Color
    
    
    fin.ignore(12, '\n');
    getline(fin, brushStyle);                    //Brush Style

    
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
    fin.ignore(9, '\n');
    fin.ignore(9, '\n');
    fin >> shapeId;                        //ShapeId
    
    fin.ignore();
    fin.ignore();
    fin.ignore(11, '\n');
    getline(fin, type);                    //ShapeType
    
    fin.ignore(17, '\n');
    
    for(index = 0; index < 4; index++)    //ShapeDimensions
    {
        fin >> dim;
        dimensions1.push_back(dim);
        
        
        if(index < 3)
        {
            fin.ignore ();
        }
    }
    
    fin.ignore ();
    fin.ignore ();
    fin.ignore(10, '\n');
    getline(fin, penColor);                //PenColor
    
    fin.ignore(10, '\n');
    fin >> penWidth;                    //PenWidth
    
    fin.ignore();
    fin.ignore();
    fin.ignore(10, '\n');
    getline(fin, penStyle);                //PenStyle
    
    fin.ignore(13, '\n');
    getline(fin, penCapStyle);                    //PenCapStyle
    
    fin.ignore(14, '\n');
    getline(fin, penJoinStyle);                    //PenJoinStyle
    
    fin.ignore(12, '\n');
    getline(fin, brushColor);                    //Brush Color
    
    
    fin.ignore(12, '\n');
    getline(fin, brushStyle);                    //Brush Style

	
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
    fin.ignore(9, '\n');
    fin.ignore(9, '\n');
    fin >> shapeId;                        //ShapeId
    
    fin.ignore();
    fin.ignore();
    fin.ignore(11, '\n');
    getline(fin, type);                    //ShapeType
    
    fin.ignore(17, '\n');
    
    for(index = 0; index < 3; index++)    //ShapeDimensions
    {
        fin >> dim;
        dimensions1.push_back(dim);
        
        if(index < 2)
        {
            fin.ignore ();
        }
    }
    
    fin.ignore ();
    fin.ignore ();
    fin.ignore(10, '\n');
    
    getline(fin, penColor);                //PenColor
    
    fin.ignore(10, '\n');
    fin >> penWidth;                    //PenWidth
    
    fin.ignore();
    fin.ignore();
    fin.ignore(10, '\n');
    getline(fin, penStyle);                //PenStyle
    
    fin.ignore(13, '\n');
    getline(fin, penCapStyle);                    //PenCapStyle
    
    fin.ignore(14, '\n');
    getline(fin, penJoinStyle);                    //PenJoinStyle
    
    fin.ignore(12, '\n');
    getline(fin, brushColor);                    //Brush Color
    
    
    fin.ignore(12, '\n');
    getline(fin, brushStyle);                    //Brush Style
    
	
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
    fin.ignore(9, '\n');
    fin.ignore(9, '\n');
    fin >> shapeId;                        //ShapeId
    
    fin.ignore();
    fin.ignore();
    fin.ignore(11, '\n');
    getline(fin, type);                    //ShapeType
    
    fin.ignore(17, '\n');
    
    for(index = 0; index < 4; index++)    //ShapeDimensions
    {
        fin >> dim;
        dimensions1.push_back(dim);
        
        
        if(index < 3)
        {
            fin.ignore ();
        }
    }
    
    fin.ignore(12, '\n');
    fin.ignore(12, '\n');
    getline(fin, textString);                //TextString
    
    
    fin.ignore(11, '\n');
    getline(fin, textColor);                    //TextColor
    
    fin.ignore(15, '\n');
    getline(fin, textAlignment);                //TextAlignment
    
    fin.ignore(15, '\n');
    fin >> textPointSize;                    //TextPointSize
    
    fin.ignore(16, '\n');
    fin.ignore(16, '\n');
    getline(fin, textFontFamily);                    //TextFontFamily
    
    fin.ignore(15, '\n');
    getline(fin, textFontStyle);                    //TextFontStyle
    
    fin.ignore(16, '\n');
    getline(fin, textFontWeight);                    //TextFontWeight
    
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

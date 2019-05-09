#ifndef SHAPEINFOFUNC_H
#define SHAPEINFOFUNC_H
#include "Shape.h"
#include "vector.h"
#include "Line.h"
#include "Polygon.h"
#include "Polyline.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Textbox.h"

// Methods for Outputting shape properties sorted by id, area, and perimeter
// to output files
class ShapeFunc
{
public:

/****************************************************************
 * static void PrintShapeListing(const Vector<Shape*>& shapes)
 *   Mutator; outputs all of the shape properties sorted by id
 *             to an output file
 *   Parameters: shapes (const Vector<Shape*>&) - the vector to
 *                                                be output
 *   Return: none
 ***************************************************************/
static void PrintShapeListing(const Vector<Shape*>& shapes)
{
    Vector<Shape*> temp = shapes;
    ofstream fout("ShapeListing.txt");

    // Runs through the vector and outputs each element
    for(int index = 0; index < temp.size(); index++)
    {
        ShapeType newShape = temp[index]->GetShape();
        // Calls the overloaded ostream operator for each specific shape
        // and outputs the shape to the output file
        switch(newShape)
        {
        case ShapeType::Line:      static_cast<Line*>
                                     (temp[index])->Print(fout);
                                   break;
        case ShapeType::Polyline:  static_cast<Polyline*>
                                     (temp[index])->Print(fout);
                                   break;
        case ShapeType::Polygon:   static_cast<Polygon*>
                                     (temp[index])->Print(fout);
                                   break;
        case ShapeType::Rectangle: static_cast<Rectangle*>
                                     (temp[index])->Print(fout);
                                   break;
        case ShapeType::Square:    static_cast<Rectangle*>
                                     (temp[index])->Print(fout);
                                   break;
        case ShapeType::Ellipse:   static_cast<Ellipse*>
                                     (temp[index])->Print(fout);
                                   break;
        case ShapeType::Circle:    static_cast<Ellipse*>
                                     (temp[index])->Print(fout);
                                   break;
        case ShapeType::Text:      static_cast<Textbox*>
                                     (temp[index])->Print(fout);
                                   break;
        case ShapeType::NoShape: break;
        }
        fout << endl;

    }
    fout.close();
}

/****************************************************************
 * static void PrintAreaShapeListing(const Vector<Shape*>& shapes)
 *   Mutator; outputs the shapes sorted by area, including the
 *            shapes id and shape type to an output file
 *   Parameters: shapes (const Vector<Shape*>&) - the vector to
 *                                                be output
 *   Return: none
 ***************************************************************/
static void PrintAreaShapeListing(const Vector<Shape*>& shapes)
{
    Vector<Shape*> temp = shapes;
    Shape* tempSpot;
    int j;
    ofstream fout;

    // Sorts the vector in ascending order of the area
    for(int i = 1; i < shapes.size(); i++)
    {
        tempSpot = temp[i];
        j = i -1;
        while(j >= 0 && temp[i]->Area() > tempSpot->Area())
        {
            temp[j + 1] = temp[j];
            j = j -1;
        }
        temp[j + 1] = tempSpot;
    }

    fout.open("AreaShapeListing.txt");
    // Outputs the area of the shape, followed by the id and then shape type
    for(int index = 0; index < temp.size(); index++)
    {
        if(temp[index]->Area() > 1) //checks if the shape has an area
        {
            ShapeType type = temp[index]->GetShape();

            fout << temp[index]->Area() << endl;
            fout << temp[index]->GetId() << endl;
            switch(type)
            {
            case ShapeType::NoShape: break;
            case ShapeType::Line: fout << "Line";
                break;
            case ShapeType::Polyline: fout << "Polyline";
                break;
            case ShapeType::Polygon: fout << "Polygon";
                break;
            case ShapeType::Rectangle: fout << "Rectangle";
                break;
            case ShapeType::Square: fout << "Square";
                break;
            case ShapeType::Ellipse: fout << "Ellipse";
                break;
            case ShapeType::Circle: fout << "Circle";
                break;
            case ShapeType::Text: fout << "Text";
                break;
            }
            fout << endl << endl;
        } // end if
    } // end for
    fout.close();
}

/****************************************************************
 * static void PrintPerimeterShapeListing(const Vector<Shape*>& shapes)
 *   Mutator; outputs the shapes sorted by perimeter, including the
 *            shapes id and shape type to an output file
 *   Parameters: shapes (const Vector<Shape*>&) - the vector to
 *                                                be output
 *   Return: none
 ***************************************************************/
static void PrintPerimeterShapeListing(const Vector<Shape*>& shapes)
{
    Vector<Shape*> temp = shapes;
    Shape* tempSpot;
    ofstream fout;
    int j;

       // Sorts the vector in ascending order of the area
       for(int i = 1; i < temp.size(); i++)
       {
           tempSpot = temp[i];
           j = i -1;
           while(j >= 0 && temp[i]->Perimeter() < tempSpot->Perimeter())
           {
               temp[j + 1] = temp[j];
               j = j -1;
           }
           temp[j + 1] = tempSpot;
       }
//       int index;

//       for(int i = shapes.size() -1; i >= 1; i--)
//       {
//           tempSpot = temp[0];
//           index = 0;

//           for(int j = 1; j <= 1; j++)
//           {
//               if(temp[j]->Area() > tempSpot->Area())
//               {
//                   tempSpot = temp[index];
//                   index = j;
//               }
//           }
//           temp[index] = temp[i];
//           temp[i] = tempSpot;
//       }

       fout.open("PerimeterShapeListing.txt");

       // Outputs the area of the shape, followed by the id and then shape type
       for(int index = 0; index < temp.size(); index++)
       {
           if(temp[index]->Perimeter() > 1) //checks if the shape has a perimeter
           {
               ShapeType type = temp[index]->GetShape();

               fout << temp[index]->Perimeter() << endl;
               fout << temp[index]->GetId() << endl;
               switch(type)
               {
               case ShapeType::NoShape: break;
               case ShapeType::Line: fout << "Line";
                   break;
               case ShapeType::Polyline: fout << "Polyline";
                   break;
               case ShapeType::Polygon: fout << "Polygon";
                   break;
               case ShapeType::Rectangle: fout << "Rectangle";
                   break;
               case ShapeType::Square: fout << "Square";
                   break;
               case ShapeType::Ellipse: fout << "Ellipse";
                   break;
               case ShapeType::Circle: fout << "Circle";
                   break;
               case ShapeType::Text: fout << "Text";
                   break;
               }
               fout << endl << endl;
           } // end if
       } // end for
//       fout.close();
}

};
#endif // SHAPEINFOFUNC_H

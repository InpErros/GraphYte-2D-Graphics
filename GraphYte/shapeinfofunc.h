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
#include <QtAlgorithms>
#include <vector.h>

enum compare {
                ID,
                AREA,
                PERIMETER
};

// Methods for Outputting shape properties sorted by id, area, and perimeter
// to output files
template <typename Type>
class ShapeFunc
{
public:

    /****************************************************************
     * static void Sort(Vector<Shape*>& shapes, compare Compare)
     *   Mutator; sorts a vector by id, area, or perimeter
     *   Parameters: shapes (Vector<Shape*>&) - the vector to be sorted
     *               Compare (compare)        - enum used to distinguish
     *                                          how to sort the vector
     *   Return: none
     ***************************************************************/
    static void Sort(Vector<Shape*>& shapes, compare Compare)
    {
        // Changes the vector to a QVector so that sort is able to be
        // implemented
        QVector<Shape*> temp = shapes.ToQV();

        // Sorts the vector by id, area, or perimeter
        switch(Compare)
        {
        case ID: std::sort(begin(temp), end(temp),
                  [](Shape* s1, Shape* s2){return s1->GetId() < s2->GetId();});

            break;
        case AREA: std::sort(begin(temp), end(temp),
                    [](Shape* s1, Shape* s2){return s1->Area() < s2->Area();});
            break;
        case PERIMETER: std::sort(begin(temp), end(temp),
                         [](Shape* s1, Shape* s2)
                             {return s1->Perimeter() < s2->Perimeter();});
            break;
        }
        // Changes the QVector back to a vector
        shapes.FromQV(temp);
    }

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
    compare Compare = AREA;

    // Calls the sort function
    Sort(temp, Compare);

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
    ofstream fout("AreaShapeListing.txt");
    compare Compare = AREA;

    // Calls the sort function
    Sort(temp, Compare);

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
    ofstream fout;
    compare Compare = PERIMETER;

    // Calls the sort function
    Sort(temp, Compare);

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

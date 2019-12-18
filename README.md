# GraphYte-2D-Graphics

This was a class project for my Computer Science class that involved a team of 6 people. 

Task:

You are to create software for modeling basic 2D graphics objects. The modeler will demonstrate the capabilities of 2D Graphics 
Modeler Inc.’sgraphics engine. Potential customers will be looking for a 2D graphics rendering librarywhich can be integrated into their 
own software suite.You must use inheritance, composition, exception handlers, a virtual function, and at least two overloaded operators. 
At least one class should use templates. At least one class must contain a pointer (a copy constructor needs to be written and tested).
Highlight the above in your code.Use the Qt QPainter low-level graphics rendering library to draw shapes on a QWidget rendering area 
(refer to the Qt Basic Drawing Example documentation and source codeas an example). Implement a Shape abstract base class which contains 
aQPainterdata member via a compositionrelationship. Shape has pure virtual functions draw, move, perimeter& area. Types of Shapes: Line, 
Polyline, Polygon, Rectangle, Ellipse, Text. Shape Properties: ShapeDimensions, Pen Color, Pen Width, Pen Style, PenCapStyle, 
PenJoinStyle, Brush Color, Brush Style.Text Properties: TextString, TextColor, TextAlignment, TextPointSize, TextFontFamily, 
TextFontStyle, TextFontWeight(refer to shape_input_file_specs.txt). Line, Polyline, Polygon, Rectangle, Ellipse, TextClasses will override
the virtual interface of base class Shape (i.e. interface inheritance).All Shape Types will be implemented as separate derived classes 
which inherit from Shape. Overload the equalityand less than relational operators in base classShape. These overloaded operators will 
compare shape object ids. This will supportsorting shapes by id. 2Disablecopy operations (constructor, assignment operator) for all shape 
types.This can be accomplished by marking the copy constructor and assignment operator for class Shape as being deleted.You must 
implement the vectorclass as outlined inthevector.hspecificationbelow. Vector will be used to store the 2D graphics objects displayed by 
the modeler. Your vector class is a close approximation to the STL vector class. Vector supports the following basic operations: 
constructors for one or more arguments, default constructors, copy constructor, copy assignment, move constructor, moveassignmentand 
destructor. Vector also supports a basic iterator member type and member function begin() and end() operations. A partial outline/
implementation of the above will be provided to the team.

#ifndef VISITOR_HPP
#define VISITOR_HPP

class Circle;
class Rectangle;
class Triangle;

class Visitor
{
public:

	virtual void VisitCircle(const Circle&) = 0;
	virtual void VisitRectangle(const Rectangle&) = 0;
	virtual void VisitTriangle(const Triangle&) = 0;
};

#endif  //  VISITOR_HPP
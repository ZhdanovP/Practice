#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "visitor.hpp"

class Shape {
public:

	virtual void Accept(Visitor&) = 0;

};

#endif  //  SHAPE_HPP


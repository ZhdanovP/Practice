#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "visitor.hpp"

class Rectangle : public Shape {
public:

	Rectangle() 
		: m_width(0.0)
		, m_length(0.0) {}

	Rectangle(const double width, const double length) 
		: m_width(width)
		, m_length(length) {}

	void Accept(Visitor& v) override {
		v.VisitRectangle(*this);
	}

	double GetWidth() const {
		return m_width;
	}

	double GetLength() const {
		return m_length;
	}

private:

	double m_width;
	double m_length;

};

#endif  //  RECTANGLE_HPP
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "visitor.hpp"

class Circle : public Shape {
public:

	Circle() : m_radius(0.0) {}

	Circle(const double radius) : m_radius(radius) {}

	void Accept(Visitor& v) override {
		v.VisitCircle(*this);
	}

	double GetRadius() const {
		return m_radius;
	}

private:

	double m_radius;

};

#endif  //  CIRCLE_HPP
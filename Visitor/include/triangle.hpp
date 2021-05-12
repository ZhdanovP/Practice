#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"
#include "visitor.hpp"

class Triangle : public Shape {
public:

	Triangle() 
		: m_side_a(0.0)
		, m_side_b(0.0)
		, m_side_c(0.0) {}

	Triangle(const double a, const double b, const double c) 
		: m_side_a(a)
		, m_side_b(b)
		, m_side_c(c) {}

	void Accept(Visitor& v) override {
		v.VisitTriangle(*this);
	}

	double GetASide() const {
		return m_side_a;
	}

	double GetBSide() const {
		return m_side_b;
	}

	double GetCSide() const {
		return m_side_c;
	}

	double GetHalfThePerimeter() const {
		const double perimeter = m_side_a + m_side_b + m_side_c;
		return perimeter / 2;
	}

private:

	double m_side_a;
	double m_side_b;
	double m_side_c;

};

#endif  //  TRIANGLE_HPP
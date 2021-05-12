#ifndef AREA_VISITOR_HPP
#define AREA_VISITOR_HPP

#include "visitor.hpp"

#include <cmath>
#include <atomic>

#define PI 3.14159265358979323846

class AreaVisitor : public Visitor {
public:

	void VisitCircle(const Circle& c) override {
		m_currentArea = PI * c.GetRadius() * c.GetRadius();
	}

	void VisitRectangle(const Rectangle& r) override {
		m_currentArea = r.GetWidth() * r.GetLength();
	}

	void VisitTriangle(const Triangle& t) override {
		const double p = t.GetHalfThePerimeter();
		const double a = t.GetASide();
		const double b = t.GetBSide();
		const double c = t.GetCSide();

		m_currentArea = std::sqrt(p * (p - a) * (p - b) * (p - c));
	}

	double GetArea() const {
		return m_currentArea;
	}

private:

	std::atomic<double> m_currentArea;

};

#endif  //  AREA_VISITOR_HPP
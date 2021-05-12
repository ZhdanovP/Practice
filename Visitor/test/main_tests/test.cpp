#include "gtest/gtest.h"

#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "area_visitor.hpp"

#include <iostream>

//#define DEBUG_TESTS

namespace TestHelper {

template<class T>
void print_comparable(const T& expected, const T& actual) {
#ifdef DEBUG_TESTS
	std::cout << std::fixed << std::setprecision(20) 
        << "expected=" << expected 
        << "\nactual=" << actual << '\n';
#endif
}

}  // TestHelper

TEST(VisitorTest, Test_Circle_DefaultConstructor) {
	Circle c;

	const double expected_radius = 0.0;
	const double actual_radius = c.GetRadius();

	EXPECT_EQ(expected_radius, actual_radius);
}

TEST(VisitorTest, Test_Circle_ParameterizedConstructor) {
	Circle c(5.2);

	const double expected_radius = 5.2;
	const double actual_radius = c.GetRadius();

	EXPECT_EQ(expected_radius, actual_radius);
}

TEST(VisitorTest, Test_Rectangle_DefaultConstructor) {
	Rectangle r;

	const double expected_width = 0.0;
	const double expected_length = 0.0;

	const double actual_width = r.GetWidth();
	const double actual_length = r.GetLength();

	EXPECT_EQ(expected_width, actual_width);
	EXPECT_EQ(expected_length, actual_length);
}

TEST(VisitorTest, Test_Rectangle_ParameterizedConstructor) {
	Rectangle r(5, 10);

	const double expected_width = 5;
	const double expected_length = 10;

	const double actual_width = r.GetWidth();
	const double actual_length = r.GetLength();

	EXPECT_EQ(expected_width, actual_width);
	EXPECT_EQ(expected_length, actual_length);
}

TEST(VisitorTest, Test_Triangle_DefaultConstructor) {
	Triangle t;

	const double expected_a_side = 0.0;
	const double expected_b_side = 0.0;
	const double expected_c_side = 0.0;

	const double actual_a_side = t.GetASide();
	const double actual_b_side = t.GetBSide();
	const double actual_c_side = t.GetCSide();

	EXPECT_EQ(expected_a_side, actual_a_side);
	EXPECT_EQ(expected_b_side, actual_b_side);
	EXPECT_EQ(expected_c_side, actual_c_side);
}

TEST(VisitorTest, Test_Triangle_ParameterizedConstructor) {
	Triangle t(5, 10, 7);

	const double expected_a_side = 5;
	const double expected_b_side = 10;
	const double expected_c_side = 7;

	const double actual_a_side = t.GetASide();
	const double actual_b_side = t.GetBSide();
	const double actual_c_side = t.GetCSide();

	EXPECT_EQ(expected_a_side, actual_a_side);
	EXPECT_EQ(expected_b_side, actual_b_side);
	EXPECT_EQ(expected_c_side, actual_c_side);
}

TEST(VisitorTest, Test_Triangle_HalfThePerimiter_Calculation) {
	Triangle t(5, 10, 7);

	const double expected_half_the_perimeter = 11.0;

	const double actual_half_the_perimeter = t.GetHalfThePerimeter();

	EXPECT_EQ(expected_half_the_perimeter, actual_half_the_perimeter);
}

TEST(VisitorTest, Test_AreaVisitor_CircleArea) {
	AreaVisitor area_visitor;

	std::shared_ptr<Shape> c = std::make_shared<Circle>(2);

	c->Accept(area_visitor);
	const double actual_circle_area = area_visitor.GetArea();

	const double expected_circle_area = 12.56637061435917246399;

	TestHelper::print_comparable(expected_circle_area, actual_circle_area);

	EXPECT_EQ(expected_circle_area, actual_circle_area);
}

TEST(VisitorTest, Test_AreaVisitor_RectangleArea) {
	AreaVisitor area_visitor;

	std::shared_ptr<Shape> c = std::make_shared<Rectangle>(5, 10);

	c->Accept(area_visitor);
	const double actual_rectangle_area = area_visitor.GetArea();

	const double expected_rectangle_area = 50.0;

	TestHelper::print_comparable(actual_rectangle_area, expected_rectangle_area);

	EXPECT_EQ(actual_rectangle_area, expected_rectangle_area);
}

TEST(VisitorTest, Test_AreaVisitor_TriangleArea) {
	AreaVisitor area_visitor;

	std::shared_ptr<Shape> c = std::make_shared<Triangle>(5, 10, 7);

	c->Accept(area_visitor);
	const double actual_triangle_area = area_visitor.GetArea();

	const double expected_triangle_area = 16.24807680927192166109;

	TestHelper::print_comparable(actual_triangle_area, expected_triangle_area);

	EXPECT_EQ(actual_triangle_area, expected_triangle_area);
}

TEST(VisitorTest, Test_AreaVisitor_ComplexArea) {

	std::vector<std::shared_ptr<Shape> > shapes {
		std::make_shared<Circle>(2),
		std::make_shared<Rectangle>(5, 10),
		std::make_shared<Triangle>(5, 10, 7)
	};

	AreaVisitor area_visitor;

	double acctual_total_area = 0.0;

	for(auto s : shapes) {
		s->Accept(area_visitor);
		acctual_total_area += area_visitor.GetArea();
	}

	const double expected_total_area = 78.81444742363109412508;

	TestHelper::print_comparable(expected_total_area, acctual_total_area);

	EXPECT_EQ(expected_total_area, acctual_total_area);
}









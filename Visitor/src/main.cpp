#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "area_visitor.hpp"

#include <vector>
#include <memory>
#include <iostream>


int main(int argc, char **argv) {

	std::vector<std::shared_ptr<Shape> > shapes {
		std::make_shared<Circle>(),
		std::make_shared<Rectangle>(),
		std::make_shared<Triangle>()
	};

	AreaVisitor area_visitor;

	double total_area = 0.0;

	for(auto s : shapes) {
		s->Accept(area_visitor);
		total_area += area_visitor.GetArea();
	}

	std::cout << "Total area is: " << total_area << std::endl;

	return 0;
}
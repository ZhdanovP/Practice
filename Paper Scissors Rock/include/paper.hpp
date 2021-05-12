#ifndef PAPER_HPP
#define PAPER_HPP

#include "symbol.hpp"

class Paper : public Symbol
{
public:

	Paper()
		: Symbol("Paper") {}


	Result IsBeat(const Symbol& s) const override {
		return s.IsBeat(*this);
	}
	Result IsBeat(const Paper&) const override {
		return Result::TIE;
	}
	Result IsBeat(const Scissors& s) const override {
		return Result::LOOSE;
	}
	Result IsBeat(const Rock& s) const override {
		return Result::WIN;
	}
};

#endif  // SCISSORS_HPP
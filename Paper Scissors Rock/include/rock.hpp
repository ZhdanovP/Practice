/*
 * Copyright (c) 2021, Pavel Zhdanov
 * All rights reserved.
 */

#ifndef ROCK_HPP
#define ROCK_HPP

#include "symbol.hpp"

class Rock : public Symbol
{
public:

	Rock()
		: Symbol("Rock") {}


	Result IsBeat(const Symbol& s) const override {
		return s.IsBeat(*this);
	}
	Result IsBeat(const Paper&) const override {
		return Result::LOOSE;
	}
	Result IsBeat(const Scissors& s) const override {
		return Result::WIN;
	}
	Result IsBeat(const Rock& s) const override {
		return Result::TIE;
	}
};

#endif  // SCISSORS_HPP
/*
 * Copyright (c) 2021, Pavel Zhdanov
 * All rights reserved.
 */

#ifndef SCISSORS_HPP
#define SCISSORS_HPP

#include "symbol.hpp"

class Scissors : public Symbol
{
public:

	Scissors()
		: Symbol("Scissors") {}

	Result IsBeat(const Symbol& s) const override {
		return s.IsBeat(*this);
	}
	Result IsBeat(const Paper&) const override {
		return Result::WIN;
	}
	Result IsBeat(const Scissors& s) const override {
		return Result::TIE;
	}
	Result IsBeat(const Rock& s) const override {
		return Result::LOOSE;
	}
};

#endif  // SCISSORS_HPP
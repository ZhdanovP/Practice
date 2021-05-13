/*
 * Copyright (c) 2021, Pavel Zhdanov
 * All rights reserved.
 */

#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <string>

enum class Result {
	WIN,
	LOOSE,
	TIE
};

class Paper;
class Scissors;
class Rock;

class Symbol {
public:

	/**
	* @brief Initialize symbol name
	* @param std::string
	*/
	Symbol(const std::string name)
		: m_symbol_name(name) {}

	/**
	* @brief GetName - getter for symbol name
	*/
	std::string GetName() const {
		return m_symbol_name;
	}

	/**
	* @brief IsBeat - is the given symbol beat the opposite one
	* @param Symbol
	*/
	virtual Result IsBeat(const Symbol& s) const = 0;

	/**
	* @brief IsBeat - is the given symbol beat the opposite one
	* @param Paper
	*/
	virtual Result IsBeat(const Paper& s) const = 0;

	/**
	* @brief IsBeat - is the given symbol beat the opposite one
	* @param Scissors
	*/
	virtual Result IsBeat(const Scissors& s) const = 0;

	/**
	* @brief IsBeat - is the given symbol beat the opposite one
	* @param Rock
	*/
	virtual Result IsBeat(const Rock& s) const = 0;

protected:

	std::string m_symbol_name;
};

#endif  // SYMBOL_HPP
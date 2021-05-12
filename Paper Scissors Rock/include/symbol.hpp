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

	Symbol(const std::string name)
		: m_symbol_name(name) {}

	virtual ~Symbol() = 0;

	std::string GetName() const {
		return m_symbol_name;
	}

	virtual Result IsBeat(const Symbol& s) const = 0;
	virtual Result IsBeat(const Paper& s) const = 0;
	virtual Result IsBeat(const Scissors& s) const = 0;
	virtual Result IsBeat(const Rock& s) const = 0;

protected:

	std::string m_symbol_name;
};

Symbol::~Symbol() {}

#endif  // SYMBOL_HPP
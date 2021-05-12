#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "symbol.hpp"

#include <memory>
#include <string>
#include <stdexcept>

class Player
{
public:

	Player(const std::string& name)
		: m_name(name) {}

	void SetName(const std::string& name) {
		m_name = name;
	}

	const std::string& GetName() const {
		return m_name;
	}

	void MakeChoose(std::function<std::shared_ptr<Symbol>()> method) {
		m_symbol = method();
	}

	const Symbol& GetSymbol() const {
		if (!m_symbol) {
			throw std::runtime_error("Symbol for player wasn't created.");
		}
		return *m_symbol;
	}

protected:
	std::shared_ptr<Symbol> m_symbol;
	std::string m_name;
};

#endif  // PLAYER_HPP
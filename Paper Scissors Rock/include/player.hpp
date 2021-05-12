#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "symbol.hpp"

#include <memory>
#include <string>

class Player
{
public:

	Player(const std::string& name)
		: m_name(name) {}

	virtual ~Player() = 0;

	const std::string& GetName() const {
		return m_name;
	}

	void SetSymbol(std::shared_ptr<Symbol> symbol) {
		m_symbol = symbol;
	}

	const Symbol& GetSymbol() const {
		return *m_symbol;
	}

protected:
	std::shared_ptr<Symbol> m_symbol;
	std::string m_name;
};

Player::~Player() {}

#endif  // PLAYER_HPP
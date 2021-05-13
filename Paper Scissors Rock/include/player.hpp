#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "symbol.hpp"

#include <memory>
#include <string>
#include <stdexcept>

class Player
{
public:

	Player(const std::string& name);

	void SetName(const std::string& name);

	const std::string& GetName() const;

	void MakeChoose(std::function<std::shared_ptr<Symbol>()> method);

	const Symbol& GetSymbol() const;

protected:
	std::shared_ptr<Symbol> m_symbol;
	std::string m_name;
};

#endif  // PLAYER_HPP
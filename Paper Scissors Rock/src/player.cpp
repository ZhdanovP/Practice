#include "player.hpp"

Player::Player(const std::string& name)
	: m_name(name) {}

void Player::SetName(const std::string& name) {
	m_name = name;
}

const std::string& Player::GetName() const {
	return m_name;
}

void Player::MakeChoose(std::function<std::shared_ptr<Symbol>()> method) {
	m_symbol = method();
}

const Symbol& Player::GetSymbol() const {
	if (!m_symbol) {
		throw std::runtime_error("Symbol for player wasn't created.");
	}
	return *m_symbol;
}
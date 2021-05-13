#ifndef CONSOLE_DRAWER_HPP
#define CONSOLE_DRAWER_HPP

#include <iostream>
#include "symbol.hpp"
#include "player.hpp"
#include "drawer.hpp"

class ConsoleDrawer : public Drawer {
public:

	ConsoleDrawer();

	void ShowMainScreen(
		const std::vector<std::shared_ptr<Symbol> > symbols) override;

	std::string GetPlayerName() override;

	void ShowChoose(const Player& first, const Player& second) override;

	std::shared_ptr<Symbol> PlayerChoose() override;

	void Hurray() override;

	void Loose() override;

	void Tie() override;

	bool IsContinue() override;

	void GoodByeScreen() override;

private:

	void PrintInLoop(const int num, const char symbol);

private:

	char m_border_symbol;
	size_t m_border_length;
	size_t m_indent_length;
};

#endif  // CONSOLE_DRAWER_HPP
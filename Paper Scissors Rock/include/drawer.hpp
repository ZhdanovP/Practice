#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <memory>
#include <vector>

class Drawer
{
public:

	virtual void ShowMainScreen(const std::vector<std::shared_ptr<Symbol> > symbols) = 0;

	virtual std::string GetPlayerName() = 0;

	virtual void ShowChoose(const Player&, const Player&) = 0;

	virtual std::shared_ptr<Symbol> PlayerChoose() = 0;

	virtual void Hurray() = 0;

	virtual void Loose() = 0;

	virtual void Tie() = 0;

	virtual bool IsContinue() = 0;

	virtual void GoodByeScreen() = 0;
};

#endif  // DRAWER_HPP
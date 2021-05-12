#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <memory>
#include <vector>

class Drawer
{
public:

	virtual void ShowMainScreen(const std::vector<std::shared_ptr<Symbol> > symbols) = 0;

	virtual std::string GetPlayerName() = 0;

	virtual void ShowChoose(const std::shared_ptr<Player>, const std::shared_ptr<Player>) = 0;

	virtual void PlayerChoose(std::shared_ptr<Player> player) = 0;

	virtual void Hurray() = 0;

	virtual void Loose() = 0;

	virtual void Tie() = 0;

	virtual bool IsContinue() = 0;
};

#endif  // DRAWER_HPP
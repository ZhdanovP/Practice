/*
 * Copyright (c) 2021, Pavel Zhdanov
 * All rights reserved.
 */

#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <memory>
#include <vector>

class Drawer
{
public:


	/**
	* @brief ShowMainScreen - this method shows main\greeting screen for user
	* @param std::vector<std::shared_ptr<Symbol> > collerction of allowed symbols in game
	*/
	virtual void ShowMainScreen(const std::vector<std::shared_ptr<Symbol> > symbols) = 0;

	/**
	* @brief GetPlayerName - Asks user to enter his name
	*/
	virtual std::string GetPlayerName() = 0;

	/**
	* @brief ShowChoose - shows which symbols were choosed by both players
	* @param const Player& - first player
	* @param const Player& - second player
	*/
	virtual void ShowChoose(const Player&, const Player&) = 0;

	/**
	* @brief PlayerChoose - ask player to choose symbol
	* @return std::shared_ptr<Symbol> - return choosed symbol
	*/
	virtual std::shared_ptr<Symbol> PlayerChoose() = 0;

	/**
	* @brief Hurray - say the game was finished and player 1 win
	*/
	virtual void Hurray() = 0;

	/**
	* @brief Loose - say the game was finished and player 1 loose
	*/
	virtual void Loose() = 0;

	/**
	* @brief Tie - say the game was finished with tie result
	*/
	virtual void Tie() = 0;

	/**
	* @brief IsContinue - ask player to continue / could be implemented at separate screen
	*/
	virtual bool IsContinue() = 0;

	/**
	* @brief GoodByeScreen - show GoodBye screen to player
	*/
	virtual void GoodByeScreen() = 0;
};

#endif  // DRAWER_HPP
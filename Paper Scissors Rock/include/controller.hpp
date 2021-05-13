/*
 * Copyright (c) 2021, Pavel Zhdanov
 * All rights reserved.
 */

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "player.hpp"
#include "drawer.hpp"
#include "console_drawer.hpp"

#include "paper.hpp"
#include "scissors.hpp"
#include "rock.hpp"

class Controller {
public:

	Controller(std::shared_ptr<Drawer> drawer);

	void CreatePlayers();

	void GameLoop();

private:

	std::shared_ptr<Symbol> RandomChoose();

	std::vector<std::shared_ptr<Symbol> > allowed_symbols {
		std::make_shared<Paper>(),
		std::make_shared<Scissors>(),
		std::make_shared<Rock>()
	};

	std::shared_ptr<Drawer> m_drawer;

	Player m_first_player;
	Player m_second_player;
};

#endif  // CONTROLLER_HPP
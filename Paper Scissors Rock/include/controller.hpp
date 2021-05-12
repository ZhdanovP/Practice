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

	Controller(std::shared_ptr<Drawer> drawer)
		: m_drawer(drawer)
		, m_first_player("")
		, m_second_player("") {}

	void CreatePlayers() {
		auto player_name = m_drawer->GetPlayerName();

		m_first_player.SetName(player_name);
		m_second_player.SetName("Computer");
	}

	void GameLoop() {

		m_drawer->ShowMainScreen(allowed_symbols);

		do{

	        m_first_player.MakeChoose(std::bind(&Drawer::PlayerChoose, m_drawer));
	        m_second_player.MakeChoose(std::bind(&Controller::RandomChoose, *this));

	        m_drawer->ShowChoose(m_first_player, m_second_player);

	        const Result result = 
	        	m_first_player.GetSymbol().IsBeat(m_second_player.GetSymbol());

	        if(Result::WIN == result){
	        	m_drawer->Hurray();
	        }
	        else if(Result::LOOSE == result){
	        	m_drawer->Loose();
	        }
	        else{
	        	m_drawer->Tie();
	        }

	    } while(m_drawer->IsContinue());

	    m_drawer->GoodByeScreen();
	}

private:

	std::shared_ptr<Symbol> RandomChoose() {
		int number = 0;
		srand(time(0));
		number = rand() % 100;

		if (number < 40) {
		    return std::make_shared<Rock>();
		}
		else if (number > 60) {
			return std::make_shared<Scissors>();
		}

		return std::make_shared<Paper>();
	}


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
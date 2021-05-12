#include "player.hpp"
#include "real_player.hpp"
#include "virtual_player.hpp"
#include "drawer.hpp"
#include "console_drawer.hpp"

#include "paper.hpp"
#include "scissors.hpp"
#include "rock.hpp"

void RandomChoose(std::shared_ptr<Player> player) {
	int number = 0;
	srand(time(0));
	number = rand() % 100;

	if (number < 40) {
	    player->SetSymbol(std::make_shared<Rock>());
	}
	else if (number > 60) {
		player->SetSymbol(std::make_shared<Scissors>());
	}
	else {
		player->SetSymbol(std::make_shared<Paper>());
	}
}

int main(int argc, char **argv) {

	std::vector<std::shared_ptr<Symbol> > allowed_symbols {
		std::make_shared<Paper>(),
		std::make_shared<Scissors>(),
		std::make_shared<Rock>()
	};

	std::shared_ptr<ConsoleDrawer> drawer = std::make_shared<ConsoleDrawer>();

	auto player_name = drawer->GetPlayerName();

	std::shared_ptr<Player> first_player = std::make_shared<RealPlayer>(player_name);
	std::shared_ptr<Player> second_player = std::make_shared<VirtualPlayer>("Computer");

	drawer->ShowMainScreen(allowed_symbols);

	do{

        drawer->PlayerChoose(first_player);
        RandomChoose(second_player);

        drawer->ShowChoose(first_player, second_player);

        const Result result = 
        	first_player->GetSymbol().IsBeat(second_player->GetSymbol());

        if(Result::WIN == result){
        	drawer->Hurray();
        }
        else if(Result::LOOSE == result){
        	drawer->Loose();
        }
        else{
        	drawer->Tie();
        }

    } while(drawer->IsContinue());

	

	return 0;
}
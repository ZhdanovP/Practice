#include "controller.hpp"
#include "console_drawer.hpp"

int main(int argc, char **argv) {

	Controller game(std::make_shared<ConsoleDrawer>());

	game.CreatePlayers();
	
	game.GameLoop();
	
	return 0;
}
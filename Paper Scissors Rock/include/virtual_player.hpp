#ifndef VIRTUAL_PLAYER_HPP
#define VIRTUAL_PLAYER_HPP

#include "player.hpp"

class VirtualPlayer : public Player
{
public:

	VirtualPlayer(const std::string& name)
		: Player(name) {}
};


#endif  // VIRTUAL_PLAYER_HPP
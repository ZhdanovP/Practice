#ifndef REAL_PLAYER_HPP
#define REAL_PLAYER_HPP

#include "player.hpp"

class RealPlayer : public Player
{
public:

	RealPlayer(const std::string& name)
		: Player(name) {}
};


#endif  // REAL_PLAYER_HPP
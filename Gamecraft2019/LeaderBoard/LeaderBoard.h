#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class LeaderBoard {
public:

	LeaderBoard();
	~LeaderBoard();

	void render();
	void save();
	void load();

private:
	std::vector<std::pair<const std::string, int>> m_scores;
};

#endif // !LEADERBOARD_H


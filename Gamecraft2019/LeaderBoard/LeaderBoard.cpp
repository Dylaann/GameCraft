#include "LeaderBoard.h"

LeaderBoard::LeaderBoard()
{
	load();
}

LeaderBoard::~LeaderBoard()
{
}

void LeaderBoard::render()
{
}

void LeaderBoard::save()
{
}

void LeaderBoard::load()
{
	// Load scores
	std::ifstream m_scoreFile("./ASSETS/leaderboard.json");
	json jScore = json::parse(m_scoreFile);

	std::map<std::string, int> m_jsonScoreFile = jScore;

	for (auto key : m_jsonScoreFile) {
		m_scores.push_back(std::make_pair(key.first, key.second));
	}
}

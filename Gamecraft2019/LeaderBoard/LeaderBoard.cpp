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

void LeaderBoard::save(std::string name, int score)
{
	int tracking = 0;
	json j;
	std::ofstream o("./ASSETS/LeaderBoard.json");

	m_scores.push_back(std::make_pair(name, score));
	o << "{ "<< std::endl;
	for (auto key : m_scores) {
		if (tracking != m_scores.size() - 1) {
			o << "\"" << key.first << "\"" << ": " << key.second << "," << std::endl;
		}
		else {
			o << "\"" << key.first << "\"" << ": " << key.second << std::endl;
		}
		tracking++;
	}
	o << "}" << std::endl;
	
}

void LeaderBoard::load()
{
	// Load scores
	std::ifstream m_scoreFile("./ASSETS/LeaderBoard.json");
	json jScore = json::parse(m_scoreFile);

	std::map<std::string, int> m_jsonScoreFile = jScore;

	for (auto key : m_jsonScoreFile) {
		m_scores.push_back(std::make_pair(key.first, key.second));
	}
}

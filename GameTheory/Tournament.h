#pragma once

#include "Ranking.h"
#include "IStrategy.h"

#include <vector>


class Tournament
{
	std::vector<IStrategy*> m_strategies;
	std::vector<Ranking>    m_rankings;
public:
	void PopulateStrategy();

	void Simulate();

	std::vector<Ranking> GenerateFinalRankingByPoint() const;
	std::vector<Ranking> GenerateFinalRankingByWinDrawLoss() const;
};

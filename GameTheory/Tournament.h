#pragma once

#include "Ranking.h"

#include <vector>

class Tournament
{
public:
	void PopulateStrategy();

	void Simulate();

	std::vector<Ranking> GenerateFinalRankingByPoint() const;
	std::vector<Ranking> GenerateFinalRankingByWinDrawLoss() const;
};
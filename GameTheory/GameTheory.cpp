#include "Ranking.h"
#include "Tournament.h"

#include <iostream>
#include <iomanip>

void PrintResult(const std::vector<Ranking>& ranking)
{
    std::cout << std::left
        << std::setw(20) << "Name"
        << std::right
        << std::setw(12) << "Points"
        << std::setw(10) << "Wins"
        << std::setw(10) << "Draws"
        << std::setw(10) << "Losses"
        << "\n";

    std::cout << std::string(62, '-') << "\n";

    for (const Ranking& player : ranking)
    {
        std::cout << std::left
            << std::setw(20) << player.StrategyName
            << std::right
            << std::setw(12) << player.TotalPoint
            << std::setw(10) << player.Win
            << std::setw(10) << player.Draw
            << std::setw(10) << player.Lose
            << "\n";
    }
}


int main()
{
    Tournament t;

    t.PopulateStrategy();

    t.Simulate();

    PrintResult(t.GenerateFinalRankingByPoint());
    std::cout << "\n\n";
    PrintResult(t.GenerateFinalRankingByWinDrawLoss());
}
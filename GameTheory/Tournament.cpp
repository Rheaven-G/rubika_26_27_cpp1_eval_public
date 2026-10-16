#include "Tournament.h"

#include <algorithm>
#include <iostream>
#include <ostream>

void Tournament::PopulateStrategy()
{
    m_strategies.push_back(new AlwaysCooperate("Always Cooperate"));
    m_strategies.push_back(new AlwaysBetray("Always Betray"));
    m_strategies.push_back(new TitForTat("Tit-for-tat"));
    m_strategies.push_back(new ResentfulCooperate("Resentful Cooperate"));
    m_strategies.push_back(new Fiftyfifty("Fifty-fifty"));
    m_strategies.push_back(new ReverseResentful("Reverse Resentful"));
}

void Tournament::Simulate()
{
    for (auto& strategyA : m_strategies)
    {
        Ranking rank{
            strategyA->Name,
            0,
            0,
            0,
            0};
        
        for (auto& strategyB : m_strategies)
        {
            int ptsA = 0;
            int ptsB = 0;
            for (auto i {0}; i < 50; ++i)
            {
                std::vector<Choice> decisionsA;
                std::vector<Choice> decisionsB;
                
                // Take decision
                Choice choiceA = strategyA->Decide(decisionsA, decisionsB);
                Choice choiceB = strategyB->Decide(decisionsB, decisionsA);
                // Apply decision
                decisionsA.push_back(choiceA);
                decisionsB.push_back(choiceB);
                
                if (choiceA == choiceB)
                {
                    if (choiceA == Choice::Cooperate)
                    {
                        ptsA += 3;
                        ptsB += 3;
                    } 
                    else
                    {
                        ptsA += 1;
                        ptsB += 1;
                    }
                } else
                {
                    if (choiceA == Choice::Betray) 
                        ptsA += 5;
                    else 
                        ptsB += 5;
                    
                    // We don't write choiceA == Choice::Cooperate
                    // Because if A != B and A == Cooperate,
                    // that means A lost and gained 0
                }
            } // ---- End of match
            
            rank.TotalPoint += ptsA;
            rank.Win        += ptsA > ptsB  ? 1 : 0;
            rank.Lose       += ptsA < ptsB  ? 1 : 0;
            rank.Draw       += ptsA == ptsB ? 1 : 0;
            
        } // ---- End of opponent, change
        
        m_rankings.push_back(rank);
    } // -- End of strategy, change 
}

std::vector<Ranking> Tournament::GenerateFinalRankingByPoint() const
{
    std::vector<Ranking> sortedRankings = m_rankings;
    std::sort(sortedRankings.begin(), sortedRankings.end(), [](Ranking& r1, Ranking& r2)
    {
        // Max Point
        if (r1.TotalPoint > r2.TotalPoint)
            return true;
        if (r2.TotalPoint > r1.TotalPoint)
            return false;
        
        // Max Win
        if (r1.Win > r2.Win)
            return true;
        if (r2.Win > r1.Win)
            return false;
        
        // Max Draws
        if (r1.Draw > r2.Draw)
            return true;
        if (r2.Draw > r1.Draw)
            return false;
        
        
        // Ultimately...
        return r1.Lose < r2.Lose;
    });
    
    return sortedRankings;
}
std::vector<Ranking> Tournament::GenerateFinalRankingByWinDrawLoss() const
{
    std::vector<Ranking> sortedRankings = m_rankings;
    std::sort(sortedRankings.begin(), sortedRankings.end(), [](Ranking& r1, Ranking& r2)
    {
        // Max Win
        if (r1.Win > r2.Win)
            return true;
        if (r2.Win > r1.Win)
            return false;
        
        // Max Draws
        if (r1.Draw > r2.Draw)
            return true;
        if (r2.Draw > r1.Draw)
            return false;
        
        
        // Ultimately...
        return r1.Lose < r2.Lose;
    });
    
    return sortedRankings;
}

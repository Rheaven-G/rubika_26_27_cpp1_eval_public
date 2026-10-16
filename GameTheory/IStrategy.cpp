#include "IStrategy.h"

Choice AlwaysCooperate::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    return Choice::Cooperate;
}

Choice AlwaysBetray::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    return Choice::Betray;
}

Choice TitForTat::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    // theoretically, both should fill at the same rate
    if (previousDecisions.empty() || opponentPreviousDecisions.empty()) 
        return Choice::Cooperate;
    
    // Always returns last opponent latest decision.
    return opponentPreviousDecisions.back();
}

Choice ResentfulCooperate::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    if (opponentPreviousDecisions.empty())
    { // Means we started a new match
        m_gotBetrayed = false;
        return Choice::Cooperate;
    }
    
    if (!m_gotBetrayed && previousDecisions.back() == Choice::Betray)
        m_gotBetrayed = true;
    
    return m_gotBetrayed ? Choice::Betray : Choice::Cooperate;
}

Choice Fiftyfifty::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    // theoretically, both should fill at the same rate
    if (previousDecisions.empty() || opponentPreviousDecisions.empty()) 
        return Choice::Cooperate;
    
    // Always returns last opponent latest decision.
    return previousDecisions.back() == Choice::Cooperate ? Choice::Betray : Choice::Cooperate;
}

Choice ReverseResentful::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    if (opponentPreviousDecisions.empty())
    { // Means we started a new match
        m_gotBetrayed = false;
        return Choice::Betray;
    }
    
    if (!m_gotBetrayed && previousDecisions.back() == Choice::Cooperate)
        m_gotBetrayed = true;
    
    return m_gotBetrayed ? Choice::Cooperate : Choice::Betray;
}

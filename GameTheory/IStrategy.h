#pragma once

#include "Choice.h"

#include <string>
#include <vector>

class IStrategy abstract
{
public:
	IStrategy(const std::string& name) : Name(name) {}
	~IStrategy() = default;

	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) = 0;

	std::string Name;
};

class AlwaysCooperate : public IStrategy
{
public:
	AlwaysCooperate(const std::string& name) : IStrategy(name) {}
	
	Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

class AlwaysBetray : public IStrategy
{
public:
	AlwaysBetray(const std::string& name) : IStrategy(name) {}
	
	Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

class TitForTat : public IStrategy
{
public:
	TitForTat(const std::string& name) : IStrategy(name) {}
	
	Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

class ResentfulCooperate : public IStrategy
{
	bool m_gotBetrayed { false };
public:
	
	ResentfulCooperate(const std::string& name) : IStrategy(name) {}
	
	Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

class Fiftyfifty : public IStrategy
{
public:
	Fiftyfifty(const std::string& name) : IStrategy(name) {}
	
	Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

class ReverseResentful : public IStrategy
{
	bool m_gotBetrayed { false };
public:
	ReverseResentful(const std::string& name) : IStrategy(name) {}
	
	Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

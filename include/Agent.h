#pragma once

#include <vector>
#include "Simulation.h"
#include "SelectionPolicy.h"
#include "Offer.h"

class SelectionPolicy;
class Simulation;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(const Agent& toClone, int newId, int partyId);
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    int getCoalitionId() const;

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mCoalitionId;
};

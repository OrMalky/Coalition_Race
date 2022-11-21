#pragma once

#include <vector>
#include "SelectionPolicy.h"
#include "Offer.h"

class SelectionPolicy;
class Simulation;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(const Agent& toClone, int newId, int partyId);
    Agent(const Agent& toClone);
    Agent& operator=(const Agent& other);
    ~Agent();
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    int getCoalitionId() const;
    SelectionPolicy* getSelectionPolicy() const;

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mCoalitionId;
};

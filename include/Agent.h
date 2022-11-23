#pragma once

#include <vector>
#include "SelectionPolicy.h"
#include "Offer.h"

class SelectionPolicy;
class Simulation;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);  //Constructor
    Agent(const Agent& toClone, int newId, int partyId);    //Constructor [for coalition]
    Agent(const Agent& toClone);    //Copy Constructor
    Agent& operator=(const Agent& other);   //Assignment operator
    ~Agent();   //Destructor

    /*  Rule of 5 [not actually needed]
    Agent(Agent&& a);   //Move Constructor
    Agent& operator=(Agent&& other);    //Move Assignment Operator
    */

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

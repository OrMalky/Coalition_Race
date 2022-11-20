#include "../include/Agent.h"
#include "../include/Simulation.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) :
    mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalitionId(agentId)
{
    // You can change the implementation of the constructor, but not the signature!
}

Agent::Agent(const Agent& toClone, int newId, int partyId) :
    mAgentId(newId), mPartyId(partyId), mSelectionPolicy(toClone.mSelectionPolicy), mCoalitionId(toClone.mCoalitionId)
{

}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

int Agent::getCoalitionId() const
{
    return mCoalitionId;
}

void Agent::step(Simulation &sim)
{
    int toOffer = (*mSelectionPolicy).select(sim, *this);
    if(toOffer > -1)
    {
        Offer newOffer(mCoalitionId);
        sim.getParty(toOffer).takeOffer(newOffer);
    }
}

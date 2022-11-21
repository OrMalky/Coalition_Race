#include "../include/Agent.h"
#include "../include/Simulation.h"
#include <iostream>

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) :
    mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalitionId(agentId)
{
    // You can change the implementation of the constructor, but not the signature!
    std::cout << "agent created " << mAgentId  << " " << this << " SP: " << mSelectionPolicy << " cast: "
                << reinterpret_cast<unsigned long*>(mSelectionPolicy)[0] << std::endl;
}

Agent::Agent(const Agent& toClone, int newId, int partyId) :
    mAgentId(newId), mPartyId(partyId), mSelectionPolicy(toClone.mSelectionPolicy), mCoalitionId(toClone.mCoalitionId)
{
    std::cout << "agent created " << mAgentId  << " " << this << std::endl;
}

Agent::Agent(const Agent& toClone) : mAgentId(toClone.getId()), mPartyId(toClone.getPartyId()), mSelectionPolicy() ,mCoalitionId(toClone.getCoalitionId())
{
    mSelectionPolicy = toClone.getSelectionPolicy();
    std::cout << "agent copied " << mAgentId  << " " << this << " SP: " << mSelectionPolicy << " cast: "
                << reinterpret_cast<unsigned long*>(mSelectionPolicy)[0] << std::endl;
}

Agent& Agent::operator=(const Agent& other)
{
    mAgentId = other.getId();
    mPartyId = other.getPartyId();
    mSelectionPolicy = nullptr;
    mCoalitionId = other.getCoalitionId();
    return *this;
}

Agent::~Agent()
{
    std::cout << "agent deleted " << mAgentId  << " " << this <<" cast: " << reinterpret_cast<unsigned long*>(mSelectionPolicy)[0] << std::endl;
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

SelectionPolicy* Agent::getSelectionPolicy() const
{
    return mSelectionPolicy;
}

void Agent::step(Simulation &sim)
{
    std::cout << "agent: " << this << " sp: " << mSelectionPolicy << " cast: " << reinterpret_cast<unsigned long*>(mSelectionPolicy)[0] << std::endl;
    int toOffer = (*mSelectionPolicy).select(sim, *this);
    std::cout << "Used selection policy ok" << std::endl;
    if(toOffer > -1)
    {
        Offer newOffer(mCoalitionId);
        std::cout << "offer created ok" << std::endl;
        sim.getParty(toOffer).takeOffer(newOffer);
        std::cout << "offer passed ok" << std::endl;
    }
}



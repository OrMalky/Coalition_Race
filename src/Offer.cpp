#include "../include/Offer.h"

Offer::Offer(int coalitionId, int agentId) : mCoalitionId(coalitionId), mAgentId(agentId) {}

int Offer::getCoalitionId() const
{
    return mCoalitionId;
}

int Offer::getAgentId() const
{
    return mAgentId;
}
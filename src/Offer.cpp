#include "../include/Offer.h"

Offer::Offer(int coalitionId) : mCoalitionId(coalitionId) {}

int Offer::getCoalitionId() const
{
    return mCoalitionId;
}
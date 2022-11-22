#include "../include/Coalition.h"
#include <iostream>

Coalition::Coalition(int id) : mId(id), mTotalMandates(0), mOfferedParties(), mParties()
{

}

int Coalition::getTotalMandates() const
{
    return mTotalMandates;
}

void Coalition::addParty(Party* party)
{
    mParties.push_back(party);
    mTotalMandates += (*party).getMandates();
}

bool Coalition::checkOfferedParties(int partyId)
{
    for(int p : mOfferedParties)
    {
        if(p == partyId)
            return false;
    }
    return true;
}

void Coalition::addPartyOffer(int partyId)
{
    mOfferedParties.push_back(partyId);
}

const vector<Party*> Coalition::getParties() const
{
    return mParties;
}

int Coalition::getId() const
{
    return mId;
}
#include "../include/Coalition.h"

int Coalition::getTotalMandates() const
{
    return mTotalMandates;
}

void Coalition::addParty(Party& party)
{
    mParties.push_back(party);
    mTotalMandates += party.getMandates();
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

void Coalition::addPartyOffer(Party& party)
{
    mOfferedParties.push_back(party);
}

vector<Party&> Coalition::getParties()
{
    return mParties;
}

int Coalition::getId() const
{
    return mId;
}
#include "../include/Coalition.h"

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
    for(Party* p : mOfferedParties)
    {
        if(p->getGetId() == partyId)
            return false;
    }
    return true;
}

void Coalition::addPartyOffer(Party* party)
{
    mOfferedParties.push_back(party);
}

const vector<Party*> Coalition::getParties() const
{
    return mParties;
}

int Coalition::getId() const
{
    return mId;
}
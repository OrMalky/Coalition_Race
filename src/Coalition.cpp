#include "../include/Coalition.h"
#include <iostream>

Coalition::Coalition(int id) : mId(id), mTotalMandates(0), mOfferedParties(), mParties()
{

}

Coalition::Coalition(const Coalition& c) : mId(c.getId()), mTotalMandates(c.getTotalMandates()), mOfferedParties(c.getOfferedParties()), mParties(c.getParties())
{
    
}


Coalition& Coalition::operator=(const Coalition& other)
{
    mId = other.getId();
    mParties = other.getParties();
    mOfferedParties = other.getOfferedParties();
    mTotalMandates = other.getTotalMandates();
    return *this;
}

/*
Coalition::Coalition(Coalition&& c) : mId(c.getId()), mTotalMandates(c.getTotalMandates()), mOfferedParties(c.getOfferedParties()), mParties(c.getParties())
{
    c = Coalition(-1);
}

Coalition& Coalition::operator=(Coalition&& other)
{
    if(this != &other)
    {
        mId = other.getId();
        mTotalMandates = other.getTotalMandates();
        mOfferedParties = other.getOfferedParties();
        mParties = other.getParties();
        other = Coalition(-1);
    }
    return *this;
}
*/

const vector<int> Coalition::getOfferedParties() const
{
    return mOfferedParties;
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
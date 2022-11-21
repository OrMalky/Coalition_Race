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
    std::cout << mParties.size() << std::endl;
    for(int unsigned p=0; p < mParties.size(); p++)
    {
        std::cout << "db" << p << std::endl;
        if(mParties[p]->getGetId() == partyId)
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
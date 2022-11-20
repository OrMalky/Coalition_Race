#include "../include/Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), timer(3)
{
    // You can change the implementation of the constructor, but not the signature!
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

int Party::getGetId() const
{
    return mId;
}

void Party::joinCoalition(Simulation& sim)
{
    const Offer& toJoin = mJoinPolicy->join(sim, offers);
    sim.getCoalition(toJoin.getCoalitionId()).addParty(*this);
    sim.cloneAgent(toJoin.getCoalitionId(), mId);
}

void Party::takeOffer(Offer offer)
{
    offers.push_back(offer);
    if(mState == Waiting)
        mState = CollectingOffers;
}

void Party::step(Simulation &s)
{
    switch (mState)
    {
    case Waiting:
        break;

    case CollectingOffers:
        timer -= 1;
        if(timer == 0)
            joinCoalition(s);
        break;
    
    case Joined:
        break;
    
    default:
        throw "wat";
        break;
    }
}

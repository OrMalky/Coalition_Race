#include "../include/Party.h"
#include "../include/Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), mTimer(3), mOffers()
{
    // You can change the implementation of the constructor, but not the signature!
}

Party::Party(const Party& toClone) : mId(toClone.getGetId()), mName(toClone.getName()), mMandates(toClone.getMandates()), mJoinPolicy(toClone.getJoinPolicy()), mState(Waiting), mTimer(3), mOffers()
{

}

Party& Party::operator=(const Party& other)
{
    mId = other.getGetId();
    mName = other.getName();
    mMandates = other.getMandates();
    mJoinPolicy = other.getJoinPolicy();
    mTimer = 3;
    mState = Waiting;
    return *this;
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
    const Offer& toJoin = mJoinPolicy->join(sim, mOffers);
    sim.getCoalition(toJoin.getCoalitionId()).addParty(this);
    sim.cloneAgent(toJoin.getCoalitionId(), mId);
}

void Party::takeOffer(Offer offer)
{
    mOffers.push_back(offer);
    if(mState == Waiting)
        mState = CollectingOffers;
}

JoinPolicy* Party::getJoinPolicy() const
{
    return mJoinPolicy;
}

void Party::step(Simulation &s)
{
    switch (mState)
    {
    case Waiting:
        break;

    case CollectingOffers:
        mTimer -= 1;
        if(mTimer == 0)
            joinCoalition(s);
        break;
    
    case Joined:
        break;
    
    default:
        throw "wat";
        break;
    }
}

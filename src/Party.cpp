#include "../include/Party.h"
#include "../include/Simulation.h"
#include <iostream>

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates),
    mJoinPolicy(jp), mState(Waiting), mTimer(3), mOffers()
{
    std::cout << "party created " << mId  << " " << this << " JP: " << mJoinPolicy << std::endl;
}

Party::Party(const Party& toClone) : mId(toClone.getGetId()), mName(toClone.getName()),
    mMandates(toClone.getMandates()), mJoinPolicy(toClone.getJoinPolicy()->clone()), mState(Waiting), mTimer(3), mOffers()
{
    std::cout << "party copied " << mId  << " " << this << " JP: " << mJoinPolicy << std::endl;
}

Party& Party::operator=(const Party& other)
{
    mId = other.getGetId();
    mName = other.getName();
    mMandates = other.getMandates();
    mJoinPolicy = other.getJoinPolicy();
    mTimer = 3;
    mState = other.getState();
    return *this;
}

Party::~Party()
{
    std::cout << "deleting jp in: " << mJoinPolicy << std::endl;
    delete mJoinPolicy;
    std::cout << "deleted " << std::endl;
}

Party::Party(Party&& p) : mId(p.getGetId()), mName(p.getName()), mMandates(p.getMandates()), mJoinPolicy(p.getJoinPolicy()), mState(p.getState()), mTimer(3), mOffers()
{
    if(this != &p)
        p.nullify();
}

Party& Party::operator=(Party&& p)
{
    if(this != &p)
    {
        mId = p.getGetId();
        mName = p.getName();
        mMandates = p.getMandates();
        mJoinPolicy = p.getJoinPolicy();
        mState = Waiting;
        mTimer = 3;
        mOffers = vector<Offer>();
        p.nullify();
    }
    return *this;
}

void Party::nullify()
{
    mId = -1;
    mName = "";
    mMandates = 0;
    mJoinPolicy = nullptr;
    mOffers.clear();
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
    setState(Joined);
    sim.cloneAgent(toJoin.getCoalitionId(), mId);
    std::cout << "joined coalition: " << toJoin.getCoalitionId() << std::endl;
}

void Party::takeOffer(Offer offer, Coalition& c)
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

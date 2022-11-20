#pragma once
#include <string>
#include <vector>
#include "Offer.h"
#include "Simulation.h"
#include "JoinPolicy.h"

using std::string;
using std::vector;

class Simulation;
class JoinPolicy;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 
    Party(const Party&);
    Party& operator=(const Party&);

    State getState() const;
    void setState(State state);
    int getMandates() const;
    int getGetId() const;
    void step(Simulation &s);
    const string &getName() const;
    void takeOffer(Offer offer);

private:
    void joinCoalition(Simulation& sim);
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    int timer;
    State mState;
    vector<Offer> offers;
};

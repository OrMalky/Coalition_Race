#pragma once
#include <string>
#include <vector>
#include "Offer.h"
#include "JoinPolicy.h"
#include "Coalition.h"

using std::string;
using std::vector;

class Simulation;
class JoinPolicy;
class Coalition;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); //Constructor
    Party(const Party& toClone);    //Copy Constructor
    Party& operator=(const Party& other);   //Copy Assignemtn Operator
    ~Party();   //Destructor

    //Rule of 5 [not actually needed]
    Party(Party&& p);   //Move Constructor
    Party& operator=(Party&& p);    //Move Assignment Operator
    

    State getState() const;
    void setState(State state);
    int getMandates() const;
    int getGetId() const;
    void step(Simulation &s);
    const string &getName() const;
    void takeOffer(Offer offer, Coalition& c);
    JoinPolicy* getJoinPolicy() const;
    void nullify();

private:
    void joinCoalition(Simulation& sim);
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int mTimer;
    vector<Offer> mOffers;
};

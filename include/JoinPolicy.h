#pragma once

#include <vector>
#include "Offer.h"

class Simulation;

using std::vector;

class JoinPolicy
{
    public:
        virtual Offer join(Simulation& sim, const vector<Offer>& offers) = 0;
        virtual ~JoinPolicy() = default;
};

class MandatesJoinPolicy : public JoinPolicy
{
    public:
        MandatesJoinPolicy(){};
        Offer join(Simulation& sim, const vector<Offer>& offers);
        ~MandatesJoinPolicy() = default;
};

class LastOfferJoinPolicy : public JoinPolicy
{
    public:
        LastOfferJoinPolicy(){};
        Offer join(Simulation& sim, const vector<Offer>& offers);
        ~LastOfferJoinPolicy() = default;
};
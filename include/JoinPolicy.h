#pragma once

#include <vector>
#include "Simulation.h"
#include "Offer.h"

class Simulation;

using std::vector;

class JoinPolicy
{
    public:
        virtual Offer join(Simulation& sim, const vector<Offer>& offers) = 0;
};

class MandatesJoinPolicy : public JoinPolicy
{
    public:
        virtual Offer join(Simulation& sim, const vector<Offer>& offers);
};

class LastOfferJoinPolicy : public JoinPolicy
{
    public:
        virtual Offer join(Simulation& sim, const vector<Offer>& offers);
};
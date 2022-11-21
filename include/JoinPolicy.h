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
        Offer join(Simulation& sim, const vector<Offer>& offers);
};

class LastOfferJoinPolicy : public JoinPolicy
{
    public:
        Offer join(Simulation& sim, const vector<Offer>& offers);
};
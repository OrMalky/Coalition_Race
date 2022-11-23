#pragma once

#include <vector>
#include "Offer.h"

class Simulation;

using std::vector;

class JoinPolicy
{
    public:
        virtual Offer join(Simulation& sim, const vector<Offer>& offers) = 0;
        virtual JoinPolicy* clone() = 0;
        virtual ~JoinPolicy() = default;
};

class MandatesJoinPolicy : public JoinPolicy
{
    public:
        MandatesJoinPolicy();
        virtual MandatesJoinPolicy* clone();
        virtual Offer join(Simulation& sim, const vector<Offer>& offers);
        virtual ~MandatesJoinPolicy() = default;
};

class LastOfferJoinPolicy : public JoinPolicy
{
    public:
        LastOfferJoinPolicy();
        virtual LastOfferJoinPolicy* clone();
        virtual Offer join(Simulation& sim, const vector<Offer>& offers);
        virtual ~LastOfferJoinPolicy() = default;
};
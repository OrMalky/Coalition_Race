#include "../include/JoinPolicy.h"
#include "../include/Simulation.h"

MandatesJoinPolicy::MandatesJoinPolicy(){};

Offer MandatesJoinPolicy::join(Simulation& sim, const vector<Offer>& offers)
{
    int mostMandates = -1;
    Offer* bestOffer = nullptr;
    for (Offer o : offers)
    {
        int currentMandates = sim.getCoalition(o.getCoalitionId()).getTotalMandates();
        if(mostMandates < currentMandates)
        {
            mostMandates = currentMandates;
            bestOffer = &o;
        }
    }
    return *bestOffer;
}

LastOfferJoinPolicy::LastOfferJoinPolicy(){};

Offer LastOfferJoinPolicy::join(Simulation& sim, const vector<Offer>& offers)
{
    return offers.back();
}
#include "../include/JoinPolicy.h"
#include "../include/Simulation.h"

MandatesJoinPolicy::MandatesJoinPolicy(){std::cout << "Mandates JP created " << this << std::endl;};
MandatesJoinPolicy* MandatesJoinPolicy::clone()
{
    return new MandatesJoinPolicy;
} 

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

LastOfferJoinPolicy::LastOfferJoinPolicy(){std::cout << "Last JP created " << this << std::endl;};
LastOfferJoinPolicy* LastOfferJoinPolicy::clone()
{
    return new LastOfferJoinPolicy;
}

Offer LastOfferJoinPolicy::join(Simulation& sim, const vector<Offer>& offers)
{
    return offers.back();
}
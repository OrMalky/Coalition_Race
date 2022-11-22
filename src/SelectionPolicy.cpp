#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"
#include <iostream>

MandatesSelectionPolicy::MandatesSelectionPolicy(){std::cout << "Mandate SP created " << this << std::endl;}

MandatesSelectionPolicy* MandatesSelectionPolicy::clone()
{
    return new MandatesSelectionPolicy;
}

int MandatesSelectionPolicy::select(Simulation& sim, const Agent& agent)
{
    Graph& g = sim.getGraph();
    int mostMandates = 0;
    int bestParty = -1;
    for(int i=0; i<g.getNumVertices(); i++)
    {
        int currentMandates = g.getMandates(i);
        if(sim.getParty(i).getState() != Joined && i != agent.getPartyId() && !sim.getCoalition(agent.getCoalitionId()).checkOfferedParties(i))
        {
            if(currentMandates > mostMandates)
            {
                mostMandates = currentMandates;
                bestParty = i;
            }
        }
    }
    return bestParty;
}

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(){std::cout << "Edge SP created " << this << std::endl;};

EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone()
{
    return new EdgeWeightSelectionPolicy;
}

int EdgeWeightSelectionPolicy::select(Simulation& sim, const Agent& agent)
{
    Graph& g = sim.getGraph();
    int bestWeight = 0;
    int bestParty = -1;
    for(int i=0; i<g.getNumVertices(); i++)
    {
        int currentWeight = g.getEdgeWeight(agent.getPartyId(), i);
        std::cout << "party: " << i << " weight: " << currentWeight << " offered: " << !sim.getCoalition(agent.getCoalitionId()).checkOfferedParties(i) << std::endl;
        if(currentWeight > bestWeight && sim.getParty(i).getState() != Joined && sim.getCoalition(agent.getCoalitionId()).checkOfferedParties(i))
        {
            bestWeight = currentWeight;
            bestParty = i;
        }
    }
    std::cout << "selected: " << bestParty << std::endl;
    return bestParty;
}
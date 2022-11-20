#include "../include/SelectionPolicy.h"

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

int EdgeWeightSelectionPolicy::select(Simulation& sim, const Agent& agent)
{
    Graph& g = sim.getGraph();
    int bestWeight = 0;
    int bestParty = -1;
    for(int i=0; i<g.getNumVertices(); i++)
    {
        int currentWeight = g.getEdgeWeight(agent.getPartyId(), i);
        if(currentWeight > bestWeight && i != agent.getPartyId() && !sim.getCoalition(agent.getCoalitionId()).checkOfferedParties(i))
        {
            bestWeight = currentWeight;
            bestParty = i;
        }
    }
    return bestParty;
}
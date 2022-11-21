#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) , mCoalitions()
{
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
    //Parties Step
    for(Party p : mGraph.getParties())
    {
        p.step(*this);
    }

    //Agents Step
    for(Agent a : mAgents)
    {
        a.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    //Is there a Coalition with 61 mandates or more?
    for(Coalition c : mCoalitions)
    {
        if(c.getTotalMandates() >= 61)
            return true;
    }

    //Are all parties already Joined?
    for(int i=0; i<mGraph.getNumVertices(); i++)
    {
        if(mGraph.getParty(i).getState() != Joined)
            return false;
    }
    return true;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

Party& Simulation::getParty(int partyId)
{
    return mGraph.getParty(partyId);
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

Graph &Simulation::getGraph()
{
    return mGraph;
}

Coalition& Simulation::getCoalition(int id)
{
    return mCoalitions[id];
}

void Simulation::cloneAgent(int agentId, int partyId)
{
    Agent newAgent(mAgents[agentId], mAgents.size(), partyId);
    mAgents.push_back(newAgent);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> partiesByCoalition;
    for(Coalition c : mCoalitions)
    {
        vector<int> coalition;
        for(Party* p : c.getParties())
        {
            coalition.push_back((*p).getGetId());
        }
        partiesByCoalition.push_back(coalition);
    }
    return partiesByCoalition;
}

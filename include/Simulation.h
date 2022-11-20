#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"
#include "Party.h"
#include "Coalition.h"

class Coalition;
class Agent;
class Party;
class Coalition;

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);
    void step();
    bool shouldTerminate() const;
    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    Party& getParty(int partyId);
    Graph& getGraph();
    Coalition& getCoalition(int id);
    void cloneAgent(int agentId, int partyId);
    const vector<vector<int>> getPartiesByCoalitions() const;

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> mCoalitions;
};

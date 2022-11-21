#pragma once

#include "Graph.h"
#include "Party.h"
#include "Agent.h"

class Agent;
class Simulation;

class SelectionPolicy
{
    public:
        virtual int select(Simulation& sim, const Agent& agent) = 0;
        virtual ~SelectionPolicy() = default;
};

class MandatesSelectionPolicy: public SelectionPolicy
{
    public:
        MandatesSelectionPolicy(){};
        int select(Simulation& sim, const Agent& agent);
        virtual ~MandatesSelectionPolicy() = default;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{
    public:
        EdgeWeightSelectionPolicy(){};
        int select(Simulation& sim, const Agent& agent);
        virtual ~EdgeWeightSelectionPolicy() = default;
};
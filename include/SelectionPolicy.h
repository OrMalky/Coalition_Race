#pragma once
#include "Simulation.h"
#include "Agent.h"

class Agent;
class Simulation;

class SelectionPolicy
{
    public:
        virtual int select(Simulation& sim, const Agent& agent);
};

class MandatesSelectionPolicy: public SelectionPolicy
{
    public:
        int select(Simulation& sim, const Agent& agent);
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{
    public:
        int select(Simulation& sim, const Agent& agent);
};
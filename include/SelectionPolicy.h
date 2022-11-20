#pragma once
#include "Simulation.h"
#include "Agent.h"

class Agent;
class Simulation;

class SelectionPolicy
{
    public:
        virtual int select(Simulation& sim, const Agent& agent) = 0;
};

class MandatesSelectionPolicy: public SelectionPolicy
{
    public:
        virtual int select(Simulation& sim, const Agent& agent) = 0;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{
    public:
        virtual int select(Simulation& sim, const Agent& agent) = 0;
};
#pragma once
#include "Agent.h"

class Agent;
class Simulation;

class SelectionPolicy
{
    public:
        virtual int select(Simulation& sim, const Agent& agent);
        virtual ~SelectionPolicy() = default;
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
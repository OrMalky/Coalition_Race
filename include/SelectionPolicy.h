#pragma once

#include <iostream>
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
        MandatesSelectionPolicy(){std::cout << "SP created " << this << std::endl;};
        virtual int select(Simulation& sim, const Agent& agent);
        virtual ~MandatesSelectionPolicy(){std::cout << "SP destroyed " << this << std::endl;};
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{
    public:
        EdgeWeightSelectionPolicy(){std::cout << "SP created " << this << std::endl;};
        virtual int select(Simulation& sim, const Agent& agent);
        virtual ~EdgeWeightSelectionPolicy(){std::cout << "SP destroyed " << this << std::endl;};
};
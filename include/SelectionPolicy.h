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
        virtual SelectionPolicy* clone() = 0;
        virtual ~SelectionPolicy() = default;
};

class MandatesSelectionPolicy: public SelectionPolicy
{
    public:
        MandatesSelectionPolicy();
        //MandatesSelectionPolicy(const MandatesSelectionPolicy& toClone);
        virtual MandatesSelectionPolicy* clone();
        virtual int select(Simulation& sim, const Agent& agent);
        virtual ~MandatesSelectionPolicy() = default;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{
    public:
        EdgeWeightSelectionPolicy();
        //EdgeWeightSelectionPolicy(const EdgeWeightSelectionPolicy& toClone);
        virtual EdgeWeightSelectionPolicy* clone();
        virtual int select(Simulation& sim, const Agent& agent);
        virtual ~EdgeWeightSelectionPolicy() = default;
};
# Coalition Race (SPL1)

## Project Goals
* Learn and practice memory managemnt in C++
* Hands on experience with Linux OS and WSL, and compiling for Linux using makefile
* Practice debugging and finding memory leaks
* Experience working with Valgrind to find memory leaks
* Practice proper implemantation of the 'Rule of 5' in C++

## Table of Contents
* [Prologue](#prologue)
* [The Simulation](#the-simulation)
* [How To Run](#how-to-run)
* [Use Example](#use-example)
* [How It Works](#how-it-works)
* [About](#about)

## Prologue
In a faraway democracy, SPLand, there is a political crisis, they can't form a government in
years. After 5 elections, the SPLand president decided to change the method of forming a coalition by
letting multiple "agents" from different parties try their best to create a 61 coalition as fast as
possible.
This program simulates the "Coalition Race" and report the first coalition formed (or failure).

## The Simulation
The simulation beggins with different parties, each with it's own agent, offer policy, join policy and number of mandates out of the 120 in total.
Parties can either be connected if they are somewhat simillar, then having simillarity score, or not connected if they are not simillar at all.

### In each iteration of the simulation:
  1. Each party can offer one other connected party to join it to form a coalition. Which party will be chosen is 
  based on the party's specific offer policy. After being offered it's first offer, a party changes it's state and now has to accept one of   it's offers in
  exactly 3 itterations.
  2. Each party can accept one of it's coalition offers, based on it's specific join policy, if 3 itterations have passed since it's          first offer. After joining
  a coalition the party's state changes again. From this moment on this party will try to recruit for it's coalition and will not recieve     any more offers.

### Offer and Join Policies:
As mentioned, each party has an offer and a join policy.  

**Join Policies:**
  * Most Mandates - Accept the offer of the party with the most mandates.
  * Most Recent - Accept the most recent offer.

**Offer Policies:**
  * Most Mandates - Offer a coalition to the connected party with the most mandates (that was not already offered).
  * Most Simillar - Offer a coalition to the conneceted party with the highest similarity score.

## How To Run
**Running**  
The program will recieve a single command line argument, a path to a JSON file represnting the starting arrangment:
```
bin/cRace <input file>
```
**Visualization**  
The program will create a .out file containing the entire simulation (as JSON).
Visualization.py can be used to visualize the simulation based on this file.
To see the visualization, run it with a signle command line argument, a path to the .out file.
```
python3 visualization.py <output file>
```

## Use Example
For convinience, there is a folder with ready to test JSON files, [tests](tests).
This folder contains a few tests, for each the following file:
  1. **x.json** - the test file, represnting the initial simulation state.
  2. **x.out** - the outputed solution file from the simulation, can be visualized using visualization.py.
  3. **x_sol.out** - a hand made solution for reference. can be visualized using visualization.py.
For example, to run the 01 simulation we will execute:
```
bin/cRace tests/01.json
```
This will output a new (overwrite) file:
> tests/01.out

We can now visualize this with:
```
python3 visualization.py tests/01.out
```
This will open up a visualization of this simulation.
Finally we can easily compare this to the reference solution by visualazing it too:
```
python3 visualization.py tests/01_sol.out
```
Or by using Linux **diff** command to check the difference between the two files:
```
$diff tests/01.out 01_sol.out
```

## How It Works
The simulation is presented as a graph. Parties are vertex, connections are weighted edges. When a party joins a coalition it's agent is deleted and replaced with the coalition's agent (which is the agent of the original party that formed this coalition).

## About
This program was written in C++ and compiled for Linux.

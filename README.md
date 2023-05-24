# SPL1

**The Simulation**
In a faraway democracy, SPLand, there is a political crisis, they can't form a government in
years. After 5 elections, the SPLand president decided to change the method of forming a coalition by
letting multiple "agents" from different parties try their best to create a 61 coalition as fast as
possible.
This C++ program simulates the "Coalition Race" and report the first coalition formed (or failure).

The simulation beggins with different parties, each with it's own agent, offer policy, join policy and number of mandates out of 120 total.
Parties can either be connected if they are somewhat simillar, then having simillarity score, or not connected if they are not simillar at all.

In each iteration of the simulation:
1) Each party can offer one other connected party to join it to form a coalition. Which party will be chosen is 
based on the party's specific offer policy. After being offered it's first offer, a party changes it's state and now has to accept one of it's offers in
exactly 3 itterations.
2) Each party can accept one of it's coalition offers, based on it's specific join policy, if 3 itterations have passed since it's first offer. After joining
a coalition the party's state changes again. From this moment on this party will try to recruit for it's coalition and will not recieve any more offers.

If one coalition has 61 mandates or more, it has won. Otherwise, if no more coalitions can be formed, the coalition with most mandates win.

Offer policy can be either most mandate or strongset connection.
Join policy can be either most mandate or latest offer.

**How It Works**
The simulation is presented as a graph. Parties are vertex, connections are weighted edges. When a party joins a coalition it's agent is deleted and
replaced with the coalitions agent.

The program will recieve a path to a JSON file for the starting arrangment as a command line argument.
The program will return a .out result file containing the entire simulation (as JSON).
Visualization.py can be used to visualize a simulation, running it with the .out file as its command line argument.

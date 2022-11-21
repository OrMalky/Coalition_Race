#include <iostream>
#include <iomanip>
#include "../include/Parser.h"
#include "../include/Simulation.h"

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    cout << "Starting up" << endl;
    if (argc != 2)
    {
        cout << "usage: " << argv[0] << " <config_path>" << endl;
        return -1;
    }

    // read simulation from config file
    cout << "Reading from config file" << endl;
    const string config_path = argv[1];
    Simulation simulation = Parser::readSimulation(argv[1]);

    // run simulation and store json state after each iteration
    cout << "Running simulation" << endl;
    int itr = 1;
    vector<json> outPerIter = {Parser::makeJson(simulation)};
    while (!simulation.shouldTerminate())
    {
        cout << "Iteration: " << itr << endl;
        simulation.step();
        cout << "Simulation step successeful. ";
        outPerIter.push_back(Parser::makeJson(simulation));
        cout << "Output to parser successful." << endl;
        itr++;
    }

    // writing the outputs list to a file
    cout << "Writing to output file" << endl;
    const string output_path = config_path.substr(0, config_path.find_last_of('.')) + ".out";
    std::ofstream outputFile(output_path);
    outputFile << std::setw(4) << json(outPerIter) << endl;

    return 0;
}
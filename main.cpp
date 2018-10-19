#include <iostream>
#include "netsim.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    NetSim *sim = new NetSim();
    sim->runSim();
    return 0;
}

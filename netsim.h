#ifndef NETSIM_H
#define NETSIM_H


class NetSim
{
public:
    NetSim();
    void runSim();
    int chooseSim();
    char CRCSim();

private:
    int code;
};

#endif // NETSIM_H

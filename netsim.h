#ifndef NETSIM_H
#define NETSIM_H


class NetSim
{
public:
    NetSim();
    void runSim();
    int chooseSim();
    void CRCSim();

private:
    int code;
    const static int gSize=32, mSize=64, xxSize=128;
    bool g[gSize], m[mSize], tx[xxSize], rx[xxSize];
    int n;

    void booldump(bool *array, int size, int op=0);
    int boolsave(bool* array, int size);
    void boolls(bool* array, int size); //left shift
    void boolrs(bool* array, int size); //right shift
    void boolreset(bool* array, int size); // fill with zero

};

#endif // NETSIM_H

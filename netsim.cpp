#include <iostream>
#include <conio.h>
#include <string.h>
#include "netsim.h"

using namespace std;

NetSim::NetSim()
{
    code=-1;
}

void NetSim::runSim()
{
    cout << "Running simulation ..." << endl;
    while(code!=0){
        if(code<0)
            code=(char)chooseSim();
        switch(code){
        case 1:
            CRCSim();
            break;
        default:
            cout << "this feautur will add later" << endl;
            code=-1;
        }
    }
    cout << "simulation done" << endl;
}

int NetSim::chooseSim()
{
    int ans=0;

    while(ans<1 || ans>4){
        cout << "Select what part do you wanna simulate:" << endl;
        cout << "1) CRC" << endl;
        cout << "2) checksum" << endl;
        cout << "3) matrix parity" << endl;
        cout << "4) parity" << endl;

        ans=0;
        int ch=0;
        while(ch!='\r' && ch!='\n'){
            ch=getch();
            if(ch>='0'&&ch<='9'){
                ch-='0';
                ans=(ans*10)+ch;
            }
        }
    }
//    code = ans;
    return ans;
}

void NetSim::CRCSim()
{
    cout << "running CRC simulation ..." << endl;

    code = -1;
}

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
        case 0:
            exit(0);
            break;
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
    int ans=-1;

    while(ans<0 || ans>4){
        cout << "Select what part do you wanna simulate:" << endl;
        cout << "0) Exit" << endl;
        cout << "1) CRC" << endl;
        cout << "2) checksum" << endl;
        cout << "3) matrix parity" << endl;
        cout << "4) parity" << endl;

        ans=0;
        int ch=0;
        while(ch!='\r' && ch!='\n'){
            ch=getch();
            if(ch>='0'&&ch<='9'){
                cout << (char)ch;
                ch-='0';
                ans=(ans*10)+ch;
            }
        }
        cout << endl;
    }
    code = ans;
    return ans;
}

void NetSim::CRCSim()
{
    boolreset(g,gSize);
    boolreset(m,mSize);
    boolreset(tx,xxSize);
    boolreset(rx,xxSize);
    cout << "running CRC simulation ..." << endl;
    cout << "input Generator function (G) in bin format like 11001 for x4+x3+1:\t";
    n=boolsave(g,gSize);
    cout << endl;
    cout << "input your specified message in bin format:\t";
    boolsave(m,mSize);
    cout << endl;
    //Compute here
    for(int i=0; i<mSize; i++){
        tx[i+(xxSize-mSize)] = m[i];
    }
    bool fcs[n-1];
    for(int i=0; i<n-1; i++){
        boolls(tx,xxSize);
    }
    int i=0;
    for(i=0; i<xxSize; i++){
        if(tx[i] != 0)
            break;
    }


    //noise here
    cout << "We transmitte final messgae (shown below) and lets make some noise here." << endl;
    cout << "                             \t";
    booldump(tx,xxSize);
    cout << endl;
    cout << "what do you expect to recive?\t";
    boolsave(rx,xxSize);
    cout << endl;

    //Check here




    code = -1;
}

void NetSim::booldump(bool *array, int size)
{
    int i=0;
    for(; i<size && array[i] == 0; i++);
    for(; i<size; i++){
        cout << (char)(array[i] + '0');
    }
}

int NetSim::boolsave(bool *array, int size)
{
    boolreset(array,size);

    int ch=0, i=0;
    while(ch!='\r' && ch!='\n' && i<size){
        ch=getch();
        if(ch>='0'&&ch<='1'){
            i++;
            boolls(array,size);
            array[size-1] = ch-'0';
            cout << (char)ch;
        }else if (ch == 8 && i>0){
            i--;
            boolrs(array,size);
            cout << (char)8 << ' ' << (char)8;
        }
    }
    return i;
}

void NetSim::boolls(bool *array, int size)
{
    for(int i=1; i<size; i++){
        array[i-1]=array[i];
    }
    array[size-1]=0;
}

void NetSim::boolrs(bool *array, int size)
{
    for(int i=size-1; i>0; i--){
        array[i]=array[i-1];
    }
    array[0]=0;
}

void NetSim::boolreset(bool *array, int size)
{
    for(int i=0; i<size; i++)
        array[i]=0;
}

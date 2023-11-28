#include <iostream>
using namespace std;

int main(){ 
    int *p = new int[5];
    int *q = new int[10];

    p[0] = 1;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    // p[] = {1, 5, 7, 9, 11};

    for(int i=0; i<5; i++){
        q[i] = p[i];
    }

    delete []p;
    p = q;
    q = NULL;

    for(int i=0; i<10; i++){
        cout << p[i] << " ";
    }

    delete[] p;
}
#include "capacete.h"
#include <iostream>

using namespace std;
#ifndef CAPACETE_H
#define CAPACETE_H
void capacete:: pressLeft(){

cout <<leftSlot<< endl;

}
void capacete :: pressRight(){
    cout<< rightSlot<< endl;

}
void capacete:: Slots(string newleft, string newright){
    leftSlot = newleft;
    rightSlot = newright;

}
#endif
//
// Created by VladR on 10/28/2021.
//


#include "bqueue.h"
using namespace std;
int main()
{
    bqueue k;
    k.enqueue(60);
    k.print();
    k.enqueue(20);
    k.enqueue(30);
    k.print();
    k.enqueue(10);
    k.print();
    k.enqueue(50);
    k.enqueue(40);
    k.print();
    bqueue j =k;
   // j.print();//  test
    j.dequeue();
    j.print();
    j.dequeue();
    j.dequeue();
    j.dequeue();
    j.print();
    j.dequeue();
    j.dequeue();
    j.print();
    j.dequeue();
    j.dequeue();
    return 0;
}
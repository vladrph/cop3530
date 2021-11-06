//
// Created by VladR on 10/28/2021.
//

#ifndef ASSIGNMENT6_BQUEUE_H
#define ASSIGNMENT6_BQUEUE_H

#endif //ASSIGNMENT6_BQUEUE_H
class bqnode
{
public:
int priority;
bqnode *prev,*next;
};
class bqueue
{
public:
bqueue();
~ bqueue();
bqueue(const bqueue&);
void enqueue(int);
void dequeue();
void print();
bool empty(){return front==0;}
private:
bqnode *front; //useONLYone pointer
};
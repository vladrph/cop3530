//
// Created by VladR on 10/28/2021.
//

#include "bqueue.h"
#include<iostream>
using namespace std;


/***********************FUNCTION HEADER ******************************************************************************************************************
Name:  Default Constructor A queue object
Pre-Condition: None
Post-Condition:  An empty queue object has been constructed
Description: This default constructor creates a queue object and sets front to null
**********************************************************************************************************************************************************/

bqueue::bqueue():front(0){
    cout << "inside default constructor " <<endl;



}
/***********************FUNCTION HEADER ******************************************************************************************************************
Name:  Destructor
Pre-Condition: Elements are in order in a queue
Post-Condition: Top elements in the queue are removed
Description: the destructor removes the top  elements from a queue
**********************************************************************************************************************************************************/

bqueue::~ bqueue(){

    cout <<" inside the destructor "<< endl;

    cout<<"~QUEUE has been called\n";
    while (!empty())
    {
        dequeue();
    }
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name:  Copy Constructor
Pre-Condition: None
Post-Condition:  A new copy of the queue contains its own memory location
Description: A deep copy of a queue is performed both copies are in their own memory location
**********************************************************************************************************************************************************/

bqueue::bqueue(const bqueue& value){
   // cout << "inside the copy constructor"  << endl;
  ///  front  = 0;


    (*this).front =0;
    bqnode *p = value.front;



        do {

            enqueue(p->priority);
            p = p->next;

        }while(p!=value.front->prev->next);

}
/***********************FUNCTION HEADER ******************************************************************************************************************
Name:  enqueue
Pre-Condition: Elements are not inserted into a queue.
Post-Condition:  Elements are inserted into a queue.
Description: Enqueue inserts elements into the back of a queue provided there is space
**********************************************************************************************************************************************************/


void bqueue::enqueue(int number){
    //cout << "algorithm to add  value to queue" << endl;

    if (!empty())
    {
        bqnode *newNode = new bqnode;
        newNode->priority = number; // new node gets number info

        front->prev->next = new bqnode;   // adding to the back
        front->prev->next->prev = front->prev;  // connecting links
        front->prev = front->prev->next; //connecting links
        front->prev->priority = number;   // insert data information
        cout << "Inserting number " << number << " into queue" << endl;

    }
    else
    {

        front = new bqnode();
        front->priority = number;
        front->next = front->prev=front;
       // front->prev = front->next ;
        cout << "Inserting number " << number << " into queue" << endl;


        return ;
    }
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name:  Dequeue
Pre-Condition: Elements are in order in a queue
Post-Condition: Top elements in the queue are removed
Description: the dequeue function removes the top (front)  elements from a circular linked  queue
**********************************************************************************************************************************************************/

void bqueue::dequeue(){
   // cout<< "algorithm to remove value from queue  " << endl;
    bqnode *p;
    p= front;

    if ( front->prev != front)
    {
        cout << "Removing number " << front->priority << " from queue" << endl;
     front->prev->next = front->next;
     front->next->prev = front->prev;
        front = front->next;

        delete p;

    }
    else if(front->next == front)
    {
       // cout << "last node " << front->priority  << endl;
        cout << "Removing number " << front->priority << " from queue " << endl;

        front = 0;
        delete p;
        cout<<"Cannot deQueue because queue is empty\n";
    }



}
/***********************FUNCTION HEADER ******************************************************************************************************************
Name:  Print
Pre-Condition: None
Post-Condition: Queue elements are printed to the console
Description: Elements in the queue are linked via a circularly linked list.  Print function will continue to print as
 long as the last node's next is not equal to the front.
**********************************************************************************************************************************************************/

void bqueue::print(){
   // cout<< "inside the print function" << endl;

   bqnode *p = front;




   if (front == 0){
       cout << "Error queue is empty can't print " << endl;
       exit(1);
       }
    if (p->next != front) {


        do {
            cout << p->priority<< endl;
            p = p->next;
        } while (p != front->prev->next);

    }else if (p->next == front){
        cout << p->priority << endl;
    }


}


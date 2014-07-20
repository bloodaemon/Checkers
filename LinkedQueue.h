/** Queue implemented by a linked list
  *
  * @author Richard
  *
  *
  *
  */

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "Node.h"
#include "Node.cpp"

namespace DataStructureSzeto
{
    template<class T>
    class LinkedQueue
    {
    public:
        LinkedQueue();
        LinkedQueue(const LinkedQueue<T> &queueObject);
        ~LinkedQueue();
        LinkedQueue<T>& operator =(const LinkedQueue<T> &rightSide);
        T* getFront();
        T* removeFront();
        void addToBack(T* newElement);
        int getLength() const;
        bool isEmpty() const;
        void clear();

    protected:
        Node<T> *front;
        Node<T> *back;
        int length;
    };
}

#endif
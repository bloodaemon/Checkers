/** Queue implemented by a linked list
  *
  * @author Richard
  *
  *
  *
  */

#ifndef LINKEDQUEUE_CPP
#define LINKEDQUEUE_CPP

#include <cstddef>
#include "LinkedQueue.h"

namespace DataStructureSzeto
{
    template<class T>
    LinkedQueue<T>::LinkedQueue()
    {
        front = NULL;

        back = NULL;

        length = 0;
    }

    template<class T>
    LinkedQueue<T>::LinkedQueue(const LinkedQueue<T> &queueObject)
    {
        Node<T> *otherNode;

        front = NULL;

        back = NULL;

        otherNode = queueObject.front;

        if(otherNode != NULL)
        {
            front = new Node<T>(otherNode->getData());

            back = front;

            otherNode = otherNode->getLink();
        }

        while(otherNode != NULL)
        {
            back->setLink(new Node<T>(otherNode->getData()));

            back = back->getLink();

            otherNode = otherNode->getLink();
        }

        length = queueObject.length;
    }

    template<class T>
    LinkedQueue<T>::~LinkedQueue()
    {
        clear();
    }

    template<class T>
    LinkedQueue<T>& LinkedQueue<T>::operator =(const LinkedQueue<T> &rightSide)
    {
        Node<T> *otherNode;

        front = NULL;

        back = NULL;

        otherNode = rightSide.front;

        if(otherNode != NULL)
        {
            front = new Node<T>(otherNode->getData());

            back = front;

            otherNode = otherNode->getLink();
        }

        while(otherNode != NULL)
        {
            back->setLink(new Node<T>(otherNode->getData()));

            back = back->getLink();

            otherNode = otherNode->getLink();
        }

        length = rightSide.length;

        return *this;
    }

    template<class T>
    T* LinkedQueue<T>::getFront()
    {
        if(!isEmpty())
        {
            return front->getData();
        }

        return NULL;
    }

    template<class T>
    T* LinkedQueue<T>::removeFront()
    {
        if(!isEmpty())
        {
            T *result;

            result = front->getData();

            Node<T> *nextNode;

            nextNode = front->getLink();

            delete front;

            front = nextNode;

            length--;

            if(front == NULL)
            {   
                back = NULL;
            }

            return result;
        }

        return NULL;
    }

    template<class T>
    void LinkedQueue<T>::addToBack(T* newElement)
    {
        if(isEmpty())
        {
            front = new Node<T>(newElement);

            back = front;
        }
        else
        {
            back->setLink(new Node<T>(newElement));

            back = back->getLink();
        }

        length++;
    }

    template<class T>
    int LinkedQueue<T>::getLength() const
    {
        return length;
    }

    template<class T>
    bool LinkedQueue<T>::isEmpty() const
    {
        return (front == NULL &&
            back == NULL &&
            length == 0);
    }

    template<class T>
    void LinkedQueue<T>::clear()
    {
        if(!isEmpty())
        {
            Node<T> *nextNode;

            while(front != NULL)
            {
                nextNode = front->getLink();

                front->clear();

                delete front;

                front = nextNode;
            }

            back = NULL;

            length = 0;
        }
    }
}

#endif
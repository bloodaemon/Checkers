/** Node of pointers for a linked list
  *
  * @author Richard Szeto
  *
  *
  *
  */

#ifndef NODE_CPP
#define NODE_CPP

#include <cstddef>
#include "Node.h"

namespace DataStructureSzeto
{
    template<class T>
    Node<T>::Node()
    {
        data = NULL;

        link = NULL;
    }

    template<class T>
    Node<T>::Node(T *newData)
    {
        data = newData;

        link = NULL;
    }

    template<class T>
    Node<T>::Node(T *newData, Node<T> *newLink)
    {
        data = newData;

        link = newLink;
    }

    template<class T>
    Node<T>::Node(const Node<T> &nodeObject)
    {
        data = nodeObject.getData();

        link = NULL;
    }

    template<class T>
    Node<T>::~Node()
    {
        clear();
    }

    template<class T>
    void Node<T>::clear()
    {
        data = NULL;

        link = NULL;
    }

    template<class T>
    Node<T>& Node<T>::operator =(const Node<T> &rightSide)
    {
        clear();

        data = rightSide.getData();

        link = NULL;

        return *this;
    }

    template<class T>
    T* Node<T>::getData()
    {
        return data;
    }

    template<class T>
    Node<T>* Node<T>::getLink()
    {
        return link;
    }

    template<class T>
    void Node<T>::setData(T *newData)
    {
        data = newData;
    }

    template<class T>
    void Node<T>::setLink(Node<T> *newLink)
    {
        link = newLink;
    }
}

#endif
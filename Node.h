/** Node of pointers for a linked list
  *
  * @author Richard Szeto
  *
  *
  *
  */

#ifndef NODE_H
#define NODE_H

namespace DataStructureSzeto
{
    template<class T>
    class Node
    {
    public:
        Node();
        Node(T* newData);
        Node(T* newData, Node<T> *newLink);
        Node(const Node<T> &nodeObject);
        ~Node();
        void clear();
        void deleteData();
        Node<T>& operator =(const Node<T> &rightSide);
        T* getData();
        Node<T>* getLink();
        void setData(T *newData);
        void setLink(Node<T> *newLink);

    protected:
        T *data;
        Node<T> *link;
    };
}

#endif
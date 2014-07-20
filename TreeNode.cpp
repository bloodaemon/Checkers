#ifndef TREENODE_CPP
#define TREENODE_CPP

#include <cstddef>
#include "TreeNode.h"

namespace DataStructureSzeto
{
    template<class T>
    TreeNode<T>::TreeNode()
    {
        data = NULL;

        numberOfChildren = 0;

        child = NULL;
    }

    template<class T>
    TreeNode<T>::TreeNode(T *newData)
    {
        data = newData;

        numberOfChildren = 0;

        child = NULL;
    }

    template<class T>
    TreeNode<T>::TreeNode(T *newData, int newSize)
    {
        data = newData;

        numberOfChildren = newSize;

        child = new TreeNode<T>*[numberOfChildren];

        for(int i = 0; i < numberOfChildren; i++)
        {
            child[i] = NULL;
        }
    }

    template<class T>
    TreeNode<T>::~TreeNode()
    {
        if(child != NULL)
        {
            delete [] child;
        }

        child = NULL;

        if(data != NULL)
        {
            delete data;
        }

        numberOfChildren = 0;
    }

    template<class T>
    T* TreeNode<T>::getData()
    {
        return data;
    }

    template<class T>
    int TreeNode<T>::getNumberOfChildren() const
    {
        return numberOfChildren;
    }

    template<class T>
    TreeNode<T>* TreeNode<T>::getChild(int index)
    {
        if(child != NULL &&
            index >= 0 &&
            index < numberOfChildren)
        {
            return child[index];
        }

        retun NULL;
    }

    template<class T>
    void TreeNode<T>::setData(T* newData)
    {
        data = newData;
    }

    template<class T>
    bool TreeNode<T>::setNumberOfChildren(int newSize)
    {
        if(child == NULL)
        {
            numberOfChildren = newSize;

            child = new TreeNode<T>*[numberOfChildren];

            for(int i = 0; i < numberOfChildren; i++)
            {
                child[i] = NULL;
            }

            return true;
        }

        return false;
    }

    template<class T>
    bool TreeNode<T>::setChild(int index)
    {
        if(child != NULL &&
            index >= 0 &&
            index < numberOfChildren)
        {
            if(child[index] != NULL)
            {
                delete child[index];
            }

            child[index] = new TreeNode<T>();

            return true;
        }

        return false;
    }

    template<class T>
    bool TreeNode<T>::setChild(int index, T* newData)
    {
        if(setChild(index))
        {
            child[index]->setData(newData);

            return true;
        }

        return false;
    }

    template<class T>
    bool TreeNode<T>::setChild(int index, T* newData, int newSize)
    {
        if(setChild(index, newData))
        {
            return child[index]->setNumberOfChildren(newSize);
        }

        return false;
    }
}

#endif
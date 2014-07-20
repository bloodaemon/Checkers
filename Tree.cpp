#ifndef TREE_CPP
#define TREE_CPP

#include "Tree.h"

namespace DataStructureSzeto
{
    template<class T>
    Tree<T>::Tree()
    {
        root = NULL;

        currentNode = NULL;
    }

    template<class T>
    Tree<T>::~Tree()
    {
        deleteSubTree(root);
    }

    template<T>
    PostOrderIterator<T> Tree<T>::getPostOrderIterator()
    {
        return PostOrderIterator<T>(root);
    }

    template<T>
    void Tree<T>::deleteSubTree(TreeNode<T> *subTreeRoot)
    {
        if(subTreeRoot != NULL)
        {
            for(int i = 0; i < subTreeRoot->getNumberOfChildren(); i++)
            {
                if(subTreeRoot->getChild(i) != NULL)
                {
                    deleteSubTree(subTreeRoot->getChild(i));
                }
            }

            delete subTreeRoot;

            subTreeRoot = NULL;
        }
    }
}

#endif
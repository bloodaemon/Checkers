#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"
#include "TreeNode.cpp"
#include "PostOrderIterator.h"
#include "PostOrderIterator.cpp"

namespace DataStructureSzeto
{
    template<class T>
    class Tree
    {
    public:
        Tree();
        ~Tree();
        PostOrderIterator<T> getPostOrderIterator();

    protected:
        void deleteSubTree(TreeNode<T> *subTreeRoot);
        
        TreeNode<T> *root;
    };
}

#endif
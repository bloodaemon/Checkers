#ifndef TREENODE_H
#define TREENODE_H

namespace DataStructureSzeto
{
    template<class T>
    class TreeNode
    {
    public:
        TreeNode();
        TreeNode(T *newData);
        TreeNode(T *newData, int newSize);
        ~TreeNode();
        T* getData();
        int getNumberOfChildren() const;
        TreeNode<T>* getChild(int index);
        void setData(T *newData);
        bool setNumberOfChildren(int newSize);
        bool setChild(int index);
        bool setChild(int index, T* newData);
        bool setChild(int index, T* newData, int newSize);

    protected:
        T *data;
        int numberOfChildren;
        TreeNode<T> **child;
    };
}

#endif
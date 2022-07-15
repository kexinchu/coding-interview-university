/**
 * 实现一个二叉查找树<Binary-Search-Tree>
 * 主要功能包括：
 * - Insert
 * - Search
 * - DeleteTree
 * - GetMin
 * - GetMax
 * - GetHeight
 * - PrintBFS       // BFS
 * - PrintInOrder   // DFS
 * - PrintPreOrder
 * - PrintPostOrder
 * - IsBinarySearchTree
 * - IsBetween
 * - DeleteValue
 * - GetMinNode
 * - GetSuccessor
*/

#include <iostream>
#include <queue>

#ifndef PROJECT_BINARY_SEARCH_TREE_H
#define PROJECT_BINARY_SEARCH_TREE_H

namespace chukexin
{

    struct TreeNode
    {
        int data;
        struct TreeNode *left;
        struct TreeNode *right;

        struct TreeNode *father; // 父节点指针 - 红黑树使用
        std::string color;       // 颜色标识 - 红黑树使用
        // 初始化方法
        TreeNode(){};
        TreeNode(int val) : data(val), left(nullptr), right(nullptr), father(nullptr){};
    };
    typedef struct TreeNode *NodePtr;

    class BinarySearchTree
    {
    public:
        // Insert
        NodePtr Insert(NodePtr node, int val);
        // Returns true if given value is in our tree
        bool Search(NodePtr node, int val);
        // Frees memory allocated for the tree.
        void DeleteTree(NodePtr node);
        // Returns the minimum value stored in the tree,
        // or -1 if tree is empty
        int GetMin(NodePtr node);
        // Returns the maximum value stored in the tree,
        // or -1 if tree is empty
        int GetMax(NodePtr node);
        // Returns height of the tree, 0 if empty
        int GetHeight(NodePtr node);
        // Print out the items in the tree in level order
        void PrintBFS(NodePtr node);
        // DFS
        void PrintInOrder(NodePtr node);
        void PrintPreOrder(NodePtr node);
        void PrintPostOrder(NodePtr node);
        // Returns true if tree is a binary search tree
        bool IsBinarySearchTree(NodePtr node);
        // Returns true if all items in the given tree are between the given values
        bool IsBetween(NodePtr node, int min, int max);
        // Delete a specific node from the tree
        NodePtr DeleteValue(NodePtr node, int val);
        // Returns the node in the tree with the minimum value
        NodePtr GetMinNode(NodePtr node); // 后继节点
        NodePtr GetMaxNode(NodePtr node); // 前置节点
        // Returns the in-order 后继节点 of the given value
        NodePtr GetSuccessor(NodePtr node, int val);
    };

} // namespace chukexin

#endif // PROJECT_BINARY_SEARCH_TREE_H
#include <assert.h>
#include <stdlib.h>
#include "bst_sample.h"

int main(int argc, char *argv[])
{
    using namespace chukexin;

    NodePtr root = nullptr;
    BinarySearchTree BST = BinarySearchTree();

    root = BST.Insert(root, 15);
    root = BST.Insert(root, 10);
    root = BST.Insert(root, 12);
    root = BST.Insert(root, 8);
    root = BST.Insert(root, 9);
    root = BST.Insert(root, 5);
    root = BST.Insert(root, 7);
    root = BST.Insert(root, 23);
    root = BST.Insert(root, 16);
    root = BST.Insert(root, 44);
    root = BST.Insert(root, 2);
    root = BST.Insert(root, 32);

    int min = BST.GetMin(root);
    int max = BST.GetMax(root);
    int height = BST.GetHeight(root);

    std::cout << "Min: " << min << std::endl;
    assert(min == 2);
    std::cout << "Max: " << max << std::endl;
    assert(max == 44);
    std::cout << "Height: " << height << std::endl;
    assert(height == 5);

    std::cout << "Tree items (breadth-first): ";
    BST.PrintBFS(root);
    std::cout << std::endl;

    std::cout << "Tree items (in order): ";
    BST.PrintInOrder(root);
    std::cout << std::endl;

    std::cout << "Tree items (pre order): ";
    BST.PrintPreOrder(root);
    std::cout << std::endl;

    std::cout << "Tree items (post order): ";
    BST.PrintPostOrder(root);
    std::cout << std::endl;

    std::cout << "Is a binary search tree: " << BST.IsBinarySearchTree(root)
              << std::endl;
    assert(BST.IsBinarySearchTree(root));

    NodePtr suc1 = BST.GetSuccessor(root, 5);
    std::cout << "Successor to 5 (2 children), should be 7: " << suc1->data
              << std::endl;
    assert(suc1->data == 7);

    NodePtr suc1a = BST.GetSuccessor(root, 7);
    std::cout << "Successor to 7 (0 children), should be 8: " << suc1a->data
              << std::endl;
    assert(suc1a->data == 8);

    NodePtr suc2 = BST.GetSuccessor(root, 12);
    std::cout << "Successor to 12 (0 children), should be 15: " << suc2->data
              << std::endl;
    assert(suc2->data == 15);

    NodePtr suc3 = BST.GetSuccessor(root, 15);
    std::cout << "Successor to 15 (2 children), should be 16: " << suc3->data
              << std::endl;
    assert(suc3->data == 16);

    // bad tree
    NodePtr otherroot = new TreeNode(25);
    NodePtr node1 = new TreeNode(12);
    NodePtr node2 = new TreeNode(15);
    NodePtr node3 = new TreeNode(85);
    otherroot->left = node1;
    otherroot->right = node2;
    otherroot->left->right = node3;

    std::cout << "Is a binary search tree: " << BST.IsBinarySearchTree(otherroot)
              << std::endl;
    assert(!BST.IsBinarySearchTree(otherroot));

    std::cout << "Removing 2 (no children)" << std::endl;
    root = BST.DeleteValue(root, 2);
    std::cout << "Tree items (in order): ";
    BST.PrintInOrder(root);
    std::cout << std::endl;

    std::cout << "Removing 5 (one child)" << std::endl;
    root = BST.DeleteValue(root, 5);
    std::cout << "Tree items (in order): ";
    BST.PrintInOrder(root);
    std::cout << std::endl;

    std::cout << "Removing 10 (2 children)" << std::endl;
    root = BST.DeleteValue(root, 10);
    std::cout << "Tree items (in order): ";
    BST.PrintInOrder(root);
    std::cout << std::endl;

    BST.DeleteTree(root);
    BST.DeleteTree(otherroot);

    return EXIT_SUCCESS;
}
#include <assert.h>
#include <stdlib.h>
#include "avl-tree_sample.h"

int main(int argc, char *argv[])
{
    using namespace chukexin;

    NodePtr root = nullptr;
    AVLTree AVL = AVLTree();

    root = AVL.Insert(root, 15);
    root = AVL.Insert(root, 10);
    root = AVL.Insert(root, 12);
    root = AVL.Insert(root, 8);
    root = AVL.Insert(root, 9);
    root = AVL.Insert(root, 5);
    root = AVL.Insert(root, 7);
    root = AVL.Insert(root, 23);
    root = AVL.Insert(root, 16);
    root = AVL.Insert(root, 44);
    root = AVL.Insert(root, 2);
    root = AVL.Insert(root, 32);

    int min = AVL.GetMin(root);
    int max = AVL.GetMax(root);
    int height = AVL.GetHeight(root);

    std::cout << "Min: " << min << std::endl;
    assert(min == 2);
    std::cout << "Max: " << max << std::endl;
    assert(max == 44);
    std::cout << "Height: " << height << std::endl;
    assert(height == 4);

    // 9 7 16 5 8 12 32 2 10 15 23 44
    std::cout << "Tree items (breadth-first): ";
    AVL.PrintBFS(root);
    std::cout << std::endl;

    std::cout << "Tree items (in order): ";
    AVL.PrintInOrder(root);
    std::cout << std::endl;

    std::cout << "Is a binary search tree: " << AVL.IsBinarySearchTree(root)
              << std::endl;
    assert(AVL.IsBinarySearchTree(root));

    std::cout << "Removing 8 (no children)" << std::endl;
    root = AVL.DeleteValue(root, 8);
    std::cout << "Tree items (breadth-first): ";
    // 9 5 16 2 7 12 32 10 15 23 44
    AVL.PrintBFS(root);
    std::cout << std::endl;

    std::cout << "Removing 5 (2 child)" << std::endl;
    root = AVL.DeleteValue(root, 5);
    std::cout << "Tree items (breadth-first): ";
    // 9 7 16 2 12 32 10 15 23 44
    AVL.PrintBFS(root);
    std::cout << std::endl;

    std::cout << "Removing 7 (1 children)" << std::endl;
    root = AVL.DeleteValue(root, 7);
    std::cout << "Tree items (breadth-first): ";
    // 16 9 32 2 12 23 44 10 15
    AVL.PrintBFS(root);
    std::cout << std::endl;

    AVL.DeleteTree(root);

    return EXIT_SUCCESS;
}
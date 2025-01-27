#include <assert.h>
#include <stdlib.h>
#include "red-black-tree_sample.h"

int main(int argc, char *argv[])
{
    using namespace chukexin;

    NodePtr root = nullptr;
    RedBlackTree RBTree = RedBlackTree();

    root = RBTree.Insert(root, 15);
    root = RBTree.Insert(root, 10);
    root = RBTree.Insert(root, 12);
    root = RBTree.Insert(root, 8);
    root = RBTree.Insert(root, 9);
    root = RBTree.Insert(root, 5);
    root = RBTree.Insert(root, 7);
    root = RBTree.Insert(root, 23);
    root = RBTree.Insert(root, 16);
    root = RBTree.Insert(root, 44);
    root = RBTree.Insert(root, 2);
    root = RBTree.Insert(root, 32);

    /*
                      12<黑>   
                    /       \
                9<黑>        16<黑>
               /    \       /     \
            7<红>  10<黑>  15<黑>  32<黑>
           /    \                 /    \
         5<黑>  8<黑>            23<红> 44<红>
        /
      2<红>
    */

    int min = RBTree.GetMin(root);
    int max = RBTree.GetMax(root);
    int height = RBTree.GetHeight(root);

    std::cout << "Min: " << min << std::endl;
    assert(min == 2);
    std::cout << "Max: " << max << std::endl;
    assert(max == 44);
    std::cout << "Height: " << height << std::endl;
    assert(height == 5);

    // 12 9 16 7 10 15 32 5 8 23 44 2
    std::cout << "Tree items (breadth-first): ";
    RBTree.PrintBFS(root);
    std::cout << std::endl;

    std::cout << "Tree items (in order): ";
    RBTree.PrintInOrder(root);
    std::cout << std::endl;

    std::cout << "Is a binary search tree: " << RBTree.IsBinarySearchTree(root)
              << std::endl;
    assert(RBTree.IsBinarySearchTree(root));

    // // 测试 re-balance after delete
    // std::cout << "Removing 23" << std::endl;
    // root = RBTree.DeleteValue(root, 23);
    // std::cout << "Removing 44" << std::endl;
    // root = RBTree.DeleteValue(root, 44);
    // // 上面是构造待删除为叶子节点 & 兄弟节点为黑 + 父节点为黑
    // std::cout << "Removing 32" << std::endl;
    // root = RBTree.DeleteValue(root, 32);
    // std::cout << "Tree items (breadth-first): ";
    // // 9 7 12 5 8 10 15 2 16
    // RBTree.PrintBFS(root);
    // std::cout << std::endl;

    std::cout << "Removing 5 (1 child)" << std::endl;
    root = RBTree.DeleteValue(root, 5);
    std::cout << "Tree items (breadth-first): ";
    // 12 9 16 7 10 15 32 2 8 23 44
    RBTree.PrintBFS(root);
    std::cout << std::endl;

    std::cout << "Removing 10 (no children)" << std::endl;
    root = RBTree.DeleteValue(root, 10);
    std::cout << "Tree items (breadth-first): ";
    // 12 7 16 2 8 15 32 9 23 44
    RBTree.PrintBFS(root);
    std::cout << std::endl;

    std::cout << "Removing 16 (2 children)" << std::endl;
    root = RBTree.DeleteValue(root, 16);
    std::cout << "Tree items (breadth-first): ";
    // 12 7 23 2 8 15 32 9 44
    RBTree.PrintBFS(root);
    std::cout << std::endl;

    RBTree.DeleteTree(root);

    return EXIT_SUCCESS;
}
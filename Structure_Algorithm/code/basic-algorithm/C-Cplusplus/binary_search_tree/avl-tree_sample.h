/**
 * 实现一个AVL树 <二叉平衡树>
 * 主要功能复用BinarySearchTree;涉及自平衡的插入，删除操作这里重写
 * - Insert
 * - GetHeight
 * - DeleteValue
*/
#include "bst_sample.h"

#ifndef PROJECT_AVL_TREE_H
#define PROJECT_AVL_TREE_H

namespace chukexin
{

    class AVLTree : public BinarySearchTree
    {
    private:
        /**
     * AVL 树自平衡  <高度平衡二叉树: 每个节点的左右子树高度差不超过1>
     * 当AVL树中 插入元素 和 删除元素 之后可能会造成不平衡(某节点的左右子树高度差>1)
     * 节点左子树高度 > 右子树高度
     * LL: 左子树的左子树高度 >= 左子树的右子树  =>  右旋
     * LR: 左子树的右子树高度 > 左子树的左子树  =>  先对左子树左旋，转换成LL，再右旋
     * 节点右子树高度 > 左子树高度
     * RR: 右子树的右子树高度 >= 右子树的左子树  =>  左旋
     * RL: 右子树的左子树高度 > 右子树的右子树  =>  先对右子树右旋，转换成RR，再左旋
    */
        NodePtr left_left_rotation(NodePtr node)
        {
            NodePtr p = node->left;
            node->left = p->right;
            p->right = node;
        }

        NodePtr right_right_rotation(NodePtr node)
        {
            NodePtr p = node->right;
            node->right = p->left;
            p->left = node;
        }

        NodePtr left_right_rotation(NodePtr node)
        {
            node->left = right_right_rotation(node->left);
            return left_left_rotation(node);
        }

        NodePtr right_left_rotation(NodePtr node)
        {
            node->right = left_left_rotation(node->right);
            return right_right_rotation(node);
        }

    public:
        NodePtr Insert(NodePtr node, int val);

        NodePtr DeleteValue(NodePtr node, int val);
    };

} // chukexin

#endif

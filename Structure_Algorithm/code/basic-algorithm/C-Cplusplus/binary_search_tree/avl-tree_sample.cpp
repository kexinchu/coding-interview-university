#include "avl-tree_sample.h"

namespace chukexin
{

    // Insert： 先插入节点，再调整
    NodePtr AVLTree::Insert(NodePtr node, int val)
    {
        if (nullptr == node)
        { // 根节点为空
            node = new TreeNode(val);
            return node;
        }
        if (val < node->data)
        { // 在左子树中插入
            node->left = Insert(node->left, val);
            // 判断左子树插入后高度 是否比右子树高 > 1 （再平衡）
            if (GetHeight(node->left) - GetHeight(node->right) > 1)
            {
                if (GetHeight(node->left->left) >= GetHeight(node->left->right))
                {
                    node = left_left_rotation(node);
                }
                else
                {
                    node = left_right_rotation(node);
                }
            }
        }
        else if (val > node->data)
        {
            node->right = Insert(node->right, val);
            if (GetHeight(node->right) - GetHeight(node->left) > 1)
            {
                if (GetHeight(node->right->right) >= GetHeight(node->right->left))
                {
                    node = right_right_rotation(node);
                }
                else
                {
                    node = right_left_rotation(node);
                }
            }
        }
        else
        {
            // 值为val的节点已存在
        }
        return node;
    }

    // DeleteValue: 先删除节点，再调整
    NodePtr AVLTree::DeleteValue(NodePtr node, int val)
    {
        if (nullptr == node)
            return nullptr;

        if (val < node->data)
        {
            node->left = DeleteValue(node->left, val);
            // 删除之后，左子树高度可能变矮。<跟插入是反着的>
            if (GetHeight(node->right) - GetHeight(node->left) > 1)
            {
                if (GetHeight(node->right->right) >= GetHeight(node->right->left))
                {
                    node = right_right_rotation(node);
                }
                else
                {
                    node = right_left_rotation(node);
                }
            }
        }
        else if (val > node->data)
        {
            node->right = DeleteValue(node->right, val);
            if (GetHeight(node->left) - GetHeight(node->right) > 1)
            {
                if (GetHeight(node->left->left) >= GetHeight(node->left->right))
                {
                    node = left_left_rotation(node);
                }
                else
                {
                    node = left_right_rotation(node);
                }
            }
        }
        else
        {
            // 删除节点 node :
            // 1, node 为叶子节点, 直接删除
            // 2, node 含一个子节点，用非空子节点替换node
            // 3, node 的左右子树均不为空，根据左右子树高度选择前置节点 或 后继节点
            if (nullptr != node->left && nullptr != node->right)
            {
                if (GetHeight(node->left) > GetHeight(node->right))
                {
                    // 前置节点替换
                    NodePtr tmp = GetMaxNode(node->left);
                    node->data = tmp->data;
                    node->left = DeleteValue(node->left, tmp->data);
                }
                else
                {
                    // 后继节点替换
                    NodePtr tmp = GetMinNode(node->right);
                    node->data = tmp->data;
                    node->right = DeleteValue(node->right, tmp->data);
                }
            }
            else
            {
                NodePtr tmp = node;
                if (nullptr != node->left)
                    node = node->left;
                else
                    node = node->right;
                delete tmp;
            }
        }
        return node;
    }

} // chukexin
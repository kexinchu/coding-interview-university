#include "bst_sample.h"

namespace chukexin
{

    NodePtr BinarySearchTree::Insert(NodePtr node, int val)
    {
        // 插入在叶子节点上
        if (nullptr == node)
        {
            node = new TreeNode(val);
            return node;
        }
        if (val < node->data)
        {
            node->left = Insert(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = Insert(node->right, val);
        }
        else
        {
            // 树中已存在值为val的节点
        }
        return node;
    }

    bool BinarySearchTree::Search(NodePtr node, int val)
    {
        NodePtr p = node;
        while (nullptr != p && val != p->data)
        {
            if (val < p->data)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        if (nullptr == p)
            return false;
        else
            return (val == p->data);
    }

    void BinarySearchTree::DeleteTree(NodePtr node)
    {
        // 递归
        if (nullptr == node)
            return;

        if (nullptr != node->left)
            DeleteTree(node->left);
        if (nullptr != node->right)
            DeleteTree(node->right);
        delete node;
    }

    int BinarySearchTree::GetMin(NodePtr node)
    {
        if (nullptr == node)
            return -1;
        NodePtr p = node;
        while (nullptr != p && nullptr != p->left)
        {
            p = p->left;
        }
        return p->data;
    }

    int BinarySearchTree::GetMax(NodePtr node)
    {
        if (nullptr == node)
            return -1;
        NodePtr p = node;
        while (nullptr != p && nullptr != p->right)
        {
            p = p->right;
        }
        return p->data;
    }

    int BinarySearchTree::GetHeight(NodePtr node)
    {
        if (nullptr == node)
            return 0;
        return std::max(GetHeight(node->left), GetHeight(node->right)) + 1;
    }

    void BinarySearchTree::PrintBFS(NodePtr node)
    {
        std::queue<NodePtr> treeQue;
        NodePtr topNode;
        treeQue.push(node);
        while (!treeQue.empty())
        {
            topNode = treeQue.front();
            treeQue.pop();

            if (nullptr != topNode)
            {
                std::cout << topNode->data << " ";

                if (nullptr != topNode->left)
                    treeQue.push(topNode->left);
                if (nullptr != topNode->right)
                    treeQue.push(topNode->right);
            }
        }
    }

    void BinarySearchTree::PrintInOrder(NodePtr node)
    {
        // 递归
        if (nullptr == node)
            return;

        if (nullptr != node->left)
            PrintInOrder(node->left);
        std::cout << node->data << " ";
        if (nullptr != node->right)
            PrintInOrder(node->right);
    }

    void BinarySearchTree::PrintPreOrder(NodePtr node)
    {
        // 递归
        if (nullptr == node)
            return;

        std::cout << node->data << " ";
        if (nullptr != node->left)
            PrintInOrder(node->left);
        if (nullptr != node->right)
            PrintInOrder(node->right);
    }

    void BinarySearchTree::PrintPostOrder(NodePtr node)
    {
        // 递归
        if (nullptr == node)
            return;

        if (nullptr != node->left)
            PrintInOrder(node->left);
        if (nullptr != node->right)
            PrintInOrder(node->right);
        std::cout << node->data << " ";
    }

    bool BinarySearchTree::IsBinarySearchTree(NodePtr node)
    {
        // 判断是否满足：左子树 < root < 右子树
        int min = GetMin(node), max = GetMax(node);
        return IsBetween(node, min, max);
    }

    bool BinarySearchTree::IsBetween(NodePtr node, int min, int max)
    {
        // 递归
        if (nullptr == node)
            return true;

        if (node->data >= min && node->data <= max &&
            IsBetween(node->left, min, node->data) &&
            IsBetween(node->right, node->data, max))
        {
            return true;
        }
        return false;
    }

    NodePtr BinarySearchTree::DeleteValue(NodePtr node, int val)
    {
        /**
     * 删除节点 - 三种情况
     * 1，P是叶子结点，直接删除
     * 2，P只有一个非空子树：如果p没有父节点，将p删除，并将p子树的根节点设为新的搜索树的根节点；如果p有父节点pp，使pp指向p的唯一子节点，并删除p
     * 3，P左右子树均不为空：用左子树中的最大元素/右子树的最小元素替换p，并删除原节点
    */
        if (nullptr == node)
            return nullptr;

        if (val < node->data)
        {
            node->left = DeleteValue(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = DeleteValue(node->right, val);
        }
        else
        {
            // 找到节点，删除
            if (nullptr == node->left && nullptr == node->right)
            {
                // 叶子节点
                delete node;
                node = nullptr;
            }
            else if (nullptr == node->left)
            {
                // 只有右子节点
                NodePtr tmp = node;
                node = node->right; // 使用右子节点替换node
                delete tmp;
            }
            else if (nullptr == node->right)
            {
                // 只有左子节点
                NodePtr tmp = node;
                node = node->left;
                delete tmp;
            }
            else
            {
                // 左右子节点均存在 => 后继节点替换根节点
                NodePtr tmp = GetMinNode(node->right);
                node->data = tmp->data;
                node->right = DeleteValue(node->right, tmp->data); // 转换为删除后继节点
            }
        }

        return node;
    }

    NodePtr BinarySearchTree::GetMinNode(NodePtr node)
    {
        if (nullptr == node)
            return node;

        if (nullptr == node->left)
        {
            return node;
        }

        return GetMinNode(node->left);
    }

    NodePtr BinarySearchTree::GetMaxNode(NodePtr node)
    {
        if (nullptr == node)
            return node;

        if (nullptr == node->right)
        {
            return node;
        }

        return GetMaxNode(node->right);
    }

    NodePtr BinarySearchTree::GetSuccessor(NodePtr node, int val)
    {
        // 获取 中序 遍历下val的后继节点
        if (nullptr == node)
            return node;

        // find value
        NodePtr p = node;
        while (nullptr != p && val != p->data)
        {
            if (val < p->data)
            {
                p = p->left;
            }
            else if (val > p->data)
            {
                p = p->right;
            }
        }
        if (nullptr == p)
            return nullptr; // 无值为val的节点

        if (nullptr != p->right)
        { // p有右子树，查找后继节点即可
            return GetMinNode(p->right);
        }
        else
        {
            // p无右子节点，find deepest ancestor where val is in it's left subtree
            NodePtr ancestor = node, successor = nullptr;
            while (nullptr != ancestor)
            {
                if (val < ancestor->data)
                {
                    successor = ancestor;
                    ancestor = ancestor->left;
                }
                else
                {
                    ancestor = ancestor->right;
                }
            }
            return successor;
        }
    }

} // namespace chukexin
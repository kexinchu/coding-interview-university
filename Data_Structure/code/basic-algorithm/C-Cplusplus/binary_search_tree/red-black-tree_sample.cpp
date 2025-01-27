#include "red-black-tree_sample.h"

namespace chukexin
{

    // 左旋 返回新的根节点(node的替代节点)
    void RedBlackTree::left_rotate(NodePtr node)
    {
        NodePtr right_node = node->right;
        NodePtr father_node = node->father;

        // 围绕node左旋
        node->right = right_node->left;
        right_node->left = node;

        // 处理father节点
        node->father = right_node;
        right_node->father = father_node;
        if (nullptr == father_node)
        {
            // node 为根节点 => right成了新的根节点
        }
        else if (node == father_node->left)
        {
            father_node->left = right_node;
        }
        else
        {
            father_node->right = right_node;
        }
        // return right_node;
    }

    // 右旋 返回新的根节点(node的替代节点)
    void RedBlackTree::right_rotate(NodePtr node)
    {
        NodePtr left_node = node->left;
        NodePtr father_node = node->father;

        // 围绕node右旋
        node->left = left_node->right;
        left_node->right = node;

        // 处理father节点
        node->father = left_node;
        left_node->father = father_node;
        if (nullptr == father_node)
        {
            // 根节点 不用处理
        }
        else if (node == father_node->left)
        {
            father_node->left = left_node;
        }
        else
        {
            father_node->right = left_node;
        }
        // return left_node;
    }

    // 插入操作之后的re-balance, 目标节点node均为红色<解决相邻红色的问题>
    void RedBlackTree::rebalance_after_insert(NodePtr node)
    {
        if (nullptr == node)
            return;
        NodePtr father_node = node->father;
        // case1、目标节点为根节点 => 颜色变黑即可
        if (nullptr == father_node)
        {
            node->color = "black";
            return;
        }
        // case2、父节点为黑色 => 符合红黑树特性，结束re-balance
        if ("black" == father_node->color)
        {
            return;
        }

        // 以下 父节点为红色(必有祖父节点且为黑色<根为黑 + 红不相邻>)， 需要根据叔叔节点的颜色来判断处理
        NodePtr g_father_node = father_node->father;
        // 目标节点在 祖父 节点的 左子树中
        if (father_node == g_father_node->left)
        {
            NodePtr uncle_node = g_father_node->right;
            // case3 叔叔节点也为红色 => 父/叔变黑，祖父变红，目标变祖父，继续
            if (nullptr != uncle_node && "red" == uncle_node->color)
            {
                father_node->color = "black";
                uncle_node->color = "black";
                g_father_node->color = "red";
                rebalance_after_insert(g_father_node);
            }
            else
            {
                // 叔节点为黑色; 结合node的位置处理
                if (node == father_node->right)
                {
                    // case4 a为父节点的右子节点 => (LR结构)先绕父节点左旋，得到LL结构
                    left_rotate(father_node);
                    rebalance_after_insert(father_node);
                }
                else
                {
                    // case5 a为父节点的左子节点 => (RR结构)绕祖父节点右旋 + 交换父节点与祖父节点颜色，结束
                    father_node->color = g_father_node->color;
                    g_father_node->color = "red";
                    right_rotate(g_father_node);
                }
            }
        }
        else
        {
            // 目标节点在 祖父 节点的 右子树中
            NodePtr uncle_node = g_father_node->left;
            // case3 叔叔节点也为红色 => 父/叔变黑，祖父变红，目标变祖父，继续
            if (nullptr != uncle_node && "red" == uncle_node->color)
            {
                father_node->color = "black";
                uncle_node->color = "black";
                g_father_node->color = "red";
                rebalance_after_insert(g_father_node);
            }
            else
            {
                // 叔节点为黑色; 结合node的位置处理
                if (node == father_node->left)
                {
                    // case6 (RL结构)先绕父节点右旋，得到RR结构
                    right_rotate(father_node);
                    rebalance_after_insert(father_node);
                }
                else
                {
                    // case7 (RR结构)绕祖父节点左旋 + 交换父节点与祖父节点颜色，结束
                    father_node->color = g_father_node->color;
                    g_father_node->color = "red";
                    left_rotate(g_father_node);
                }
            }
        }
    }

    // Insert
    NodePtr RedBlackTree::Insert(NodePtr node, int val)
    {
        if (nullptr == node)
        {
            node = new TreeNode(val);
            node->color = "black";
            return node;
        }

        // 寻找插入位置
        NodePtr p = node, pp = nullptr;
        while (nullptr != p && val != p->data)
        {
            pp = p;
            if (val < p->data)
                p = p->left;
            else
                p = p->right;
        }
        // 值为val的节点已存在
        if (nullptr != p && val == p->data)
        {
            return node;
        }

        // 插入
        NodePtr tmp = new TreeNode(val);
        tmp->color = "red";
        tmp->father = pp;
        if (val < pp->data)
        {
            pp->left = tmp;
        }
        else
        {
            pp->right = tmp;
        }
        // 再平衡
        rebalance_after_insert(tmp);

        // 返回根节点
        while (nullptr != node->father)
        {
            node = node->father;
        }
        return node;
    }

    // 删除操作之后的re-balance, 目标节点node为黑色<解决黑色高度不一致的问题>
    void RedBlackTree::rebalance_after_delete(NodePtr node)
    {
        if (nullptr == node || nullptr == node->father)
            return;
        NodePtr father_node = node->father;
        if (node == father_node->left)
        {
            // 目标节点 P 是 父节点 F 的左子节点
            NodePtr brother_node = father_node->right;
            if ("red" == brother_node->color)
            {
                // case1， B为红 => 交换B F颜色，围绕F左旋，以P为目标节点继续
                brother_node->color = father_node->color;
                father_node->color = "red";
                left_rotate(father_node);
                // father_node =  left_rotate(father_node);
                rebalance_after_delete(node);
            }
            else
            {
                // 兄弟节点B为黑色
                NodePtr NodeBL = brother_node->left;
                NodePtr NodeBR = brother_node->right;
                if ((nullptr == NodeBL || "black" == NodeBL->color) && "black" == NodeBR->color)
                {
                    // case2，B的左右子节点均为黑 => 令B为红，F为黑，若F原本就是黑色，则以F为目标节点继续
                    brother_node->color = "red";
                    if ("red" == father_node->color)
                    {
                        father_node->color = "black";
                    }
                    else
                    {
                        rebalance_after_delete(father_node);
                    }
                }
                else if (("red" == NodeBL->color) && ("black" == NodeBR->color))
                {
                    // case3，BL为红，BR为黑 => (BL)交换BL 和 B的颜色，绕B右旋，得到(RR)case4
                    NodeBL->color = brother_node->color;
                    brother_node->color = "red";
                    right_rotate(brother_node);
                }
                else
                {
                    // case4,BR为红色，BL任意 => (RR)交换B和F的颜色，令BR为黑，绕F左旋,结束
                    brother_node->color = father_node->color;
                    father_node->color = "black";
                    NodeBR->color = "black";
                    left_rotate(father_node);
                }
            }
        }
        else
        {
            // 目标节点 P 是 父节点 F 的右子节点
            NodePtr brother_node = father_node->left;
            if ("red" == brother_node->color)
            {
                // case1， B为红 => 交换B F颜色，围绕F右旋，以P为目标节点继续
                brother_node->color = father_node->color;
                father_node->color = "red";
                right_rotate(father_node);
                rebalance_after_delete(node);
            }
            else
            {
                // 兄弟节点B为黑色
                NodePtr NodeBL = brother_node->left;
                NodePtr NodeBR = brother_node->right;
                if ("black" == NodeBL->color && "black" == NodeBR->color)
                {
                    // case2，B的左右子节点均为黑 => 令B为红，F为黑，若F原本就是黑色，则以F为目标节点继续
                    brother_node->color = "red";
                    if ("red" == father_node->color)
                    {
                        father_node->color = "black";
                    }
                    else
                    {
                        rebalance_after_delete(father_node);
                    }
                }
                else if ("red" == NodeBR->color && "black" == NodeBL->color)
                {
                    // case3，BR为红，BL为黑 => (LR)交换BL 和 B的颜色，绕B左旋，得到(LL)case4
                    NodeBL->color = brother_node->color;
                    brother_node->color = "red";
                    left_rotate(brother_node);
                }
                else
                {
                    // case4,BL为红色，BR任意 => (LL)交换B和F的颜色，令BL为黑，绕F右旋,结束
                    brother_node->color = father_node->color;
                    father_node->color = "black";
                    NodeBR->color = "black";
                    right_rotate(father_node);
                }
            }
        }
    }

    // 删除叶子节点
    void RedBlackTree::delete_leaf(NodePtr node)
    {
        if (nullptr == node)
            return;
        NodePtr father_node = node->father;
        if (nullptr == node->father)
        {
            // 根节点
            NodePtr p = node;
            node = nullptr;
            delete p;
            return;
        }
        // 叶子节点颜色为红色，直接删除节点
        if ("red" == node->color)
        {
            if (node == father_node->left)
                father_node->left = nullptr;
            else
                father_node->right = nullptr;
            delete node;
            return;
        }

        // P为黑色 => 根据特征4，兄弟节点必定存在
        if (node == father_node->left)
        {
            // P是父节点的左孩子
            NodePtr brother_node = father_node->right;
            // case1 兄弟节点B的颜色为红 => 交换父节点F 和 B的颜色, 并围绕F左旋
            if ("red" == brother_node->color)
            {
                brother_node->color = father_node->color;
                father_node->color = "red";
                left_rotate(father_node);
                delete_leaf(node);
            }
            else
            {
                NodePtr NodeBL = brother_node->left;
                NodePtr NodeBR = brother_node->right;
                // 将删除node的操作提前<case2 ~ case5 均需要>
                delete node;
                father_node->left = nullptr;
                if (nullptr == NodeBL && nullptr == NodeBR)
                {
                    // case2, B无子节点 => 使F为红，并围绕F左旋，<如果F本来是黑色 => 黑色深度-1，需要重新平衡>
                    if ("red" == father_node->color)
                    {
                        left_rotate(father_node);
                    }
                    else
                    {
                        father_node->color = "red";
                        left_rotate(father_node);
                        // 左旋之后，兄弟节点成为新的父节点
                        rebalance_after_delete(brother_node);
                    }
                }
                else if (nullptr == NodeBR)
                {
                    // case3,B只有左子节点BL<RL> => 令BL颜色=F; F为黑色， 删除节点P & 围绕B右旋得到RR & 围绕F左旋
                    NodeBL->color = father_node->color;
                    father_node->color = "black";
                    right_rotate(brother_node);
                    left_rotate(father_node);
                }
                else
                {
                    // case4 & case5 , B有右子节点BR(RR) => 交换F和B的颜色; 令BR为黑色 & 围绕F左旋
                    brother_node->color = father_node->color;
                    father_node->color = "black";
                    NodeBR->color = "black";
                    left_rotate(father_node);
                }
            }
        }
        else
        {
            // P是父节点的右孩子
            NodePtr brother_node = father_node->left;
            // case1 兄弟节点B的颜色为红 => 交换父节点F 和 B的颜色, 并围绕F右旋
            if ("red" == brother_node->color)
            {
                brother_node->color = father_node->color;
                father_node->color = "red";
                right_rotate(father_node);
                delete_leaf(node);
            }
            else
            {
                NodePtr NodeBL = brother_node->left;
                NodePtr NodeBR = brother_node->right;
                // 将删除node的操作提前<case2 ~ case5 均需要>
                delete node;
                father_node->right = nullptr;
                if (nullptr == NodeBL && nullptr == NodeBR)
                {
                    // case2, B无子节点 => 使F为红，并围绕F右旋，<如果F本来是黑色 => 黑色深度-1，需要重新平衡>
                    if ("red" == father_node->color)
                    {
                        right_rotate(father_node);
                    }
                    else
                    {
                        father_node->color = "red";
                        right_rotate(father_node);
                        // 左旋之后，兄弟节点成为新的父节点
                        rebalance_after_delete(brother_node);
                    }
                }
                else if (nullptr == NodeBL)
                {
                    // case3,B只有右子节点BR<LR> => 令BR颜色=F; F为黑色， 删除节点P & 围绕B左旋得到LL & 围绕F右旋
                    NodeBR->color = father_node->color;
                    father_node->color = "black";
                    left_rotate(brother_node);
                    right_rotate(father_node);
                }
                else
                {
                    // case4 & case5 , B有左子节点BL(LL) => 交换F和B的颜色; 令BL为黑色 & 围绕F左旋
                    brother_node->color = father_node->color;
                    father_node->color = "black";
                    NodeBL->color = "black";
                    right_rotate(father_node);
                }
            }
        }
    }

    // delete value
    NodePtr RedBlackTree::DeleteValue(NodePtr node, int val)
    {
        if (nullptr == node)
            return node;

        // Search 待删除节点
        NodePtr p = node;
        while (nullptr != p && val != p->data)
        {
            if (val < p->data)
                p = p->left;
            else
                p = p->right;
        }
        // 没找到值为val的节点
        if (nullptr == p)
            return node;

        // 删除
        if (nullptr == p->left && nullptr == p->right)
        {
            // 情况1，删除叶子节点
            delete_leaf(p);
        }
        else if (nullptr == p->right)
        {
            // 情况2-1，p 仅有左子节点<根据红黑树定义4，其子节点必为红色，且无孙子节点>
            NodePtr tmp = p->left;
            p->data = tmp->data;
            p->left = nullptr;
            delete tmp;
        }
        else if (nullptr == p->left)
        {
            // 情况2-2，p 仅有右子节点
            NodePtr tmp = p->right;
            p->data = tmp->data;
            p->right = nullptr;
            delete tmp;
        }
        else
        {
            // 情况3，左右子树均非空 => 交换 p 和 其后继节点，删除后继节点
            NodePtr next_node = GetMinNode(p->right);
            p->data = next_node->data;
            NodePtr tmp = DeleteValue(p->right, next_node->data); // 这里可能调用delete_leaf，导致无返回值
        }

        // 返回根节点
        while (nullptr != node->father)
        {
            node = node->father;
        }
        return node;
    }
}
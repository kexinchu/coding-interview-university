/**
 * 实现一个红黑树 <二叉平衡树>
 * 主要功能复用BinarySearchTree; 涉及自平衡的插入，删除操作这里重写
 * - Insert <增加节点颜色>
 * - DeleteValue
 * 
 * 参考：https://github.com/william-zk/RB_Tree
 * 红黑树部分知识参考：https://github.com/kexinchu/coding-interview-university/blob/main/README.md
 * 
 * 注意：
 *   红黑树中，不存在的叶子节点(nullptr)均视为黑色
*/
#include "bst_sample.h"

#ifndef PROJECT_AVL_TREE_H
#define PROJECT_AVL_TREE_H

namespace chukexin
{

    class RedBlackTree : public BinarySearchTree
    {
    private:
        // 左旋 & 右旋操作 -- 是 红黑树 插入 & 删除 再平衡的核心操作
        /* 左旋:
        F                        F
        |                        |
        P                        R
       /  \                     /  \
      L    R         ==>       P   RR
          /  \                /  \
         RL  RR              L    RL
    */
        void left_rotate(NodePtr node);

        /* 右旋:
        F                        F
        |                        |
        P                        L
       /  \                     /  \
      L    R         ==>       LL   P
    /  \                           /  \
    LL  LR                        LR   R
    */
        void right_rotate(NodePtr node);

        /**
     * 插入操作: 使插入节点为为红色 & 插入节点都放在叶子节点上
     * case1、插入节点a为根节点，直接变颜色为黑
     * case2、插入节点a的父节点颜色为黑色，什么都不用做
     * case3、父节点为红色，叔节点也为红色 => 父/叔变黑，祖父变红，设置祖父为新的关注节点
     * if 父节点 是 祖父节点的左孩子
     * case4、父为红，叔为黑，且a为父节点的右子节点(LR结构) => 绕父节点左旋，设父节点为关注节点<形成LL结构>
     * case5、父为红，叔为黑，且a为父节点的左子节点(LL结构) => 绕祖父节点右旋，交换父节点与祖父节点的颜色
     * else 
     * case6、父为红，叔为黑，且a为父节点的左子节点(RL结构) => 绕父节点右旋，设置父节点为关注节点<形成RR结构>
     * case7、父为红，叔为黑，且a为父节点的右子节点(RR结构) => 围绕祖父节点右旋，交换父节点与祖父节点的颜色
    */
        void rebalance_after_insert(NodePtr node);

        /**
     * 删除叶子节点的 case2 会造成红黑树失衡 => rebalance (此时关注节点均为黑色)
     * if P 是 父节点F 的左子节点
     *   case1、关注节点P的兄弟节点B为红 => 交换B F颜色，围绕F左旋，以P为目标节点继续
     *   case2、兄弟节点B为黑色，且其左右子节点均为黑  => 令B为红，F为黑，若F原本就是黑色，则以F为目标节点继续
     *   case3、B为黑色，且其左子节点BL为红，右子节点BR为黑 => (BL)交换BL 和 B的颜色，绕B右旋，得到(RR)case4
     *   case4、B为黑色，BR为红色，BL任意 => (RR)交换B和F的颜色，令BR为黑，绕F左旋,结束
     * else
     *   case1 ~ 4, 旋转方向相反
    */
        void rebalance_after_delete(NodePtr node);

        /**
     * 删除叶子节点 - 单独写成函数
    */
        void delete_leaf(NodePtr node);

    public:
        /**
     * 插入节点
     * 插入在叶子节点上，且设为红色；然后在以插入节点为目标节点re-balance
    */
        NodePtr Insert(NodePtr node, int val);

        /**
     * 删除操作:
     * - 1，待删除节点的三种情况分类
     *      1，待删除节点为叶子节点；
     *      2，待删除节点只有一个子节点，(此时根据红黑树定义4，其子节点为红色，且不可能是子树)；
     *      3，待删除节点两个子节点/子树均非空，交换待删除节点与其后继节点，构造情况1或情况2；          
     *      // 情况2，可以交换删除节点与子节点，再删除子节点即可
     *      // 情况1较复杂，涉及删除后的再平衡
     * 
     * - 2，删除叶子节点 : 单独写成函数 delete_leaf
     *      - P为红色,令P为黑色，继续
     *      - P为黑色
     *        if 目标节点P 是 父节点F 的左孩子
     *          - case1, P的兄弟节点B为红色 => 交换父节点F 和 B的颜色, 并围绕F左旋
     *          - case2, B为黑色，且B无子节点 => 使F为红色，并围绕F左旋 <if F本来就是红色，结束，else 黑色深度-1 需要re-balance>
     *          - case3, B为黑色，B只有左子节点BL => 令BL颜色=F; P为红色，F为黑色， 删除节点P & 围绕B右旋得到RR & 围绕F左旋
     *          - case4, B为黑色，B只有右子节点BR => 交换F和B的颜色; P为红色，BR为黑色(RR) & 围绕P左旋
     *          - case5, B为黑色，且有2个子节点 => 交换B和F, 令BR为黑色， 删除P，围绕F左旋(操作与case4一致)
     *          else
     *          - 情况同上，旋转方向相反即可
    */
        NodePtr DeleteValue(NodePtr node, int val);
    };

} // chukexin

#endif

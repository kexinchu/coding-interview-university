# 递归

## 三个条件

* 可分解为子问题
* 子问题与原问题解法一致，只有规模上的不同
* 有终止条件

## 写递归代码

* 整理出递推公式
* 确定好终止条件
* 「翻译」成代码

关键：

> 只要遇到递归，我们就把它抽象成一个递推公式，不用想一层层的调用关系，不要试图用人脑去分解每一个步骤。

## 警惕

* 堆栈溢出 <- 递归深度过大
* 重复计算 <- 递归过程中的不同分支，重复计算相同子问题
  * 保存子问题结果（map/dict）
* 空间复杂度高 <- 递归函数调用带来的消耗

## 递归改写非递归

本质：人肉模拟函数调用堆栈。

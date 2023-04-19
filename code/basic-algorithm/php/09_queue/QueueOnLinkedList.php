<?php
/**
 * User: chukexin
 * Date: 2020/10/03
 */

namespace Algo_09;

use Algo_06\SingleLinkedListNode;

class QueueOnLinkedList{
    /**
     * 队列 链表实现
     */
    public $head;
    public $tail;
    public $length;

    public function __construct(){
        $this->head = new SingleLinkedListNode();
        $this->tail = $this->head;

        $this->length = 0;
    }

    public function enqueue($data){
        /**
         * 入队 
         */
        $newNode = new SingleLinkedListNode();
        $newNode->data = $data;

        $this->tail->next = $newNode;
        $this->tail = $newNode;

        $this->length++;
    }

    public function dequeue(){
        /**
         * 出队 
         */
        if (0 == $this->length) {
            return false;
        }

        $node = $this->head->next;
        $this->head->next = $this->head->next->next;

        $this->length--;

        return $node;
    }

    public function getLength(){
        // 获取队列长度
        return $this->length;
    }

    public function printSelf(){
        // 打印队列
        if (0 == $this->length) {
            echo 'empty queue' . PHP_EOL;
            return;
        }

        echo 'head.next -> ';
        $curNode = $this->head;
        while ($curNode->next) {
            echo $curNode->next->data . ' -> ';

            $curNode = $curNode->next;
        }
        echo 'NULL' . PHP_EOL;
    }
}

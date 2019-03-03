//
// Created by 김민호 on 2019-03-03.
//

#ifndef STACK_MSTACK_H
#define STACK_MSTACK_H

template <class V>
class _Node {
public:
    V val;

    _Node(V val): val(val){};
};

template <class V>
class MStack {
private:
    int _top;
    int _capacity;
    _Node<V>** pNode;

public:
    MStack() {
        _capacity = 20;
        this->pNode = new _Node<V>* [_capacity];
        _top = -1;
    }

    void push(V val) {
        if(_capacity > _top) {
            // 나중에 _capacity 재할당
        }
        this->pNode[++this->_top] = new _Node<V> (val);
    }

    void pop() {
        if(_top == -1)
            exit(11);
        delete this->pNode[this->_top--];
    }

    V top() {
        if(_top == -1) exit(11);
        else return this->pNode[this->_top]->val;
    }

};

#endif //STACK_MSTACK_H

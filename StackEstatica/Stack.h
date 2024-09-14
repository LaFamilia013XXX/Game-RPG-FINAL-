#ifndef STACK_H
#define STACK_H

const int MaxStack = 100;

class Stack {
    public:
        Stack();
        ~Stack();
        bool Empty();
        bool Full();
        void Push(int x);
        void Pop(int &x);
        void Clear();
        void Top(int &x);
        int Size();
        void exibirStack();
    private:
        int top;
        int Entry[MaxStack-1];
};

#endif
#ifndef STACK_H
#define STACK_H

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
    private:

        struct StackNode {
            int Entry;
            StackNode *NextNode;
        };

        typedef StackNode *StackPointer;

        StackPointer top;
};   


#endif
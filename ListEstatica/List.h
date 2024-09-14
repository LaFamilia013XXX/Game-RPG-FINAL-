#ifndef LIST_H
#define LIST_H

const int MaxList = 100;

class List {
    public:
        List();
        ~List();
        bool Empty();
        bool Full();
        void Insert(int p, int x);
        void Delete(int p, int &x);
        void Retrieve(int p, int &x);
        void Replace(int p, int x);
        void Clear();
        int Size();
        void exibirList();
    private:
        int count;
        int Entry[MaxList+1]; 

};

#endif

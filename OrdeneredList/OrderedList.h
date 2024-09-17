


class OrderedList{
    public:
        OrderedList();
        ~OrderedList();
        bool Empty();
        void Insert(int x);
        void Delete(int x);
        int Search(int x); // Retornar 0, se x não ocorre na lista; // Senão retorna a posição da primeira ocorrência;
        void Clear();
        int Size();
    private:
        struct ListNode{
            int Entry;
            ListNode* NextNode;
        };

        typedef ListNode* ListPointer;
        int count;
        ListPointer head, sentinel;
};
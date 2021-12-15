#include <iostream>
using namespace std;

template <class T>

class ListNode{
    public:
        ListNode *next;
        T date;
};

template <class T>
class Stack{
    private:
        int num;
        ListNode<T>* top;
        ListNode<T>* bottom;
    public:
        Stack();
        ~Stack();
        void push(const T &t);
        T pop();
        bool isEmpty();
        int size();
};

template<class T>
int Stack<T>::size(){
    return this->num;
}

template <class T>
Stack<T> :: Stack(){
    this->num = 0;
    bottom = new ListNode<T>;
    bottom->next = NULL;
    top = bottom;
}

template <class T>
void Stack<T> :: push(const T &t){
    ListNode<T>* o = new ListNode<T>;
    o->next = top;
    o->date = t;
    top = o;
    num++;
}

template <class T>
T Stack<T> :: pop(){
    T ans = top->date;
    if(top->next != NULL)
        top = top->next;
    num--;
    return ans;
}

template <class T>
bool Stack<T> :: isEmpty(){
    return top == bottom;
}

template <class T>
Stack<T> :: ~Stack(){
    cout<< "销毁"<< endl;
}

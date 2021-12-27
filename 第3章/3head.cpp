#include <iostream>
#include <string>
#include <stack>
#define MAX_AMOUNT 100
using namespace std;
//3-15
class Stack_two{
    private:
        int *elem;
        int ListSize;
        int left;
        int right;
    public:
        void initStack();
        void push(int i,int x);
        int pop(int i);
        void show();
};

void Stack_two::initStack() {
    elem = new int[MAX_AMOUNT];
    ListSize = MAX_AMOUNT;
    left = 0;
    right = ListSize - 1;
}

void Stack_two::push( int i, int x) {
    if(left<right){
        if(i==0){
            this->elem[left] = x;
            left++;
        }else if(i==1){
            this->elem[right] = x;
            right--;
        }else{
            printf("error\n");
        }
    }else {
        printf("满了\n");
    }
}

int Stack_two::pop( int i) {
    int x = -1;
    if(i==0){
        if(left>=0){
            x = this->elem[left];
            left--;
        }else{
            printf("error\n");
        }
    }else if(i == 1){
        if(right<=ListSize-1){
            x = this->elem[right];
            right++;
        }else{
            printf("error\n");
        }
    }else{
        printf("不合法\n");
    }
    return x;
}

void Stack_two::show() {
    cout<<"左栈为：";
    for(int i = 0;i<left;i++){
        printf("%d ",elem[i]);
    }
    printf("\n右栈为:");
    for(int i = ListSize-1;i>right;i--){
        printf("%d ",elem[i]);
    }
}

//3-16


//3-17
int Judge(string s){
    int t = s.length();
    const char* str = s.data();
    if(str[t-1]!='@'){
        printf("输入错误!");
        return -1;
    }else{
        int left = 0,right = t-2;
        while(left < right){
            if(str[left]==str[right] && str[left] != '&' ){
                left++;
                right--;
            }else if(str[left]!=str[right]){
                return -1;
            }
        }
        if(str[left] == '&' ){
            return 1;
        }else{
            return -1;
        }
    }
}

//3-18
bool Judge_kuohao(string s){
    stack<char> stk;
    for(int i = 0 ; i < s.length(); i++){
        char ch = s[i];
        if(ch == '(' || ch == '['){
            stk.push(ch);
        }else if(ch == ')') {
            if (stk.top() == '('  && !stk.empty()) {
                stk.pop();
            } else {
                return false;
            }
        }else if(ch == ']') {
            if (stk.top() == '[' && !stk.empty()) {
                stk.pop();
            } else {
                return false;
            }
        }
    }
    return stk.empty();
}

//3-19
bool Judge_3(string s){
    stack<char> stk;
    for(int i = 0 ; i < s.length(); i++){
        char ch = s[i];
        if(ch!='(' && ch !=')' && ch!='[' && ch!=']' && ch!='{' && ch!='}'){
            continue;
        }else{
            if(ch == '(' || ch == '[' || ch == '{'){
                stk.push(ch);
            }else if(ch == ')'){
                if('(' == stk.top()  && !stk.empty()){
                    stk.pop();
                } else{
                    return false;
                }
            }else if(ch == '}'){
                if('{' == stk.top()  && !stk.empty()){
                    stk.pop();
                } else{
                    return false;
                }
            } else if(ch == ']'){
                if('[' == stk.top()  && !stk.empty()){
                    stk.pop();
                } else{
                    return false;
                }
            }
        }
    }
    return stk.empty();
}

//3-20
//3-21 3-22
int Change(string s){
    stack<char> st1;
    stack<int> st2;
    bool key = true;
    for(int i = 0  ; i< s.length();i++){
        char ch = s[i];
        if(ch == ' '){
            continue;
        } else if(ch>='0' && ch <='9'){
            if(key){
                st2.push(ch - '0');
                key = false;
            }else{
                return -1;
            }
        }else if(ch == '+' || ch == '-' || ch == 'x' || ch == '/'){
            if((ch == '+' || ch == '-') && (st1.top() == 'x' || st1.top() == '/')){
                switch(st1.top()) {
                    case 'x':{
                        int n1, n2;
                        if (!st2.empty()) {
                            n1 = st2.top();
                            st2.pop();
                        } else {
                            return -1;
                        }
                        if (!st2.empty()) {
                            n2 = st2.top();
                            st2.pop();
                        } else {
                            return -1;
                        }
                        int m = n1 * n2;
                        st2.push(m);
                        break;
                    }
                    case '/':{
                        int n1, n2;
                        if (!st2.empty()) {
                            n1 = st2.top();
                            st2.pop();
                        } else {
                            return -1;
                        }
                        if (!st2.empty()) {
                            n2 = st2.top();
                            st2.pop();
                        } else {
                            return -1;
                        }
                        int m = n2 / n1;
                        st2.push(m);
                        break;
                    }
                }
            }
            key = true;
        }
    }
    while(!st1.empty()){
        char ch = st1.top();
        st1.pop();
        switch(ch) {
            case '+': {
                int n1, n2;
                if (!st2.empty()) {
                    n1 = st2.top();
                    st2.pop();
                } else {
                    return -1;
                }
                if (!st2.empty()) {
                    n2 = st2.top();
                    st2.pop();
                } else {
                    return -1;
                }
                int m = n1 + n2;
                st2.push(m);
                break;
            }
            case '-': {
                int n1, n2;
                if (!st2.empty()) {
                    n1 = st2.top();
                    st2.pop();
                } else {
                    return -1;
                }
                if (!st2.empty()) {
                    n2 = st2.top();
                    st2.pop();
                } else {
                    return -1;
                }
                int m = n2 - n1;
                st2.push(m);
                break;
            }
        }
    }
    if(st2.size()==1){
        return st2.top();
    }else{
        return -1;
    }
}
//3-24
int g(int m,int n){
    if(m == 0 && n >= 0){
        return 0;
    }else if(m>0 && n>=0){
        return g(m-1,2*n) + n;
    }else{
        cerr<<"something wrong"<<endl;
        exit(-1);
    }
}

//3-25
int F(int n){
    if(n == 0){
        return 1;
    }else if(n>0){
        return n*F(n/2);
    }else{
        cerr<<"something wrong"<<endl;
        exit(-1);
    }
}

int main() {
    string s = "(a+b)(";
    cout<<Judge_3(s);
    return 0;
}

#include <iostream>
#include <math.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
using namespace std;
typedef int ElemType;
typedef struct {
    ElemType *elem;
    int length;
    int listsize;
}SqList;

typedef struct Node{
    ElemType data;
    Node *next;
}LNode,*LinkList;

//2-10
int DeleteK(SqList &L,int i,int k){
    if(i < 1 || k < 0 || i + k >L.length){
        return -1;
    }
    int g = 0;
    for(int j = i+k;j<L.length;j++){
        L.elem[j - k] = L.elem[j];
        g++;
    }
    L.length-=g;
    return 1;
}

//2-11
int Insert(SqList &L,ElemType e,int NO){
    if(L.length >= L.listsize){
        L.listsize++;
        L.elem =(ElemType*) realloc(L.elem,sizeof (ElemType) * L.listsize);
        if(L.elem == NULL){
            printf("扩容失败！\n");
            return -1;
        }
        L.length++;
    }
    for(int i = L.length ; i > NO;i--){
        L.elem[i] = L.elem[i-1];
    }
    L.elem[NO] = e;
    return 1;
}

//2-12
int Compare(SqList &A, SqList &B){
    int a = A.length , b = B.length , x = 0 , y = 0;
    while(x<a && y<b){
        if(A.elem[x]>B.elem[y]){
            return 1;
        }else if(A.elem[x] < B.elem[y]){
            return -1;
        }
        ++x;
        ++y;
    }
    if(x == a && y == b){
        return 0;
    }else if(x!=a){
        return -1;
    } else{
        return 1;
    }
}

//2-14
int LinkList_Length(LinkList L){
    LNode *p = L;
    int t = 0;
    while(p!=NULL){
        t++;
        p = p->next;
    }
    return t;
}

//2-15
int DeleteAndInsert(LinkList La,LinkList Lb,int i,int j,int len){
    if(i < 0 || j < 0 || len < 0 || i>= LinkList_Length(La) || j>= LinkList_Length(Lb) || i+len>= LinkList_Length(La)){
        return -1;
    }
    LNode *p = new LNode;
    p->data = 0;
    p->next = La;
    int t = 1;
    while(t<i){
        p = p->next;
        ++t;
    }
    LNode *q = new LNode ;
    q->data = 0;
    q->next = Lb;
    t = 1;
    while(t<j){
        q = q->next;
        t++;
    }
    LNode *s = q->next;
    q->next = p->next;
    t = 0;
    LNode *o = p;
    for(int e = 0;e < len ; e++){
        o = o->next;
    }
    p->next = o->next;
    o->next = s;
}

//2-17
void Link_Insert(LinkList L,int i ,int b){
    LNode *p = new LNode ;
    p->data = 0;
    p->next = L;
    LNode *o = new LNode ;
    o->data = b;
    o->next = NULL;
    for(int h = 1;h<i;h++){
        p = p->next;
    }
    o->next = p->next;
    p->next = o;
}

//2-18
void Link_Delete(LinkList L,int i){
    if(LinkList_Length(L) <= i){
        LNode *p = new LNode ;
        p->data = 0;
        p->next = L;
        for(int t = 1;t<i;t++){
            p = p->next;
        }
        p->next = p->next->next;
    }else{
        printf("错误");
    }
}

//2-19
void Link_delete_middle(LinkList L,int min,int max){
    LNode *head = new LNode ;
    head->data = 0;
    head->next = L;
    LNode *p = head->next;
    while(p!=NULL) {
        if (p->data > min && p->data < max) {
            head->next = p->next;
            LNode *q = p;
            head = head->next;
            p = p->next;
            free(q);
        } else {
            head = head->next;
            p = p->next;
        }
    }
}

//2-20
void Link_delete_common(LinkList L){
    LNode *head = L;
    LNode *p = head->next;
    while(p!=NULL){
        if(head->data == p->data){
            head->next = p->next;
            p = p->next;
        }else{
            head = head->next;
            p = p->next;
        }
    }
}

//2-21
void SqList_Reverse(SqList &L){
    int left = 0,right = L.length-1;
    while(left < right){
        int t = L.elem[left];
        L.elem[left] = L.elem[right];
        L.elem[right] = t;
        left++;
        right--;
    }
}

//2-22
LinkList Link_Reverse(LinkList L){
    LNode *p = L;
    LNode *head = NULL ;
    while(p != NULL){
        LNode *q = p;
        p = p->next;
        q->next = head;
        head = q;
    }
    return head;
}

//2-23
SqList he_bing(SqList &A,SqList &B){
    int m = A.length , n = B.length;
    if(m<=n){
        SqList C = A;
        A = B;
        B = C;
        m = A.length;
        n = B.length;
    }
    for(int i = 0;i<n;i++){
        A.elem[i] = B.elem[i];
    }
    return A;
}

LinkList I_know(LinkList A,LinkList B){
    LNode *p = A->next, *q = B->next;
    LNode *head = A;
    while(p != NULL && q != NULL){
        if(p->data > q->data){
            head->next = q;
            head = head->next;
            q = q->next;
        }else{
            head->next = p;
            head = head->next;
            p = p->next;
        }
    }
    if(p!=NULL){
        head->next = p;
    }
    if(q!=NULL){
        head->next = q;
    }
    head = Link_Reverse(A);
    return head;
}

//2-24
SqList SqList_heji(SqList &A,SqList &B){
    int a = A.length,b = B.length;
    int *c = new int[min(a,b)];
    int n = 0,m = 0,t = 0;
    while(n < a&& m <b){
        if(A.elem[n]>B.elem[m]){
            m++;
        }else if(A.elem[n]<B.elem[m]){
            n++;
        }else{
            c[t] = A.elem[n];
            n++;
            m++;
            t++;
        }
    }
    SqList *C = new SqList;
    C->elem = c;
    C->length = t;
    C->listsize = 100;
    return *C;
}

LinkList Link_heji(LinkList A,LinkList B){
    LNode *p = A->next , *q = B->next;
    int t = 0;
    LNode *r = new LNode ;
    r->next = NULL;
    r->data = 0;
    LNode *head = r;
    while(p != NULL && q !=NULL){
        if(p->data > q->data){
            q = q->next;
        }else if(p->data < q->data){
            p = p->next;
        }else{
            r->next = p;
            p=p->next;
            q =q->next;
            r = r->next;
        }
    }
    return head;
}
int main() {
    return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
};

//输出头指针之后的所有节点 
void ListShow(ListNode *tail){
	ListNode *p = tail->next;//p指向头节点 
	ListNode *q = p->next; //q指向首个有意义的节点； 
	while(q!=p){
		printf("%d\n",q->val);
		q = q->next;
	}
}

//输入尾节点，从头指针输出的，验证是否为循环链表 
void show(ListNode *tail){
	ListNode *p = tail->next;
	while(p!=tail){
		printf("%d ",p->val);
		p = p->next;
	}
	printf("%d  ",p->val);
	p = p->next;
	printf("%d\n",p->val);
}

//La,Lb是尾指针 
void SortList(ListNode *La,ListNode *Lb){
	ListNode *p = La->next->next,*q = Lb->next->next,*t = La->next;
	//t的作用是重新串联起整个链表 
	while(p!=La->next && q!=Lb->next){
		if(p->val<q->val){
			t->next = p;
			p = p->next;
			t = t->next;
		}else if(p->val > q->val){
			t->next = q;
			q = q->next;
			t = t->next;
			//t->next = p;//t实际上是用来重新规划链表的路径的，不需要在结束时更改t的next，因为每个操作开始之前都会进行这一步
			//这一步加上后相当于并未对Lb链表进行修改？ 
		}else{
			p = p->next;
			q = q->next;
			t = t->next;
		}
	}
	if(q!=Lb->next){
		t->next = q;
		Lb->next = p;
		t = Lb;  
	}else{
		t->next = p;
		t=La;
	}
	ListShow(t);
	//show(La);
	//show(Lb);//最后t指向Lb？ 
	//La,Lb无法改变？ 
}


int main(){
	cout<<"请输入一段数字作为第一个链表La(输入999结束,请输入-998~998的数)"<<endl;
	ListNode *La = new ListNode;//设置La为头结点
	La->val = 999;
	La->next = NULL;
	ListNode *p = La;
	int f,o = -999;
	while(1){
		scanf("%d",&f);
		if(f>=999||f<=-999){
			printf("我都不知道怎么说你了，毁灭吧，赶紧的\n");
			return 0;
		}
		char key = getchar();
		if((key>'9'||key<'0') && key != ' ' && key != '\n' && key != '\r'){
			printf("叫你不按正常输，再次启动吧！GG");
			return 0; 
		} 
		if(f==999){
			p->next = La;
			La = p;
			break;
		}
		if(o>f){
			printf("不讲武德，还偷袭！\n");
			return 0;
		}
		ListNode *l = new ListNode;
		l->val = f;
		l->next = NULL;
		p->next = l;
		p = p->next;
		o = f;
	}
	ListShow(La);
	
	cout<<"请输入一段数字作为第二个链表Lb（输入999结束,请输入-998~998的数）"<<endl;
	ListNode *Lb = new ListNode;//设置Lb为头结点； 
	Lb->val = 999;
	Lb->next = NULL;
	ListNode *q = Lb;
	o = -999;
	while(1){
		scanf("%d",&f);
		if(f>=999||f<=-999){
			printf("我都不知道怎么说你了，毁灭吧，赶紧的\n");
			return 0;
		}
		char key = getchar();
		if((key>'9'||key<'0') && key != ' ' && key != '\n' && key != '\r'){
			printf("叫你不按正常输，再次启动吧！GG");
			return 0; 
		} 
		if(f==999){
			q->next = Lb;
			Lb = q;
			break;
		}
		if(o>f){
			printf("不讲武德，还偷袭！\n");
			return 0;
		}
		ListNode *l = new ListNode;
		l->val = f;
		l->next = NULL;
		q->next = l;
		q = q->next;
		o = f;
	}
	ListShow(Lb);
	printf("\n");
	
	show(La);
	show(Lb);
	
	SortList(La,Lb);
	printf("\n");
	return 0;
	
}


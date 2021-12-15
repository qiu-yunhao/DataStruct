#include <iostream>
#include <stdio.h>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
};

//���ͷָ��֮������нڵ� 
void ListShow(ListNode *tail){
	ListNode *p = tail->next;//pָ��ͷ�ڵ� 
	ListNode *q = p->next; //qָ���׸�������Ľڵ㣻 
	while(q!=p){
		printf("%d\n",q->val);
		q = q->next;
	}
}

//����β�ڵ㣬��ͷָ������ģ���֤�Ƿ�Ϊѭ������ 
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

//La,Lb��βָ�� 
void SortList(ListNode *La,ListNode *Lb){
	ListNode *p = La->next->next,*q = Lb->next->next,*t = La->next;
	//t�����������´������������� 
	while(p!=La->next && q!=Lb->next){
		if(p->val<q->val){
			t->next = p;
			p = p->next;
			t = t->next;
		}else if(p->val > q->val){
			t->next = q;
			q = q->next;
			t = t->next;
			//t->next = p;//tʵ�������������¹滮�����·���ģ�����Ҫ�ڽ���ʱ����t��next����Ϊÿ��������ʼ֮ǰ���������һ��
			//��һ�����Ϻ��൱�ڲ�δ��Lb��������޸ģ� 
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
	//show(Lb);//���tָ��Lb�� 
	//La,Lb�޷��ı䣿 
}


int main(){
	cout<<"������һ��������Ϊ��һ������La(����999����,������-998~998����)"<<endl;
	ListNode *La = new ListNode;//����LaΪͷ���
	La->val = 999;
	La->next = NULL;
	ListNode *p = La;
	int f,o = -999;
	while(1){
		scanf("%d",&f);
		if(f>=999||f<=-999){
			printf("�Ҷ���֪����ô˵���ˣ�����ɣ��Ͻ���\n");
			return 0;
		}
		char key = getchar();
		if((key>'9'||key<'0') && key != ' ' && key != '\n' && key != '\r'){
			printf("���㲻�������䣬�ٴ������ɣ�GG");
			return 0; 
		} 
		if(f==999){
			p->next = La;
			La = p;
			break;
		}
		if(o>f){
			printf("������£���͵Ϯ��\n");
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
	
	cout<<"������һ��������Ϊ�ڶ�������Lb������999����,������-998~998������"<<endl;
	ListNode *Lb = new ListNode;//����LbΪͷ��㣻 
	Lb->val = 999;
	Lb->next = NULL;
	ListNode *q = Lb;
	o = -999;
	while(1){
		scanf("%d",&f);
		if(f>=999||f<=-999){
			printf("�Ҷ���֪����ô˵���ˣ�����ɣ��Ͻ���\n");
			return 0;
		}
		char key = getchar();
		if((key>'9'||key<'0') && key != ' ' && key != '\n' && key != '\r'){
			printf("���㲻�������䣬�ٴ������ɣ�GG");
			return 0; 
		} 
		if(f==999){
			q->next = Lb;
			Lb = q;
			break;
		}
		if(o>f){
			printf("������£���͵Ϯ��\n");
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


#include <stdio.h>
#include <stdlib.h>
#define LIST_MAX_SIZE  100	//�ռ��ʼ��С
#define OK 1
#define ERROR 0

typedef int ElemType;    	//Ԫ�ص���������
typedef int Status;			//״̬����������ֵ 
typedef struct {
// 	ElemType elem[ LIST_MAX_SIZE ]; // �洢�ռ�
   	ElemType * elem; 	// �洢�ռ�
  	int  length;        // ��ǰԪ�ظ���
  	int  listsize;		// �ܹ���������Ԫ������ 
} SqList;

// ����Ϊ����ԭ�� 
Status InitList( SqList & );
Status ListInsert( SqList &, int, ElemType );	//������Ҫ���д�Ļ������� 
Status GetElem( SqList, int, ElemType & );	//������Ҫ���д�Ļ������� 
int	   ListLength( SqList );		//������Ҫ�����д�Ļ�����
Status ListTraverse( SqList &, void (*)( ElemType ) );
void   ListUnion( SqList &, SqList );
void   out( ElemType );
int    equal(ElemType, ElemType ); 
Status LocateElem(SqList, ElemType, Status (*)(ElemType,ElemType));

// ����Ϊ��������
Status InitList( SqList & L ) 	// ����һ���յ����Ա� L
{
	L.elem = (ElemType *)malloc(LIST_MAX_SIZE*sizeof(ElemType));
//  if ( !L.elem )	exit(-1);	// ʧ������ֹ���� 
  	L.length 	= 0;   			// �ձ���Ϊ0
  	L.listsize 	= LIST_MAX_SIZE;
  	return OK;
}

Status ListTraverse( SqList &L, void (*visit)( ElemType ) )
{	// ���ζ�L��ÿ��Ԫ�ص��ú���visit()����visit()ʧ�ܣ������ʧ��
	int i, L_len = ListLength( L );
	ElemType e;
	
	for ( i = 1;  i <= L_len; i++ )  {
    	GetElem(L, i, e);
    	(*visit)( e );
	}
  	return OK;
}

int equal(ElemType x, ElemType y)
{
	return x==y;
}

Status LocateElem( SqList L, ElemType e,
 				   Status (*compare)(ElemType,ElemType) )
{	//��L�в�����Ԫ�� e ����compare() �ĵ� 1 ��Ԫ��
	//���� L �е� 1 ���� e �����ϵcompare( ) ��Ԫ�ص�λ��
	int i = 1;
	ElemType * p;
    while ( i<=L.length )  //
	   	if  ( (*compare)(e,L.elem[i-1]) ) break;
		else  i++;
    if ( i <= L.length ){
        return i;
		}  // �ҵ� e������λ��i
    else{
        return 0;		//��û���ҵ����򷵻�0
	}
}

void out( ElemType e )
{
	printf("%d,", e);
}

void ListUnion( SqList &La,  SqList Lb ) //�� A��A��B
{
	int La_len, Lb_len, i;
	ElemType e;
 
	La_len = ListLength( La );       // �����Ա�ĳ���
	Lb_len = ListLength( Lb );
	for ( i = 1;  i <= Lb_len;  i++ )  {
    	GetElem(Lb, i, e);  // ȡLb�е�i������Ԫ�ظ���e
    	//if ( !LocateElem(La,e,))
	}
}

Status ListInsert( SqList &L, int Number, ElemType e){
	if(L.length>=L.listsize){
		L.elem = (ElemType *)realloc(L.elem, (LIST_MAX_SIZE+1)*sizeof(ElemType));
		L.listsize = MB_CUR_MAX + 1;
		if(!L.elem) exit(-1);		
	}
	int len = L.length;
	ElemType *q = L.elem + Number -1;
	for(ElemType *p = &L.elem[len-1];p>=q;p--){
		*(p+1) = *p;
	}
	*q = e;
	L.length++;
		
	return OK;
} 
Status GetElem( SqList L, int Number, ElemType &e ){
	ElemType *p = L.elem + Number - 1;
	e = *p;
	return OK;
}	 
int	ListLength(SqList L){
	return 	L.length;
}	//������Ҫ�����д�Ļ�����

int main(){
	int i;
	SqList L;
	InitList(L);
	int l = ListLength(L);
	printf("%d\n",l);
	ElemType t = 2;
	for( i = 1;i<=101;i++){
		ListInsert(L,i,i);
	}
	l = ListLength(L);
	printf("%d\n",l);
	for(i = 1;i<=101;i++){
		ElemType e;
		GetElem(L,i,e);
		out(e);
	}
	return 0;

}

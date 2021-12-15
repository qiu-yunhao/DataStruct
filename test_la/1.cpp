#include <stdio.h>
#include <stdlib.h>
#define LIST_MAX_SIZE  100	//空间初始大小
#define OK 1
#define ERROR 0

typedef int ElemType;    	//元素的数据类型
typedef int Status;			//状态。函数返回值 
typedef struct {
// 	ElemType elem[ LIST_MAX_SIZE ]; // 存储空间
   	ElemType * elem; 	// 存储空间
  	int  length;        // 当前元素个数
  	int  listsize;		// 能够保存的最大元素数量 
} SqList;

// 以下为函数原型 
Status InitList( SqList & );
Status ListInsert( SqList &, int, ElemType );	//这是需要你编写的基本操作 
Status GetElem( SqList, int, ElemType & );	//这是需要你编写的基本操作 
int	   ListLength( SqList );		//这是需要你编作写的基本操
Status ListTraverse( SqList &, void (*)( ElemType ) );
void   ListUnion( SqList &, SqList );
void   out( ElemType );
int    equal(ElemType, ElemType ); 
Status LocateElem(SqList, ElemType, Status (*)(ElemType,ElemType));

// 以下为函数定义
Status InitList( SqList & L ) 	// 建立一个空的线性表 L
{
	L.elem = (ElemType *)malloc(LIST_MAX_SIZE*sizeof(ElemType));
//  if ( !L.elem )	exit(-1);	// 失败则终止程序 
  	L.length 	= 0;   			// 空表长度为0
  	L.listsize 	= LIST_MAX_SIZE;
  	return OK;
}

Status ListTraverse( SqList &L, void (*visit)( ElemType ) )
{	// 依次对L的每个元素调用函数visit()。若visit()失败，则操作失败
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
{	//在L中查找与元素 e 满足compare() 的第 1 个元素
	//返回 L 中第 1 个与 e 满足关系compare( ) 的元素的位序
	int i = 1;
	ElemType * p;
    while ( i<=L.length )  //
	   	if  ( (*compare)(e,L.elem[i-1]) ) break;
		else  i++;
    if ( i <= L.length ){
        return i;
		}  // 找到 e，返回位序i
    else{
        return 0;		//若没有找到，则返回0
	}
}

void out( ElemType e )
{
	printf("%d,", e);
}

void ListUnion( SqList &La,  SqList Lb ) //求 A＝A∪B
{
	int La_len, Lb_len, i;
	ElemType e;
 
	La_len = ListLength( La );       // 求线性表的长度
	Lb_len = ListLength( Lb );
	for ( i = 1;  i <= Lb_len;  i++ )  {
    	GetElem(Lb, i, e);  // 取Lb中第i个数据元素赋给e
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
}	//这是需要你编作写的基本操

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

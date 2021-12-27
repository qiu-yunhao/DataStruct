#include <stdio.h>
#define M 10000
int what_is_your_name(int k,int m){
	int a[M] = {0};
	a[k-1] = 1;
	for(int i = k;i<m;i++){
		for(int j = 1;j<=k;j++){
			a[i]+=a[i-j];
		}
	}
	return a[m-1];
}
int main(){
	int m,n;
	printf("请输入阶数");
	scanf("%d",&m);
	printf("请输入第几个");
	scanf("%d",&n);
	int t = what_is_your_name(m,n);
	printf("%d",t);
	return 0;
} 

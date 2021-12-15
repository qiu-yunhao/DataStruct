#include <stdio.h>
#include <math.h>
int main(){
	int n,x;
	scanf("%d %d",&x,&n);
	if(n>10){
		printf("球球了，我不想用malloc！");
		return 0;
	}
	int a[10] = {0};
	int m,sum = 0;
	for(int i = 0;i<n;i++){
		scanf("%d",&m);
		sum += m*pow(x,i);
	}
	printf("%d",sum);
	return 0;
}

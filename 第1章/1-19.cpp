 #include <stdio.h>
int main(){
	int a[10] = {0},n;
	a[1] = 2;
	scanf("%d",&n);
	if(n>=10||n<1){
		printf("³ö´í");
		return 0;
	}
	for(int i = 2;i<10;i++){
		a[i] = a[i-1] * 2 * i;
	
	}
	printf("%d\n",a[n-1]);
	return 0;
} 

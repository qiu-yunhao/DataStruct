#include <iostream>
void divide(int *arr,int n,int left,int *temp);
void sort(int *arr,int *temp, int n, int left ,int mid ,int right);
void mergeSort(int *arr , int n);

int main(){
    int a[] = {1,9,5,4,8,3,2,6,7,0};
    int n = sizeof(a)/sizeof(a[0]);
    mergeSort(a,10);
    for(int i = 0; i < n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
//归并排序的分阶段，左闭右开
void divide(int *arr,int n,int left,int right,int *temp){
    if(left + 1 < right){//分的思想
        int mid = (left + right)>>1;
        divide(arr,n,left,mid,temp);
        divide(arr,n,mid,right,temp);
        sort(arr,temp,n,left,mid,right);//合并并排序
    }

}

void mergeSort(int *arr,int n){
    int *temp = new int[n];
    divide(arr,n,0,n,temp);
}

void sort(int *arr,int *temp, int n, int left ,int mid ,int right){
    int l = left,r = mid,t = 0;
    while(l < mid && r < right ){
        if(arr[l] <= arr[r]){
            temp[t++] = arr[l++];
        }else{
            temp[t++] = arr[r++];
        }
    }
    while(l < mid){
        temp[t++] = arr[l++];
    }
    while(r < right){
        temp[t++] = arr[r++];
    }
    for(int i = 0 ; i < t;i++){
        arr[left + i] = temp[i];
    }
}
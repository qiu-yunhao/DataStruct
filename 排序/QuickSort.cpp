#include <iostream>
void qucikSort(int *arr,int n,int left,int right);

int main(){
    int a[] = {2,6,3,0,7,1,9,4,5,8};
    int n = sizeof(a)/sizeof(a[0]);
    qucikSort(a,n,0,n);
    for(int i = 0 ; i < n; i++){
        printf("%d ",a[i]);
    }
    return 0;
}

void qucikSort(int *arr,int n,int left,int right){
    if(left >= right){
        return;
    }
    int key = arr[left];
    int l = left , r = right - 1;
    while(l < r){
        while(r > l){
            if(arr[r] < key){
                arr[l] = arr[r];
                break;
            }
            r--;
        }
        while(r > l){
            if(arr[l] > key){
                arr[r] = arr[l];
                break;
            }
            l++;
        }
    }
    arr[l] = key;
    qucikSort(arr,n,left,l);
    qucikSort(arr,n,l+1,right);
}
#include <iostream>

void heapSort(int *arr,int n);
void createBigHeap(int *arr,int n);

int main(){
    int a[] = {1,5,7,3,6,4,8,2,9,0};
    int n = sizeof(a)/sizeof(a[0]);
    heapSort(a,n);
    for(int i = 0 ; i < n; i++){
        printf("%d ",a[i]);
    }
    return 0;
}

void heapSort(int *arr,int n){
    for(int i = n; i > 0; i--){
        printf("第%d趟为:",n - i + 1);
        createBigHeap(arr,i);
        printf("\n");
    }
}

void createBigHeap(int *arr,int n){
    int t = n/2 - 1;//选择最后所构成的大顶堆的最后一个非叶子节点
    for(int i = t ; i >= 0 ;i--){
        int child_left = 2 * i + 1;
        int child_right = 2 * i + 2;
        if(child_right == n){//判断有没有右孩子
            if(arr[child_left] > arr[i]){//没有直接比较父节点与左孩子
                int c = arr[child_left];
                arr[child_left] = arr[i];
                arr[i] = c;
            }
        }else{//有的话就选取左右节点中较大的那一个与父节点比较
            int max = arr[child_left] > arr[child_right] ? child_left : child_right;
            if(arr[max] > arr[i]){
                int c = arr[max];
                arr[max] = arr[i];
                arr[i] = c;
            }
        }
    }
    int g = arr[0];
    arr[0] = arr[n-1];
    arr[n-1] = g;
    for(int i = 0 ; i < n; i++){
        printf("%d ",arr[i]);
    }
}


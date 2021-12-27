#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

void digui(int *ans,int left,int right,int *nums,int start,int end){
    if(right == left){//当左右相等时进行符合要求，进行判断
       *ans = max(*ans,left);//将符合两边相等的数据与之前的符合要求的最大数据比较,保留最大者
    }
    if(start == end){
        return;//当start等于end时，数组已经遍历完了，结束，退出递归
    }
    int t = nums[start];//选定了下标为start的那个石柱的高度
    left = left + t;//将其放入左堆
    digui(ans,left,right,nums,start + 1,end);//在上一步的基础上继续考虑下一个
    left = left - t;//恢复放入之前的状态
    right = right + t;//将其放入右堆
    digui(ans,left,right,nums,start + 1,end);//在上一步的基础上继续考虑下一个
    right = right - t; //恢复放入之前的状态 
    digui(ans,left,right,nums,start + 1,end);//考虑不放入的情况
}

int main(){
    printf("请输入石块的个数：\n");
    int n = 0;
    scanf("%d", &n);
    int* nums = new int[n];
    printf("请输入各个石块的高度\n");
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &nums[i]);
    }
    int ans = 0;
    clock_t t1,t2;
    digui(&ans,0,0,nums,0,n);
    printf("答案是：%d\n",ans);
    return 0;
}
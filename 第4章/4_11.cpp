#include "StringType.cpp"

void Search(StringType s , StringType t);

int main(){
    char s1[] = "ashdkjewhbfkzxiofewnkch", s2[] = "wqioenmdshv";
    StringType *s = new StringType(s1);
    StringType *t = new StringType(s2);
    Search(*s, *t);
    return 0;
}

void Search(StringType s, StringType t){
    char *str1 = s.c_str();
    char *str2 = t.c_str();
    int len1 = strlen(str1) ,len2 = strlen(str2);
    int *num = new int[26];
    for(int i = 0 ; i< len2 ; i++){
        num[str2[i] - 'a']++;
    }
    char *ans = new char[len1+1];
    int k = 0;
    for(int i = 0 ; i < len1 ; i++){
        int t = str1[i] - 'a';
        if(num[t] == 0){
            ans[k++] = str1[i];
        }
    }
    
    int *res = new int[k];
    for(int j = 0; j< k;j++){
        for(int i = 0; i < len1; i++){
            if(str1[i] == ans[j]){
                res[j] = i + 1;
            }
        }
    }
    

    for(int i = 0 ; i < k; i++){
        printf("%d\n",res[i]);
    }
}
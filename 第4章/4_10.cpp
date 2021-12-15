#include "StringType.cpp"

StringType Reverse_String1(StringType s);//递推
StringType Reverse_String2(const StringType &s,int first ,int last);//递归

int main(){
    char str[] = "123456";
    StringType *t = new StringType(str);
    printf("%s\n",Reverse_String1(*t).c_str());
    return 0;
}
StringType Reverse_String1(StringType s){
    int n = strlen(s.c_str());
    char *p = new char[n+1];
    for(int i = 0 ; i < n;i++){
        p[i] = s.c_str()[n-1-i];
    }
    StringType *st = new StringType(p);
    return *st;
}

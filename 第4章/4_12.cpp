#include "StringType.cpp"

void Replace(StringType &s,char a,char b);

int main(){
    char c[] = "1234567111";
    StringType * t = new StringType(c);
    Replace(*t,'1','2');
    printf("%s\n",t->c_str());
}

void Replace(StringType &s,char a,char b){
    char *str = s.c_str();
    for(int i = 0 ; i< s.StrLength() ; i++){
        if(a == str[i]){
            str[i] = b;
        }
    }
}
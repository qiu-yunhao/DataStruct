#include <iostream>
#include <string.h>
using namespace std;

class StringType{
    private:
        char *s;
        int len;
    public:
        StringType();
        StringType(char *c);
        void StrAssign(StringType &t,StringType s);
        int StrCompare(StringType s,StringType t);
        int StrLength();
        char* c_str();
        StringType Concat(StringType s,StringType t);
        StringType subString(StringType s,int start,int end);
};

StringType::StringType(){
    this->s = NULL;
    this->len = 0;
}
StringType::StringType(char *c){
    len = strlen(c);
    char *str = new char[len];
    strcpy(str,c);
    this->s = str;
}

char* StringType::c_str(){
    return this->s;
}

void StringType::StrAssign(StringType &t,StringType s){
    t.len = strlen(s.c_str());
    char *str = new char[t.len];
    strcpy(str,s.c_str());
    t.s = str;
}

int StringType::StrCompare(StringType s,StringType t){
    return strcmp(s.c_str(),t.c_str());
}

int StringType::StrLength(){
    return this->len;
}

StringType StringType::Concat(StringType s,StringType t){
    this->len = strlen(s.c_str()) + strlen(t.c_str());
    char *str = new char[len];
    strcpy(str,s.c_str());
    strcpy(str + s.StrLength(),t.c_str());
    this->s = str;
    return *this; 
}

StringType StringType::subString(StringType s,int start,int end){
    char *p = s.c_str() + start - 1;
    char *t = new char[end - start + 2];
    for(int i = 0 ; i < end - start ; i++){
        *(t+i) = *(p + i);
    }
    this->s = t;
    this->len = end - start + 1;
    return *this;
}

    
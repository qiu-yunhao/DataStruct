#include <iostream>
using namespace std;
int main(){
	int x,y,z;
	cin>>x>>y>>z;
	if(x<y){
		int t = x;
		x = y;
		y = t;
	}
	if(x<z){
		int t = x;
		x = z;
		z = t;
	}
	if(y<z){
		int t = y;
		y = z;
		z = t;
	}
	cout<< "最大是"<<x <<endl <<"次大是"<< y <<endl <<"最小是" << z<<endl;
	return 0;
}

#include<iostream>

using namespace std;

int main(){
	int num[20];
	num[0]=num[1]=num[2]=1;
	for(int i=3;i<20;i++) num[i]=num[i-1]+num[i-3];
	cout<<"1-20年奶牛的数目：";
	for(int i=0;i<20;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}

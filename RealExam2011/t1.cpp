#include<iostream>
#include<string> 
#include<cstdio>

using namespace std;

//判断整型n是否回文 
bool charge(int n){
	char s[10];
	sprintf(s,"%d",n);
	string str="";
	str+=s;
	bool isok=true;
	for(int i=0,size=str.size(),k=size-1;i<size/2;i++,k--){
		if(str[i]!=str[k]){
			isok=false;
			break;
		}
	}
	return isok;
}

int main(){
	for(int i=1;i<256;i++){
		if(charge(i*i)) cout<<i<<endl;
	}
	return 0;
}

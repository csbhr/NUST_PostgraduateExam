#include<iostream>
#include<cstdio>

using namespace std;

//将int类型转换为string 
string toString(int a){
	char s[10];
	sprintf(s,"%d",a);
	string str="";
	str+=s;
	return str;
}

//将十进制转换为二进制 
string TenToBin(long tenN){
	string binN="";
	while(tenN>0){
		int a=tenN%2;
		binN=toString(a)+binN;
		tenN/=2; 
	}
	return binN;
}

int main(){
	long a;
	cin>>a;
	cout<<TenToBin(a)<<endl;
	return 0;
} 

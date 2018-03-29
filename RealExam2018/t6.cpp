#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int stringToInt(string str){
	istringstream iss(str);
	int t;
	iss>>t;
	return t;
}

void func(int &count,string sou,int n){
	if(n==sou.length()){
		count++;
		return;
	}
	if(n>sou.length()) return;
	char temp=sou[n];
	string str=""; str+=temp;
	int a=stringToInt(str);
	if(a==0) return;
	if(a==1){
		func(count,sou,n+1);
		func(count,sou,n+2);
	}else if(a==2){
		char temp2=sou[n];
		string str2=""; str2+=temp2;
		int a2=stringToInt(str2);
		if(a2<=6){
			func(count,sou,n+1);
			func(count,sou,n+2);
		}else{
			func(count,sou,n+1);
		}
	}else{
		func(count,sou,n+1);
	}
}

int main(){
	string sou;
	getline(cin,sou);
	int count=0;
	func(count,sou,0);
	cout<<count<<endl;
	return 0;
} 

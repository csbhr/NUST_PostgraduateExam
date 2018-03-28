#include<iostream>

using namespace std;

int toInt(char c){
	string str="";
	str+=c;
	int a;
	sscanf(str.c_str(),"%d",&a);
	return a;
}

int doOdd(string str){
	int size=str.size();
	int sum=0;
	for(int i=size-1,k=1;i>=0;i--,k++){
		if(k%2!=0){
			sum+=toInt(str[i]);
		}
	} 
	return sum;
}

int doEven(string str){
	int size=str.size();
	int sum=0;
	for(int i=size-1,k=1;i>=0;i--,k++){
		if(k%2==0){
			int a=toInt(str[i]);
			a*=2;
			if(a>=10) a-=9;
			sum+=a;
		}
	}
	return sum;
}

int main(){
	string str;
	cin>>str;
	if(doOdd(str)==doEven(str)) cout<<"合法"<<endl;
	else cout<<"不合法"<<endl;
	return 0;
}

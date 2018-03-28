#include<iostream>

using namespace std;

#define M 13

//获得出栈序列个数
//卡特兰数公式 
int getCount(int n){
	int sum1=1,sum2=1;
	for(int i=0;i<n;i++){
		sum1*=(2*n-i);
		sum2*=(n-i);
	}
	return sum1/(sum2*(n+1));
}

//判断序列sou是否符合出栈规则 
bool isOk(char sou[M],int n){
	for(int i=0;i<n;i++){
		char buf[M];
		int top=-1;
		for(int j=i+1;j<n;j++){
			if(sou[j]<sou[i]) buf[++top]=sou[j];
		}
		for(int j=0;j<top;j++){
			if(buf[j]<buf[j+1]) return false;
		}
	}
	return true;
}

//判断c是否在序列sou中 
bool isSame(char sou[M],int n,char c){
	for(int i=0;i<n;i++){
		if(sou[i]==c) return false;
	}
	return true;
}

//递归，遍历不重复的N位序列，并判断是否符合出栈规则，符合就输出 
void func(char sou[M],int n,int N){
	if(n==N){
		if(isOk(sou,n)){
			for(int i=0;i<n;i++){
				cout<<sou[i];
			}
			cout<<endl;
		}
		return;
	}
	for(int i=0;i<N;i++){
		char temp='a'+i;
		if(isSame(sou,n,temp)){
			sou[n]=temp;
			func(sou,n+1,N);
		}
	}
}

int main(){
	int n;
	cin>>n;
	char sou[M];
	
	//输出出栈序列的个数 
	int count=getCount(n);
	cout<<count<<endl;
	
	//递归输出出栈序列 
	func(sou,0,n);
	
	return 0;
}

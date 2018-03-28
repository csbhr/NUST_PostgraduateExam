#include<iostream>

using namespace std;

#define M 1000

//判断素数 
bool isSu(int n){
	if(n<=1) return false;
	for(int i=2;i<n;i++){
		if(n%i==0) return false;
	}
	return true;
}

//获取n的所有质因数 
void getSuChild(int stack[M],int &top,int n){
	if(isSu(n)){
		stack[++top]=n;
		return;
	}
	for(int i=2;i<n;i++){
		if(isSu(i)&&n%i==0){
			stack[++top]=i;
			getSuChild(stack,top,n/i);
			break;
		}
	}
}

int main(){
	int stack[M],top=-1;
	int sou[M],stop=-1;
	int n;
	cin>>n;
	int flag=1;
	while(stop<n-1){
		top=-1;
		getSuChild(stack,top,flag);
		bool isok=true;
		for(int j=0;j<=top;j++){
			if(stack[j]!=2&&stack[j]!=3&&stack[j]!=5){
				isok=false;
				break;
			}
		}
		if(isok) sou[++stop]=flag;
		flag++;
	}
	cout<<sou[stop]<<endl;
	return 0;
}

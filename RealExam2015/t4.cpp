#include<iostream>

using namespace std;

#define M 10

//计算x=x+y 
void Multi(int x[M],int y[M]){
	int postIn=0;
	int i=0;
	while(y[i]!=0){
		int temp=x[i]+y[i]+postIn;
		x[i]=temp%10;
		postIn=temp/10;
		i++;
	}
	if(postIn!=0) x[i]=postIn;
}

int main(){
	int x[M],y[M];
	for(int i=0;i<M;i++){
		x[i]=0;
		y[i]=0;
	}
	int a,n;
	cin>>a>>n;
	for(int i=0;i<n;i++){
		y[i]=a;
		Multi(x,y);
	}
	//下面倒序输出x 
	int stack[M],top=-1;
	int flag=0;
	while(x[flag]!=0){
		stack[++top]=x[flag];
		flag++;
	}
	while(top!=-1) cout<<stack[top--];
	return 0;
}

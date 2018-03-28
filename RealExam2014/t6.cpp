#include<iostream>
#include<cmath>

using namespace std;

#define N 7
#define M 100

int getP(int x,int y){
	int sum=1;
	for(int i=0;i<y;i++){
		sum*=x;
	}
	return sum;
}

int getWei(int n,int s[M]){
	int stack[M],top=-1;
	while(n>0){
		stack[++top]=n%10;
		n=n/10;
	}
	int flag=0;
	while(top!=-1){
		s[flag++]=stack[top--];
	}
	return flag;
}

int main(){
	int s[M];
	int low=1,high=9;
	for(int i=0;i<N-1;i++) {
		low*=10;
		high=high*10+9;
	}
	for(int i=low;i<=high;i++){
		getWei(i,s);
		int sum=0;
		for(int j=0;j<N;j++) sum+=pow(s[j],N);
		if(i==sum) cout<<i<<endl;
	}
	return 0;
}

#include<iostream>

using namespace std;

#define M 10

void sort(int sou[],int begin,int end){
	if(begin>end) return;
	int be=begin,en=end;
	int temp=sou[be];
	while(be<en){
		while(sou[en]<=temp&&be<en) en--;
		sou[be]=sou[en];
		while(sou[be]>=temp&&be<en) be++;
		sou[en]=sou[be];
	}
	sou[be]=temp;
	sort(sou,begin,be-1);
	sort(sou,en+1,end);
}

int main(){
	int m;
	int sou[M][M];
	cin>>m;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cin>>sou[i][j];
		}
	}
	int stack[3*M],top=-1;
	//求每行元素之和 
	for(int i=0;i<m;i++){
		int sum=0;
		for(int j=0;j<m;j++){
			sum+=sou[i][j];
		}
		stack[++top]=sum;
	}
	//求每列元素之和 
	for(int i=0;i<m;i++){
		int sum=0;
		for(int j=0;j<m;j++){
			sum+=sou[j][i];
		}
		stack[++top]=sum;
	}
	//求对角线元素之和 
	int sum1=0,sum2=0; 
	for(int i=0;i<m;i++){
		sum1+=sou[i][i];
		sum2+=sou[i][m-i-1];
	}
	stack[++top]=sum1;
	stack[++top]=sum2;
	sort(stack,0,top);
	for(int i=0;i<=top;i++){
		cout<<stack[i];
		if(i<top) cout<<" ";
	}
	cout<<endl;
	return 0;
} 

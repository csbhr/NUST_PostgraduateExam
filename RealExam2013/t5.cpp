#include<iostream>

using namespace std;

int childSum(int n){
	int sum=0;
	for(int i=1;i<n;i++){
		if(n%i==0){
			sum+=i;
		}
	}
	return sum;
}

int main(){
	bool visited[3001];
	for(int i=1;i<=3000;i++){
		if(!visited[i]){
			int brother=childSum(i);
			//获取i因子之和brother
			//若brother满足：不等于i、在1-3000之间、未访问、因子之和等于i
			//则i与brother为一对亲密数 
			if(brother!=i&&brother>=1&&brother<=3000&&!visited[brother]&&childSum(brother)==i){
				cout<<i<<"-"<<brother<<endl;
				visited[brother]=true;
			}
			visited[i]=true; 
		}
	}
	return 0;
}

#include<iostream>
#include<vector>

using namespace std;

int fun(vector<int> sou,int n,int num,int x){
	int count=0;
	for(int i=0;i<n-num+1;i++){
		int sum=0;
		for(int j=0;j<num;j++){
			sum+=sou[i+j];
		}
		if(sum>=x) count++;
	}
	return count;
}

int main(){
	vector<int> sou;
	int c,x;
	cin>>c>>x;
	for(int i=0;i<c;i++){
		int m;
		cin>>m;
		sou.push_back(m);
	}
	int count=0;
	for(int i=1;i<=c;i++){
		count+=fun(sou,c,i,x);
	}
	cout<<count<<endl;
	return 0;
}

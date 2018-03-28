#include<iostream>

using namespace std;

bool isSu(int n){
	if(n<=1) return false;
	for(int i=2;i<n;i++){
		if(n%i==0) return false;
	}
	return true;
}

int main(){
	bool visited[101];
	int count=0;
	for(int i=1;i<=98;i++){
		if(isSu(i)&&isSu(i+2)){
			cout<<i<<"-"<<i+2<<endl;
			count++;
		}
	}
	cout<<"孪生素数对个数："<<count<<endl;
	return 0;
}

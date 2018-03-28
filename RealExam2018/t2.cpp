#include<iostream>

using namespace std;

#define M 100

typedef struct{
	char type;
	int D1;
	int D2;
}Item;

//A操作
void funcA(int sou[M],int &n,Item it){
	sou[n++]=it.D1;
}

//I操作
void funcI(int sou[M],int &n,Item it){
	for(int i=n;i>=it.D1;i--){
		sou[i]=sou[i-1];
	}
	sou[it.D1-1]=it.D2;
	n++;
}

//Q操作
int funcQ(int sou[M],int n,Item it){
	int sum=0;
	for(int i=0;i<n;i++){
		if(sou[i]==it.D1) sum++;
	}
	return sum;
}

//P操作
void funcP(int sou[M],int n){
	for(int i=0;i<n;i++){
		cout<<sou[i];
		if(i!=n-1) cout<<" ";
	} 
}
 

int main(){
	int n;
	int sou[M];
	cin>>n;
	for(int i=0;i<n;i++) cin>>sou[i];
	
	int m;
	Item its[M];
	cin>>m;
	for(int i=0;i<m;i++){
		char temp;
		cin>>temp;
		if(temp=='A'||temp=='Q'){
			its[i].type=temp;
			cin>>its[i].D1;
		}else if(temp=='I'){
			its[i].type=temp;
			cin>>its[i].D1>>its[i].D2;
		}else{
			its[i].type=temp;
		}
	}
	
	for(int i=0;i<m;i++){
		if(its[i].type=='A'){
			funcA(sou,n,its[i]);
		}else if(its[i].type=='I'){
			funcI(sou,n,its[i]);
		}else if(its[i].type=='Q'){
			int num=funcQ(sou,n,its[i]);
			cout<<num<<endl;
		}else{
			funcP(sou,n);
			cout<<endl;
		}
	}
	return 0;
}

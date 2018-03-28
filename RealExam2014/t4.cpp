#include<iostream>
#include<string>

using namespace std;

int ctoi(char c){
	string str="";
	str+=c;
	int a;
	sscanf(str.c_str(),"%d",&a);
	return a;
}

int doOdd(string cid){
	int sum=0;
	int size=cid.size();
	for(int i=size-1,k=1;i>=0;i--,k++){
		if(k%2!=0){
			sum+=ctoi(cid[i]);
		}
	}
	return sum;
}

int doEven(string cid){
	int sum=0;
	int size=cid.size();
	for(int i=size-1,k=1;i>=0;i--,k++){
		if(k%2==0){
			int a=ctoi(cid[i]);
			a*=2;
			if(a>=10) a-=9;
			sum+=a;
		}
	}
	return sum;
}

int main(){
	string cid;
	cin>>cid;
	if(doOdd(cid)==doEven(cid)){
		cout<<"合法"<<endl;
	}else{
		cout<<"不合法"<<endl;
	}
	return 0;
} 

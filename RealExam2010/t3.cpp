#include<iostream>
#include<cmath> 

using namespace std;

#define M 1000



//将十进制转换为二进制，并倒序 
string TenToBinReverse(int tenN){
	char c_binN[M];
	int top=-1;
	while(tenN>0){
		c_binN[++top]=(char)(tenN%2+48);
		tenN/=2;
	}
	string binN="";
	for(int i=0;i<=top;i++) binN+=c_binN[i];
	return binN;
}

//将二进制转换为十进制
int BinToTen(string binN){
	int tenN=0;
	for(int i=0,size=binN.size();i<size;i++){
		tenN+=pow(2,size-i-1)*((int)(binN[i]-48));
	}
	return tenN;
} 
 

int main(){
	int tenN;
	cin>>tenN;
	string binN=TenToBinReverse(tenN);
	tenN=BinToTen(binN);
	cout<<tenN<<endl;
	return 0;
} 

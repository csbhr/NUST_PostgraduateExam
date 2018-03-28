#include<iostream>
#include<cmath>

using namespace std;

int main(){
	for(int i=1;i<=20;i++){
		int a;
		if(i<=3) a=0;
		else{
			a=i-3;
		}
		cout<<pow(2,a)<<endl;
	}
	return 0;
}

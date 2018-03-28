#include<iostream>
#include<iomanip>

using namespace std;

//¼ÆËã1/n
double func(int n){
	return 1/((double)n);
} 

int main(){
	int n;
	cin>>n;
	double sum=0;
	for(int i=1;i<=n;i++){
		sum+=func(i);
	}
	cout<<setiosflags(ios::fixed)<<setprecision(6)<<sum<<endl;
	return 0;
} 

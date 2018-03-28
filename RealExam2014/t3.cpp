#include<iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int groupNum;
	if(n%8==0) groupNum=n/8;
	else groupNum=n/8+1;
	int base=n/groupNum;
	int mode=n%groupNum;
	for(int i=0;i<groupNum;i++,mode--){
		if(mode>0) cout<<(base+1);
		else cout<<base;
		if(i<groupNum-1) cout<<",";
	}
	cout<<endl;
	return 0;
}

#include<iostream>

using namespace std;

int main(){
	int k;
	cin>>k;
	int maxM=0,maxN=0,maxZ=0;
	bool isexist=false;
	for(int m=0;m<k;m++){
		for(int n=0;n<k;n++){
			if(n*n-m*m-n*m==1){
				if(m*m+n*n>=maxZ){
					isexist=true;
					maxZ=m*m+n*n;
					maxM=m;
					maxN=n;
				}
			}
		}
	}
	if(isexist){
		cout<<"m="<<maxM<<",n="<<maxN<<"  m*m+n*n="<<maxZ<<endl;
	}else{
		cout<<"²»´æÔÚ"<<endl;
	}
	
	return 0;
}

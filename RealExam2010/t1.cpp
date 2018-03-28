#include<iostream>

using namespace std;

int main(){
	string s,t;
	cout<<"s:";
	cin>>s;
	cout<<"t:";
	cin>>t;
	int count=0;
	int size_s=s.size(),size_t=t.size();
	for(int i=0;i<size_s-size_t+1;i++){
		bool isok=true;
		for(int j=0;j<size_t;j++){
			if(s[i+j]!=t[j]){
				isok=false;
				break;
			}
		}
		if(isok){
			count++;
			cout<<i<<" ";
		}
	}
	cout<<endl;
	cout<<count<<endl;
	return 0;
} 

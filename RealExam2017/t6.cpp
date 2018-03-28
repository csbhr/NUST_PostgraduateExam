#include<iostream>
#include<string>

using namespace std;

int lps(string str,int begin,int end){
	if(begin==end) return 1;
	if(begin>end) return 0;
	if(str[begin]==str[end]) return lps(str,begin+1,end-1)+2;
	else{
		int a=lps(str,begin,end-1);
		int b=lps(str,begin+1,end);
		if(a>=b) return a;
		else return b;
	}
}

int main(){
	string str;
	cin>>str;
	for(char &c:str){
		if(c>='A'&&c<='Z'){
			c=c+32;
		}
	}
	int len=lps(str,0,str.size()-1);
	cout<<len<<endl;
	return 0;
} 

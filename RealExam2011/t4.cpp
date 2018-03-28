#include<iostream>

using namespace std;

int main(){
	cout<<"满足条件的abc的值依次为："<<endl;
	for(int a=0;a<=5;a++){
		for(int b=0;b<=5;b++){
			for(int c=0;c<=9;c++){
				int abc=a*100+b*10+c;
				int bcc=b*100+c*10+c;
				if(abc+bcc==532){
					cout<<"a="<<a<<" b="<<b<<" c="<<c<<endl;
				}
			}
		}
	}
	return 0;
} 

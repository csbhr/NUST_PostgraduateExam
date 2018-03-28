#include<iostream>

using namespace std;

//判断x条鱼是否可以“扔掉一条，再分成5份” 
bool isLegal(int x){
	bool isok=true;
	if(x<=5) isok=false;
	if((x-1)%5!=0) isok=false;
	return isok;
}

//判断x条鱼是否可以够5次分发 
bool isEnough(int x){
	bool isok=true;
	for(int i=0;i<5;i++){
		if(!isLegal(x)){
			isok=false;
			break;
		}
		x=x-((x-1)/5)-1;
	}
	return isok;
} 

int main(){
	int x=6;
	while(!isEnough(x)) x++;
	cout<<x<<endl;
	return 0;
}

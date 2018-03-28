#include<iostream>

using namespace std;

#define Max 100

int main(){
	int result[Max];
	int rear=0;
	int model[Max];
	for(int i=0;i<Max;i++) model[i]=-1;
	int M,N;
	cin>>M>>N;
	while(M!=0&&model[M]==-1){
		result[rear++]=(M*10)/N;
		model[M]=rear;
		M=(M*10)%N;
	} 
	cout<<M<<"/"<<N<<"=0.";
	for(int i=0;i<rear;i++) cout<<result[i];
	if(M!=0){
		cout<<"，无限循环小数，从第"<<model[M]<<"位开始循环"; 
	}
	return 0;
}

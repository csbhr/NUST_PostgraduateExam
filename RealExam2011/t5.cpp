#include<iostream>
#include<cstdio>

using namespace std;

#define M 100

//在sou后面追加a 
void addItem(int sou[M],int &top,int a){
	sou[++top]=a;
}

//将sou中的a替换成b
void replaceItem(int sou[M],int top,int a,int b){
	for(int i=0;i<=top;i++){
		if(sou[i]==a) sou[i]=b;
	} 
} 

//将sou中的a删除
void deleteItem(int sou[M],int &top,int a){
	int i=0;
	while(i<=top){
		if(sou[i]==a){
			for(int j=i+1;j<=top;j++){
				sou[j-1]=sou[j];
			}
			top--;
		}
		i++;
	}
}

//执行命令 
void charge(int sou[M],int &top,string str){
	if(str[0]=='a'){
		int a;
		sscanf(str.c_str(),"a %d",&a);
		addItem(sou,top,a);
	}else if(str[0]=='c'){
		int a,b;
		sscanf(str.c_str(),"c/%d/%d",&a,&b);
		replaceItem(sou,top,a,b);
	}else if(str[0]=='d'){
		int a;
		sscanf(str.c_str(),"d %d",&a);
		deleteItem(sou,top,a);
	}else{
		cout<<"命令有误！"<<endl;
	}
} 

int main(){
	int sou[M],top=-1;
	int item;
	cout<<"请输入初始序列，以-1结束：";
	cin>>item; 
	while(item!=-1){
		sou[++top]=item;
		cin>>item;
	}
	cout<<"Now:";
	for(int i=0;i<=top;i++) cout<<sou[i]<<" ";
	cout<<endl;
	cout<<"请输入操作命令：";
	string str;
	getline(cin,str);
	getline(cin,str);
	charge(sou,top,str);
	cout<<"Now:";
	for(int i=0;i<=top;i++) cout<<sou[i]<<" ";
	cout<<endl;
	return 0;
}

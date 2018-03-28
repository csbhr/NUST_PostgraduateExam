#include<iostream>

using namespace std;

class Tim{
	public:
		int value;
		int times;
		Tim(){}
		Tim(int val){
			value=val;
			times=1;
		}
};

void sort(Tim tims[30],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(tims[j].times<tims[j+1].times){
				Tim t=tims[j];
				tims[j]=tims[j+1];
				tims[j+1]=t;
			}
		}
	}
}

void sort(Tim tims[30],int begin,int end){
	if(begin>end) return;
	int be=begin,en=end;
	Tim t=tims[be];
	while(be<en){
		while(tims[en].times<=t.times&&be<en) en--;
		tims[be]=tims[en];
		while(tims[be].times>=t.times&&be<en) be++;
		tims[en]=tims[be];
	}
	tims[be]=t;
	sort(tims,begin,be-1);
	sort(tims,en+1,end);
}

int main(){
	int orgin[30],otop=-1,ttop=-1;
	Tim tims[30];
	int a;
	cin>>a;
	while(a!=-1){
		orgin[++otop]=a;
		cin>>a;
	}
	for(int i=0;i<=otop;i++){
		bool isok=true;
		int j=0;
		for(j=0;j<=ttop;j++){
			if(tims[j].value==orgin[i]){
				isok=false;
				break;
			}
		}
		if(isok){
			Tim t(orgin[i]);
			tims[++ttop]=t;
		}else{
			tims[j].times++;
		}
	}
	for(int i=0;i<=ttop;i++){
		cout<<tims[i].value<<":"<<tims[i].times;
		if(i<ttop) cout<<",";
	}
	cout<<endl;
	sort(tims,ttop+1);
	cout<<"ÅÅÐò½á¹û£º"<<endl;
	for(int i=0;i<=ttop;i++){
		cout<<tims[i].value<<":"<<tims[i].times;
		if(i<ttop) cout<<",";
	}
	cout<<endl;
	return 0;
}

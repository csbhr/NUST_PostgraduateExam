#include<iostream>

using namespace std;

#define M 100
#define M_P 1000

//迪杰斯特拉算法
void  Dijkstra(int arc[M][M],int n,int begin,bool S[M],int Path[M],int D[M]){
	for(int i=0;i<n;i++){
		S[i]=false;
		D[i]=arc[begin][i];
		if(arc[begin][i]<M_P) Path[i]=begin;
		else Path[i]=-1; 
	}
	S[begin]=true;
	D[begin]=0;
	Path[begin]=-1;
	for(int i=0;i<n;i++){
		int min=M_P;
		int v=-1;
		for(int j=0;j<n;j++){
			if(!S[j]&&D[j]<min){
				min=D[j];
				v=j;
			}
		}
		if(v>=0){
			S[v]=true;
			for(int j=0;j<n;j++){
				if(!S[j]&&D[v]+arc[v][j]<D[j]){
					D[j]=D[v]+arc[v][j];
					Path[j]=v;
				}
			}
		}
	}
}

int main(){
	
	int n,m;
	cin>>n>>m;
	
	int arc[M][M];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			arc[i][j]=M_P;
		}
	}
	
	for(int i=0;i<m;i++){
		int a,b,w;
		cin>>a>>b>>w;
		a--;
		b--;
		arc[a][b]=w;
		arc[b][a]=w;
	}
	
	int s,e;
	cin>>s>>e;
	s--;
	e--;
	
	bool S[M];
	int Path[M],D[M];
	Dijkstra(arc,n,s,S,Path,D);
	
	if(!S[e]){
		cout<<"Excuse me?"<<endl;
	}else{
		cout<<D[e]<<endl;
	}
	
	return 0;
} 

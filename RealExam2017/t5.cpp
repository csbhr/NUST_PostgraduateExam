#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

#define MAX_PATH 150000
#define MAX_POINT 100 

class Point{
	public:
		int x;
		int y;
};

class Adjac{
	public:
		int begin;
		int end;
		double weight;
};

void printGraph(double arc[MAX_POINT][MAX_POINT],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arc[i][j]==MAX_PATH) cout<<"M ";
			else cout<<arc[i][j]<<" ";
		}
		cout<<endl;
	}
}

int FirstAdj(double arc[MAX_POINT][MAX_POINT],int n,int v){
	for(int i=0;i<n;i++){
		if(arc[v][i]<MAX_PATH) return i;
	}
	return -1;
}

int NextAdj(double arc[MAX_POINT][MAX_POINT],int n,int v,int w){
	for(int i=w+1;i<n;i++){
		if(arc[v][i]<MAX_PATH) return i;
	}
	return -1;
}

void BroadTraver(double arc[MAX_POINT][MAX_POINT],int n,int begin,bool visited[MAX_POINT],int stack[MAX_POINT],int top){
	for(int i=0;i<n;i++) visited[i]=false;
	top=-1;
	int v=begin;
	int queue[MAX_POINT],rear=0,front=0;
	visited[v]=true;
	stack[++top]=v;
	queue[rear]=v; rear=(rear+1)%MAX_POINT;
	while(front!=rear){
		v=queue[front]; front=(front+1)%MAX_POINT;
		for(int w=FirstAdj(arc,n,v);w>=0;w=NextAdj(arc,n,v,w)){
			if(!visited[w]&&arc[v][w]<MAX_PATH){
				visited[w]=true;
				stack[++top]=w;
				queue[rear]=w; rear=(rear+1)%MAX_POINT;
			}
		}
	}
}

void sortAdjac(Adjac adjs[MAX_POINT*MAX_POINT],int begin,int end){
	if(begin>end) return;
	int be=begin,en=end;
	Adjac adj=adjs[be];
	while(be<en){
		while(adjs[en].weight>=adj.weight&&be<en) en--;
		adjs[be]=adjs[en];
		while(adjs[be].weight<=adj.weight&&be<en) be++;
		adjs[en]=adjs[be];
	}
	adjs[be]=adj;
	sortAdjac(adjs,begin,be-1);
	sortAdjac(adjs,en+1,end);
}

void Kruskal(double arc[MAX_POINT][MAX_POINT],int n,int adjNum,double arcMin[MAX_POINT][MAX_POINT]){
	Adjac adjs[MAX_POINT*MAX_POINT];
	bool visited[MAX_POINT];
	int stack[MAX_POINT],top;
	for(int i=0,k=0;i<n;i++){
		for(int j=0;j<n;j++){
			arcMin[i][j]=MAX_PATH;
			if(arc[i][j]<MAX_PATH){
				adjs[k].begin=i;
				adjs[k].end=j;
				adjs[k].weight=arc[i][j];
				k++;
			}
		}
	}
	sortAdjac(adjs,0,adjNum-1);
	for(int i=0;i<adjNum;i++){
		BroadTraver(arcMin,n,adjs[i].begin,visited,stack,top);
		if(!visited[adjs[i].end]){
			arcMin[adjs[i].begin][adjs[i].end]=adjs[i].weight;
			arcMin[adjs[i].end][adjs[i].begin]=adjs[i].weight;
		}
	}
	
}

int main(){
	double arc[MAX_POINT][MAX_POINT];
	int n;
	cin>>n;
	Point points[MAX_POINT];
	for(int i=0;i<n;i++){
		cin>>points[i].x>>points[i].y;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) arc[i][j]=MAX_PATH;
			else{
				arc[i][j]=sqrt(pow(points[i].x-points[j].x,2)+pow(points[i].y-points[j].y,2));
			}
		}
	}
	double arcMin[MAX_POINT][MAX_POINT];
	Kruskal(arc,n,n*(n-1),arcMin);
	double pathLength=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(arcMin[i][j]<MAX_PATH) pathLength+=arcMin[i][j];
		}
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<pathLength<<endl;
	return 0;
}

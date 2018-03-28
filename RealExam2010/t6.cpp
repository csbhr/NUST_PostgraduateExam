#include<iostream>

using namespace std;

//类比八皇后算法 

#define M 100

typedef struct{
	int x;
	int y;
}Point;

int MaxPath,maxTop,nowTop;
Point maxStack[M],nowStack[M];
//MaxPath记录当前经过的最大值，maxStack和maxTop用于记录此最大值所经过的点
//nowStack和nowTop用于记录此时的路径 

//判断在now点是否能走下去
//type=1是往右走，type=2 是往右下走 
bool isOk(int arc[M][M],int n,Point now,int type){
	if(now.y==n-1) return false;
	if(type==2){
		if(now.x==n-1) return false;
	}
	return true;
}

//递归回溯遍历
//now是当前的位置 
void Traver(int arc[M][M],int n,Point now){
	if(!isOk(arc,n,now,1)&&!isOk(arc,n,now,2)){
		//表明现在已经不能再走下去了，需要计算最大值 
		nowStack[++nowTop]=now;
		int max=0;
		for(int i=0;i<=nowTop;i++){
			max+=arc[nowStack[i].x][nowStack[i].y];
		}
		if(max>MaxPath){
			//取最大值及其路径 
			MaxPath=max;
			maxTop=-1;
			for(int i=0;i<=nowTop;i++){
				maxStack[++maxTop]=nowStack[i];
			}
		}
		nowTop--; //回溯前恢复当前状态 
	} else{
		if(isOk(arc,n,now,1)){
			//向右可走，则向右走 
			nowStack[++nowTop]=now;
			Point next; next.x=now.x; next.y=now.y+1;
			Traver(arc,n,next);
			nowTop--; //恢复到向右走之前的状态 
		}
		if(isOk(arc,n,now,2)){
			//向右下可走，则向右下走 
			nowStack[++nowTop]=now;
			Point next; next.x=now.x+1; next.y=now.y+1;
			Traver(arc,n,next);
			nowTop--; //恢复到向右下走之前的状态
		}
	}
}

int main(){
	int n;
	int arc[M][M];
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arc[i][j];
		}
	} 
	MaxPath=0;
	maxTop=nowTop=-1;
	Point now; now.x=now.y=0;
	Traver(arc,n,now);
	cout<<"MaxLength:"<<MaxPath<<endl;
	cout<<"Path:";
	for(int i=0;i<=maxTop;i++){
		cout<<arc[maxStack[i].x][maxStack[i].y]<<"  ";
	} 
	return 0;
} 

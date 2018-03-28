#include<iostream>
#include<math.h>
using namespace std;

int total=0;
int c[8];

bool is_ok(int row){
    for(int j=0;j!=row;j++){
        if(c[row]==c[j] || row-c[row]==j-c[j] || row+c[row]==j+c[j])
            return false;
    }
    return true;
}

void queen(int row){
    if(row==8)
        total++;
    else
        for(int col=0;col!=8;col++){
            c[row]=col;
            if(is_ok(row))
                queen(row+1);
        }       
}

int main(){
    queen(0);
    cout<<total;
    return 0;
}

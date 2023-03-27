#include<bits/stdc++.h>
using namespace std;

#define N 9
bool column(int board[][N],int row,int col){
    for(int i=row-1;i>=0;i--){
        if(board[i][col]==1) return false;
    }
    return true;
}
bool leftDiagonal(int  board[][N], int n,int row, int col){
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(board[i][j]==1) return false;
    }
    return true;
}
bool rightDiagonal(int  board[][N],int n,int row, int col){
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        if(board[i][j]==1) return false;
    }
    return true;
}
bool canPlace(int board[][N],int n,int x,int y){
    if(column(board,x,y)&&leftDiagonal(board,n,x,y)&&rightDiagonal(board,n,x,y)) return true;
    return false;
}
void printBoard(int board[][N],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
    }
    cout<<endl;
}
void placeNQueen(int  board[][N],int n,int row=0)
{
    if(row==n) printBoard(board,n);
    for(int i=0;i<n;i++){
        board[row][i]=1;
        if(canPlace(board,n,row,i)) placeNQueen(board,n,row+1);
        board[row][i]=0;
    }
}
int main(){
    // write your code here
    int n;
    cin>>n;
    int board[N][N];
    memset(board,0,N*N*sizeof(int));
    placeNQueen(board,n);
    return 0;
}
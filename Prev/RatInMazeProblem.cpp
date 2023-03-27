#include<bits/stdc++.h>
using namespace std;
#define N 19
#define L2(m,n) for(int i=0;i<m;i++)for(int j=0;j<n;j++)
void printMaze(int sol[][N],int n){
    L2(n,n) cout<<sol[i][j]<<" ";
    cout<<endl;
}
void solveMaze(int maze[][N],int n,int sol[][N], int x=0, int y=0){
    if(x==n-1&&y==n-1){ sol[x][y]=1; printMaze(sol,n); sol[x][y]=0; return; }
    if(x>=n||y>=n||x<0||y<0||sol[x][y]==1||maze[x][y]==0) return;

    sol[x][y]=1;
    solveMaze(maze,n,sol,x-1,y);
    solveMaze(maze,n,sol,x+1,y);
    solveMaze(maze,n,sol,x,y-1);
    solveMaze(maze,n,sol,x,y+1);
    sol[x][y]=0;
    return;

}
int main() {
	// Write your code here
    int n;
    cin>>n;
    int maze[N][N];
    memset(maze,0,N*N*sizeof(int));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    int sol[N][N];
    memset(sol,0,N*N*sizeof(int));
    solveMaze(maze,n,sol);
	return 0;
}

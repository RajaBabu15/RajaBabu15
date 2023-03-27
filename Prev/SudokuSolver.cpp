#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define n 9
bool findemptylocation(int grid[n][n],int &row,int &col)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==0)
            {
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
    
}
bool issafeingrid(int grid[n][n],int row,int col ,int num)
{
    int cellrow=row/3;
    int cellcol = col/3;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(grid[3*cellrow+i][3*cellcol+j]==num)
                return false;
    return true;
}
bool issafeincol(int grid[n][n],int col ,int num)
{
    for(int i=0;i<n;i++)
    {
        if(grid[i][col]==num)
        return false;
    }
    return true;
}
bool issafeinrow(int grid[n][n],int row ,int num)
{
    for(int i=0;i<n;i++)
    {
        if(grid[row][i]==num)
        return false;
    }
    return true;
}
bool issafe(int grid[n][n],int row ,int col,int num)
{
    if(issafeinrow(grid,row,num)&&issafeincol(grid,col,num)&&issafeingrid(grid,row,col,num))
    return true;
    return false;
}
bool checkSolved(int grid[n][n]){

    bool flag_Solved= false;
    int count[9]={};
    for(int i=0;i<9;i++) count[i]=1;
    int k=0;
    for(int i=0;i<9;i++) {
    for(int j=0;j<9;j++){
        int b = pow(i/3,j/3);
        count[grid[i][j]-1]+=1;
    } 
    }
    for(int i=0;i<8;i++) if(count[i]!=count[i+1]) ;return flag_Solved;
    return true;
    
}
bool solvesudoko(int grid[n][n])
{
    int row,col;
    if(!findemptylocation(grid,row,col)) return checkSolved(grid);
    for(int i=1;i<=9;i++)
    {
        if(issafe(grid,row,col,i))
        {
            grid[row][col]=i;
            if(solvesudoko(grid))
            return true;
            grid[row][col]=0;
        }        
    }
    return false;
}

int main()
{
    int grid[n][n];
    for(int i=0;i<n;i++)
    { 
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<((solvesudoko(grid))?"true":"false")<<endl;
    
    return 0;
}

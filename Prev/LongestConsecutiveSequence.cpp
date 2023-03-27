#include <iostream>
#include <vector>
using namespace std;
#include<unordered_map>
#include<deque>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
	unordered_map<int,bool> map;
    for(int i=0;i<n;i++) map[arr[i]]=true;
    
    deque<int> que;
    for(int i=0;i<n;i++){
        if(!map[arr[i]]) continue;
        deque<int> tmp;
        tmp.push_back(arr[i]);
        int data=arr[i];
        data++;
        while(map[data]){
            tmp.push_back(data);
            map[data]=false;
            data++;
        }
        data=arr[i];
        data--;
        while(map[data]){
            tmp.push_front(data);
            map[data]=false;
            data--;
        }
        if(tmp.size()>que.size()){
            que=tmp;
        }
    }
    cout<<"Here"<<endl;
    vector<int> vect{que.front(),que.back()};
    return vect;
}

#include<bits/stdc++.h>
using namespace std;

int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    int **grid = new int*[n+1];
    for(int i=0;i<n+1;i++)
        grid[i] = new int[maxWeight+1];
    for(int j=0;j<maxWeight+1;j++)
    grid[n+1][j]=0;

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<maxWeight+1;j++){
            grid[i][j]=max(value[i]+grid[i+1][j-weight[i]],grid[i+1][j]);
        }
    }
    int max=0;
    for(int i=0;i<maxWeight+1;i++){
        if(max<grid[0][i])
        max=grid[0][i];
    }
    return max;
}

// bool hasSquare(int **arr,int n,int m,int x,int y,int len){
// 	for(int i=x;i<x+len;i++){
// 		if(i>=n) return false;
// 		for(int j=y;j<y+len;j++){
// 			if(j>=m) return false;
// 			if(arr[i][j]!=0) return false;
// 		}
// 	}
// 	return true;
// }
// void paintSquare(int **arr,int x,int y,int len){
//   for (int i = x; i < x + len; i++) 
//     for (int j = y; j < y + len; j++) 
//      	arr[i][j] =1;
// }
int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here
	// int max=0;
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		if(arr[i][j]==0){
	// 			int val=1;
	// 			while(hasSquare(arr, n, m, i, j, ++val));
	// 			val--;
	// 			paintSquare(arr, i, j, val);
	// 			if(val>max) max=val;
	// 		}
	// 	}
	// }
	// return max;
    #include<bits/stdc++.h>
    using namespace std;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) arr[i][j]=((arr[i][j]==0)?1:0);
	int m1=0;
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(arr[i][j]==1)
			arr[i][j]=1+max(arr[i-1][j-1],max(arr[i-1][j],arr[i][j-1]));
		}
	}
	return m1;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);
    cout<<"heresdnfm"<<endl;
    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}

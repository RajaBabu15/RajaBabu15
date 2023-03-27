

#include <iostream>
using namespace std;
#include<bits/stdc++.h>
using namespace std;

#define N 10000000

int longestIncreasingSubsequenceHelper(int *arr, int n, int* help[N], int r, int c){
	if(n<=0) return 0;

	if(help[r][c]!=-1) return help[r][c];

	int notCurrent=longestIncreasingSubsequenceHelper(arr+1,n-1,help,r+1,c+1);
	int current=1;
	int maxi=max(current,notCurrent);
	for(int i=1;i<n;i++){
		if(arr[i]>arr[0]){
			current=1+longestIncreasingSubsequenceHelper(arr+i,n-i,help, r+1,c+i);
			if(current>maxi)
				maxi=current;
		}
	}
	help[r][c]=maxi;
	return maxi;
}

int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
	int **help;
    help =new  int*[n];

    for(int i=0;i<n;i++){
    help[i]=new int[n];
	for(int j=0;j<n;j++)
	help[i][j]=-1;
	}

	return longestIncreasingSubsequenceHelper(arr, n, help, 0, 0);
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}
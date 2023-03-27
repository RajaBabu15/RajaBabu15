#include <bits/stdc++.h>
#include <iostream>
#include <stack>


using namespace std;

void getConnectedComponent(int **edges, int n,  bool *visited,int start,vector<int> &vect) {
  queue<int> que;
  que.push(start);
  visited[start] = true;
  while (!que.empty()) {
    int val = que.front();
    vect.push_back(val);
    que.pop();
    for (int i = 0; i < n; i++) {
      if (i == val)
        continue;
      if (edges[val][i] == 1 && visited[i] == false) {
        visited[i] = true;
        que.push(i);
      }
    }
  }
}

void printVector(vector<int> &vect){
  for(int i=0;i<vect.size();i++){
    cout<<vect[i]<<" ";
  }
}

void printConnectedComponents(int**edges,int n,bool *visited){
    for(int i=0;i<n;i++){
        vector<int> vect;
        if(visited[i]==false){
            getConnectedComponent(edges,n,visited,i,vect);
        }
        sort(vect.begin(),vect.end());
        printVector(vect);
    }
}

int main() {
  int n, e;
  cin >> n >> e;
  int **edges = new int *[n];
  for (int i = 0; i < n; i++) {
    edges[i] = new int[n];
    for (int j = 0; j < n; j++)
      edges[i][j] = 0;
  }

  for (int i = 0; i < e; i++) {
    int f, s;
    cin >> f >> s;
    edges[f][s] = 1;
    edges[s][f] = 1;
  }

  bool *visited =new bool[n];
 for(int i=0;i<n;i++) visited[i]=false; 

  printConnectedComponents(edges,n,visited);

  for (int i = 0; i < n; i++)
    delete[] edges[i];
  delete[] edges;
    delete [] visited;

  return 0;
}
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class edge {
public:
  int a, b, wt;

};

// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph
#include <bits/stdc++.h>
using namespace std;
 
// Number of vertices in the graph

 
// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[],int V)
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int **graph,int V)
{
    // cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        if(parent[i]<i) cout << parent[i] << " " << i << " "<< graph[i][parent[i]] << " \n";
        else cout << i << " "<< parent[i] << " " << graph[i][parent[i]] << " \n";
    }
}
 
// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(int **graph,int V)
{
    // Array to store constructed MST
    int parent[V];
 
    // Key values used to pick minimum weight edge in cut
    int key[V];
 
    // To represent set of vertices included in MST
    bool mstSet[V];
 
    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first
    // vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST
 
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet,V);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < V; v++)
 
            // graph[u][v] is non zero only for adjacent
            // vertices of m mstSet[v] is false for vertices
            // not yet included in MST Update the key only
            // if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 
    // print the constructed MST
    printMST(parent, graph,V);
}

int findParent(int v, int *parent) {
  if (parent[v] == v)
    return v;
  else
    return findParent(parent[v], parent);
}

bool comparator(const edge &e1, const edge &e2) { return (e1.wt < e2.wt); }

void Prims(int **edges,int n,bool *visited,int *parent) {
    parent[0]=-1;
    int ptr = 0;
    for(int i=0;i<n-1;i++){
        visited[ptr]=true;
        int minval=INT_MAX;
        int minvalIndex = 0;
        for(int j=0;j<n;j++){
            if(edges[ptr][j]>0&&visited[j]==false){
                if(edges[ptr][i]!=minval)
                parent[j]=ptr;
                if(minval>edges[ptr][j]) {
                    minval = edges[ptr][j];
                    minvalIndex = j;
                }
            }
        }
        for(int j=0;j<n;j++){
            if(edges[ptr][j]==minval&&j!=minvalIndex){
                // i++;
                visited[j]=true;
            }
        }
        // if(minvalIndex>=0)
        ptr= minvalIndex;
    }
}

int print(int** edges,int n,int*parent,int  val){
    int count=0;
    for(int i=0;i<n;i++){
        if(parent[i]==val){
            if(i<val) cout<<i<<" "<<val<<edges[i][val]<<endl;
            else cout<<val<<" "<<i<<" "<<edges[i][val]<<endl;
            count++;
        }
    }
    return count;
}


int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    int **edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j]=0;
        }
    }
    
    for(int i=0;i<e;i++){
        int f,s,wt;
        cin>>f>>s>>wt;
        edges[f][s] = wt;
        edges[s][f] = wt;
    }
    primMST(edges,n);

    // bool *visited = new bool[n];
    // for(int i=0;i<n;i++){
    //     visited[i] = false;
    // }
    // int *parent = new int[n];
    // for (int i = 0; i < n; i++) {
    //   parent[i] = -2;
    // }
    
    // Prims(edges,n,visited,parent);
    // edge ouput[n - 1];
    // for(int i=1;i<n;i++){
    //     edge e1;
    //     e1.a=i;
    //     e1.b = parent[i];
    //     //  cout<<i<<" "<<parent[i]<<endl;
    //     e1.wt = edges[i][parent[i]];
    //     ouput[i-1]=e1;
    // }
    // // for (int i = 0; i < n - 1; i++) {
    // //   edge e = ouput[i];
    // //   int a, b, wt;
    // //   a = e.a;
    // //   b = e.b;
    // //   wt = e.wt;
    // //   if (a < b)
    // //     cout << a << " " << b << " ";
    // //   else
    // //     cout << b << " " << a << " ";
    // //   cout << wt << endl;
    // // }
    // // sort(ouput, n, comparator);
    // // print(parent,n);
    // // for(int i=0;i<n-1; ){
    // //     i+=print(edges,n,parent,i);
    // // }


    // // for(int i=0;i<path.size();i++){
    // //     pair<int,int> p =path[i];
    // //     int f= p.first;
    // //     int s = p.second;
    // //     if(f<s)
    // //     cout<<f<<" "<<s<<" "<<edges[f][s]<<endl;
    // //     else
    // //     cout<<s<<" "<<f<<" "<<edges[f][s]<<endl;
    // // }

    // // Printing the output Array
    // for (int i = 0; i < n - 1; i++) {
    //   edge e = ouput[i];
    //   int a, b, wt;
    //   a = e.a;
    //   b = e.b;
    //   wt = e.wt;
    //   if (a < b)
    //     cout << a << " " << b << " ";
    //   else
    //     cout << b << " " << a << " ";
    //   cout << wt << endl;
    // }
    // for(int i=0;i<n;i++) delete [] edges[i];
    // delete [] edges;delete[] visited;
    // delete[] parent;
}
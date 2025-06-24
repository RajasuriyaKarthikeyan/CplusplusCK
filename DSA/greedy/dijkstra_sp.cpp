#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minDist(vector<int> dist, vector<bool> visited, int n){
    int min = INT_MAX;
    int index;
    for(int i=0;i<n;i++){
        if(!visited[i] && dist[i]<=min){
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstraGreedy(vector<vector<int>> graph, int src, int n){
    vector<int> dist(n,INT_MAX);
    vector<bool> visited(n, false);
    dist[src] = 0;
    for(int i=0;i<n;i++){
        int min = minDist(dist, visited, n);
        visited[min] = true;
        for(int j=0;j<n;j++){
            if(!visited[j] && graph[min][j] && dist[min]!=INT_MAX && dist[min]+graph[min][j]<dist[j]){
                dist[j] = dist[min]+graph[min][j];
            }
        }

    }

    cout << "Vertex  <----> Distance from source vertex" << endl;
    for(int i=0;i<n;i++){
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main(){
    int n=6;
    vector<vector<int>> graph = {
        {0,1,2,0,0,0},
        {1,0,0,5,1,0},
        {2,0,0,2,3,0},
        {0,5,2,0,2,2},
        {0,1,3,2,0,1},
        {0,0,0,2,1,0},
    };
    int src;
    cout << "Enter the source vertex : ";
    cin >> src;
    dijkstraGreedy(graph, src, n);
    return 0;
}


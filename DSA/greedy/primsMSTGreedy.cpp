#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <utility>

using namespace std;

#define INF INT_MAX 

void primsMST(vector<vector<int>>& graph, int n, int start){
    vector<int> key(n, INF); // Store the smallest distance from edge[i]
    vector<bool> inMST(n, false); // Store the visiting status
    vector<int> parent(n,-1); // To store the parent of each vertex

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    key[start] = 0;
    pq.push({key[start], start});

    while(!pq.empty()){
        int minkey = pq.top().second;
        pq.pop();

        if(inMST[minkey]) continue;

        inMST[minkey] = true;

        for(int v=0; v<n; v++){

            if(graph[minkey][v] != INF && !inMST[v] && graph[minkey][v] < key[v]){
                //Update the key to store the min value 
                key[v] = graph[minkey][v];
                parent[v] = minkey; // Storing the staring point of the edge
                pq.push({key[v], v}); //Pushing the update key value and vertex in prio queue
            }
        }
    }
    int totalWight = 0;
    cout << "Print MST edges with Weight : " << endl;
    for(int i=0;i<n;i++){
        if(parent[i] != -1){
            cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
            totalWight += graph[i][parent[i]];
        }
    }

    cout << "Total Weight of Prims MST : " << totalWight << endl;
}

int main(){
    int n = 5;
    vector<vector<int>> graph = {
        {INF, 2, INF, 6, INF},
        {2, INF, 3, 8, 5},
        {INF, 3, INF, INF, 7},
        {6, 8, INF, INF, 9},
        {INF, 5, 7, 9, INF}
    };

    primsMST(graph, n, 4);
    return 0;
}
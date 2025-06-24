#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> graph, vector<int> colors, int n, int color, int node){
    for(int i=0;i<n;i++){
        if(graph[node][i]==1 && colors[i]==color){
            return false;
        }
    }
    return true;
}

void greedyMapColuring(vector<vector<int>> graph, int n){
    vector<int> colors(n,-1);
    colors[0] = 0;
    for(int node=1;node<n;node++){
        for(int color=0;color<n;color++){
            if(isSafe(graph,colors,n,color,node)){
                colors[node]=color;
                break;
            }
        }
    }
    cout << "Vertex <---> Color" << endl;
    for(int i=0;i<n;i++){
        cout << i << "\t\t" << colors[i] << endl;
    }
}

int main(){
    int n=5;
    vector<vector<int>> graph = {
        {0,1,1,1,1},
        {1,0,0,0,1},
        {1,0,0,1,0},
        {1,0,1,0,1},
        {1,1,0,1,0}
    };
    greedyMapColuring(graph,n);
    return 0;
}
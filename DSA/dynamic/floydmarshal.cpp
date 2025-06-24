#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

#define INF INT_MAX

using namespace std;

void printMatrix(vector<vector<int>> matrix){
    cout << "Distance matrix with Floydd distance approach :" << endl;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix.size();j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void floydmarshal(vector<vector<int>>& dist){
    int V = dist.size();

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    printMatrix(dist);
}

int main(){
    vector<vector<int>> dist = {
        {0,5,INF,6,INF},
        {INF,0,1,INF,7},
        {3,INF,0,4,INF},
        {INF,INF,2,0,3},
        {2,INF,INF,5,0}
    };
    floydmarshal(dist);
    return 0;
}
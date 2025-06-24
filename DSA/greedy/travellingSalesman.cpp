#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findNearestCity(int current, int n, vector<bool>& visited, vector<vector<int>>& dist){
    int nearest = -1;
    int minDist = INT_MAX;
    for(int i=0;i<n;i++){
        if(!visited[i] && dist[current][i]<minDist){
            minDist = dist[current][i];
            nearest = i;
        }
    }
    return nearest;
}

void TravellingSalesManGreedy(vector<vector<int>>& dist, int n, int start){
    vector<bool> visited(n, false);
    visited[start] = true;
    int current = start;
    int totalDistance = 0;

    cout << " Tour starts at city : " << start << endl;

    for(int i=1;i<n;i++){
        int nextCity = findNearestCity(current, n, visited, dist);

        visited[nextCity] = true;

        cout << "Next Stop : " << nextCity << endl;

        totalDistance += dist[current][nextCity];

        current = nextCity;
    }
    totalDistance += dist[current][start];

    cout << "Final stop(starting city) : " << start << endl;

    cout << "Total Distance : " << totalDistance << endl;
}

int main(){
    vector<vector<int>> dist = {
        {0, 10, 15, 20, 25},
        {10, 0, 35, 25, 30},
        {15, 35, 0, 30, 20},
        {20, 25, 30, 0, 15},
        {25, 30, 20, 15, 0}
        };
    
    int n = 5;

    TravellingSalesManGreedy(dist, n, 0);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjoinSet {
    private:
        vector<int> parent, rank;
    public:
        DisjoinSet(int n){
            parent.resize(n);
            rank.resize(n,0);
            for(int i=0;i<n;i++){
                parent[i] = i; //Initialize each node is own parent(self)
            }
        }

        int find(int x){
            if(parent[x]!=x){
                parent[x] = find(parent[x]); 
            }
            return parent[x];
        }

        void unite(int x, int y){
            int rootX = find(x);
            int rootY = find(y);

            if(rootX != rootY){
                //Attach the smaller tree under the graph by using rank(no of vertices that tree have)
                if(rank[rootX] > rank[rootY]){
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]){
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }
};

struct Edge{
    int u, v, weight;
};

bool compareEdges(const Edge &e1, const Edge &e2){
    return e1.weight < e2.weight;;
}


int kruskalMST(int n, vector<Edge>& edges){
    DisjoinSet dsu(n);
    sort(edges.begin(), edges.end(), compareEdges); // Sort the edges

    int mstWeight = 0;
    int edgeCount = 0;

    for(const Edge &e : edges){
        int u = e.u;
        int v = e.v;

        if(dsu.find(u) != dsu.find(v)){ // To find if there is cycle formed in MST
            dsu.unite(u,v);
            mstWeight+= e.weight;
            edgeCount++;

            if(edgeCount == n-1){ // As no of edges in MST = total no of vertices - 1
                break;
            }
        }
    }
    return mstWeight;
}

int main(){
    int n,m;
    cout << "Enter number of vertices and edges : ";
    cin >> n >> m;

    vector<Edge> edges(m);

    cout << "Enter edges (u,v, weight):" << endl;
    for(int i=0;i<m;i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    int mstWeight = kruskalMST(n, edges);
    cout << "Weight of MST : " << mstWeight << endl;

    return 0;
}



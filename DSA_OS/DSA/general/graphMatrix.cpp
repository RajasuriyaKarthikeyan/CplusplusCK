#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

class Graph{
    private:
        int V;
        vector<list<int>> adjList;
    public:
        Graph(int V){
            this->V = V;
            adjList.resize(V);
        }

        void addEdge(int u, int v){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        void DisplayGraph(){
            int matrix[V][V];
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    matrix[i][j] = 0;
                }
            }
            for(int i=0;i<V;i++){
                cout << "Vertex " << i << " : ";
                for(auto neighbour : adjList[i]){
                    cout << neighbour << " ";
                    matrix[i][neighbour] = 1;
                }
                cout << endl;
            }
            cout << "Adjacent matrix : " <<endl;
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.DisplayGraph();
    return 0;
}

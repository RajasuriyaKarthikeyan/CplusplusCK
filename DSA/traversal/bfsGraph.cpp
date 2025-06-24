#include <iostream>
#include <vector>
#include <array>


using namespace std;
constexpr int MAX = 5;

struct Vertex{
    char label;
    bool visited;
};

//stack variables for dfs
array<int,MAX> queue;
int rear = -1;
int front = 0;
int queueCount = 0;

void insertData(int data){
    queue[++rear] = data;
    queueCount++;
}

int DeleteData(){
    queueCount--;
    return queue[front++];
}

bool isQueueEmpty(){
    return queueCount == 0;
}

//array of veritices
array<Vertex*,MAX> listVertices;
//array for adjacent matrix
array<array<int,MAX>,MAX> adjMatrix;
//vertex count
int vertexCount = 0;

void displayVertex(int vertextIndex){
    cout << listVertices[vertextIndex]->label << " ";
}

void addVertex(char label){
    Vertex* vertex = new Vertex;
    vertex->label = label;
    vertex->visited = false;
    listVertices[vertexCount++] = vertex;
}

void addEdges(int start, int end){
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

void addAdjacentUnivisitedVertext(int vertextIndex){
    for(int i=0;i<vertexCount;i++){
        if(adjMatrix[vertextIndex][i]==1 && listVertices[i]->visited==false){
            listVertices[i]->visited = true;
            insertData(i);
        }
    }
}

void resetList(){
    for(int i=0;i<vertexCount;i++){
        listVertices[i]->visited = false;
    }
}

void BreadthFirstSearch(int startIndex){
    listVertices[startIndex]->visited = true;
    insertData(startIndex);
    while(!isQueueEmpty()){
        int data = DeleteData();
        displayVertex(data);
        addAdjacentUnivisitedVertext(data);
    }
    resetList();
}

int main(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            adjMatrix[i][j] = 0;
        }
    }
    addVertex('S');
    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');
    addEdges(0,1);
    addEdges(1,4);
    addEdges(0,2);
    addEdges(1,3);
    addEdges(2,4);
    addEdges(3,4);
    cout << "BFS Queue Approach : ";
    BreadthFirstSearch(0);
    return 0;
}

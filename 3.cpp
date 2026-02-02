#include <iostream>
using namespace std;

class GraphNode{
    int vertex;
    GraphNode *next;
    friend class Graph;
};

class Graph{
    private:
        GraphNode *heads[20];
        int n;
    
    public:
        Graph(){
            cout << "Enter # of Vertices: ";
            cin >> n;
            for(int i = 0; i < n; i++){
                cout << "How many adjacent vertices?: ";
                int edges;
                cin >> edges;

                cout << "Enter connections: ";
                heads[i] = new GraphNode;
                GraphNode *current = heads[i];
                for(int j = 0; j < edges; j++){
                    cin >> current->vertex;
                    current->next = new GraphNode;
                    current = current->next;
                }
            }
        }

        void display(){
            for(int i = 0; i < n; i++){
                while(heads[i] != NULL){

                }
            }
        }
};

int main(){
    Graph g;
    return(0);
}

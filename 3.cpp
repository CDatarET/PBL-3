#include <iostream>
using namespace std;

class GraphNode{
    int vertexID;
    string name;
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
                heads[i] = new GraphNode;
                heads[i]->next = new GraphNode;
                GraphNode *current = heads[i]->next;
                current->vertexID = i;

                cout << "Enter Name: ";
                cin >> current->name;

                cout << "Enter # of edges: ";
                int edges;
                cin >> edges;
                if(edges <= 0){
                    cout << endl;
                    continue;
                }

                cout << "Enter IDs of connections that " << current->name << " (ID = " << current->vertexID << ")" << " has: ";
                for(int i = 0; i < edges; i++){
                    GraphNode *t = new GraphNode;
                    cin >> t->vertexID;
                    current->next = t;
                    current = current->next;
                }
                current->next = NULL;
                cout << endl;
            }
        }

        void displayMatrix(){
            cout << "  ";
            for(int i = 0; i < n; i++){
                cout << i << " ";
            }
            cout << endl << "  ";

            for(int i = 0; i < n - 1; i++){
                cout << "--";
            }
            cout << "-" << endl;

            for(int i = 0; i < n; i++){
                GraphNode *current = heads[i]->next->next;
                cout << i << "|";
                for(int j = 0; j < n; j++){
                    if(current == NULL){
                        cout << "0 ";
                    }
                    else{
                        if(current->vertexID == j){
                            cout << "1 ";
                            current = current->next;
                        }
                        else{
                            cout << "0 ";
                        }
                    }
                }
                cout << endl;
            }

            cout << endl;
        }

        void displayList(){
            for(int i = 0; i < n; i++){
                GraphNode *current = heads[i]->next;
                while(current != NULL){
                    cout << heads[current->vertexID]->next->name;
                    if(current->next != NULL){
                        cout << "->";
                    }
                    
                    current = current->next;
                }

                cout << endl;
            }

            cout << endl;
        }

        
        void DFS(int v, int visited[]){
            cout << v << ", ";
            visited[v] = 1;
            GraphNode *current = heads[v]->next;

            while(current != NULL){
                if(heads[current->vertexID] == 0){
                    DFS(current->vertexID, visited);
                }
                current = current->next;
            }
            
        }

        void DFS(){
            int visited[n] = {0};

            cout << "Enter starting vertex: ";
            int v;
            cin >> v;
            DFS(v, visited);

            cout << endl;
        }

        void BFS(){
            int Q[n] = {0};
            int f = 0;
            int r = 0;

            cout << "Enter starting vertex: ";
            int v;
            cin >> v;


        }

        void checkHeads(){
            for(int i = 0; i < n; i++){
                cout << heads[i]->next->vertexID << " ";
            }
            cout << endl << endl;
        }
};

int main(){
    Graph g;
    g.displayMatrix();
    g.displayList();
    g.DFS();
    g.checkHeads();
    return(0);
}

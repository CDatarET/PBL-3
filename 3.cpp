#include <iostream>
using namespace std;

class GraphNode{
    int vertex;
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
                cout << "Enter name: ";
                string name;
                cin >> name;

                cout << "How many adjacent vertices?: ";
                int edges;
                cin >> edges;

                cout << "Enter connections for " << name << ", ID = " << i << ": ";
                heads[i] = new GraphNode;
                heads[i]->name = name;
                heads[i]->vertex = i;
                heads[i]->next = new GraphNode;

                GraphNode *current = heads[i]->next;
                for(int j = 0; j < edges; j++){
                    cin >> current->vertex;
                    current->next = new GraphNode;
                    current = current->next;
                }

                current->next = NULL;
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
                GraphNode *current = heads[i];
                cout << i << "|";
                for(int j = 0; j < n; j++){
                    if(current == NULL){
                        cout << "0 ";
                    }
                    else{
                        if(current->vertex == j){
                            cout << "1 ";
                            current = current->next;
                        }
                        else{
                            cout << "0 ";
                        }
                    }
                }
                cout << endl
            }

            cout << endl;
        }

        void displayList(){
            for(int i = 0; i < n; i++){
                GraphNode *current = heads[i];
                while(current != NULL){
                    cout << heads[current->vertex]->name;
                    if(current->next != NULL){
                        cout << "->";
                    }
                    else{
                        cout << endl;
                    }

                    current = current->next;
                }
            }
        }

        /*
        void DFS(int v, int visited[]){
            cout << v << ",";
            visited[v] = 1;
            
        }

        void DFS(){
            int v;
            int visited[n];
            for(int i = 0 i < n; i++){
                visited[i] = 0;
            }


        }
        
        */
};

int main(){
    Graph g;
    g.displayMatrix();
    g.displayList();
    return(0);
}

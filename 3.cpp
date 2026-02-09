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
                cout << endl;
            }
        }
};

int main(){
    Graph g;
    g.display();
    return(0);
}

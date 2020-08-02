#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <errno.h>
#include <iterator>
#include <utility>
#include <algorithm>

const long long lrg = 100000000;

using namespace std;


struct vertex{
    int idex;
    bool visited = false;
    int path_length = 0;
    std::vector<int> path;    
    std::vector<std::pair<vertex*,int>> adjacent_vert;
};

bool compareByIdex(const vertex &a, const vertex &b)
{
    return a.idex < b.idex;
}

void dijkstra(vertex *V, int num_vertices){
    
    V[0].visited = true;
    
    // X is vector containing visited vertices
    std::vector<vertex> X = {V[0]};

    while(X.size() < num_vertices){
        // vertex in our visited set
        vertex current;
        // vertex not in our visited set
        vertex next;
        int edge_len;
        int greedy = lrg;
        // iterate through all vertices in our visited set
        for(auto vert : X){           
            // iterate through all vertices adjacent to our visted vertices
            for(auto adj : vert.adjacent_vert){
                // it we've already visited the adjacent vertex then skip the rest
                if(V[adj.first->idex].visited)continue;
                // Dijkstra's greedy criterion
                if(vert.path_length + adj.second < greedy){
                    greedy = vert.path_length + adj.second;
                    // the already visited vertex that connects to the unexplored vertex
                    current = vert;
                    // the next vertex to be added to our visited set
                    next = *(adj.first);
                    edge_len = adj.second;
                }
            }
        }
        // in our graph, mark the next vertex as having been visited
        V[next.idex].visited = true;
        // calculate the path length to to the next vertex
        next.path_length = current.path_length + edge_len;    
        // path to next vertex
        next.path = current.path;
        next.path.push_back(current.idex);
        // finally add the next vertex to our set of visited vertices, X
        X.push_back(next);
        
    }
    
    std::sort(X.begin(), X.end(), compareByIdex);
    
    cout << "-------" << endl;
    for(int i = 0; i<X.size(); i++){
        cout << "To vertex " << X[i].idex << "  path length is " << X[i].path_length 
             << ",  path is ";
        for(int p : X[i].path)
            cout << p << " -> ";
        cout << X[i].idex << endl;
    }    
    
}


int main(int argc, char* argv[]){

    std::string in_file_name = argv[1];
        
    int num_vertices = 0;

    FILE * in_file = fopen(in_file_name.c_str(),"r");
    if (in_file == NULL) perror ("Error opening file");

    char buffer[1024];
    while(fgets(buffer, 1024, in_file)){
        num_vertices++;
    }
    
    printf("Input graph contains %d vertices.\n",num_vertices);
    
    // array of vertices
    vertex * V;
    V = new vertex[num_vertices];
    
    rewind(in_file);
    
    int i_tmp = 0;
    while(fgets(buffer, 1024, in_file)){
        std::stringstream ss(buffer);
        V[i_tmp].idex = i_tmp;
        int id;
        char c;
        int adjacent_vert_idex;
        int adjacent_vert_len;
        ss >> id;
        while(ss >> adjacent_vert_idex >> c >> adjacent_vert_len){
            std::cout << V[i_tmp].idex << "  " << adjacent_vert_idex-1 << "," << adjacent_vert_len << "  ";
            V[i_tmp].adjacent_vert.push_back(std::make_pair(&V[adjacent_vert_idex-1],adjacent_vert_len));
        }
        std::cout << endl;
        i_tmp++;
    }
    
    dijkstra(V,num_vertices);
            
    delete [] V;
    
}
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
       
        vertex next;
        vertex current;
        int edge_len;
        int greedy = lrg;
        for(auto vert : X){           
            for(auto adj : vert.adjacent_vert){
                if(V[adj.first->idex].visited)continue;   
                if(vert.path_length + adj.second < greedy){
                    greedy = vert.path_length + adj.second;
                    current = vert;
                    next = *(adj.first);
                    edge_len = adj.second;
                }
            }
        }
        // in our graph, mark the new vertex as having been visited
        V[next.idex].visited = true;
        next.path_length = current.path_length + edge_len;
        next.path = current.path;
        next.path.push_back(current.idex);
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
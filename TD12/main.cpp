#include <iostream>
#include "Graph.h"

int main() {
    std::cout << "Hello, World!" << std::endl;


//    try{
//        Graph G("Test",9);
//
//        G.addEdge(0,8);
//        G.addEdge(1,2);
//        G.addEdge(7,5);
//        G.addEdge(3,4);
//        G.addEdge(0,8);
//
//        G.addEdge(0,8);
//
//
//        cout<<G;
//    }
//    catch (GraphException &e){
//        cout<<e.what()<<endl;
//    }

    try{
        GraphG<float > G("test");

        G.addEdge(1,3);
        G.addEdge(1,5);
        G.addEdge(1,7);
        G.addEdge(7,9);
        G.addEdge(100,1);

        cout <<G;

        G.removeVertex(1);
        cout << G;


        //G.addEdge(0,8);


        cout<<G;
    }
    catch (GraphException &e){
        cout<<e.what()<<endl;
    }






    return 0;
}
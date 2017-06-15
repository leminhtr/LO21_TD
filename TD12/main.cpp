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

//    try{
//        GraphG<float > G("test");
//
//        G.addEdge(1,3);
//        G.addEdge(1,5);
//        G.addEdge(1,7);
//        G.addEdge(7,9);
//        G.addEdge(100,1);
//
//        cout <<G;
//
//        G.removeVertex(1);
//        cout << G;
//
//
//        //G.addEdge(0,8);
//
//
//        cout<<G;
//    }
//    catch (GraphException &e){
//        cout<<e.what()<<endl;
//    }


    try{
        Graph G1("G1",5); cout<<G1;
        G1.addEdge(0,1); G1.addEdge(0,2); G1.addEdge(1,2); G1.addEdge(1,3);
        G1.addEdge(1,4); G1.addEdge(3,0);
        cout<<G1;
        GraphG<char> G2("G2");
        G2.addVertex('a'); G2.addVertex('b'); G2.addEdge('a','c');
        G2.addEdge('a','d'); G2.addEdge('d','e'); G2.addEdge('e','b');

        cout<<G2;
        cout<<"vertices of G2 are: ";
        for(GraphG<char>::vertex_iterator it=G2.begin_vertex();
            it!=G2.end_vertex(); ++it) cout<<*it<<" ";
        cout<<"\nsuccessors of a: ";
        for(GraphG<char>::successor_iterator it=G2.begin_successor('a');
        it!=G2.end_successor('a'); ++it){ std::cout<<*it<<" "; }
        GraphG<string> G3("Pref");
        G3.addEdge("LO21","IA01"); G3.addEdge("IA02","IA01"); G3.addEdge("IA01","NF17");
        G3.addEdge("IA02","NF16"); G3.addEdge("NF93","NF16");
        cout<<G3;
    }catch(exception e){ std::cout<<e.what()<<"\n"; }



    return 0;
}
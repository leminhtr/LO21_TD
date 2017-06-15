//
// Created by Minh Tri on 15/06/2017.
//

#ifndef TD12_GRAPH_H
#define TD12_GRAPH_H

#include<string>
#include<stdexcept>
#include <iostream>
#include<vector>
#include <c++/list>
#include <map>
#include <set>  // ensemble de ...

using namespace std;

class GraphException : public exception {
    string info;
public:
    GraphException(const string& i) throw():info(i){}
    virtual ~GraphException() throw(){}
    const char* what() const throw(){ return info.c_str(); }
};



class Graph {
    vector<list<unsigned int> > adj;
    string name;
    //champ indiquant le nombre d'arcs
    unsigned int nb_edges;


public:
    // appel le constructor de vector<list <unsigned int> avec nb comme parametre
    // initialiser name à n et nb_edges à 0
    Graph(const string& n, unsigned int nb): adj(nb), name(n), nb_edges(0){}


    const string& getName() const{ return  name;}
    unsigned int getNbVertices() const {return adj.size();}
    unsigned int getNbEdges() const { return  nb_edges;}
    void addEdge(unsigned int i, unsigned int j);
    void removeEdge(unsigned int i, unsigned int j);
    const list<unsigned int>& getSuccessors(unsigned int i) const;
    const list<unsigned int> getPredecessors(unsigned int j) const;
};
ostream& operator<<(ostream& f, const Graph& G);


//**************** class GraphG **************************
template<class Vertex>
class GraphG {
    map<Vertex,set<Vertex> > adj;   // tableau clé-valeur, ensemble de Vertex
            // set : la valeur d'un élément est aussi sa clé.
    string name;
    unsigned int nbEdges;


public:
    GraphG(const string& n): adj(), name(n), nbEdges(0) {}


    const string& getName() const { return name;}
    unsigned int getNbVertices() const { return adj.size();}
    unsigned int getNbEdges() const { return nbEdges;}

    void addVertex(const Vertex& i);
    void addEdge(const Vertex& i, const Vertex& j);
    void removeEdge(const Vertex& i, const Vertex& j);
    void removeVertex(const Vertex& i);
    void print(ostream& f) const;
};
template<class V> ostream& operator<<(ostream& f, const GraphG<V>& G);

//************* Class GraphG : méthode
template <class Vertex>
void GraphG<Vertex>::addVertex(const Vertex& i){
    /*  appel à l'operateur []
     * si i correspond à la clé d'un élément, ça retourne la référence vers la valeur mappée (clé-valeur)
     * si i ne correspond à la clé d'aucun élément, la fonction insert un nouveau élément avec cette clé.
     */
    adj[i];
    /* Solutions alternatives
     *  1. - adj.insert(make_pair(i, std::set<vectex()>));
     *
     *  2. - map<Vertex, set<Vertex>>::iterator it= adj.find(i)
     *      if(it==adj.end()) adj[i]==set<Vertex();
     */
}

template <class Vertex>
void GraphG<Vertex>::addEdge(const Vertex &i, const Vertex &j) {
    // ajouter le sommet j au graphe s'il n'existe pas !
    adj[j];
    //ajouter le sommet i au graphe s'il n'existe pas !
    std::pair<typename set<Vertex>::iterator, bool> ret;    //ret est un objet de la classe pair <=> un couple
                        // set : conteneur  : ensemble d'éléments unique et dans un ordre spécifique
    ret = adj[i].insert(j); //insère j à l'adjacence de i

    //incrémenter nbEdges que dans le cas où l'insertion a été faite
    // cart set::insert n'autorise pas la duplication des éléments
    if(ret.second)  // second élément du couple
        nbEdges++;

}

template <class Vertex>
void GraphG<Vertex>::removeEdge(const Vertex& i, const Vertex& j){
    //trouver le sommet i
    typename map<Vertex, set<Vertex> >::iterator it=adj.find(i);
    //si le sommet existe bien dans la liste des sommets
    if(it!= adj.end())
        nbEdges= nbEdges - (*it).second.erase(j);   //return nb éléments supprimés
    //On peut aussi écrire : nbEdges = nbEdges - it->second.erase(j);
}

template <class Vertex>
void GraphG<Vertex>::removeVertex(const Vertex& i){
    // Vérifier si i existe
    typename map<Vertex, set<Vertex> >::iterator it=adj.find(i);
    if(it!=adj.end()) {
        //décrémenter nbEdges par le nombre de successeurs de i. -> On enlève tous les arcs contenant le sommet i
        nbEdges -= (*it).second.size();

        //supprimer le sommet i
        adj.erase(it);

        //chercher les arcs dont i est la destination
        for(it=adj.begin(); it!=adj.end();++it){

            // ------------- Solution 1
            typename set<Vertex>::const_iterator it2=(*it).second.find(i);
            if(it2!=(*it).second.end()){
                // i est bien sommet successeur de (*it)
                (*it).second.erase(it2);
                nbEdges--;
            }

            // ------------ Solution alternative (moins explicite) ---------------
             /* nbEdges-= (*it).second.erase(i);    //erase cherche i. Si i est trouvé alors supprime i et retourne nb éléments supprimés (1)
             */
        }
    }
}

template <class Vertex>
void GraphG<Vertex>::print(ostream& f) const{
    f<< "Graph "<< getName()<<" ("<<getNbVertices()<<" vertices and "<<getNbEdges()<< " edges)"<< endl;

    typename map<Vertex, set<Vertex> >::const_iterator it; // iterator sur le type map de (clé-valeur) (sommet, ensemble sommet)

    for (it = adj.begin(); it != adj.end() ; ++it) {
        f<<it->first<<": ";
        typename set<Vertex>::const_iterator it2;
        for  (it2 = it->second.begin(); it2 !=it->second.end() ; ++it2) {
            f<<*it2<<" "<<endl;
        }
    }
}

template <class Vertex>
ostream& operator<<(ostream& f, const GraphG<Vertex>& G){
    G.print(f);
    return f;
}







#endif //TD12_GRAPH_H

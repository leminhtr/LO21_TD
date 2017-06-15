//
// Created by Minh Tri on 15/06/2017.
//

#include <c++/algorithm>
#include "Graph.h"


/*!
 * \brief Ajoute un arc (i,j)
 * @param i : Le sommet i
 * @param j : Le sommet j
 *
 * \details 1) Check if problème de taille
 *          2) Cherche si l'arc (i,j) existe déjà en cherchant si j est déjà un successeur de i
 *          3) Sinon, insère le sommet j aux tableau d'adjacences
 */
void Graph::addEdge(unsigned int i, unsigned int j){
    // si i ou j est plus grand que le nombre de sommets => Erreur
    if(i>= getNbVertices() || j>= getNbVertices())
        throw GraphException("Bad argument : a vertex of the edge is not defined.");

    //Vérifie si j est un successeur de i Retourne un iterator : (*it) == unsigned int
    // Cherche j dans la list entre .begin() et .end()
    list<unsigned int>::iterator it= std::find(adj[i].begin(), adj[i].end(), j);// cherche le sommet j

    if(it==adj[i].end())// si l'iterator est à la fin de la liste alors l sommet n'a pas été trouvé
    {
        adj[i].insert(adj[i].end(),j);  //donc on peut insérer le sommet j à la fin du tableau d'adjacence
        nb_edges++;
    }
}

void Graph::removeEdge(unsigned int i, unsigned int j) {
    // si i ou j est plus grand que le nombre de sommets => Erreur
    if(i>= getNbVertices() ||j>= getNbVertices())
        throw GraphException("Bad argument : a vertex of the edge is not defined.");

    // Cherche j dans la list entre .begin() et .end()
    list<unsigned int>::iterator it=find (adj[i].begin(),adj[i].end(),j);
    if (it!=adj[i].end()){
        //j est successeur de i
        /*!
         * \a it : position à supprimer
         */
        adj[i].erase(it);
        nb_edges--;
    }
    else
        throw GraphException("Bad argument : edge is not defined.");

}

const list<unsigned int> &Graph::getSuccessors(unsigned int i) const {
    if(i>= getNbVertices())
        throw GraphException("Bad argument : vertex is not defined.");
    return adj[i];
}

//renvoie la liste des prédécesseurs de j
const list<unsigned int> &Graph::getPredecessors(unsigned int j) const {
    if(j>=getNbVertices())
        throw GraphException("Bad argument : vertex is not defined.");

    list<unsigned int> res;

    for (unsigned int i = 0; i < adj.size(); ++i) {
        //parcourir tous les sommets du graphe
        if(find(adj[i].begin(),adj[i].end(),j) != adj[i].end())//si on trouve un adjacent à i vaut j avant .end() alors j est un succ de i
            //j est successeur de i
        res.insert(res.end(),i);
        //insérer i à la fin de la liste res !
    }
    //renvoie la liste des prédécesseurs de j
    return res;

}

ostream& operator<<(ostream& f, const Graph& G){
    f<< "Graph"<<G.getName()<<" ("<<G.getNbVertices()<<" vertices and "<<G.getNbEdges()<< " edges)"<<endl;

    for (unsigned int i = 0; i <G.getNbVertices() ; ++i) {
        f<<i<<":";
        list<unsigned int>::const_iterator it;
        for (it = G.getSuccessors(i).begin(); it !=G.getSuccessors(i).end() ; ++it) {
            f<<*it<< " ";
        }
        f<<endl;
    }
    return f;

}


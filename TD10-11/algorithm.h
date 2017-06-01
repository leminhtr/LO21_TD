//
// Created by Minh Tri on 01/06/2017.
//

#ifndef TD10_11_ALGORITHM_H
#define TD10_11_ALGORITHM_H



namespace  LO21 {
    template<class IT>IT element_minimum(IT it1, IT it2);

    // surcharge de element_min
    template<class IT, class COMP>IT element_minimum(IT it1, IT it2, COMP comp);    // comp peut être une fonction quelconque => /!\ FONCTION à DEFINIR
                                                                                    // on a donc une fonction element_min dynamique
                                                                                    // qui peut faire différentes comparaisons de 2 IT

}

/*minimum_element qui prend en arguments deux itérateurs it1 et it2 de n’importe
quel conteneur et qui permet de renvoyer un itérateur désignant l’élément minimum dans le conteneur entre les itérateurs it1 et it2 (it2 non compris)
*/

template<class IT> IT LO21::element_minimum(IT it1, IT it2) {

    IT it_min = it1;
    ++it1;
    while(it1!= it2){   // tant qu'on arrive pas à it2,
        if(*it1<*it_min) // on cherche un minimum
            it_min = it1;

        ++it1;
    }

    return it_min; // on renvoie le minimum

}

template<class IT, class COMP>IT LO21::element_minimum(IT it1, IT it2, COMP comp){
    IT it_min =it1;
    ++it1;

    while(it1!= it2){
        if(comp(*it1, *it_min)) // comp est une fonction dynamique : < ou <= ou ou > ou >=
                                // on compare donc *it1 et /it2 avec une fonction donnée en argument
            //comp() appel le constructeur de la classe comparateur (voir main) qui effectue la comparaison return a<b ou a>b
            it_min=it1;

        ++it1;

    }
    return it_min;


};




#endif //TD10_11_ALGORITHM_H

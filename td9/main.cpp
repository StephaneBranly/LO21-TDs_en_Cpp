#include "graph.h"
#include "timing.h"
#include "evenement.h"
#include "agenda.h"
#include "container.h"

#include <list>
#include<iostream>

using namespace std;
using namespace TIME;
int main(int argc, char *argv[])
{
    // EXO 31
//   try{
//        Graph G1("G1",5);
//        cout<<G1;
//        G1.addEdge(0,1);
//        G1.addEdge(0,2);
//        G1.addEdge(1,2);
//        G1.addEdge(1,3);
//        G1.addEdge(1,4);
//        G1.addEdge(3,0);
//        cout<<G1;
//    }catch(exception e)
//    {
//        std::cout<<e.what()<<"\n";
//    }

//    Evt1j e1(Date(4,10,1957),"Spoutnik");
//    Evt1j e2(Date(11,6,2013),"Shenzhou");
//    Evt1jDur e3(Date(11,6,2013),"Lancement de Longue Marche",Horaire(17,38),Duree(0,10));
//    e1.afficher();
//    e2.afficher();
//    e3.afficher();

//    Rdv e(Date(11,11,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
//    std::cout<<"RDV:";
//    e.afficher();

    //    e1.afficher();
    //    e2.afficher();
    //    e3.afficher();
    //    e4.afficher();
//    Evt1j e1(Date(4,10,1957),"Spoutnik");
//    Evt1j e2(Date(11,6,2013),"Shenzhou");
//    Evt1jDur e3(Date(11,6,2013),"Lancement de Longue Marche",Horaire(17,38),Duree(0,10));
//    Rdv e4(Date(11,4,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");

//    Agenda agenda;
//    agenda<<e1 << e2 << e3 << e4;
////    agenda.afficher();

//    for(auto it = agenda.begin(); it!=agenda.end(); ++it)
//        std::cout<<*it;

    TD::Vector<int> monVecteur(4,1);
    monVecteur[2]=6;
    using namespace std;
    for(unsigned int i = 0; i<monVecteur.size();i++)
    {
        cout << monVecteur[i] << endl;
    }
    cout << "pile 1" << endl;
    TD::Stack1<int, list<int>> pile;
    pile.push(4);
    pile.push(2);
    pile.push(1);
    pile.push(6);
    while(!pile.empty())
    {
        cout << pile.top() << endl;
        pile.pop();
    }

    std::list<int> l;
    l.push_back(2);
    l.push_back(5);
    l.push_back(6);
    l.push_back(2);
    l.push_back(5);
    l.push_back(1);
//    auto min = element_minimum(l.begin(),l.end());

    return 0;
}

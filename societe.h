#ifndef SOCIETE_H
#define SOCIETE_H
#include <iostream>
#include <cstring>
using namespace std;
struct valeur
{
    char* marque;
    char* gamme;
    int annee;
    char* modele;
};
struct Voiture
{
    char* cle;
    valeur val;
};
class Societe
{
private:
   int nbml;
   int nbmc;
   Voiture*** tabVo;
public:
    Societe(int nbl,int nbc);
    ~Societe();
    void insertion(Voiture);
    void supprimer(const char*);
    bool rechercher(const char*);
    int hachage(const char* )const;
    void affichage()const;
    Societe(const Societe&);
    Societe& operator=(const Societe&);

    friend void situation(Societe);

};
#endif 
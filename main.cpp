#include "societe.h"
#include <iostream>
using namespace std;

int main() {
    Societe maSociete(5, 4);
   Societe soc2(5,4);
  
    Voiture v1;
    v1.cle = new char[strlen("ABC123") + 1];
    strcpy(v1.cle, "ABC123");
    v1.val.marque = new char[strlen("Toyota") + 1];
    strcpy(v1.val.marque, "Toyota");
    v1.val.gamme = new char[strlen("SUV") + 1];
    strcpy(v1.val.gamme, "SUV");
    v1.val.annee = 2020;
    v1.val.modele = new char[strlen("RAV4") + 1];
    strcpy(v1.val.modele, "RAV4");

    Voiture v2;
    v2.cle = new char[strlen("XYZ789") + 1];
    strcpy(v2.cle, "XYZ789");
    v2.val.marque = new char[strlen("Honda") + 1];
    strcpy(v2.val.marque, "Honda");
    v2.val.gamme = new char[strlen("Sedan") + 1];
    strcpy(v2.val.gamme, "Sedan");
    v2.val.annee = 2019;
    v2.val.modele = new char[strlen("Civic") + 1];
    strcpy(v2.val.modele, "Civic");

    Voiture v3;
    v3.cle = new char[strlen("LMN456") + 1];
    strcpy(v3.cle, "LMN456");
    v3.val.marque = new char[strlen("Ford") + 1];
    strcpy(v3.val.marque, "Ford");
    v3.val.gamme = new char[strlen("Truck") + 1];
    strcpy(v3.val.gamme, "Truck");
    v3.val.annee = 2021;
    v3.val.modele = new char[strlen("F-150") + 1];
    strcpy(v3.val.modele, "F-150");

    Voiture v4;
    v4.cle = new char[strlen("OUS123") + 1];
    strcpy(v4.cle, "OUS123");
    v4.val.marque = new char[strlen("Deribordo") + 1];
    strcpy(v4.val.marque, "Deribordo");
    v4.val.gamme = new char[strlen("Boum") + 1];
    strcpy(v4.val.gamme, "Boum");
    v4.val.annee = 2024;
    v4.val.modele = new char[strlen("OKA") + 1];
    strcpy(v4.val.modele, "OKA");
  
    maSociete.insertion(v1);
    maSociete.insertion(v2);
    maSociete.insertion(v3);
    maSociete.insertion(v4);
   
    cout << "Affichage de la société après insertion : " << endl;
    maSociete.affichage();

    cout << "\nRecherche de la voiture avec la clé 'XYZ789' :";
    if (maSociete.rechercher("XYZ789")) {
        cout << "Voiture trouvée." << endl;
    } else {
        cout << "Voiture non trouvée." << endl;
    }

    cout << "\nSuppression de la voiture avec la clé 'ABC123'." << endl;
    maSociete.supprimer("ABC123");
  
    cout << "Affichage de la société après suppression : " << endl;
    maSociete.affichage();

     Societe soc(maSociete);

     situation(soc);

     soc2=maSociete;
     soc2.affichage();

    delete[] v1.cle;
    delete[] v1.val.marque;
    delete[] v1.val.gamme;
    delete[] v1.val.modele;
    
    delete[] v2.cle;
    delete[] v2.val.marque;
    delete[] v2.val.gamme;
    delete[] v2.val.modele;

    delete[] v3.cle;
    delete[] v3.val.marque;
    delete[] v3.val.gamme;
    delete[] v3.val.modele;

    delete[] v4.cle;
    delete[] v4.val.marque;
    delete[] v4.val.gamme;
    delete[] v4.val.modele;

    return 0;
}

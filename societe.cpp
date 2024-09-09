#include"societe.h"
Societe::Societe(int nbl,int nbc)
{
    nbml=nbl;
    nbmc=nbc;
    tabVo=new Voiture**[nbml];
    for(int i=0; i<nbml;i++){
        tabVo[i]=new Voiture*[nbmc];
    }
    for(int i=0; i< nbml;i++){
        for(int j=0;j< nbmc;j++){
            tabVo[i][j]=nullptr;
        }
    }
}
Societe::~Societe() {
   for(int i=0; i< nbml; i++) {
        for(int j=0; j< nbmc; j++) {
            if (tabVo[i][j]) {
                delete[] tabVo[i][j]->cle;
                delete[] tabVo[i][j]->val.marque;
                delete[] tabVo[i][j]->val.gamme;
                delete[] tabVo[i][j]->val.modele;
                delete tabVo[i][j];
                tabVo[i][j] = nullptr;
            }
        }
        delete[] tabVo[i]; 
    }
    delete[] tabVo; 
}
void Societe::insertion(Voiture v) {
    int k = hachage(v.cle);
    for (int i = 0; i < nbmc; i++) {
        if (tabVo[k][i] != nullptr && strcmp(this->tabVo[k][i]->cle, v.cle) == 0) {
            cout << "Attention, la voiture avec cette clé existe déjà dans la société !" << endl;
            return;
        }
    }
    for (int j = 0; j < nbmc; j++) {
        if (tabVo[k][j] == nullptr) {
            tabVo[k][j] = new Voiture;  
           
            tabVo[k][j]->cle = new char[strlen(v.cle) + 1];
            strcpy(tabVo[k][j]->cle, v.cle);

            tabVo[k][j]->val.marque = new char[strlen(v.val.marque) + 1];
            strcpy(tabVo[k][j]->val.marque, v.val.marque);

            tabVo[k][j]->val.gamme = new char[strlen(v.val.gamme) + 1];
            strcpy(tabVo[k][j]->val.gamme, v.val.gamme);

            tabVo[k][j]->val.annee = v.val.annee;

            tabVo[k][j]->val.modele = new char[strlen(v.val.modele) + 1];
            strcpy(tabVo[k][j]->val.modele, v.val.modele);

            return; 
        }
    }
    cout << "Impossible d'insérer, la ligne est pleine." << endl;
}

void Societe::supprimer(const char* cl) {
    int k = hachage(cl);
    for (int i = 0; i < nbmc; i++) {
        if (tabVo[k][i] != nullptr && strcmp(this->tabVo[k][i]->cle, cl) == 0) {

            delete[] tabVo[k][i]->cle;
            delete[] tabVo[k][i]->val.marque;
            delete[] tabVo[k][i]->val.gamme;
            delete[] tabVo[k][i]->val.modele;
           
            delete tabVo[k][i];
            tabVo[k][i] = nullptr;

            return;
        }
    }
    cout << "Voiture non trouvée." << endl;
}

bool Societe::rechercher(const char* cl){
    int k=hachage(cl);
    for(int i=0;i< nbmc;i++){
        if(strcmp(this->tabVo[k][i]->cle,cl)==0)
       return true;
    }
    return false;
}
void Societe::affichage() const {
    for (int i = 0; i < nbml; i++) {
        for (int j = 0; j < nbmc; j++) {
            if (tabVo[i][j] != nullptr) {
                 cout<< tabVo[i][j]->cle <<" " 
                     << tabVo[i][j]->val.marque <<" " 
                     << tabVo[i][j]->val.gamme <<" " 
                     << tabVo[i][j]->val.annee <<" " 
                     << tabVo[i][j]->val.modele <<" <-> ";
            }
        }
        cout<<endl;
    }
}
int Societe::hachage(const char* cle) const {
        int hash = 0;
        for (int i = 0; cle[i] != '\0'; i++) {
            hash = (hash * 31 + cle[i]) % nbml;
        }
        return hash;
}
Societe::Societe(const Societe& s2){
    nbml=s2.nbml;
    nbmc=s2.nbmc;
    this->tabVo=new Voiture**[s2.nbml];
     for(int i=0; i<nbml;i++){
        tabVo[i]=new Voiture*[nbmc];
    }
    for(int i=0; i< nbml;i++){
        for(int j=0;j< nbmc;j++){
            if(s2.tabVo[i][j]!=nullptr){
            tabVo[i][j]=new Voiture;

            tabVo[i][j]->cle=new char[strlen(s2.tabVo[i][j]->cle)+1];
            strcpy(tabVo[i][j]->cle,s2.tabVo[i][j]->cle);

             tabVo[i][j]->val.marque=new char[strlen(s2.tabVo[i][j]->val.marque)+1];
            strcpy(tabVo[i][j]->val.marque,s2.tabVo[i][j]->val.marque);

             tabVo[i][j]->val.gamme=new char[strlen(s2.tabVo[i][j]->val.gamme)+1];
            strcpy(tabVo[i][j]->val.gamme,s2.tabVo[i][j]->val.gamme);

            tabVo[i][j]->val.annee=s2.tabVo[i][j]->val.annee;

             tabVo[i][j]->val.modele=new char[strlen(s2.tabVo[i][j]->val.modele)+1];
            strcpy(tabVo[i][j]->val.modele,s2.tabVo[i][j]->val.modele);
            }
        }
    }
}
Societe& Societe::operator=(const Societe& s2){
    if(this==&s2){return *this;}
    for(int i=0; i< nbml; i++) {
        for(int j=0; j< nbmc; j++) {
            if (tabVo[i][j]) {
                delete[] tabVo[i][j]->cle;
                delete[] tabVo[i][j]->val.marque;
                delete[] tabVo[i][j]->val.gamme;
                delete[] tabVo[i][j]->val.modele;
                delete tabVo[i][j];
                tabVo[i][j] = nullptr;
            }
        }
        delete[] tabVo[i]; 
    }
    delete[] tabVo; 

    nbml=s2.nbml;
    nbmc=s2.nbmc;
    this->tabVo=new Voiture**[s2.nbml];
     for(int i=0; i<nbml;i++){
        tabVo[i]=new Voiture*[nbmc];
    }
    for(int i=0; i< nbml;i++){
        for(int j=0;j< nbmc;j++){
            if(s2.tabVo[i][j]!=nullptr){
            tabVo[i][j]=new Voiture;

            tabVo[i][j]->cle=new char[strlen(s2.tabVo[i][j]->cle)+1];
            strcpy(tabVo[i][j]->cle,s2.tabVo[i][j]->cle);

             tabVo[i][j]->val.marque=new char[strlen(s2.tabVo[i][j]->val.marque)+1];
            strcpy(tabVo[i][j]->val.marque,s2.tabVo[i][j]->val.marque);

             tabVo[i][j]->val.gamme=new char[strlen(s2.tabVo[i][j]->val.gamme)+1];
            strcpy(tabVo[i][j]->val.gamme,s2.tabVo[i][j]->val.gamme);

            tabVo[i][j]->val.annee=s2.tabVo[i][j]->val.annee;

             tabVo[i][j]->val.modele=new char[strlen(s2.tabVo[i][j]->val.modele)+1];
            strcpy(tabVo[i][j]->val.modele,s2.tabVo[i][j]->val.modele);
            }
            else {
                tabVo[i][j] = nullptr;  
            }
        }
    }
    return *this;
}

void situation(Societe s){
    cout<<"situation d'invocation pour le constructeur de recopie"<<endl;
    cout<<s.nbmc;

}
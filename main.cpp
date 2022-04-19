#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
#include "Pendu.h"

int main()
{ string motpioche; char lettre_donnee;
int *lettretrouvee=NULL,coupsRestants=10;
    cout << "Bienvenue dans le Pendu!!\n\n" << endl;
if(!piocherMot(motpioche)) exit(0);
    lettretrouvee=( int*) malloc(motpioche.size()*sizeof(int));
     if(lettretrouvee==NULL) exit(0);
     for(int i=0;i<motpioche.size();i++) lettretrouvee[i]=0;
      while(coupsRestants>0 && !gagner(lettretrouvee,motpioche))
 { cout << "\n\nIl vous reste " << coupsRestants <<" coups a jouer";
   cout << "\nQuel est le mot secret ? ";
     for (int i = 0 ; i < motpioche.size() ; i++)
{
if (lettretrouvee[i]) // Si on a trouvé la lettre n° i
cout << motpioche[i]; // On l'affiche
else
cout << "*"; // Sinon, on affiche une étoile pour les lettres non trouvées
}
cout << "\nProposez une lettre: ";
lettre_donnee=lirecaractere();
if(!rechercherlettre(lettre_donnee,motpioche,lettretrouvee)) {coupsRestants--;}
 }
if(gagner(lettretrouvee,motpioche)) cout << "\n\nGagne! Le mot secret etait bien " << motpioche <<"\n";
 else cout << "\n\nPerdu ! Le mot secret etait :" << motpioche <<"\n";
 free(lettretrouvee);
 system("PAUSE");
    return 0;
}

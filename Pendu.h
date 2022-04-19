#ifndef PENDU_H_INCLUDED
#define PENDU_H_INCLUDED
int nombre_aleatoir(int nbrMax)
{
srand(time(0));
return(rand() % nbrMax) ;
}
int piocherMot(string &motpioche)
{ ifstream dico("dico.txt");
if(dico)
{
int i=0,j=0,nbrpioche; char a;
while(a!='0')
{
 dico.get(a);
 if(a=='\n') {i++;}
}
nbrpioche=nombre_aleatoir(i);
dico.seekg(0, ios::beg);
while(j<nbrpioche)
{
    dico.get(a);
    if(a=='\n') {j++;}
}
dico >> motpioche;
}
else
{
cout << "ERREUR: Impossible d'ouvrir le dictionnaire des mots." <<
endl;
}
return 1;
}
char lirecaractere()
{ char caractere;
 caractere=getchar();
 caractere=toupper(caractere);/*Le caractere obtenu sera converti en magiscule*/
 while(getchar()!='\n');
 return caractere;
}
int gagner(int lettretrouvee[],string &motpioche)
{
    int i=0,joueurgagne=1;
    for(i=0;i<motpioche.size();i++)
    {
        if(lettretrouvee[i]==0) joueurgagne=0;
    }
    return joueurgagne;
}
int rechercherlettre(char lettre,string &motpioche,int lettretrouvee[])
{
    int i=0,bonnelettre=0;
    for(i=0;i<motpioche.size();i++)
    {
        if(lettre==motpioche[i])
        {
         bonnelettre = 1;
         lettretrouvee[i]=1;
        }
    }
    return bonnelettre;
}
#endif // PENDU_H_INCLUDED

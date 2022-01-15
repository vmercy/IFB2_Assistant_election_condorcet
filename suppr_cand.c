#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void suppr_cand(int nb_cand, int etat_candidats[50], char noms_candidats[50][51], char noms_classes[50][51])
{
    int pos=0;
    printf("\nSaisissez le numero de la ligne a liberer : ");
    scanf("%i",&pos);
    while(!((pos>=1)&&(pos<=nb_cand)&&strcmp(noms_classes[pos-1],"")!=0)) //message d'erreur si la position saisie ne fait pas partie des positions disponibles
    {
        printf("\nVous avez saisi une position inexistante ou qui correspond a une ligne vide (le dernier cas echeant, utilisez la fonction d'ajout dans le menu). Veuillez recommencer : ");
        scanf("%i",&pos);
    }
    for(int f=0; f<nb_cand; f++)    //on recherche l'index du candidat dans la liste de base pour pouvoir le libérer
    {
        if(strcmp(noms_classes[pos-1],noms_candidats[f])==0)
        {
            etat_candidats[f]=0;
        }
    }
    strcpy(noms_classes[pos-1],""); //on vide la ligne
}

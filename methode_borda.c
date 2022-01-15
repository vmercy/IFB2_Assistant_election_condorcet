#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "header.h"

void methode_borda(int nb_cand, int nb_elec, char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING], int liste_prefs[NB_MAX_ELECTEURS][NB_CANDIDATS])
{
    char tableau_points[NB_CANDIDATS]; //tableau du nombre de points associes a chaque candidat

    for(int g = 0; g<NB_CANDIDATS; g++)
    {
        tableau_points[g]=0;
    }

    for(int i = 0; i<nb_elec; i++)
    {
        for(int j=0; j<nb_cand; j++)
        {
            tableau_points[liste_prefs[i][j]]+=(nb_cand-(j+1));
        }
    }

    printf("\n\nVOICI LE TABLEAU DES POINTS DE BORDA : \n");
    int maxi_points = -1;
    int index_vainqueur = 0;
    int vainqueur_multiple = -1; //passe à 1 ou plus si le vainqueur est à ex-aequo avec un autre
    for(int h = 0; h<nb_cand; h++)  //on balaye une premiere fois pour déterminer le maximum de points
    {
        if(tableau_points[h]>=maxi_points)
        {
            maxi_points = tableau_points[h];
            index_vainqueur=h;
        }
        printf("\nNombre de points de %s : %i",noms_candidats[h], tableau_points[h]);
    }
    for(int h = 0; h<nb_cand; h++)  //puis on balaye une seconde fois pout déterminer le nombre de candidats qui atteignent ce maximum
    {
        if(tableau_points[h]==maxi_points)
        {
            vainqueur_multiple++;
        }
    }
    printf("\n");
    if(vainqueur_multiple==0)   //le vainqueur est unique, on l'affiche
    {
        printf("\nL'unique vainqueur de cette election selon la methode de Borda est donc %s.",noms_candidats[index_vainqueur]);
    }
    else if(vainqueur_multiple==-1)     //erreur d'execution : aucun vainqueur n'a ete trouve
    {
        printf("\nAucun vainqueur n'a ete trouve avec la methode de Borda.");
    }
    else    //les vainqueurs de Borda sont multiples
    {
        printf("\nVoici les multiples vainqueurs a ex-aequo selon la methode de Borda : ");
        for(int y=0; y<nb_cand; y++)    //on balaye une troisième fois pour afficher les noms des candidats qui atteignent le score maximum
        {
            if(tableau_points[y]==maxi_points)
            {
                printf("\n%s",noms_candidats[y]);
            }
        }
    }





}

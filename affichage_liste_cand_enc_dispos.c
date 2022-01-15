#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void affichage_liste_cand_enc_dispos(int nb_cand, int etat_candidats[50], char noms_candidats[50][51])
{
    printf("\nVoici la liste des candidats encore disponibles : ");
    int nb_cand_dispos = 0;
    for(int p = 0; p<nb_cand; p++)      //compte le nombre de candidats encore disponibles
    {
        if(etat_candidats[p]==0)
        {
            nb_cand_dispos++;
        }
    }

    char noms_candidats_enc_dispo[50][51];
    char noms_candidats_melanges[50][51];

    for(int t = 0; t <50; t++)
    {
        strcpy(noms_candidats_enc_dispo[t],"");
        strcpy(noms_candidats_melanges[t],"");
    }

    for(int d=0; d<50; d++)
    {
        if(etat_candidats[d]==0)
        {
            int cand_place = 0;
            int f=0;
            while(cand_place==0)
            {
                if(strcmp(noms_candidats_enc_dispo[f],"")==0)
                {
                    strcpy(noms_candidats_enc_dispo[f],noms_candidats[d]);
                    cand_place=1;
                }
                else
                {
                    f++;
                }
            }
        }
    }

    melange_aleatoire(noms_candidats_enc_dispo,noms_candidats_melanges,nb_cand_dispos); //FONCTION DE TIRAGE SANS REMISE POUR PRESENTER LES CANDIDATS RESTANTS DANS UN ORDRE ALEATOIRE

    int nb_virg_posees = 0;
    for(int s=0; s<nb_cand_dispos; s++)
    {
        for(int q=0; q<strlen(noms_candidats_melanges[s]); q++)
        {
            printf("%c",noms_candidats_melanges[s][q]);
        }
        if(nb_virg_posees<nb_cand_dispos-1)
        {
            printf(", ");
            nb_virg_posees++;
        }
    }
}

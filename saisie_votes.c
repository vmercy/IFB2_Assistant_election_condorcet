#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "header.h"

void saisie_votes(int nb_cand, int nb_elec, char noms_candidats[50][51], char noms_cand_classes[50][51], int *init, char mentions_jug_maj[50], char initiales_possibles[6], char mentions_possibles[6][12], char nom_fichier[51], int jug_maj_recquis)
{
    if(nb_elec==-1)     //nombre d'electeurs indetermine
    {
        int dernier_vote = 1;   //passe à 0 lorsque le dernier electeur se signale
        while(dernier_vote==1){
            dernier_vote = saisie_liste_preferences(1,nb_cand,noms_candidats,noms_cand_classes);
        }
    }
    else
    {
        for(int u=1; u<=nb_elec; u++)
        {
            printf("\n\n");
            chargement();
            for(int u = 0; u <50; u++)  //on remonte tout ce qui se trouve affiché à l'écran pour présenter une console vide à l'électeur (on évite ainsi qu'il soit influencé par le vote de l'électeur précédent)
            {
                printf("\n");
            }
            printf("\n\n    SAISIE DES VOTES -- ELECTEUR N.%i",u);
            saisie_liste_preferences(0,nb_cand,noms_candidats,noms_cand_classes);
            if(jug_maj_recquis==1)
            {
                printf("\n\n    SAISIE DES VOTES -- ELECTEUR N.%i",u);
                saisie_mentions(init, nb_cand, noms_candidats, mentions_jug_maj, initiales_possibles, mentions_possibles);
            }
            ecriture_bulletin(nom_fichier, u, nb_cand,noms_cand_classes,mentions_jug_maj);
            for(int a = 0; a<nb_cand; a++)   //remise_a_zero
            {
                strcpy(noms_cand_classes[a],"");
                mentions_jug_maj[a]=0;
            }
        }
    }


}

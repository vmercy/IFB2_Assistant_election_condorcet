#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "header.h"

void methode_jugement_maj(int nb_elec, int nb_cand, char initiales_possibles[NB_MENTIONS],char mentions_possibles[NB_MENTIONS][TAILLE_MAX_MENTION], char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING], char mentions[NB_MAX_ELECTEURS][NB_CANDIDATS])
{
    int tableau_occurences[nb_cand][NB_MENTIONS];
    for(int i = 0; i<nb_cand; i++)  //reset tableau
    {
        for(int j = 0; j<NB_MENTIONS; j++)
        {
            tableau_occurences[i][j]=0;
        }
    }
    for(int i=0; i<nb_elec; i++)
    {
        for(int j=0; j<nb_cand; j++)
        {
            switch(mentions[i][j])
            {
            case 'R':
                tableau_occurences[j][0]++;
                break;
            case 'I':
                tableau_occurences[j][1]++;
                break;
            case 'P':
                tableau_occurences[j][2]++;
                break;
            case 'A':
                tableau_occurences[j][3]++;
                break;
            case 'B':
                tableau_occurences[j][4]++;
                break;
            case 'T':
                tableau_occurences[j][5]++;
                break;
            default:
                break;
            }
        }
    }
    printf("\n\nVoici le tableau des mentions, en pourcentages : \n");
    int long_max_nom = recherche_nom_plus_long(nb_cand,noms_candidats);
    int largeur_colonne = 5 + TAILLE_MAX_MENTION;
    int espace_a_combler_bis = TAILLE_MAX_MENTION-2;
    printf("\n");
    for(int i=0; i<long_max_nom+3; i++)
    {
        printf(" ");
    }
    for(int u=0; u<NB_MENTIONS; u++)        //affichage des intitules des mentions
    {
        printf("|%s",mentions_possibles[u]);    //on affiche l'intitule de la mention
        int nbr_espaces = largeur_colonne-strlen(mentions_possibles[u]);
        for(int j=0; j<nbr_espaces; j++)                  //on complete avec des espaces pour garder l'alignement dans le tableau
        {
            printf(" ");
        }
    }
    printf("\n");
    for(int j=0; j<nb_cand; j++)
    {
        printf("\n%s",noms_candidats[j]);
        int espace_a_combler = long_max_nom-strlen(noms_candidats[j])+3;
        for(int l=0; l<espace_a_combler; l++)   //on comble l'espace entre la fin du nom et le debut des donnees
        {
            printf(" ");
        }
        for(int k = 0; k<NB_MENTIONS; k++)
        {
            printf("|");
            //printf("%i", tableau_occurences[j][k]);
            float pourcentage = 100*(float)tableau_occurences[j][k]/nb_elec;
            printf("%6.2f%%",pourcentage);  //on utilise les doubles '%' pour afficher un symbole '%' sans le considérer comme un format
            for(int m=0; m<espace_a_combler_bis; m++)   //on comble l'espace vide entre le '%' et le début de la donnee suivante
            {
                printf(" ");
            }
        }
    }

    //une fois le tableau des occurences affiché, on détermine les mentions médianes de chaque candidat, on détermine la plus haute et on affiche le candidat correspondant
    char mentions_medianes[nb_cand];    //tableau qui repertorie, pour chaque candidat (dans l'ordre de la saisie des noms), sa mention médiane
    //les instructions qui suivent permettent de remplir le tableau precdent

    printf("\n");

    for(int i = 0; i<nb_cand; i++)
    {
        char mentions_triees[nb_elec];
        int pos_dep=0;  //position de depart du curseur qui sert à remplir le tableau des mentions triées
        for(int j=0; j<NB_MENTIONS; j++)
        {
            int nb_apparitions_mentions = tableau_occurences[i][j];
            //le for suivant permet de remplir la matrice mentions_triees
            int pos_fin = pos_dep+nb_apparitions_mentions;
            for(int k=pos_dep; k<pos_fin; k++)
            {
                mentions_triees[k]=initiales_possibles[j];
                pos_dep++;
            }
        }
        /*
        printf("\nTableau des mentions triees pour le candidat %s : ",noms_candidats[i]);
        printf("{");
        for(int g = 0; g<nb_elec;g++){
            printf(" %c,",mentions_triees[g]);
        }
        printf("}");
        */

        //on recherche maintenant la mention mediane de chaque candidat et on l'enregistre dans le tableau des mentions médianes

        int pos_mention_mediane = nb_elec/2;    //quelle que soit la parité de nb_elec, cette formule permet bien d'obtenir l'index de la position médiane
        mentions_medianes[i] = mentions_triees[pos_mention_mediane];

        printf("\nVoici la mention mediane du candidat %s : %s", noms_candidats[i],  mentions_possibles[getIdMention(mentions_medianes[i],initiales_possibles)]);   //on affiche les mentions medianes de tous les candidats
    }
    //on détermine la plus haute mention médiane

    int index_mention_mediane_max = -1;

    for(int i = 0; i<nb_cand; i++)
    {
        int index_mention = getIdMention(mentions_medianes[i],initiales_possibles);
        if(index_mention>=index_mention_mediane_max)
        {
            index_mention_mediane_max = index_mention;
        }
    }

    //on balaye une deuxième fois le tableau pour déterminer le nombre de candidats qui ont cette mention max

    int nb_vainqueur_jug_maj = 0;
    int index_unique_vainqueur = -1;

    for(int i = 0; i<nb_cand; i++)
    {
        int index_mention = getIdMention(mentions_medianes[i],initiales_possibles);
        if(index_mention==index_mention_mediane_max)
        {
            nb_vainqueur_jug_maj++;
            index_unique_vainqueur = i;
        }
    }
    printf("\n");
    if(nb_vainqueur_jug_maj==1)
    {
        printf("\nL'unique candidat vainqueur selon le jugement majoritaire est donc %s.", noms_candidats[index_unique_vainqueur]);
    }
    else if(nb_vainqueur_jug_maj>1)
    {
        printf("\nLes candidats vainqueurs selon le jugement majoritaire, arrives a ex-aequo, sont donc : ");
        for(int j =0; j<nb_cand; j++)   //on balaye une troisième fois les candidats pour afficher tous les candidats qui ont la mention max
        {
            int index_mention = getIdMention(mentions_medianes[j],initiales_possibles);
            if(index_mention==index_mention_mediane_max)
            {
                printf("- %s",noms_candidats[j]);
            }
        }
    }
    //on détermine maintenant le nombre de vainqueurs et on les affiche correctement
}

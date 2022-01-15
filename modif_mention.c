#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "header.h"

void modif_mention(int *init, int nb_cand, char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING], char mentions_possibles[NB_MENTIONS][TAILLE_MAX_MENTION], char mentions_jug_maj[NB_CANDIDATS])
{
    int pos=0;
    char nom_saisi[TAILLE_MAX_STRING];
    strcpy(nom_saisi,"");
    printf("\nSaisissez le nom du candidat dont vous voulez modifier la mention : ");
    gets(nom_saisi);
    if(*init==1)     //solution de double gets (anti-flood)
    {
        gets(nom_saisi);
    }
    *init=1;
    int res = 0;    //booleenne correspondant au resultat de la recherche
    for(int y = 0; y<nb_cand; y++)  //on recherche la position du candidat
    {
        if(strcmp(noms_candidats[y],nom_saisi)==0)
        {
            pos=y+1;
            res=1;
        }
    }
    while(!(res==1))
    {
        printf("Aucun candidat de ce nom n'a ete trouve. Veuillez recommencer la saisie : ");
        gets(nom_saisi);
        for(int y = 0; y<nb_cand; y++)  //on recherche la position du candidat
        {
            if(strcmp(noms_candidats[y],nom_saisi)==0)
            {
                pos=y+1;
                res=1;
            }
        }
    }

    printf("\nVoici les mentions que vous pouvez choisir en remplacement : \n");
    int nb_virgules_posees = 0;
    for(int y = 0; y<6; y++)      //rappelle la liste des mentions attribuables
    {
        for(int h=0; h<strlen(mentions_possibles[y]); h++)  //on utilise un for-printf au lieu du puts pour s'affranchir du retour à la ligne
        {
            printf("%c",mentions_possibles[y][h]);
        }
        printf(" (%i)",y+1);
        if(nb_virgules_posees!=5)    //on intercale une virgule sauf lorsqu'on atteint le dernier élement
        {
            printf(", ");
            nb_virgules_posees++;
        }
    }
    int num_mention = 0;
    printf("\nSaisissez le numero de la mention que vous voulez attribuer a ce candidat : ");
    scanf("%i",&num_mention);
    while(!((num_mention>=1)&&(num_mention<=6)))
    {
        printf("\nLe numero saisi ne correspond a aucune mention. Veuillez recommencer : ");
        scanf("%i",&num_mention);
    }
    switch(num_mention)
    {
    case 1 :
        mentions_jug_maj[pos-1]='R';
        break;
    case 2 :
        mentions_jug_maj[pos-1]='I';
        break;
    case 3 :
        mentions_jug_maj[pos-1]='P';
        break;
    case 4 :
        mentions_jug_maj[pos-1]='A';
        break;
    case 5 :
        mentions_jug_maj[pos-1]='B';
        break;
    case 6 :
        mentions_jug_maj[pos-1]='T';
        break;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

char menu_mentions(int nb_candidats, char noms_candidats[50][51], char mentions_jug_maj[50], char initiales_possibles[6], char mentions_possibles[6][12])
{
    char choix_menu = 0;

    printf("\nMENU : \n1 - Attribuer une mention a un candidat\n2 - Modifier la mention d'un candidat\n3 - Valider la saisie");
    printf("\n\n................................\n\n");

    int longueur_max_noms=0;
    for(int t=0; t<nb_candidats; t++)
    {
        if(strlen(noms_candidats[t])>longueur_max_noms)
        {
            longueur_max_noms=strlen(noms_candidats[t]);
        }
    }
    char noms_candidats_melanges[50][51];
    //INCLURE FONCTION DE MELANGE ALEATOIRE DES CANDIDATS (TIRAGE SANS REMISE)
    melange_aleatoire(noms_candidats,noms_candidats_melanges,nb_candidats);

    for(int u = 0; u<nb_candidats; u++) //on affiche la liste provisoire des mentions pour que l'electeur sache où il en est
    {
        char mention_trouvee = 0;
        printf("\n%i. ",u+1);
        //on recherche la mention du candidat
        for(int g = 0; g<nb_candidats; g++)
        {
            if(strcmp(noms_candidats[g],noms_candidats_melanges[u])==0)
            {
                mention_trouvee=mentions_jug_maj[g];
            }
        }
        for(int d=0; d<strlen(noms_candidats_melanges[u]); d++)    //for-printf au lieu de puts pour tout garder sur une meme ligne
        {
            printf("%c", noms_candidats_melanges[u][d]);
        }
        for(int z=0; z<1+longueur_max_noms-strlen(noms_candidats_melanges[u]); z++)   //permet d'aligner les mentions
        {
            printf(" ");
        }
        printf(" : ");
        if(mention_trouvee==0)
        {
            printf("************ AUCUNE MENTION ************");
        }
        else
        {
            //on effectue une recherche dans le tableau des initiales pour afficher non pas l'initiale mais la mention complète du candidat
            int index_mention = 0;
            for(int g=0; g<6; g++)
            {
                if(mention_trouvee==initiales_possibles[g])
                {
                    index_mention=g;
                }
            }
            for(int f=0; f<strlen(mentions_possibles[index_mention]); f++)
            {
                printf("%c",mentions_possibles[index_mention][f]);
            }
            //on passe par un for-printf au lieu d'un puts pour tout afficher sur une meme ligne
        }
    }

    printf("\n\n................................\n\n");
    printf("Faites votre choix parmi les options du menu : ");
    choix_menu=getche();

    return choix_menu;
}

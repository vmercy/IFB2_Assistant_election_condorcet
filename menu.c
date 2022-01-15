#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

char menu(int nb_candidats, char noms_classes[50][51], int etat_candidats[50])
{
    char choix_menu = 0;
    //saisie_nom_candidats(noms_candidats);

    printf("\nMENU : \n1 - Ajouter un candidat a la liste\n2 - Modifier une ligne\n3 - Liberer une ligne\n4 - Valider la saisie");
    printf("\n\n................................\n\n");

    for(int u = 0; u<nb_candidats; u++) //on affiche la liste classee provisoire des candidats pour que l'electeur sache où il en est
    {
        printf("\n%i. ",u+1);
        if(strcmp(noms_classes[u],"")==0)   //si il n'y a encore aucun candidat a cette place
        {
            printf("************ VIDE ************");
        }
        else
        {
            for(int c=0; c<strlen(noms_classes[u]); c++)
            {
                printf("%c",noms_classes[u][c]);
            }
        }
    }

    printf("\n\n................................\n\n");
    printf("Faites votre choix parmi les options du menu : ");
    choix_menu=getche();

    return choix_menu;
}

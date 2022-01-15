#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "header.h"

void ecriture_bulletin(char nom_fichier[], int num_elect, int nb_cand, char noms_cand_classes[50][51], char mentions_jug_maj[50])
{
    FILE* fichier = NULL;
    fichier = fopen(nom_fichier, "a");
    if (fichier != NULL)
    {
        fprintf(fichier,"E%i-C-",num_elect);
        for(int h = 0; h<nb_cand; h++)
        {
            fputs(noms_cand_classes[h],fichier);
            if(h!=(nb_cand-1))
            {
                fprintf(fichier,",");
            }
        }
        fprintf(fichier,"-M-");
        for(int b = 0; b<nb_cand; b++)
        {
            fprintf(fichier, "%c",mentions_jug_maj[b]);
            if(b!=(nb_cand-1))
            {
                fprintf(fichier,",");
            }
        }
        fprintf(fichier,"\n");
        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier %s",nom_fichier);
    }
}

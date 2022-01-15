#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "header.h"

void saisie_noms_candidats(char noms[50][51],int nb_candidats)
{
    for(int i=0; i<nb_candidats; i++)
    {
        char nom_saisi[200];
        strcpy(nom_saisi,"");
        printf("Saisir le nom du candidat %i : ",i+1);
        int new_name = 0;
        gets(nom_saisi);
        while((new_name==0)||(strlen(nom_saisi)>50))
        {
            if(strlen(nom_saisi)>50)
            {
                printf("Le nom saisi depasse la limite de 50 caracteres. Veuillez recommencer la saisie : ");
                gets(nom_saisi);
            }
            int nom_exist = 0;
            if(new_name==0)
            {
                for(int j=0; j<nb_candidats; j++)
                {
                    if(strcmp(nom_saisi,noms[j])==0)
                    {
                        nom_exist = 1;
                    }
                }
                if(nom_exist==1)
                {
                    printf("Ce nom est vide ou identique a un nom saisi precedemment. Veuillez saisir a nouveau ce nom en y ajouter un suffixe distinctif (par exemple, l'initiale du nom du candidat) : ");
                    if(i==0)    //anti-flood
                    {
                        gets(nom_saisi);
                    }
                    gets(nom_saisi);
                }
                else
                {
                    new_name=1;
                    strncpy(noms[i],nom_saisi,50);
                }
            }

        }
    }
}

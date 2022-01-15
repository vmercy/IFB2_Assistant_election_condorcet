#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

int verif_saisie_valide(char noms_cand_classes[50][51],int nb_cand)
{
    int result=1;
    for(int o=0; o<nb_cand; o++)
    {
        if(strcmp(noms_cand_classes[o],"")==0)
        {
            printf("\nValidation impossible : la ligne %i est encore vide",o+1);
            result=0;
        }
    }
    if(result==0)
    {
        printf("\nEntrer (O) pour continuer : ");
        char saisie;
        do
        {
            saisie=getche();
        }
        while(saisie!='O');
    }
    return result;
}

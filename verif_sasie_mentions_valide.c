#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

int verif_saisie_mentions_valide(char mentions_jug_maj[50], char initiales_possibles[50],int nb_cand)
{
    int result=1;
    int res=0;
    for(int o=0; o<nb_cand; o++)    //on vérifie qu'à chaque candidat est attribuée une mention parmi la liste des mentions possibles
    {
        for(int h=0; h<6; h++)
        {
            if(mentions_jug_maj[o]==initiales_possibles[h])
            {
                res++;
            }
        }
    }
    if(res!=nb_cand)
    {
        printf("\nValidation impossible : %i candidat(s) n'a(ont) pas de mention attribuee. Veuillez leur attribuer une mention avant de valider.",nb_cand-res);
        result=0;
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

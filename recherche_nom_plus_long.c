#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "header.h"

int recherche_nom_plus_long(int nb_cand, char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING])
{
    int ret = 0;
    for(int i=0; i<nb_cand; i++)
    {
        if(strlen(noms_candidats[i])>=ret)
        {
            ret=strlen(noms_candidats[i]);
        }
    }
    return ret;

}

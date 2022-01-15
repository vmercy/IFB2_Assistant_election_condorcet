#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "header.h"

int detection_auto_param_bulletins(int matrice_nbs[2], char noms_candidats[50][51], char nom_fichier[])
{
    //Exemple de détection : E1-C-C,B,A-M-I,B,P
    int nb_elec = 0;
    int nb_cand = 0;

    FILE *file = fopen(nom_fichier,"r");

    if(file==NULL)
    {
        return 1;
    }

    char str[STRING_BUFFER];

    int line;

    for(line=0; fgets(str, 127, (FILE*) file); line++)
    {
        nb_elec++;
        char *it=str;
        char *nextit;
        char *del="-";

        //printf("%s:\r\n",str);
        for(int i=0;; i++)
        {
            if(strtok_r(it,del,&nextit)==NULL)
                break;
            // printf("=>%s\r\n",it);

            if(i==2)
            {
                char *it2=it;
                char *nextit2;
                char *del2=",";
                for(int j=0;; j++)
                {
                    if(strtok_r(it2,del2,&nextit2)==NULL)
                        break;
                    strcpy(noms_candidats[j],it2);
                    if(line==0){
                            nb_cand++;
                    }

                    //printf("=>%s\r\n",it2);
                    it2=nextit2;
                }
            }
            it=nextit;
        }

    }

    fclose(file);
    matrice_nbs[0]=nb_cand;
    matrice_nbs[1]=nb_elec;
    return 0;
}

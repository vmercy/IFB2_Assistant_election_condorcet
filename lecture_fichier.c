#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

char* strtok_r(
    char *str,
    const char *delim,
    char **nextp)
{
    char *ret;

    if (str == NULL)
    {
        str = *nextp;
    }

    str += strspn(str, delim);

    if (*str == '\0')
    {
        return NULL;
    }

    ret = str;

    str += strcspn(str, delim);

    if (*str)
    {
        *str++ = '\0';
    }

    *nextp = str;

    return ret;
}

int getId(char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING],int n,char *name)
{
    for(int i=0; i<n; i++)
    {
        if(strcmp(noms_candidats[i],name)==0)
        {
            return i;
        }
    }
    return -1;
}

int lecture_fichier(int nb_cand, int nb_elec, char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING],  char nom_fichier_a_lire[TAILLE_MAX_STRING], char mentions[NB_MAX_ELECTEURS][NB_CANDIDATS], int liste_prefs[NB_MAX_ELECTEURS][NB_CANDIDATS])
{
    //Exemple de lecture : E1-C-C,B,A-M-I,B,P

    FILE *file = fopen(nom_fichier_a_lire,"r");

    if(file==NULL)
    {
        printf("\nErreur de lecture du fichier %s",nom_fichier_a_lire);
        return 1;
    }

    char str[STRING_BUFFER];

    for(int i = 0; i< NB_MAX_ELECTEURS; i++)
    {
        for(int j= 0; j<NB_CANDIDATS; j++)
        {
            liste_prefs[i][j]=0;
            mentions[i][j]=0;
        }
    }

    int line;

    for(line=0; fgets(str, 127, (FILE*) file); line++)
    {
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
                    liste_prefs[line][j]=getId(noms_candidats,nb_cand,it2);
                    //printf("=>%s\r\n",it2);
                    it2=nextit2;
                }
            }

            else if(i==4)
            {
                char *it2=it;
                char *nextit2;
                char *del2=",";
                for(int j=0;; j++)
                {
                    if(strtok_r(it2,del2,&nextit2)==NULL)
                        break;
                    mentions[line][j]=it2[0];
                    //printf("MENTION=>%c\r\n",mentions[line][j]);
                    it2=nextit2;
                }
            }

            it=nextit;
        }

    }

    fclose(file);
    return 0;
}


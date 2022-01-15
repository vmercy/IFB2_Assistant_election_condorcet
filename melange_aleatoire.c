#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void melange_aleatoire(char entree[50][51], char sortie[50][51], int nb_cand)
{
    int index_alea[50];
    int index_mel[nb_cand];
    for(int h=0; h<50; h++)
    {
        index_alea[h]=0;
        index_mel[h]=0;
        strcpy(sortie[h],"");
    }
    int p = nb_cand;
    for(int u=0; u<p; u++)
    {
        index_mel[u]=u;
    }
    for(int i = 0; i<p; i++)
    {
        int j = rand()%p;
        int tpn = index_mel[j];
        index_mel[j]=index_mel[p-1];
        index_mel[p-1]=tpn;
        p-=1;
    }
    for(int o=0; o<nb_cand; o++)
    {
        index_alea[o]=index_mel[o];
    }
    for(int h = nb_cand; h<51; h++)
    {
        index_alea[h]=0;
    }
    for(int g=0; g<nb_cand; g++)
    {
        strcpy(sortie[g],entree[index_alea[g]]);
    }
}

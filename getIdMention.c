#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "header.h"

int getIdMention(char initiale_entree, char initiales_possibles[NB_MENTIONS])
{
    for(int d = 0; d<NB_MENTIONS; d++)
    {
        if(initiale_entree==initiales_possibles[d])
        {
            return d;
        }
    }
    return -1;
}

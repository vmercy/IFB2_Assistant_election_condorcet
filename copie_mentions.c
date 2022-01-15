#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "header.h"

void copie_mentions(char mentions_possibles[6][12])
{
    strcpy(mentions_possibles[0],"A rejeter");
    strcpy(mentions_possibles[1],"Insuffisant");
    strcpy(mentions_possibles[2],"Passable");
    strcpy(mentions_possibles[3],"Assez bien");
    strcpy(mentions_possibles[4],"Bien");
    strcpy(mentions_possibles[5],"Tres bien");
}

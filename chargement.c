#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "header.h"

void chargement()
{
    int nb_car = 100;
    printf("\n");
    for(int i = 0; i<nb_car; i++)
    {
        printf("#");
        my_delay(40-i);
    }
}

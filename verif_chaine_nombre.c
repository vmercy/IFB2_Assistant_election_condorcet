#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

int verif_chaine_nombre(char chaine[], int autor_minus)
{
    int ret = 1;
    if(chaine[0]=='-'){
        if(!autor_minus){
            ret=0;
        }
    } else if(!((chaine[0]>='0')&&(chaine[0]<='9'))){
        ret=0;
    }
    for(int i = 1; i<strlen(chaine); i++){
        if(!((chaine[i]>='0')&&(chaine[i]<='9'))){
            ret = 0;
        }
    }
    return ret;
}

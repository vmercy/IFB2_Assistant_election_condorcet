#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void saisie_mentions(int *init, int nb_candidats, char noms_candidats[50][51], char mentions_jug_maj[50], char initiales_possibles[6], char mentions_possibles[6][12])
{
    char chx=0;
    printf("\n****           SAISIE DES VOTES           ****\n**           Methode par mentions           **\n");
    int saisie_validee = 0; //booleeenne
    while(saisie_validee==0)
    {
        chx=menu_mentions(nb_candidats, noms_candidats,mentions_jug_maj,initiales_possibles,mentions_possibles);
        while(!((chx>='1')&&(chx<='3')))  //controle avec message d'erreur
        {
            printf("\nChoix invalide, veuillez recommencer : \n");
            chx=menu_mentions(nb_candidats, noms_candidats,mentions_jug_maj,initiales_possibles,mentions_possibles);
        }

        switch(chx)
        {
        case '1': //attriution d'une mention
            attribution_mention(init,nb_candidats,noms_candidats,mentions_possibles,mentions_jug_maj);
            break;
        case '2': //modification d'une mention
            modif_mention(init, nb_candidats,noms_candidats,mentions_possibles,mentions_jug_maj);
            break;
        case '3':  //validation de la saisie
            saisie_validee=verif_saisie_mentions_valide(mentions_jug_maj,initiales_possibles,nb_candidats);
            break;
        }
    }
    printf("\n\n................................\n\n");
    printf("\nLA SAISIE EST VALIDEE.");
    printf("\n\n................................\n\n");
}

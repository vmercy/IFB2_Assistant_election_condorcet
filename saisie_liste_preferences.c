#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void saisie_liste_preferences(int nb_cand, char noms_candidats[50][51], char noms_cand_classes[50][51])
{
//    int nb_cand = 0;
//    char noms_candidats[50][51];
//    char noms_cand_classes[50][51]; //tableau contenant les noms des candidats, qui doit être classé à la fin de l'exécution de cette fonction de saisie

    int etat_candidats[50];    //prend les valeurs 0 (candidat pas encore choisi) ou 1 (candidat deja choisi)
    char chx = 0;
    int saisie_validee = 0; //booleenne

    for(int t=0; t<50; t++)
    {
        strcpy(noms_cand_classes[t],"");
    }

    for(int j = 0; j<50; j++)
    {
        etat_candidats[j]=0;
    }

    printf("\n****           SAISIE DES VOTES           ****\n**     Methode par liste de preferences     **\n");

    while(saisie_validee==0)
    {
        chx=menu(nb_cand,noms_cand_classes,etat_candidats);
        while(!((chx>='1')&&(chx<='4')))  //controle avec message d'erreur
        {
            printf("\nChoix invalide, veuillez recommencer : ");
            chx=menu(nb_cand,noms_cand_classes,etat_candidats);
        }

        switch(chx)
        {
        case '1': //ajout d'un candidat a la liste
            ajout_cand(nb_cand,etat_candidats,noms_candidats,noms_cand_classes);
            break;
        case '2': //modification d'une ligne
            modif_cand(nb_cand,etat_candidats,noms_candidats,noms_cand_classes);
            break;
        case '3': //suppression d'une ligne
            suppr_cand(nb_cand,etat_candidats,noms_candidats,noms_cand_classes);
            break;
        case '4':  //validation de la saisie
            saisie_validee=verif_saisie_valide(noms_cand_classes,nb_cand);
            break;
        }
    }
    printf("\n\n................................\n\n");
    printf("\nLA SAISIE EST VALIDEE.");
    printf("\n\n................................\n\n");
}

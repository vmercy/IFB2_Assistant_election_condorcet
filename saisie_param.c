#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "header.h"

int saisie_param(int matrice_nbs[2], char noms_candidats[50][51], char nom_fichier[], char nom_fichier_recup[], char methodes_choisies[2])
{
    strcpy(nom_fichier,"");   //reset nom_fichier

    int retour = 0;

    char rep=0;
    printf("\nVoulez-vous importer (I) les bulletins depuis un fichier texte ou bien les creer maintenant (C) ? (I/C) ");
    rep=getche();

    while(!((rep=='I')||(rep=='C')))
    {
        printf("\nReponse invalide, veuillez recommencer : ");
        rep=getche();
    }
    if(rep=='I')
    {
        printf("\nVeuillez saisir le nom du fichier dans lequel les bulletins doivent etre recuperes (fichier txt, ne pas saisir l'extension avec le nom) : ");
        while(strcmp(nom_fichier,"")==0)
        {
            gets(nom_fichier);
        }
        while(strlen(nom_fichier)>45)
        {
            printf("\nErreur : le nom du fichier ne peut pas depasser 45 caracteres. Veuillez recommencer la saisie : ");
            gets(nom_fichier);
        }
        strcat(nom_fichier,".txt");
        retour = 0;
        printf("\nLe programme va maintenant lire le fichier des bulletins pour acquerir les parametres de l'election automatiquement.");
        int succes_detection = detection_auto_param_bulletins(matrice_nbs,noms_candidats,nom_fichier);
        while(succes_detection!=0)
        {
            printf("\nEchec de la detection automatique des parametres. Soit le fichier .txt est corrompu, soit il n'est pas au bon format, soit il n'existe pas.");
            strcpy(nom_fichier,"");
            printf("\nVeuillez saisir le nom du fichier dans lequel les bulletins doivent etre recuperes (fichier txt, ne pas saisir l'extension avec le nom) : ");
            while(strcmp(nom_fichier,"")==0)
            {
                gets(nom_fichier);
            }
            while(strlen(nom_fichier)>45)
            {
                printf("\nErreur : le nom du fichier ne peut pas depasser 45 caracteres. Veuillez recommencer la saisie : ");
                gets(nom_fichier);
            }
            strcat(nom_fichier,".txt");
            succes_detection = detection_auto_param_bulletins(matrice_nbs,noms_candidats,nom_fichier);
            printf("\nLe programme va maintenant lire le fichier des bulletins pour acquerir les parametres de l'election automatiquement.");
        }

        printf("\nSucces de la detection automatique des parametres : ");
        printf("\n - Nombre de candidats detecte : %i",matrice_nbs[0]);
        printf("\n - Noms des candidats trouves : ");
        for(int v = 0; v<matrice_nbs[0]; v++)
        {
            printf("\n    - %s",noms_candidats[v]);
        }
        printf("\n - Nombre d'electeurs detecte : %i",matrice_nbs[1]);
    }
    else if(rep=='C')
    {
        printf("\nUn nouveau fichier va etre cree pour stocker les bulletins saisis.\nVeuillez saisir un nom de fichier txt (ne pas saisir l'extension avec le nom) : ");
        //gets(nom_fichier);
        while(strcmp(nom_fichier,"")==0)
        {
            gets(nom_fichier);
        }
        while(strlen(nom_fichier)>45)
        {
            printf("\nErreur : le nom du fichier ne peut pas depasser 45 caracteres. Veuillez recommencer la saisie : ");
            gets(nom_fichier);
        }
        strcat(nom_fichier,".txt");
        retour = 1;

        printf("Nombre de candidats  : ");
        char chaine_entree[50];
        gets(chaine_entree);
        while(!verif_chaine_nombre(chaine_entree,0))
        {
            printf("\nCe n'est pas un nombre ! Veuillez recommencer et saisir un nombre : ");
            gets(chaine_entree);
        }
        matrice_nbs[0] = atoi(chaine_entree);
        while(!((matrice_nbs[0]>0)&&(matrice_nbs[0]<=50)))
        {
            printf("\nErreur de saisie : le nombre de candidats doit etre un entier entre 1 et 50. Veuillez recommencer : ");
            gets(chaine_entree);
            while(!verif_chaine_nombre(chaine_entree,0))
            {
                printf("\nCe n'est pas un nombre ! Veuillez recommencer et saisir un nombre : ");
                gets(chaine_entree);
            }
            matrice_nbs[0] = atoi(chaine_entree);
        }
        printf("\n");

        saisie_noms_candidats(noms_candidats,matrice_nbs[0]);  //ajouter une validation qui empêche une saisie vide (espaces seulement) et la saisie d'une virgule (utilisée comme séparateur dans le fichier de stockage des bulletins

        char repo = 0;
        printf("\nConnaissez-vous le nombre d'electeurs ? (O/N)");
        repo = getche();
        while(!((repo=='O')||(repo=='N'))){
            printf("\nSaisie inalide, veuillez recommencer :");
            repo = getche();
        }
        if(repo=='O')
        {
            printf("Nombre d'electeurs  : ");
            gets(chaine_entree);
            while(!verif_chaine_nombre(chaine_entree,0))
            {
                printf("\nCe n'est pas un nombre ! Veuillez recommencer et saisir un nombre : ");
                gets(chaine_entree);
            }
            matrice_nbs[1] = atoi(chaine_entree);
            while(!((matrice_nbs[1]>0)&&(matrice_nbs[1]<=1000)))
            {
                printf("\nErreur de saisie : le nombre de candidats doit etre un entier entre 1 et 1000. Veuillez recommencer : ");
                gets(chaine_entree);
                while(!verif_chaine_nombre(chaine_entree,0))
                {
                    printf("\nCe n'est pas un nombre ! Veuillez recommencer et saisir un nombre : ");
                    gets(chaine_entree);
                }
                matrice_nbs[1] = atoi(chaine_entree);
            }
        }
        else if(repo=='N'){
            printf("\nLe nombre d'electeurs est indefini. Le dernier electeur devra se signaler lors de la saisie de son vote via les interfaces.");
            matrice_nbs[1]=-1;  //code pour nombre d'electeurs indefini
        }
    }

    printf("\n");
    printf("\nQuelle premiere methode de scrutin alternative voulez-vous utiliser en cas de paradoxe de Condorcet ?");
    printf("\nScrutin de condorcet randomise (R), Methode Borda (B), Vote alternatif (A) ou Jugement majoritaire (J) ?\nFaites votre choix : ");
    char repo = 0;
    repo = getche();
    while(!((repo=='R')||(repo=='B')||(repo=='A')||(repo=='J')))
    {
        printf("\nChoix invalide, veuillez recommencer : ");
        repo = getche();
    }
    methodes_choisies[0]=repo;
    rep=0;
    printf("\n\nVoulez-vous utiliser une seconde methode de scrutin alternative ? (O/N) ");
    rep=getche();

    while(!((rep=='O')||(rep=='N')))
    {
        printf("\nReponse invalide, veuillez recommencer : ");
        rep=getche();
    }
    if(rep=='O')
    {
        printf("\nChoisissez une seconde methode parmi les methodes restantes : ");
        printf("\nScrutin de condorcet randomise (R), Methode Borda (B), Vote alternatif (A) ou Jugement majoritaire (J) ?\nFaites votre choix : ");
        repo = 0;
        repo = getche();
        while(!((repo=='R')||(repo=='B')||(repo=='A')||(repo=='J'))||(repo==methodes_choisies[0]))
        {

            if(!((repo=='R')||(repo=='B')||(repo=='A')))
            {
                printf("\nChoix invalide, veuillez recommencer : ");
            }
            else if(repo==methodes_choisies[0])
            {
                printf("\nVous ne pouvez pas choisir une methode de scrutin alternative secondaire identique a la premiere. Veuillez recommencer : ");
            }
            repo = getche();
        }
        methodes_choisies[1]=repo;

    }
    else if(rep=='N')
    {
        methodes_choisies[1]=0;
    }

    return retour;
}

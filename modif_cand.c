#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void modif_cand(int nb_cand, int etat_candidats[50], char noms_candidats[50][51], char noms_classes[50][51])
{
    int pos=0;
    char chaine_entree[50];
    printf("\nSaisissez le numero de la ligne a modifier : ");
    gets(chaine_entree);
    while(!verif_chaine_nombre(chaine_entree,1))
    {
        printf("\nCe n'est pas un nombre ! Veuillez recommencer et saisir un nombre : ");
        gets(chaine_entree);
    }
    pos = atoi(chaine_entree);
    while(!(((pos>=1)&&(pos<=nb_cand)&&strcmp(noms_classes[pos-1],"")!=0)||(pos==-1))) //message d'erreur si la position saisie ne fait pas partie des positions disponibles
    {
        printf("\nVous avez saisi une position inexistante ou qui correspond a une ligne vide (le dernier cas echeant, utilisez la fonction d'ajout dans le menu). Veuillez recommencer ou saisir '-1' pour quitter : ");
        gets(chaine_entree);
        while(!verif_chaine_nombre(chaine_entree,1))
        {
            printf("\nCe n'est pas un nombre ! Veuillez recommencer et saisir un nombre : ");
            gets(chaine_entree);
        }
        pos = atoi(chaine_entree);
    }
    if(pos!=-1)
    {
        for(int f=0; f<nb_cand; f++)    //on recherche l'index du candidat dans la liste de base pour pouvoir le libérer
        {
            if(strcmp(noms_classes[pos-1],noms_candidats[f])==0)
            {
                etat_candidats[f]=0;
            }
        }
        strcpy(noms_classes[pos-1],""); //on vide la ligne

        printf("\nLe candidat sur la ligne %i a ete supprime. Par qui voulez-vous le remplacer ? ",pos);

        affichage_liste_cand_enc_dispos(nb_cand,etat_candidats,noms_candidats);

        printf("\nSaisissez votre choix : ");

        char nom_a_inserer[51];
        //on effectue une recherche du candidat pour obtenir son index dans le tableau noms_candidats (on vérifie en même temps qu'il existe bien)
        int nom_existant_et_dispo = 0;  //booleenne
        int compteur=0;
        while(nom_existant_et_dispo==0)
        {
            if(compteur>1)
            {
                printf("\nLe candidat saisi n'existe pas ou n'est plus disponible. Veuillez recommencer la saisie : ");
            }
            gets(nom_a_inserer);
            for(int g=0; g<nb_cand; g++)
            {
                if(strcmp(nom_a_inserer,noms_candidats[g])==0)      //un candidat du meme nom a ete trouve
                {
                    if(etat_candidats[g]==0)
                    {
                        nom_existant_et_dispo = 1;
                        etat_candidats[g]=1;    //on met a jour l'etat : le candidat est desormais pris
                    }
                }
            }
            compteur++;
        }
        //LE CANDIDAT DEMANDE EXISTE ET N'EST PAS DEJA PRIS, ON CONTINUE
        strcpy(noms_classes[pos-1],nom_a_inserer);

    }


}

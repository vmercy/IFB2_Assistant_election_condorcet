#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "header.h"

int main()
{
    //VARIABLES GLOBALES
    char mentions[NB_MAX_ELECTEURS][NB_CANDIDATS];
    int liste_prefs[NB_MAX_ELECTEURS][NB_CANDIDATS];
    //TABLEAUX POST-SAISIE


    //RESTE
    int init= 0;
    srand(time(0));
    int nb_cand = 0;
    int nb_elec = 0;
    char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING];
    char noms_cand_classes[NB_CANDIDATS][TAILLE_MAX_STRING]; //tableau contenant les noms des candidats, qui est classé à la fin de l'exécution de la fonction de saisie
    char mentions_possibles[NB_MENTIONS][TAILLE_MAX_MENTION];
    char initiales_possibles[NB_MENTIONS]= {'R','I','P','A','B','T'};
    char mentions_jug_maj[NB_CANDIDATS];  //contient les initiales des mentions attribuées pour chaque candidat, classés dans le même ordre que noms_candidats.
    //initiales : R = A rejeter, I = Insuffisant, P = Passable, A = Assez bien, B = Bien, T = Très bien
    char nom_fichier[TAILLE_MAX_STRING];
    char nom_fichier_recup[TAILLE_MAX_STRING];
    int matrice_nbs[2]; //matrice permettant de récupérer les résultats multiples nb_elec et nb_cand apres l'execution de la fonction saisie_param
    char methodes_choisies[2];


    //FIN DECLARATION VARIABLES GLOBALES

    copie_mentions(mentions_possibles); //on remplit le tableau des mentions possibles

    strcpy(nom_fichier,""); //on vide le nom du fichier par sécurité, avant de demander sa saisie par l'utilisateur plus bas dans le programme

    for(int i = 0; i<2; i++)    //on vide par sécurité le tableau des méthodes choisies, avant de demander à l'utilisateur la saisie des méthodes choisies
    {
        methodes_choisies[i]=0;
    }

    for(int y=0; y<NB_CANDIDATS; y++)   //on vide les mentions des candidats
    {
        mentions_jug_maj[y]=0;
    }

    printf("            --        ASSISTANT POUR ELECTIONS SELON LE PRINCIPE DE CONDORCET         --");
    chargement();   //barre de chargement artificielle pour l'esthétique
    printf("\n\n");

    int choix_mode = saisie_param(matrice_nbs, noms_candidats, nom_fichier, nom_fichier_recup, methodes_choisies);  //si choix_mode = 1 : l'organisateur veut creer des nouveaux bulletins, si choix_mode = 0 : l'organisateur veut recuperer des bulletins depuis un fichier

    //l'election de Condorcet etant obligatoire, on presente obligatoirement l'intferce de saisie de listes de preferences. Par contre, on ne présente l'interface de saisie des mentions que si le jugement majoritaire a été demandé par l'organisateur.
    int jug_maj_recquis = 0;

    for(int i=0;i<2;i++){
        if(methodes_choisies[i]=='J'){  //si le jugement majoritaire est recquis, on passe la variable booleenne declarée précedemment à Vrai
            jug_maj_recquis = 1;
        }
    }

    nb_cand = matrice_nbs[0];   //reattribution
    nb_elec = matrice_nbs[1];   //reattribution

    chargement();   //barre de chargement artificielle pour l'esthétique

    switch(choix_mode)
    {
    case 1: //les interfaces de saisie de votes sont presentees aux electeurs
        printf("\nVous pouvez maintenant quitter l'ordinateur et presenter les electeurs un a un. Saisir 'C' pour demarrer les interfaces de saisie des votes : ");
        int rep = getche();
        while(rep!='C')
        {
            printf("\nSaisir 'C' pour continuer : ");
            rep = getche();
        }
        saisie_votes(nb_cand, nb_elec, noms_candidats, noms_cand_classes, &init, mentions_jug_maj, initiales_possibles, mentions_possibles, nom_fichier, jug_maj_recquis);
        printf("\nLA PHASE DE VOTE EST TERMINEE.\nLes bulletins ont ete sauvegardes dans le fichier %s.",nom_fichier);
        break;

    case 0: //les bulletins sont recuperes depuis un fichier cree a l'avance
        printf("\nLes bulletins vont etre recuperes automatiquement depuis le fichier renseigne.");
        chargement();
        break;
    }

    int succes_lecture = lecture_fichier(nb_cand, nb_elec, noms_candidats,  nom_fichier, mentions, liste_prefs);

    switch(succes_lecture)
    {
    case 1: //echec de lecture des fichiers
        printf("\n\nLe programme va s'arreter car une erreur de lecture du fichier s'est produite. Veuillez recommencer son execution.");
        return 0;
        break;
    case 0: //succes
        printf("\nLe fichier des bulletins a ete lu avec succes.");
        break;

    }

    printf("\nEtes-vous pret a executer le scrutin selon la/les methode(s) choisie(s) (le programme affichera d'abord obligatoirement les resultats selon l'election de Condorcet) ? (O/N) ");
    char rep=0;
    rep=getche();

    while(!((rep=='O')||(rep=='N')))
    {
        printf("\nReponse invalide, veuillez recommencer : ");
        rep=getche();
    }
    if(rep=='O')
    {
        printf("\n\n************* RESULTATS DU SCRUTIN SELON LA METHODE DE CONDORCET : *************");
        printf("\n\nCette méthode d'election n'est pas encore disponible : l'algorithme n'est pas encore en place.\n\n");
        //Affichage du resultat de l'election selon la methode de Condorcet
        printf("\n\nSaisir 'C' pour continuer : ");
        rep = getche();
        while(rep!='C')
        {
            printf("\nSaisir 'C' pour continuer : ");
            rep = getche();
        }


        for(int b=0; b<2; b++)
        {
            switch(methodes_choisies[b])
            {
            case 0: //si l'organisateur ne souhaite pas utiliser une seconde methode de scrutin
                break;
            case 'A':
                printf("\n\n************* RESULTATS DU SCRUTIN SELON LA METHODE DU VOTE ALTERNATIF : *************");
                printf("\n\nSaisir 'C' pour continuer : ");
                rep = getche();
                while(rep!='C')
                {
                    printf("\nSaisir 'C' pour continuer : ");
                    rep = getche();
                }
                break;
            case 'B':
                printf("\n\n************* RESULTATS DU SCRUTIN SELON LA METHODE DE BORDA : *************");
                methode_borda(nb_cand,nb_elec,noms_candidats,liste_prefs);
                printf("\n\nSaisir 'C' pour continuer : ");
                rep = getche();
                while(rep!='C')
                {
                    printf("\nSaisir 'C' pour continuer : ");
                    rep = getche();
                }
                break;
            case 'R':
                printf("\n\n************* RESULTATS DU SCRUTIN SELON LA METHODE DE CONDORCET RANDOMISEE : *************");
                printf("\n\nCette méthode d'election n'est pas encore disponible : l'algorithme n'est pas encore en place.\n\n");
                printf("\n\nSaisir 'C' pour continuer : ");
                rep = getche();
                while(rep!='C')
                {
                    printf("\nSaisir 'C' pour continuer : ");
                    rep = getche();
                }
                break;
            case 'J':
                printf("\n\n************* RESULTATS DU SCRUTIN SELON LA METHODE DU JUGEMENT MAJORITAIRE : *************");
                methode_jugement_maj(nb_elec,nb_cand,initiales_possibles,mentions_possibles,noms_candidats,mentions);
                printf("\n\nSaisir 'C' pour continuer : ");
                rep = getche();
                while(rep!='C')
                {
                    printf("\nSaisir 'C' pour continuer : ");
                    rep = getche();
                }
                break;
            default:
                break;
            }

        }


    }

    printf("\n\n********FIN DE L'EXECUTION DE L'ASSISTANT POUR ELECTIONS SELON LE PRINCIPE DE CONDORCET********\nAppuyez sur n'importe quelle touche pour en sortir\n\n");

    return 0;
}

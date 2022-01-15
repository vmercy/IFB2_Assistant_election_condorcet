#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define TAILLE_MAX_STRING 51
#define NB_CANDIDATS 50
#define TAILLE_MAX_MENTION 12
#define NB_MENTIONS 6
#define NB_MAX_ELECTEURS 1000
#define STRING_BUFFER 128

void saisie_noms_candidats(char noms[NB_CANDIDATS][TAILLE_MAX_STRING],int nb_candidats);
char menu(int nb_candidats, char noms_classes[NB_CANDIDATS][TAILLE_MAX_STRING], int etat_candidats[NB_CANDIDATS]);
void melange_aleatoire(char entree[NB_CANDIDATS][TAILLE_MAX_STRING], char sortie[NB_CANDIDATS][TAILLE_MAX_STRING], int nb_cand);
void affichage_liste_cand_enc_dispos(int nb_cand, int etat_candidats[NB_CANDIDATS], char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING]);
void ajout_cand(int nb_cand, int etat_candidats[NB_CANDIDATS], char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING], char noms_classes[NB_CANDIDATS][TAILLE_MAX_STRING]);
void modif_cand(int nb_cand, int etat_candidats[NB_CANDIDATS], char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING], char noms_classes[NB_CANDIDATS][TAILLE_MAX_STRING]);
void suppr_cand(int nb_cand, int etat_candidats[NB_CANDIDATS], char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING], char noms_classes[NB_CANDIDATS][TAILLE_MAX_STRING]);
int verif_saisie_valide(char noms_cand_classes[NB_CANDIDATS][TAILLE_MAX_STRING],int nb_cand);
void saisie_liste_preferences(int nb_cand, char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING], char noms_cand_classes[NB_CANDIDATS][TAILLE_MAX_STRING]);
char menu_mentions(int nb_candidats, char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING], char mentions_jug_maj[NB_CANDIDATS], char initiales_possibles[NB_MENTIONS], char mentions_possibles[NB_MENTIONS][TAILLE_MAX_MENTION]);
void attribution_mention(int *init, int nb_cand, char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING], char mentions_possibles[NB_MENTIONS][TAILLE_MAX_MENTION], char mentions_jug_maj[NB_CANDIDATS]);
void modif_mention(int *init, int nb_cand, char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING], char mentions_possibles[NB_MENTIONS][TAILLE_MAX_MENTION], char mentions_jug_maj[NB_CANDIDATS]);
int verif_saisie_mentions_valide(char mentions_jug_maj[NB_CANDIDATS], char initiales_possibles[NB_CANDIDATS],int nb_cand);
void saisie_mentions(int *init, int nb_candidats, char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING], char mentions_jug_maj[NB_CANDIDATS], char initiales_possibles[NB_MENTIONS], char mentions_possibles[NB_MENTIONS][TAILLE_MAX_MENTION]);
void ecriture_bulletin(char nom_fichier[], int num_elect, int nb_cand, char noms_cand_classes[NB_CANDIDATS][TAILLE_MAX_STRING], char mentions_jug_maj[NB_CANDIDATS]);
int verif_chaine_nombre(char chaine[], int autor_minus);
void my_delay(int i);
void chargement();
void copie_mentions(char mentions_possibles[NB_MENTIONS][TAILLE_MAX_MENTION]);
int saisie_param(int matrice_nbs[2], char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING], char nom_fichier[], char nom_fichier_recup[], char methodes_choisies[2]);
void saisie_votes(int nb_cand, int nb_elec, char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING], char noms_cand_classes[NB_CANDIDATS][TAILLE_MAX_STRING], int *init, char mentions_jug_maj[NB_CANDIDATS], char initiales_possibles[NB_MENTIONS], char mentions_possibles[NB_MENTIONS][TAILLE_MAX_MENTION], char nom_fichier[TAILLE_MAX_STRING], int jug_maj_recquis);
int detection_auto_param_bulletins(int matrice_nbs[2], char noms_candidats[50][51], char nom_fichier[]);
int lecture_fichier(int nb_cand, int nb_elec, char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING], char nom_fichier_a_lire[TAILLE_MAX_STRING], char mentions[NB_MAX_ELECTEURS][NB_CANDIDATS], int liste_prefs[NB_MAX_ELECTEURS][NB_CANDIDATS]); //retourne 1 en cas d'erreur, 0 sinon
void methode_borda(int nb_cand, int nb_elec, char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING], int liste_prefs[NB_MAX_ELECTEURS][NB_CANDIDATS]);
void methode_jugement_maj(int nb_elec, int nb_cand, char initiales_possibles[NB_MENTIONS], char mentions_possibles[NB_MENTIONS][TAILLE_MAX_MENTION], char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING], char mentions[NB_MAX_ELECTEURS][NB_CANDIDATS]);
int recherche_nom_plus_long(int nb_cand, char noms_candidats[NB_CANDIDATS][TAILLE_MAX_STRING]);
int getIdMention(char initiale_entree, char initiales_possibles[NB_MENTIONS]);


#endif // HEADER_H_INCLUDED

/* Je déclare qu'il s'agit de mon propre travail.*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define LG_MAX 20

/* Idées/inspirations : jeu d'escape game combinant le GameShell du TP1 (exercice 6), le jeu du donjon du TP2, le menu et fonctionnalités de l'exercice 4 du TP7, le triangle d'étoiles du TP3 cette fois en valeurs. */

// Les notions utilisées sont : les boucles (for/while/do), les booléens, les tableaux, les chaînes de caractères, les fonctions, les structures.

/* Synopsis : un 30 juin, le joueur se retrouve enfermé dans l'université après s'être endormi plusieurs heures dans l'enceinte de l'établissement. Il est minuit. Le but du jeu est de sortir de l'établissement pour éviter de se retrouver enfermé... pendant 2 mois.*/

struct id_secu {
        char nom[LG_MAX];
        char prenom[LG_MAX];
        int nb_cle;
}; /* Les informations sous forme de structure du vigile */

void menu(char choix); /* Afficher le menu de début du jeu */
void intro(void); /* Affiche l'intro/le prologue sous forme de texte */
void menu_g210(void); /* Affiche le menu du jeu */
int deroule(int choix_n2); /* Le déroulé du jeu */
/* ---------- */
int autres_salles(); /* Entrée dans "autres salles" */
int hall(); /* Entrée dans "hall" */
int administratif(); /* Entrée dans "administratif" */
int euler(); /* Entrée dans "euler" */
int intro_sortie(); /* Affiche le prologue de la sortie */
int sortie(); /* Vers la "sortie" de l'université */
/* ---------- */
void feuille_gauche(void); /* Affiche un bout de feuille gauche */
void feuille_droite(void); /* Affiche un bout de feuille droite */
void triangle_gauche(void); /* Affiche un triangle du côté gauche */
void triangle_droite(void); /* Affiche un triangle du côté droit */
int saisir_tableaux(int tab[], int taille); /* Saisir un tableau */
void comparer_tab_admin(int code_casier[], int cc_inserer[]); /* Compare le code du casier saisi au code initial (administratif) */
void comparer_tab_sortie(int numero_mdp[], int nb_cle[], struct id_secu ob); /* Compare le mdp saisi au mdp initial (sortie) */

int main()
{
        char choix;
        int choix_n2;
        do {
                menu(choix);
                scanf("%c", &choix);
        } while (choix != 'c');
        intro();
        deroule(choix_n2); // Le coeur du jeu se déroule dans cette fonction.
        
        return 0;
}

void menu(char choix)
{
        printf("********** ESCAPE **********\n");
        printf("Une nuit pour sortir de l'université.\n");
        sleep(1);
        printf("Saisir c pour commencer le jeu d'aventure.\n");
}

void intro()
{
        printf("Que l'aventure commence... bonne chance.\n");
        sleep(2);
        printf("\n");
        printf("Un buffet est organisé dans l'Institut Galilée en guise de la remise des"
        " diplômes d'ingénieurs. Cette dernière a lieu un 30 juin, dernier jour avant que"
        " l'établissement ferme pour vacances. Vous incarnerez Guy, fraîchement diplômé"
        " en ingénierie informatique, qui vivra une soirée... particulière.\n");
        sleep(5);
        printf("\n");
        printf("\"Oh là là... ce buffet m'a complètement anéanti !\"\n");
        sleep(2);
        printf("\n");
        printf("\"Peut-être qu'une bonne sieste pourra me revigorer. Rien de mieux que de la faire"
        " une dernière fois dans ma salle informatique préférée.\"\n");
        sleep(2);
        printf("\n");
        printf("Les minutes défilent... puis les heures... jusqu'au moment où il soit minuit.\n");
        sleep(2);
        printf("\n");
        printf("\"Quelle sieste... mais attendez une minute : pourquoi n'y a t-il plus de musique ?"
        " Ne me dites pas que...\"\n");
        sleep(2);
        printf("\n");
        printf("\"Toutes les lumières sont éteintes. Tout le monde est parti ! NOOOOOOOOOON !!!\"\n");
        sleep(2);
        printf("\n");
}

void menu_g210(void)
{
        printf("********** ESCAPE **********\n");
        printf("Aidez Guy à sortir de là !\n");
        printf("1) faire des recherches dans d'autres salles\n");
        printf("2) descendre dans le hall\n");
        printf("3) entrer dans l'amphithéâtre Euler\n");
        printf("4) essayer de trouver quelque chose dans le service administratif\n");
        printf("5) se diriger vers la sortie de l'université\n");
        printf("6) QUITTER LE JEU\n");
}

int deroule(int choix_n2)
{
        do {
                menu_g210(); // Affiche le menu dessus
                scanf("%d", &choix_n2);
        } while (choix_n2 < 1 || choix_n2 > 6); // Répète tant que l'utilisateur ne saisit pas une valeur entre 1 et 6
        while (choix_n2 >= 1 && choix_n2 <= 6){
                if (choix_n2 == 1){
                        autres_salles(); // Entrée dans "autres salles"
                }
                if (choix_n2 == 2){
                        hall(); // Entrée dans "hall"
                }
                if (choix_n2 == 3){
                        euler(); // Entrée dans "euler"
                }
                if (choix_n2 == 4){
                        administratif(); // Entrée dans "administratif"
                }
                if (choix_n2 == 5){
                        sortie(); // Vers la "sortie" de l'université
                }
                if (choix_n2 == 6){
                        printf("Vous avez quitté le jeu. Merci d'y avoir joué !\n");
                        return choix_n2;
                }
                menu_g210();
                scanf("%d", &choix_n2); // Ré-affiche le menu à la fin d'une "entrée" et requiert le choix de l'utilisateur pour la suite.
        }
}

// ----------
int autres_salles()
{
        printf("\n");
        printf("Guy commence à explorer une salle entrouverte, et retrouve un bout de papier"
        " déterminant pour la suite.\n");
        printf("\n");
        sleep(2);
        feuille_gauche(); // Affiche le bout de feuille gauche
        sleep(2);
        printf("\"C'est évident qu'il manque un autre bout de papier. Mais où ?"
        " Qui est Olivier B ?\"\n");
        printf("\n");
        sleep(2);
}

int hall()
{
        printf("\n");
        printf("Guy descend et se retrouve plongé dans une obscurité inédite. La fête est"
        " terminée, sans aucun doute. Mais près de la cafétéria, il ramasse un petit papier froissé.\n");
        sleep(2);
        printf("\n");
        printf("I = 1\n" "IV = 4\n" "V = 5\n" "IX = 9\n"); // Des chiffres romains
        sleep(2);
        printf("\"Mais c'est quoi ce truc... *soupir* il n'y a pas grand chose pour m'aider.\"\n");
        printf("\n");
}

int administratif()
{
        printf("\n");
        printf("Guy parcourt les couloirs du service administratif et retrouve quelque chose"
        " qui pourrait enfin faire avancer les choses.\n");
        sleep(2);
        feuille_droite(); // Affiche le bout de feuille droite
        printf("\n");
        sleep(2);
        printf("\"Un deuxième bout de papier ? Tiens donc.\"\n");
        sleep(2);
        printf("Et à ce moment là, il regarde devant lui et voit une étagère de casiers."
        " Le casier de M. Bertrand se profile devant lui... verrouillé par un cadenas à 4"
        " valeurs.\n");
        sleep(2);
        printf("\"Essayons...\" (insérez quatre chiffres séparément)\n");
        int code_casier[4] = { 2, 3, 9, 4 }; // Le code du casier (être attentif dans l'amphi Euler)
        int cc_inserer[4]; // Le code que l'utilisateur va insérer
        saisir_tableaux(cc_inserer, 4); // L'utilisateur saisit chiffre par chiffre, ligne par ligne, les valeurs du code.
        comparer_tab_admin(code_casier, cc_inserer); // La fonction compare si le code du casier est le même que celui que l'utilisateur a saisi.
        printf("\n");
}

int euler()
{
       printf("\n");
       printf("Guy entre dans l'amphithéâtre Euler sombre et calme.\n");
       printf("Or, une indication au tableau risque de changer la donne.\n");
       sleep(2);
       printf("\"Il est écrit des lettres assez étranges... II.III.IX.IV... casier-admin.\"\n"); // Chiffres romains
       sleep(2);
       printf("\"Oulà, je ne suis pas sûr de tout comprendre... autant ressortir de là.\"\n");
       sleep(2);
       printf("\n");
}

int intro_sortie()
{
        int i, correspond = 1;
        printf("\n");
        printf("Guy sort du bâtiment et se rend vers une sortie de l'université."
        " Il se retrouve face au poste de contrôle...\n");
        sleep(2);
        printf("Guy entre dans le poste et retrouve face à lui un autre casier.\n");
        sleep(2);
        printf("\n");
        printf("Il apprend que le casier ne peut être déverrouillé qu'en accédant dans l'ordinateur"
        " du vigile. Il y accède et fait face à un écran d'identificaiton.\n");
        sleep(2);
        printf("\n");
}

int sortie()
{
        char nom[LG_MAX], prenom[LG_MAX];
        int numero_mdp[6]; // La clé du casier du service administratif
        intro_sortie(); // Introduction en texte de "sortie"
        struct id_secu ob = { .nom = "BERTRAND", .prenom = "Olivier", .nb_cle = 736528 }; // Données structurées du vigile Olivier BERTRAND
        int nb_cle[6] = { 7, 3, 6, 5, 2, 8 }; // Le mot de passe de l'ordinateur du vigile
        printf("Saisir le nom en majuscules : ");
        scanf("%s", &nom);
        printf("Saisir le prénom : ");
        scanf("%s", &prenom);
        if (strcmp(nom, ob.nom) != 0 && strcmp(prenom, ob.prenom) != 0){
                printf("\n");
                printf("\"Punaise, j'ai raté quelque chose. Rebelotte...\"\n"); // Retour au déroulé
                printf("\n");
        } else {
                printf("Saisir le mot de passe (indice : 6 caractères) : \n");
                saisir_tableaux(numero_mdp, 6); // L'utilisateur saisit chiffre par chiffre, ligne par ligne, le mot de passe.
                comparer_tab_sortie(numero_mdp, nb_cle, ob); // La fonction compare le mot de passe saisi et le véritable mdp.
        }
}

/* ---------- */
void feuille_gauche()
{
        printf("---------------\n");
        triangle_gauche();
        printf("concaténer 73--------\n");
        printf("clé Olivier B--\n");
        printf("73--\n");
        printf("---------------\n");
        printf("\n");
}

void feuille_droite()
{
        printf("---------------\n");
        triangle_droite();
        printf("-65 et la somme de chaque chiffres des lignes 3 du triangle. MDP \n");
        printf("-ERTRAND\n");
        printf("-65\n");
        printf("---------------\n");
}

void triangle_gauche()
{
        for (int i = 0; i < 6; i = i + 1){
                for (int k = 0; k < i; k = k + 1){
                        printf(" ");
                }
                for (int j = 0; j < (6 - i); j = j + 1){
                        printf("%d", j + 1); // Les valeurs du triangle débutent par 1
                }
        printf("\n");
    }
}

void triangle_droite()
{
        int k, l;
        for (k = 0; k < 6; k = k + 1){
                for (l = 0; l < (6 - k); l = l + 1){
                        printf("%d", l + 3); // Les valeurs du triangle débutent par 3
                }
        printf("\n");
        }
}

int saisir_tableaux(int tab[], int taille)
{
        int i;
        for (i = 0; i < taille; i = i + 1){
                scanf("%d", &tab[i]);
        }
        return tab[i];
}

void comparer_tab_admin(int code_casier[], int cc_inserer[])
{
        int i, correspond = 1;
        for (i = 0; i < 4; i = i + 1){
                if (code_casier[i] != cc_inserer[i]){
                        correspond = 0;
                }
        }
        if (correspond != 1){
                printf("Mince... j'ai raté quelque chose !\n");
        } else {
                printf("J'ai une clé ! En route vers la sortie !\n");
        }
}

void comparer_tab_sortie(int numero_mdp[], int nb_cle[], struct id_secu ob)
{
        int i, correspond = 1;
        for (i = 0; i < 6; i = i + 1){
                if (numero_mdp[i] != nb_cle[i]){
                        correspond = 0;
                }
        }
        if (!correspond){
                printf("\n");
                printf("\"Punaise, j'ai raté quelque chose. Rebelotte...\"\n");
                printf("\n");
        } else {
                printf("\n");
                printf("\"Bienvenue, %s %s.\"\n", ob.prenom, ob.nom); // Message de bienvenue de l'ordi du vigile
                sleep(2);
                printf("Avec le mot de passe et la clé obtenue dans le service administratif,"
                " le casier a été déverrouillé sans trop de difficultés. Guy obtient la (vraie) clé"
                " pour sortir de l'université !\n");
                printf("\n");
                sleep(2);
                printf("Félicitations ! Vous avez fait sortir Guy de l'université !"
                " Il pourra désormais rentrer chez lui et profiter de ses vacances."
                " Saisissez 6 pour quitter le jeu !\n");
        }
        printf("\n");
}

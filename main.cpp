/* ---------------------------
 Laboratoire    : 5
 Fichier        : main.cpp
 Auteur(s)      : Maurice Lehmann, Mahé Fuentes, Harold Redard-Jacot
 Date           : 15.11.2018

 But            : Affiche le calendrier d'une année entre 1600 et 3000.
                  L'utilisateur peut choisir de quel jour la semaine commence
 Remarque(s)    :

 Compilateur    : MinGW-g++ 6.3.0
 --------------------------- */
 #include <cstdlib>
 #include <iostream>
 #include <iomanip>
 #include <string>
 using namespace std;



/*

OK - Ecrivez une fonction qui reçoit en paramètres un message de question, un message d'erreur, et les bornes min et max à vérifier, et boucle jusqu'à ce que l'utilisateur entre une entrée correcte.

Harold - Ecrivez une fonction qui affiche une chaine de caractères centrée dans une colonne de largeur donnée

OK - Ecrivez une fonction qui détermine si une année est bissextile.

Mahé - Ecrivez une fonction qui détermine quel jour de la semaine est le premier janvier d'une année donnée. Il existe une formule mathématique permettant de le déterminer.

Par contre, ne calculez pas quel jour de la semaine est le premier des autres mois. Determinez ce jour à partir de vos boucles.

Maurice - Ecrivez une fonction qui affiche un mois donné et qui prend entre autres un paramètre spécifiant le jour de la semaine du premier du mois. Cette fonction doit également donner en sortie le premier jour du mois suivant

*/

//TODO : Doxygene
void saisieUtilisateur(unsigned int& annee, unsigned int& lundi);
bool anneebissextile( unsigned int annee);
int afficherMois(const string& nomMois, const unsigned int& nbJourMois,unsigned int premierJourDuMois);
/**
 Affichage de texte centré

 @param texte    string utilisé afin d'etre centré
 @param largeur  unsigned int utilisé pour définir la largeur du texte

 @return rien
 */
void centrageText(string texte, unsigned largeur);

/*
Dértermine quel jour de la semaine est le 1er janvier de l'année choisie
@param annee, unsigned, année entrée par l'utilisateur
@return unsigned, correspond au jour de la semaine 0 -> samedi, 7 -> vendredi
*/
unsigned int jourDeLAn (int an);

//TODO : A faire ! Dois afficher une string "L M M J S D", ou "D L M M J S D", selon le premier jour de la semaine défini
void afficherJoursDeLaSemaine(const unsigned int& premierJour);

int main(){

    const unsigned int NB_MOIS = 12;
    unsigned int annee = 2017;
    unsigned int lundi = 0;
    //saisieUtilisateur(annee,lundi);
    unsigned int premierJourDuMois = jourDeLAn(annee);

    //Données relatives aux mois
    unsigned int nbJoursFevrier = 28 ;
    //Si l'année est bissextile, Fevrier a 29 jours
    if(anneebissextile(annee))
        nbJoursFevrier = 29 ;

    string listeNomMois[NB_MOIS] = {"Janvier","Fevrier","Mars","Avril","Mai",
                                    "Juin","Juillet","Aout","Septembre","Octobre",
                                    "Novembre","Decembre"};

    unsigned int listeNombreJoursDesMois[NB_MOIS] = {31,nbJoursFevrier,31,30,31,30,31,31,30,31,30,31};

    //On affiche tout les mois
    for(int mois = 1 ; mois <= 2 ; mois++){
        //On affiche le mois ET on assigne le prochain premier jour du mois suivant
        premierJourDuMois = afficherMois(listeNomMois[mois-1],listeNombreJoursDesMois[mois-1],premierJourDuMois);
        cout << endl ;
    }

    return EXIT_SUCCESS;
}

int afficherMois(const string& nomMois, const unsigned int& nbJourMois,unsigned int premierJourDuMois){

    const unsigned short int LARGEUR    = 21;
    const unsigned short int NB_COLONNE = 7;
    const unsigned short int NB_ESP     = 2; //Nombre d'espace du setw()

    //Valeur retournée par la fonction, correspond au numéro du premier jour du mois suivant
    unsigned int prochainPremierJour;
    unsigned int nbDecalage;

    //Entete - nom du mois
    centrageText(nomMois, LARGEUR);
    //Todo : afficher l'entete des jours de la semaine avec la fonction
    cout << "L  M  M  J  V  S  D" << endl; //TODO : A supprimer
    //On calcule le nombre de décalage à droite pour le premie jour du mois
    //Lundi [2] , Mardi[3], Mercredi[4], Jeudi[5], vendredi[6], Samedi[0], Dimanche[1]
    if( premierJourDuMois >= 2 ){
        nbDecalage = premierJourDuMois - 2;
    }else{
        nbDecalage = premierJourDuMois + 5;
    }

    //TODO : Remodifier le nbDecalage par rapport au nouveau "lundi" spécifié

    //Affiche le décalage
    for(int espace = 0 ; espace < nbDecalage ; espace++){
        cout << setw(NB_ESP + 1) << " ";
    }
    //Affichage des jours
    for(unsigned int jour = 1 ; jour <= nbJourMois ; jour++){
        cout << setw(NB_ESP) << jour << " " ;
        //Retour à la ligne
        if(!((jour+nbDecalage) % 7)){
            cout << endl ;
        }
    }
    return prochainPremierJour;
}


bool anneebissextile (unsigned int annee) {
    if( (!(annee % 4) and annee % 100) or !(annee % 400)){
        return true;
    }
    return false;
}

void saisieUtilisateur(unsigned int& annee, unsigned int& lundi){

    cout << "Quelle annee voulez-vous afficher? (1600-3000)" ;
    cin >> annee;
    while (annee < 1600 or annee > 3000) {
     cout << "Entree non valide" << endl;
     cout << "Quelle annee voulez-vous afficher? (1600-3000)" ;
     cin >> annee;
    }
    cout << "Quel jour de la semaine est le lundi? (1-7)" ;
    cin >> lundi;
    while (lundi < 1 or lundi > 7) {
        cout << "Entree non valide" << endl;
        cout << "Quel jour de la semaine est le lundi? (1-7)" ;
        cin >> lundi;
    }
}

void centrageText(string texte, unsigned largeur)
 {
    //character de remplissage
    char remplissage = '.';
    //largeur du bord à gauche
    int largeurGauche = ((largeur - texte.length())/2);
    //largeur du bord à droite
    int largeurDroite = (largeur - (largeurGauche + texte.length()))-1;
    //Affichage du texte centreé
    cout << remplissage << setfill(remplissage) << setw(largeurDroite)
         << remplissage << texte << setfill(remplissage) << setw(largeurGauche)
         << remplissage << endl;
 }
 unsigned jourDeLAn (int an) {

  unsigned const JOUR = 1;
  unsigned const MOIS = 13;
  unsigned date = an - 1;

  return ( JOUR + 2 * MOIS + ((3 * (MOIS + 1))/ 5) + date + (date / 4) - (date / 100) + (date / 400) + 2 ) % 7;
}

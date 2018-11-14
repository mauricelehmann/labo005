# labo005

Rappel de l'affichage structuré avec <iomanip>
Mise en oeuvre de boucles simples et/ou imbriquées
Validation d'entrées entières dans un intervalle donné
Ecriture et appel de fonctions simples
  
  
Le but de cet exercice est d'imprimer le calendrier d'une année. Vous devez
Demander "Quelle annee voulez-vous afficher? (1600-3000)"
Demander "Quel jour de la semaine est le lundi? (1-7)".
Afficher le calendrier de l'année demandée
Le programme doit gérer les entrées non valides en affichant "Entree non valide", puis en reposant la question.



Les entrées utilisateurs doivent être validées. En cas d'entrée non conforme (entier non lisible ou hors bornes) affichez "Entree non valide" et redemandez l'entrée. <br>
Découpez votre code en fonctions réalisant des tâches simples. 
Commentez les prototypes de vos fonctions (style Doxygen)
Ecrivez une fonction qui reçoit en paramètres un message de question, un message d'erreur, et les bornes min et max à vérifier, et boucle jusqu'à ce que l'utilisateur entre une entrée correcte.
Ecrivez une fonction qui affiche une chaine de caractères centrée dans une colonne de largeur donnée
Ecrivez une fonction qui détermine si une année est bissextile. 
Ecrivez une fonction qui détermine quel jour de la semaine est le premier janvier d'une année donnée. Il existe une formule mathématique permettant de le déterminer. 
Par contre, ne calculez pas quel jour de la semaine est le premier des autres mois. Determinez ce jour à partir de vos boucles.
Ecrivez une fonction qui affiche un mois donné et qui prend entre autres un paramètre spécifiant le jour de la semaine du premier du mois. Cette fonction doit également donner en sortie le premier jour du mois suivant

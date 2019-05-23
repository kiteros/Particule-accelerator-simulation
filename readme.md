#Présentation du projet d'accélérateur de particules (Jules Eschbach et Weisheng Wang)

1.Nous avons fait tout les exercices demandés, plus l'extension de la maille FODO

2.Nous avons une version graphique avec la bibliothèque graphique QT (ver. 5.9.5)

3.Nous avons passé en moyenne 7h par personne et par semaine sur le projet


#instructions
Dans le dossier "fichier test", les fichiers suivants peuvent être exécutés indépendament
-ex9.cc
-ex10.cc
-testAccelerateur.cc
-testParticle.cc
-testVecteur3D.cc

-> Il sont exécutable à partir du Makefile situé dans ce dossier : 
	-make
	-./"nom du fichier"

->Le fichier exercice13.cc doit être éxécuté depuis le main() en utilisant le polymorphisme sur faisceau (mettre faisceau_P13), se référer au commentaires du fichier maint-qt-gl.cc

#lancer l'accélérateur : 

#version textuelle : 
-Aller dans le dossier "TextView"
-Effectuer les commandes suivantes depuis le terminal : 
	-qmake
	-make
	-./text_sim

-L'accélérateur va se lancer automatiquement avec les paramètres renseignés dans le main de text_view. Par défaut, nous faisons 1000 itérations avec deux particules et un accélérateur complet.
-> les résultats sont affichés dans la console et sauvegardés dans le ficher results.txt


#version graphique :

-Aller dans le dossier "Qt"
-Effectuer : 
	-qmake
	-make
	-./gl_sim

-L'accélérateur se lance automatiquement. Il est possible de naviguer en 3D avec les touches WSQDAE et les flèches, et faire pause avec la barre espace. La simulation n'a pas de fin, par conséquent pour quitter, soit fermer la fenêtre soit Alt+F4

->L'exemple que nous avons implémenté pour l'instant modélise deux faisceaux de 30 macroparticules chacun, implémantent le systeme de force interparticule P14, et allant dans des sens opposés avec la même norme.

	

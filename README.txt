Analyse de logs serveur Apache
https://github.com/10v5m1ch9n5/POO-TP4

------------------------------------------

Affiche les 10 ressources les plus accédées et génère éventuellement un graphe de la navigation enregistrée.

------------------------------------------
analog [-e] [-g nomfichier.dot] [-t heure] nomfichier.log

+ -g : Produit un fichier au format GraphViz
+ -e : Exclut tous les documents qui ont une extension de type png, jpg, gif, ico, css ou js.
+ -t : Ne prend en compte que les requêtes qui ont été émises à l'heure spécifiée.

------------------------------------------
Tester le programme :

Exécuter le script mktest.sh depuis le répertoire Test

------------------------------------------
Compiler le programme :

Exécuter la commande make dans le répertoire bin


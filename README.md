# correcteur-orthographique

Petit projet de L2 info :  correcteur orthographique en C


L’objectif du DM consiste à concevoir une mini application permettant à l’utilisateur de charger en mémoire un dictionnaire et de lister les mots mal orthographiés d’un fichier donné, ainsi que les corrections possibles du mots. Ce premier rendu est une étape préliminaire dans lequel on implante la détection des mots mal orthographiés.


# Guide

|   | Commande  |
|:---|---:|
|Installer | make install
|Lancer l’exemple 1 (texte_0 / dico_1)| make exemple1
|Lancer l’exemple 2 (texte_1 / dico_2)| make exemple2
|Désinstaller | make uninstall

Produire la représentation graphique du dictionnaire (ex.):
```sh
./bin/correcteur_0 ./data/texte_1.txt ./data/dico_2.dico -a
dot -Tpdf ./data/graph.dot -o ./data/graph.pdf
```
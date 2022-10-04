# Labo_TicTacToe

Ce programme écrit en c++ permet à deux personnes de jouer une partie de Tic Tac Toe l'une contre l'autre.

Lorsque le programme est lancé, il va expliquer comment choisir une case.
Le plateau étant numéroté de 1 à 9, le joueur devra rendre le chiffre correspondant à la case où il veut placer son pion.
Le jeu est programmé pour vérifier que la case est bel est bien vide avant de placer le pion o, correspondant au premier joueur.
Ainsi, si le joueur choisit une case déjà prise ou rentre un chiffre se trouvant en dehors du rayon permis (entre 1 et 9), le jeu va demander à la personne de choisir un autre chiffre.

Après que la première personne ait joué, ce sera au tour de la deuxième qui elle va jouer les x.
Le même processus va s'appliquer à chaque joueur à chacun de leurs tours.

Pour gagner, l'un des joueurs doit réussir à aligner 3 de ses pions que ce soit en ligne, colonne ou diagonale.
Dans le cas où toutes les cases sont pleines mais que aucun des deux n'a réussi à aligner 3 de ces pions, le jeu déclare une égalité.

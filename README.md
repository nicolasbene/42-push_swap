# 42-push_swap
Fonctions a utiliser pour trier entre 6 et 100

Test de tri
1 - push b tous le nb 
2 - inserer de facon opti les nbre de b dans a
	--> "insert_fastest_a" trouve le moyen le plus rapide d'insérer un élément de la liste b dans la liste a avec d'autres fonctions
	
		- "nb_rot" retourne le nombre total de rotations nécessaires pour insérer un élément dans la liste de destination.
		- "insert_move_count" calcule le nombre de rotations nécessaires pour insérer un élément dans une autre liste et le classer.
		- "count_put_on_top" calcule la position actuelle d'un élément dans la liste et détermine combien de rotations sont nécessaires pour le mettre en haut de la liste.
		- "rotate_buf" effectue les rotations nécessaires pour insérer un élément dans la liste de destination.


sort_more.c

insert_fastest_a
-->	insert_move_count (count_put_on_top)
	--> nb_rot
	-->	rotate_buf



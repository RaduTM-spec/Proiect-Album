#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "main_functions.h"
#pragma
// main
// 
// notes
/*
	class photos - name,extension,dimension, album
	class album - name,photos_number,dimension
	
	list of photos and albums



	add_photo()
	del_photo()
	add_album()
	del_album()

	[-- MAIN SCREEN --] +NEW
	Album1                                                                          Open Delete
	Album2																			Open Delete
	Album3     [the current option is highlighted in a specific color]   then       Open Delete
	[CONTROLS]

	[-- ALBUM SCREEN --] +NEW  Number of Photos: X    Dimension: X
  
	Photo1 [Move Edit Delete]
	Photo2 [Move Edit Delete]
	Photo3 [Move Edit Delete]
	
	*/
	/* Intializes random number generator */
// storage template - txt file
/*

=data.txt ====
albums number    on the first line---then follows every album
number name dimension photos_total  on de second line - album info, then all photos from this album  |
number name dimension |																				 |
number name dimension |=> X photos_total															 | => X albums_number
number name dimension |																				 |

the file is always rewriten with a safe exit at ESC

*/
void main()
{
	load_data();
	generate_main_screen(1,albums_number,albums);
}

/*
BUGS FOUND
- dupa ce accesez un meniu si adaug poze in el si revin in galerie, daca recreez un nou album nu ma lasa sa ii adaug nume ( poate fi sters, o singura data are loc asta)


*/
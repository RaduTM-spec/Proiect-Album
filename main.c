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

	[-- MAIN SCREEN --]
	Choose album:
	Album1                                                                          Open Delete
	Album2																			Open Delete
	Album3     [the current option is highlighted in a specific color]   then       Open Delete

	[-- ALBUM SCREEN --]  Number of Photos: X    Dimension: X
	ADD PHOTO
	Name   
	Photo1 [Move Edit Delete]
	Photo2 [Move Edit Delete]
	Photo3 [Move Edit Delete]
	
	*/
	/* Intializes random number generator */

void main()
{
	printf("%d", albums[1].photos_total);
	generate_main_screen(1, albums_number, albums);
}
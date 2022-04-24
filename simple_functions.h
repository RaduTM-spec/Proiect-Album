#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <dos.h>
#include <string.h>
#include <assert.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct photos_template
{
	char name[50];
	unsigned int number;
	double dimension;//MB
}photo;

typedef struct albums_template
{
	char name[50];
	unsigned int number, photos_total;
	double dimension;//MB
	photo photos[1000];
}album;




album albums[100];
photo single_photos[10000];

unsigned int
single_photos_number,
single_photos_current_pos = 1,// counter that keeps the number of photos not added to any album
albums_number, //total albums number

input_in_main,  // if 0 then OPEN/REMOVE are invisible, if 1 they are visible
input_in_album, //same as input_in_main but for album_screen

input_controls = 0, //if 0 controls are invisible

current_photo_position = 1,// current_photo_position, always starts with 0
current_album_number = 1,
add_album_from_transfering = 0,//when you want to transfer a photo to an album, but you want to create a new album, this var will swap to 1 this way the add_album function will comeback to the transfering function
another_frk_var = 0,// asta tine numarul albumului unde trb adaugat
another_frk_var2 = 0;//asta tine numarul photografiei care trebuie adaugate
void set_red() {
	printf("\033[1;31m");
}
void set_yellow() {
	printf("\033[1;33m");
}
void set_blue() {
	printf("\033[0;34m");
}
void set_green() {
	printf("\033[0;32m");
}
void set_white() {
	printf("\033[0m");
}
void clear_screen()
{
	system("cls");
}

void print_controls()
{
	set_yellow();
	printf("\n                DOWN - s\n");
	printf("                UP   - w\n");
	printf("                NEXT - d\n");
	printf("                BACK - a\n");
	printf("                OPEN - o\n");
	printf("                DEL  - r\n");
	printf("                NEW  - n\n");
	printf("                SAVE - esc\n");
}

void saving_screen()
{
	clear_screen();
	set_green();
	printf("\n   saving...");
}
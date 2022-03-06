#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <dos.h>

typedef struct albums_template
{
	char name[50];	
	unsigned int number, photos_total;
	double dimension;//MB
}album;
typedef struct photos_template
{
	char name[50];
	char extension[50];
	unsigned int album_location[50];	
	unsigned int number;
	double dimension;//MB
}photo;

album albums[100];
unsigned int albums_number = 0, input_in_main, input_controls = 0;





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
	printf("                DEL - r\n");
	printf("                NEW - n\n");
}

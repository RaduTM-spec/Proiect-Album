#include "simple_functions.h"

//prototype
void generate_main_screen(unsigned int current_album_position, unsigned int albums_number, album albums[]);
void generate_album_screen(unsigned int album_index);
void print_album_screen(unsigned int current_photo_pos);




//defined
void add_album(unsigned int an, album albums[])
{
	albums_number++;

	clear_screen();
	set_green();
	printf(" [ NEW ALBUM ]\n");
	set_blue();

	//reading
	printf(" Album Number: ");
	scanf_s("%d", &albums[albums_number].number);


	set_green();
	printf(" [ DONE ]");
	Sleep(1000);
	generate_main_screen(1, albums_number, albums);

	albums[an].number = rand();
}
void remove_album(unsigned int album_index, unsigned int current_album_position, unsigned int albums_number, album albums[])
{
	clear_screen();
	for (size_t i = album_index+1; i <= albums_number; i++)
	{
		albums[i - 1].number = albums[i].number;

	}

	//deplasare la stanga
	input_in_main = 0;
	albums_number--;
	if (current_album_position > 1)
		current_album_position--;
	generate_main_screen(current_album_position, albums_number, albums);
}


void open_remove_main(unsigned int current_album_pos, unsigned int albums_number, album albums[],unsigned int index)
{

	//printing
	printf(">> %d", albums[index].number);
	set_green();
	printf("   OPEN");
	set_red();
	printf("   REMOVE\n");

	//continue print
	for (unsigned int i = index+1; i <= albums_number; i++)
	{
		set_white();
		printf("   %d\n", albums[i].number);
	}
	printf("\n\n");
	set_yellow();
	printf("              [ CONTROLS ] \n");
	if (input_controls == 1)
		print_controls();
    //stop printing

	while (true)
	{
		char x = _getch();
		if (x == 'o')
		{
			clear_screen();
			set_green();
			printf("\n  oppening...");
			Sleep(1000);
			generate_album_screen(index);


			//opening
		}
		else if (x == 'r')
		{
			set_red();
			clear_screen();
			printf("\n  removing...");
			Sleep(1000);
			remove_album(index, current_album_pos, albums_number, albums);
			//remove
		}
		else if (x == 'a')
		{
			input_in_main = 0;
			generate_main_screen(current_album_pos, albums_number, albums);
		}
		else if (x == 'c')
		{	
				input_controls = 1;
				print_controls();
		}
		else if (x == 's')
		{
			input_in_main = 0;
			generate_main_screen(current_album_pos+1, albums_number, albums);
		}
		else if (x == 'w')
		{
			input_in_main = 0;
			if(current_album_pos > 1)
			 generate_main_screen(current_album_pos - 1, albums_number, albums);
		}
			
	}
	
	

	
}
void print_main_screen(unsigned int current_album_pos,unsigned int albums_number, album albums[],unsigned int input,unsigned int c_input)
{
	clear_screen();
	set_yellow();
	printf("              [ GALLERY ]   ");
	set_green();
	printf("+NEW \n\n\n");
	set_white();
	for (unsigned int i = 1; i <= albums_number; i++)
	{
		if (i == current_album_pos)
		{
			set_blue();
			if (input == 0)
			{
				printf(">> %d\n", albums[i].number);
			}
			
			if (input == 1)
				open_remove_main(current_album_pos,albums_number,albums,i);
			
			set_white();
		}
		else printf("   %d\n", albums[i].number);
	}
	
	printf("\n\n");
	set_yellow();
	printf("              [ CONTROLS ] \n");
	if (c_input == 1)
		print_controls();
}
void generate_main_screen(unsigned int current_album_position,unsigned int albums_number,album albums[])
{
	clear_screen();
	print_main_screen(current_album_position,albums_number,albums,input_in_main,input_controls);//first album is 1

		char key = _getch();
		switch ((int)key)
		{
		case 27: //exit ESC
			clear_screen();
			exit(0);
			break;
		case 97: //back case
			input_in_main = 0;
			generate_main_screen(current_album_position, albums_number, albums);
		case 99: //controls case C
			if (input_controls == 0)
				input_controls = 1;
			else input_controls = 0;
			generate_main_screen(current_album_position, albums_number, albums);

		case 100: //create the submenu [OPEN REMOVE] ( album number) NEXT
			input_in_main = 1;
			generate_main_screen(current_album_position, albums_number, albums);
			break;
		case 115:// go down if possible DOWN ARROW
			input_in_main = 0;
			if (current_album_position == albums_number)
				generate_main_screen(current_album_position, albums_number, albums);
			else
			{
				generate_main_screen(++current_album_position, albums_number,albums);
			}
			break;
		case 119: // go up if possible UP ARROW
			input_in_main = 0;
			if (current_album_position == 1)
				generate_main_screen(current_album_position, albums_number, albums);
			else
			{
				generate_main_screen(--current_album_position, albums_number,albums);
			}
			break;
		


		//BUTTONS
		case 110: //ADD
			add_album(albums_number, albums);
			
			break;
		default: //do nothing s
			generate_main_screen(--current_album_position, albums_number, albums);
			break;
		
	    }
    
}


void generate_album_screen(unsigned int album_index)
{
	clear_screen();
}
void print_album_screen(unsigned int current_photo_pos)
{

}


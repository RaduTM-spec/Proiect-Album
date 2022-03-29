#include "simple_functions.h"
//load_data
void load_data()
{
	
	FILE* file = fopen("data.txt","r");
	fscanf(file, "%d", &albums_number);
	unsigned int album_index = 1;
	for (; album_index <= albums_number; album_index++)
	{
		fscanf(file, "%u%s%lf%u",
			&albums[album_index].number,
			&albums[album_index].name,
			&albums[album_index].dimension,
			&albums[album_index].photos_total);
		for (unsigned int photo_index = 1; photo_index <= albums[album_index].photos_total; photo_index++)
		{
			fscanf(file, "%u%s%lf",
				&albums[album_index].photos[photo_index].number,
				&albums[album_index].photos[photo_index].name,
				&albums[album_index].photos[photo_index].dimension);
		}

	}
	fclose(file);
}
void save_data()
{
	FILE* file = fopen("data.txt","w");
	fprintf(file, "%d\n", albums_number);
	unsigned int album_index = 1;
	for (; album_index <= albums_number; album_index++)
	{
		fprintf(file, "%u %s %lf %u\n",
			albums[album_index].number,
			albums[album_index].name,
			albums[album_index].dimension,
			albums[album_index].photos_total);
		for (unsigned int photo_index = 1; photo_index <= albums[album_index].photos_total; photo_index++)
		{
			fprintf(file, "%u %s %lf\n",
				albums[album_index].photos[photo_index].number,
				albums[album_index].photos[photo_index].name,
				albums[album_index].photos[photo_index].dimension);	
		}

	}
	fclose(file);
}



//prototype
void generate_main_screen(unsigned int current_album_position, unsigned int albums_number, album albums[]);
void generate_album_screen();
void print_album_screen();
void remove_album(unsigned int album_index, unsigned int current_album_position, unsigned int albs_number, album albums[]);

//verify name interity
int album_integrity(unsigned int album_index)
{
	if (strlen(albums[album_index].name) == 0)
	{
		return 0;
	}
	return 1;

}
int add_underscores(unsigned int album_index)
{
	for (int i = 0; i < strlen(albums[album_index].name); i++)
		if (albums[album_index].name[i] == ' ')
			albums[album_index].name[i] = '_';

}


//defined main
void add_album(album albums[])
{
	albums_number++;
	int an = albums_number;
	clear_screen();
	set_green();
	printf(" [ NEW ALBUM ]\n");
	set_blue();



	//create number
	printf(" Album's Number: ");
	set_white();
	printf("%d", an);
	albums[an].number = an;

	
	//read name
	char input_name[50];
	set_blue();
	printf("\n Album's Name: ");
	set_white();

	fgets(input_name, sizeof(input_name), stdin);
	input_name[strcspn(input_name, "\n")] = 0;
	albums[an].name[0] = '\0';
	strcat_s(albums[an].name, 50, input_name);

	albums[an].photos_total = 0;

	//set dimension
	albums[an].dimension = 0.0;

	if (!album_integrity(an))
	{
		
		
		albums_number--;
		add_album(albums);
	}
	//Add _ when spaces are met 
	add_underscores(an);
		

	set_green();
	printf(" [ DONE ]");
	Sleep(600);
	generate_main_screen(1, albums_number, albums);


}
void remove_album(unsigned int album_index, unsigned int current_album_position, unsigned int albs_number, album albums[])
{
	clear_screen();
	for (unsigned int i = album_index; i < albs_number; i++)
	{
		//albums[i].number = albums[i + 1].number;  the number is kept******
		albums[i].dimension = albums[i + 1].dimension;
		albums[i].photos_total = albums[i + 1].photos_total;
		strcpy_s(albums[i].name, 50, albums[i + 1].name);

		//now transfer all photos
		for (unsigned int j = 1; j <= albums[i].photos_total; j++)
		{
			albums[i].photos[j].number = albums[i + 1].photos[j].number;
			albums[i].photos[j].dimension = albums[i + 1].photos[j].dimension;
			strcpy_s(albums[i].photos[j].name, 50, albums[i+1].photos[j].name);
		}
	}

	//deplasare la stanga
	input_in_main = 0;
	albums_number--;
	if (current_album_position > 1)
		current_album_position--;
	generate_main_screen(current_album_position, albums_number, albums);
}
void rename_album(unsigned int album_index)
{
	clear_screen();
	set_yellow();
	printf(" [ %s ]\n", albums[album_index].name);
	set_green();
	printf("Change the name to: ");
	set_white();
	char input_name[50] = "";
	fflush(stdin);
	fgets(input_name, sizeof(input_name), stdin);
	input_name[strcspn(input_name, "\n")] = 0;
	albums[album_index].name[0] = '\0';
	strcat_s(albums[album_index].name, 50, input_name);

	if (!album_integrity(album_index))
	{
		rename_album(album_index);
	}
	add_underscores(album_index);
	input_in_main = 0;
	set_green();
	printf(" [ DONE ]");
	Sleep(600);
	generate_main_screen(1, albums_number, albums);

}
//defined album
void add_photo()
{
	albums[current_album_number].photos_total++;

	unsigned int photos_tot = albums[current_album_number].photos_total;


	clear_screen();
	set_green();
	printf(" [ NEW PHOTO ]\n");
	set_blue();


	//create number

	printf(" Photo's Number: %d", albums[current_album_number].photos_total);
	albums[current_album_number].photos[photos_tot].number = photos_tot;

	//Create name

    printf("\n Photo's Name: ");
	char photo_name[10] = "Photo_";
	char photo_number = photos_tot + '0';
	if (photo_number < 10)
	{
		photo_name[6] = photo_number;
		photo_name[7] = '\0';
	}
	else if (photo_number < 100)
	{
		//48 = '0'
		//57 = '9'
		//58 = 10 49 si 48
		//59 = 11 49 si 49
		photo_name[6] = '0' + photos_tot / 10 % 10;
		photo_name[7] = photo_number - 10 * (photos_tot / 10 % 10);
		photo_name[8] = '\0';
	}

	strcpy_s(albums[current_album_number].photos[photos_tot].name, 50, photo_name);
	
	printf("%s",photo_name);

	//Dimension
	printf("\n Dimension in MB: ");
	double dimension;
	scanf_s("%lf", &dimension);
	albums[current_album_number].photos[photos_tot].dimension = dimension;
	albums[current_album_number].dimension += dimension;
	//set dimension

   



	set_green();
	printf(" [ DONE ]");
	Sleep(600);
	generate_album_screen();

}
void remove_photo(unsigned int photo_index, unsigned int alb_number)
{
	clear_screen();
	set_red();
	printf("\n  removing...");
	albums[alb_number].dimension -= albums[alb_number].photos[photo_index].dimension;
	for (size_t i = photo_index; i < albums[alb_number].photos_total; i++)
	{
		albums[alb_number].photos[i].number = albums[alb_number].photos[i + 1].number;
		albums[alb_number].photos[i].dimension = albums[alb_number].photos[i + 1].dimension;
		strcpy_s(albums[alb_number].photos[i].name, 50, albums[alb_number].photos[i+1].name);
	}
	albums[alb_number].photos_total--;
	if (current_photo_position > 2);
		current_photo_position--;
    Sleep(700);
	generate_album_screen();
	
}

//main
void open_remove_main(unsigned int current_album_pos, unsigned int albums_number, album albums[], unsigned int index)
{
	//UPDATE : - added rename button
	//printing
	printf(">> %d     %s", albums[index].number, albums[index].name);
	set_green();
	printf("           OPEN");
	set_yellow();
	printf("   NAMECHANGE");
	set_red();
	printf("   REMOVE\n");

	//continue print
	for (unsigned int i = index + 1; i <= albums_number; i++)
	{
		set_white();
		printf("   %d     %s\n", albums[i].number, albums[i].name);
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
			Sleep(700);
			current_album_number = current_album_pos;
			current_photo_position = 1;
			generate_album_screen();

			break;
			//opening
		}
		else if (x == 'r')
		{
			set_red();
			clear_screen();
			printf("\n  removing...");
			Sleep(700);
			current_photo_position = 1;
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
			if (current_album_pos < albums_number)
				generate_main_screen(current_album_pos + 1, albums_number, albums);

		}
		else if (x == 'w')
		{
			input_in_main = 0;
			if (current_album_pos > 1)
				generate_main_screen(current_album_pos - 1, albums_number, albums);

		}
		else if (x == 27)
		{
			input_in_main = 0;
			generate_main_screen(current_album_pos, albums_number, albums);
		}
		else if (x == 'n')// rename
		{
			current_photo_position = 1;
			rename_album(current_album_pos);
		}

	}




}
void print_main_screen(unsigned int current_album_pos, unsigned int albums_number, album albums[], unsigned int input, unsigned int c_input)
{
	clear_screen();
	set_yellow();
	printf("              [ GALLERY ]   ");
	set_green();
	printf("+NEW \n\n");


	if (albums_number == 0)
	{
		set_white();
		printf("         The Gallery is Empty!");
	}
	else
	{
		set_red();
		printf(" Number  Name\n");
		set_white();

		for (unsigned int i = 1; i <= albums_number; i++)
		{
			if (i == current_album_pos)
			{
				set_blue();
				if (input == 0)
				{
					printf(">> %d     %s\n", albums[i].number, albums[i].name);
				}

				if (input == 1)
					open_remove_main(current_album_pos, albums_number, albums, i);

				set_white();
			}
			else printf("   %d     %s\n", albums[i].number, albums[i].name);
		}
	}
	printf("\n\n");
	set_yellow();
	printf("              [ CONTROLS ] \n");
	if (c_input == 1)
		print_controls();
}
void generate_main_screen(unsigned int current_album_position, unsigned int albums_number, album albums[])
{
	clear_screen();
	print_main_screen(current_album_position, albums_number, albums, input_in_main, input_controls);//first album is 1

	char key = _getch();
	switch ((int)key)
	{
	case 27: //exit ESC
		
		saving_screen();
		save_data();// rewrite the data file

		Sleep(500);//for faster save it will be increased
		set_green();
		clear_screen();
		printf("\n   [ SAVED ] \n");
		set_white();
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
			generate_main_screen(++current_album_position, albums_number, albums);
		}
		break;
	case 119: // go up if possible UP ARROW
		input_in_main = 0;
		if (current_album_position == 1)
			generate_main_screen(current_album_position, albums_number, albums);
		else
		{
			generate_main_screen(--current_album_position, albums_number, albums);
		}
		break;



		//BUTTONS
	case 110: //ADD
		add_album(albums);

		break;
	default: //do nothing s
		generate_main_screen(current_album_position, albums_number, albums);
		break;

	}

}

//album
void open_remove_album(unsigned int current_photo_pos, unsigned int index)
{
	clear_screen();
}
void generate_album_screen()
{
	clear_screen();
	print_album_screen();
	char key = _getch();
	switch (key)
	{
	case 'a':
		input_in_main = 0;
		generate_main_screen(1, albums_number, albums);
		break;
	case 27: //exit ESC - , move back as 'a'
		input_in_main = 0;
		generate_main_screen(1, albums_number, albums);
		break;
	case 99: //controls case C
		if (input_controls == 0)
			input_controls = 1;
		else input_controls = 0;
		generate_album_screen(current_album_number);
		break;
		//down and up
	case 115:// go down if possible DOWN ARROW
		input_in_album = 0;
		if (current_photo_position == albums[current_album_number].photos_total)
			generate_album_screen();
		else
		{
			++current_photo_position;
			generate_album_screen();
		}
		break;
	case 119: // go up if possible UP ARROW
		input_in_main = 0;
		if (current_photo_position == 1)
			generate_album_screen();
		else
		{
			--current_photo_position;
			generate_album_screen();
		}
		break;
	case 110: //ADD
		add_photo();
	case 'r': //REMOVE
		remove_photo(current_photo_position, current_album_number);
	default:
		generate_album_screen();
		break;

	}



}
void print_album_screen()
{
	clear_screen();
	set_yellow();
	printf("              [ %s ]   ", albums[current_album_number].name);
	set_green();
	printf("+NEW");
	set_yellow();
	if(albums[current_album_number].dimension < 1000 && albums[current_album_number].dimension>= 1) ///print in MB
	    printf("     Dimension: %0.2f MB\n\n", albums[current_album_number].dimension);
	else if(albums[current_album_number].dimension <= 1.0)
		printf("     Dimension: %0.2f KB\n\n", albums[current_album_number].dimension * 1000);///print in KB
	else printf("     Dimension: %0.2f GB\n\n", albums[current_album_number].dimension/1000);///print in GB


	if (albums[current_album_number].photos_total == 0)
	{
		set_white();
		printf("         There are no Photos!");
	}
	else
	{
		set_red();
		printf(" Number  Name\n");
		set_white();

		for (unsigned int i = 1; i <= albums[current_album_number].photos_total; i++)
		{
			int spaceing = 50 - strlen(albums[current_album_number].photos[i].name);
			if (i == current_photo_position)
			{
				set_blue();
				if (input_in_album == 0)
				{
					printf(">> %d     %s", albums[current_album_number].photos[i].number, albums[current_album_number].photos[i].name);

					//space to then print the the dimension
					for (size_t i = 0; i < spaceing; i++)
					{
						printf(" ");
					}
					if (albums[current_album_number].photos[i].dimension < 10)
						printf("  %0.2f MB\n", albums[current_album_number].photos[i].dimension);
					else if (albums[current_album_number].photos[i].dimension < 100)
						printf(" %0.2f MB\n", albums[current_album_number].photos[i].dimension);
					else
						printf("%0.2f MB\n", albums[current_album_number].photos[i].dimension);

				}

				if (input_in_album == 1)
					open_remove_album(current_photo_position, i);

				set_white();
			}
			else
			{
				printf("   %d     %s", albums[current_album_number].photos[i].number, albums[current_album_number].photos[i].name);
				//space to then print the the dimension
				for (size_t i = 0; i < spaceing; i++)
				{
					printf(" ");
				}
			
				if (albums[current_album_number].photos[i].dimension < 10)
					printf("  %0.2f MB\n", albums[current_album_number].photos[i].dimension);
				else if(albums[current_album_number].photos[i].dimension < 100)
					printf(" %0.2f MB\n", albums[current_album_number].photos[i].dimension);
				else
					printf("%0.2f MB\n", albums[current_album_number].photos[i].dimension);
			}
		}
	}
	printf("\n\n");
	set_yellow();
	printf("              [ CONTROLS ] \n");
	if (input_controls == 1)
		print_controls();

}

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	
	int column, row, length;
	char word_hunt_map[25][25], string[50];
	int i = 0;
	int found = 0, not_found = 0;


	FILE *word_hunt = fopen("word_hunt.txt", "r");

	if (!word_hunt)
	{
		printf("Error! File did not open.\n");
		return 1;
	}

	for (row = 0; row < 25; row++)
	{
		for (column = 0; column < 25; column++)
		{
			fscanf(word_hunt, " %c", &word_hunt_map[row][column]);
			word_hunt_map[row][column] = toupper(word_hunt_map[row][column]);
		}
	}

	fclose(word_hunt);

	printf("   ");

	for (column = 0; column < 25; column++)
	{
		printf("%-2d", column);
	}

	printf("\n______________________________________\n");

	for (row = 0; row < 25; row++)
	{
		printf("%-2d|", row);
		for (column = 0; column < 25; column++)
			printf("%c ", word_hunt_map[row][column]);
		printf("\n");
	}



	while (strlen(string)>0)
	{

		printf("Searching for: [%s]\n", string);

		int count = 0;
		
		for (row = 0; row < 25; row++)
		{
			for (column = 0; column < 25; column++)
			{

				if ((word_hunt_map[row][column] == (string[0])) && word_hunt_map[row][column+1]== (string[1]) && word_hunt_map[row][column + 2] == (string[2])
					|| ((word_hunt_map[row][column] == (string[0])) && word_hunt_map[row+1][column ] == (string[1]) && word_hunt_map[row+2][column] == (string[2])))
					count++;

			}
		}

		
		if (count != 0)
		{
			found++;
		}
		else
		{
			not_found++;
		}
		
		printf("Found %s %d times\n", string, count);

		if (i != 110)
		{
			i++;
		}
		 
		else
		{

			printf("Found word: %d \nNot Found word: %d \n", found, not_found);

			if (not_found != 0)
			{
				printf("A problem has been occured!!");
			}
			else
			{
				printf("Program is %%100 true ");
			}
			break;
		}

	}

	printf("\n");
	return 0;
}

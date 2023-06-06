#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "header.h"

int main() {
	FILE* file = fopen("file.txt", "r");
	if (!file) {
		perror("\n");
		return 1;
	}

	FILE* fp = fopen("done.txt", "w");
	if (ferror(fp)) {
	  printf("\nGreska u otvaranju datoteke done.txt");
	  clearerr(fp);
	}
	
    static int corner = 0;
	printf("Odaberite kut za ASCII art (1-Gornji, 2-Donji): ");

	do {
		scanf_s("%d", &corner);
		if (corner < 1 || corner > 2) {
			printf("Broj koji ste odabrali ne predstavlja broj kuta, probajte ponovno:\n");
		}
	} while (corner < 1 || corner > 2);

	int linesToSkip = 0;
	char key;

	AsciiArt art;
	art.count = 0;
	art.lines = NULL;

	char line[MAX_LINE_LENGTH];
	while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
		art.lines = realloc(art.lines, (art.count + 1) * sizeof(char*));
		art.lines[art.count] = _strdup(line);
		art.count++;
	}

	fseek(file, 0, SEEK_SET);
	fclose(file);

	while ((key = _getch()) != '*') {
		system("cls");

		if (key == 'w' || key == 'W') {
			if (linesToSkip > 0) {
				linesToSkip--;
			}
		}
		else if (key == 's' || key == 'S') {
			linesToSkip++;
		}

		printf("(W/w za gore)\n(S/s za dolje)\n(Pritisni '*' za prekid programa)\n");
		printArt(&art, linesToSkip, corner);
	}

	//fprintf(fp, "Done");
	repetition(fp);
	freeAsciiArt(&art);
	return 0;
}

	
	

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"

int main() {
	FILE* file = fopen("file.txt", "r");
	if (!file) {
		perror("\n");
		return 1;
	}

	int corner = 0;
	printf("Odaberite kut za ASCII art (1-Gornji, 2-Donji): ");
	
	do {
	scanf_s("%d", &corner);
	} while (corner < 1 || corner > 2);

	int linesToSkip = 0;
	char key;
	
	while ((key=_getch())!='*') {
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
		printArt(file, corner, linesToSkip);
	}
    
	fclose(file);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>*/
/*u tekstualnu datoteku unesi kut kretanja i prema tome nastavi kod*/
int main() {

	FILE* fps;
	fps = fopen("dvdlogo.jpg", "r+");

	if (!fps) {
        printf("Greska pri otvaranju slike!");
		
		exit(1);
	}

	FILE* fp = fopen("test.txt", "w");
	if (!fp) {
		printf("Greska pri otvaranju datoteke!");
		exit(1);
	}
	
	int yourChoice = 0;

	printf("Izaberi pocetni kut kretanja loga: \n1 - (gornji desni) \n2 - (gornji lijevi) \n3 - (donji desni) \n4 - (donji lijevi)\n");
	printf("Tvoj odabir: ");
	scanf_s("%d", &yourChoice);

	switch (yourChoice) {
	case 1:
		fprintf(fp, "Kut je gornji desni\n");
		fclose(fp);
		rename("test.txt", "gd.txt");
		printf("Done!");
		break;

	case 2:
		fprintf(fp, "Kut je gornji lijevi\n");
		fclose(fp);
		rename("test.txt", "gl.txt");
		printf("Done!");
		break;

	case 3:
		fprintf(fp, "Kut je donji desni\n");
		fclose(fp);
		rename("test.txt", "dd.txt");
		printf("Done!");
		break;

	case 4:
		fprintf(fp, "Kut je donji lijevi\n");
		fclose(fp);
		rename("test.txt", "dl.txt");
		printf("Done!");
		break;

	default:
		break;
	}

	
	fclose(fp);

	
	return 0;
}

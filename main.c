#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
	FILE* file = fopen("file.txt", "r");
	if (!file) {
		perror("Greska pri otvaranju datoteke!\n");
		return 1;
	}

	int corner = 0;
	printf("Odaberite kut za ASCII art (1-Gornji, 2-Donji): ");
	scanf("%d", &corner);

	printArt(file, corner);

	fclose(file);
	return 0;
}


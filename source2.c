#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "header.h"

void printArt(const AsciiArt* art, int linesToSkip, int corner) {
	int linesToPrint = TERMINAL_LINES;
	if (linesToSkip > art->count) {
		linesToSkip = art->count;
	}
		

	if (linesToPrint > art->count - linesToSkip) {
		linesToPrint = art->count - linesToSkip;
	}
		

	if (corner == 2) {
		linesToSkip = art->count - linesToPrint - linesToSkip;
	}

	for (int i = 0; i < linesToSkip; i++) {
		printf("\n");
	}

	for (int i = 0; i < linesToPrint; i++) {
		printf("%s", art->lines[i + linesToSkip]);
	}
}

void repetition(FILE* fp) {

}

void freeAsciiArt(AsciiArt* art) {
	
	for (int i = 0; i < art->count; i++) {
		free(art->lines[i]);
	}
	free(art->lines);
	art->count = 0;
	art->lines = NULL;
}

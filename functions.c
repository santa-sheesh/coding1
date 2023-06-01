#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
//when I press 1, the art doesn't appear immediately, have to press 'w' or 's' to appear
#define MAX_LINE_LENGTH 100
#define TERMINAL_LINES 40
void printArt(FILE* file, int corner, int linesToSkip) {
	char line[MAX_LINE_LENGTH];
	int lineNumber = 0;

	while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
		lineNumber++;
	}

	fseek(file, 0, SEEK_SET);
	
	if (corner == 2) {
		linesToSkip = TERMINAL_LINES - lineNumber;
	}

	int i = 0;

	for (i; i < linesToSkip; i++) {
		printf("\n");
	}

	while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
		printf("%s", line);
	}
}

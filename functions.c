#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#define MAX_LINE_LENGTH 100
#define TERMINAL_LINES 40
void printArt(FILE* file, int corner) {
	char line[MAX_LINE_LENGTH];
	int lineNumber = 0;

	while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
		lineNumber++;
	}

	fseek(file, 0, SEEK_SET);

	int linesToSkip = 0;
	switch (corner) {
	case 1:
		linesToSkip = 0;
		break;
	case 2:
		linesToSkip = TERMINAL_LINES - lineNumber;
		break;
	default:
		printf("Pogresna opcija za kut!\n");
		return;
	}

	int i = 0;

	for (i; i < linesToSkip; i++) {
		printf("\n");
	}

	while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
		printf("%s", line);
	}
}

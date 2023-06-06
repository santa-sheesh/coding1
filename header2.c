#pragma once
typedef struct {
	char** lines;
	int count;
} AsciiArt;

#define MAX_LINE_LENGTH 100
#define TERMINAL_LINES 40

void printArt(const AsciiArt* art, int linesToSkip, int corner);
void freeAsciiArt(AsciiArt* art);
void repetition(FILE* fp);

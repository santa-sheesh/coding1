#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define MAX_LINE_LENGTH 100
#define TERMINAL_LINES 40

typedef struct {
    char** lines;
    int count;
} AsciiArt;

void printArt(const AsciiArt* art, int linesToSkip);
void freeAsciiArt(AsciiArt* art);

int main() {
    FILE* file = fopen("file.txt", "r");
    if (!file) {
        perror("\n");
        return 1;
    }

    int corner = 0;
    printf("Odaberite kut za ASCII art (1-Gornji, 2-Donji): ");

    do {
        scanf("%d", &corner);
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
        art.lines[art.count] = strdup(line);
        art.count++;
    }

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
        printArt(&art, linesToSkip);
    }
    freeAsciiArt(&art);
    return 0;
}

void printArt(const AsciiArt* art, int linesToSkip, int corner) {
    int linesToPrint = TERMINAL_LINES;
    if (linesToSkip > art->count)
        linesToSkip = art->count;

    if (linesToPrint > art->count - linesToSkip)
        linesToPrint = art->count - linesToSkip;

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


void freeAsciiArt(AsciiArt* art) {
    for (int i = 0; i < art->count; i++) {
        free(art->lines[i]);
    }
    free(art->lines);
    art->count = 0;
    art->lines = NULL;
}




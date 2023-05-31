#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100
#define TERMINAL_LINES 25

void printArt (FILE* file, int corner){
  char line[MAX_LINE_LENGTH];
  int lineNumber = 0;

  while (fgets (line, MAX_LINE_LENGTH, file) != NULL){
      lineNumber++;
    }

  fseek (file, 0, SEEK_SET);

  int linesToSkip = 0;
  switch (corner){
    case 1:			
      linesToSkip = 0;
      break;
    case 2:			
      linesToSkip = TERMINAL_LINES - lineNumber;
      break;
    default:
      printf ("PogreE!na opcija za kut.\n");
      return;
    }

  for (int i = 0; i < linesToSkip; i++){
      printf ("\n");
    }

  while (fgets (line, MAX_LINE_LENGTH, file) != NULL){
      printf ("%s", line);
    }
}

int main (){
  FILE *file = fopen ("file.txt", "r");
  if (!file){
      printf ("GreE!ka pri otvaranju datoteke.\n");
      return 1;
    }

  int corner;
  printf ("Odaberite kut za ASCII art (1-Gornji, 2-Donji): ");
  scanf ("%d", &corner);

  printArt (file, corner);

  fclose (file);
  return 0;
}

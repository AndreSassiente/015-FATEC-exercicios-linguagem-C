#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
  char sentence[99];
  char vowels[99];
  char consonants[99];
  char numbers[99];
  char symbols[99];

  int n = 0;          // number
  int s = 0;          // symbol
  int v = 0;          // vowel
  int c = 0;          // consonants
  int i = 0;          // index
  int ls = 0;         // length sentence

  printf("TYPE A SENTENCE: ");
  fflush(stdin);
  gets(sentence);

  for (i = 0; i < strlen(sentence); i++){

    while(isspace(sentence[i])){ i++; }   // enquanto for espaco vazio, pule e verifique a proxima letra.

    sentence[i] = toupper(sentence[i]);

    if (sentence[i] == 'A' || sentence[i] == 'E' || sentence[i] == 'I' || sentence[i] == 'O' || sentence[i] == 'U') {

      vowels[v] = sentence[i];
      v++;

    } else if (sentence[i] == 'Q' || sentence[i] == 'W' || sentence[i] == 'R' || sentence[i] == 'T' || sentence[i] == 'Y' || sentence[i] == 'P' || sentence[i] == 'S' || sentence[i] == 'D' || sentence[i] == 'F' || sentence[i] == 'G' || sentence[i] == 'H' || sentence[i] == 'J' || sentence[i] == 'K' || sentence[i] == 'L' || sentence[i] == 'Z' || sentence[i] == 'X' || sentence[i] == 'C' || sentence[i] == 'V' || sentence[i] == 'B' || sentence[i] == 'N' || sentence[i] == 'M') {

    consonants[c] = sentence[i];
    c++;

    } else if (sentence[i] == '0' || sentence[i] == '1' || sentence[i] == '2' || sentence[i] == '3' || sentence[i] == '4' || sentence[i] == '5' || sentence[i] == '6' || sentence[i] == '7' || sentence[i] == '8' || sentence[i] == '9') {

    numbers[n] = sentence[i];
    n++;

    } else {

    symbols[s] = sentence[i];
    s++;

    }

  }

  printf("\n\nVOWELS \n");
	for (i = 0; i < v; i++) { printf("%c ", vowels[i]); }

	printf("\n\n\nCONSONANTS \n");
	for (i = 0; i < c; i++) { printf("%c ", consonants[i]); }

  printf("\n\n\nNUMBERS \n");
	for (i = 0; i < n; i++) { printf("%c ", numbers[i]); }

  printf("\n\n\nSYMBOLS \n");
	for (i = 0; i < s; i++) { printf("%c ", symbols[i]); }

	printf("\n\n\n");

  return 0;
}

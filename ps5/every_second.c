#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int main (int argc, char* argv[]) {
	FILE *fpointer= fopen(argv[1],"r");
	char letter;
	int c = 0;
	int g = 0;
	int sum = 0;
	int l = 0;
	int h = 0;
	char word[80];
	while (l != 2) {
		letter = fgetc(fpointer);
		        if (letter == 'O' || letter == 'P'){
				l++;
			}
			if (letter == 'S' || letter == 'T' || letter == 'A' || letter == 'R'){
				sum++;
			}
			if (sum >= 5){
				if (letter == 'T'){
					continue;
				}
			if (letter == ' ' || letter == EOF){
			g++;
			word[c] = ' ';
			word[c+1] = '\0';
			c++;
			h++;
			}
			if (g % 2 == 0){
			if (letter == ' '){
				c = c - 2;
			}
			word[c] = letter;
			word[c+1] = '\0';
			c++;
			h++;
			}
			}
	}
	fclose(fpointer);
	FILE *fpointerr= fopen("output.txt","w");
	for (int  i = 0; i < h - 1; i++){
	fprintf(fpointerr,"%c",word[i]);
	}
	fclose(fpointerr);
	return 0;
}

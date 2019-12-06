#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int main (int argc, char* argv[]) {
	FILE *fpointer= fopen(argv[1],"r");
	char letter;
	int c = 0;
	int g = 0;
	int h = 0;
	int s = 0;
	int t = 0;
	int a = 0;
	int r = 0;
	int l = 0;
	int k = 0;
	int j = 0;
	int sum = 0;
	int lol = 0;
	char word[500];
	while (sum != 1) {
		letter = fgetc(fpointer);
		        if (r == 1 && letter == 'T'){
				lol = 1;
			}
			if (letter == 'R' && a == 1){
				r = 1;
			}
			if ( j == 1 && letter != 'R'){
				a = 0;
			}
			if (letter == 'A' && t == 1){
				a = 1;
			}
			if ( t == 1 && letter != 'A'){
				t = 0;
			}
			if (letter == 'T' && s == 1){
				t = 1;
			}
			if ( s == 1 && letter != 'T'){
				s = 0;
			}
			if (letter == 'S'){
				s = 1;
			}
		if ( lol == 1){
			if (letter == 'P' && j == 1){
				sum = 1;
			}
			if ( j == 1 && letter != 'P'){
				j = 0;
			}
			if (letter == 'O' && k == 1){
				j = 1;
			}
			if ( k == 1 && letter != 'O'){
				k = 0;
			}
			if (letter == 'T' && l == 1){
				k = 1;
			}
			if ( l == 1 && letter != 'T'){
				l = 0;
			}
			if (letter == 'S'){
				l = 1;
			}
			if (letter == ' ' || letter == EOF){
				g++;
				word[c] = ' ';
				word[c+1] = '\0';
				c++;
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
	if (g % 2  == 0){
		h = h - 4;
	}
	letter = fgetc(fpointer);
	if (letter == EOF){
		FILE *ff = fopen("output.txt","w");
		fclose(ff);
		return 0;
		fclose(fpointer);
	fclose(fpointer);
	}
	FILE *fpointerr= fopen("output.txt","w");
	for (int p = 2; p < h; p++){
		fputc(word[p],fpointerr);
	}

	fclose(fpointerr);
	return 0;
}


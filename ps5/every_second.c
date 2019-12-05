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
	int d = 0;
	int e = 0;
	int w = 0;
	int q = 0;
	int sum = 0;
	char word[500];
	while (sum != 1) {
		letter = fgetc(fpointer);
		if (t >= 2){
			t++;
		}
		if (letter == 'S'){
			s++;
		}    
		if (letter == 'T'){
			t++;
		}	
		if (letter == 'A'){
			a++;
		}	
		if (letter == 'R'){
			r++;
		}
		if ( t >= 2 && r < 1){
			t--;
		}
		if (s >= 1 && t >= 3 && a >= 1 && r >= 1){
			if (letter == 'O'){
				d++;
			}
			if(letter == 'P'){
				e++;
			}
			if (letter == 'T'){
				w++;
			}
			if (letter == 'S'){
				q++;
			}
			if ( e >= 1 && d < 1){
				e--;
			}
			if ( e >= 1 && w < 1){
				e--;
			}
			if ( e >= 1 && q < 1){
				e--;
			}
			if (q >= 1 && w >= 1 && e >= 1 && d >= 1){
				sum = 1;
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
	while (d > 2)
		d--;
	while (e > 2)
		e--;
	while (w > 2)
		w--;
	while (q > 2)
		q--;
	fclose(fpointer);
	FILE *fpointerr= fopen("output.txt","w");
	for (int p = 1; p < h; p++){
		fputc(word[p],fpointerr);
	}

	fclose(fpointerr);
	return 0;
}

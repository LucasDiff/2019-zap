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
		if (s >= 1 && t >= 2 && a >= 1 && r >= 1){
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
			if (q >= 1 && w >= 1 && e >= 1 && d >= 1){
				sum = 1;
				word[c - 3] = ' ';
				word[c - 2] = ' ';
				word[c - 1] = ' ';
				word[c] = ' ';
				break;
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
	fclose(fpointer);
	FILE *fpointerr= fopen("output.txt","w");
	for (int p = 3; p < h; p++){
		fputc(word[p],fpointerr);
	}

	fclose(fpointerr);
	return 0;
}

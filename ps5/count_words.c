#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
bool is_ananas(char word[], const int velkost);
int main (int argc, char* argv[]) {
	FILE *fpointer= fopen(argv[1],"r");
	char letter;
	int count=0;
	char word[20];
	int c =0;
	int velkost = 0;
	char pismeno;
	char lol;
	while (letter != EOF) {
	letter = fgetc(fpointer);
		if (letter == ',' || letter == '.' || letter == '(' || letter == ')'){
			continue;
		}
			if (letter == ' ' || letter == EOF){
			if(is_ananas(word,velkost) == true){
				count ++;
			}
			        velkost = 0;
				c = 0;
				continue;
		}
			word[c] = letter;
			word[c+1] = '\0';
			c++;
			velkost++;
	}
	fclose(fpointer);
	FILE *fpointerr= fopen(argv[1],"w");
	pismeno = count + '0';
	if (pismeno > 57){
		pismeno = pismeno - 10;
		lol = 49;
		fputc(lol,fpointerr);
	}
        fputc(pismeno,fpointerr);
	fclose(fpointerr);
	return 0;
}
bool is_ananas(char word[], const int velkost){
	int a = 0;
	int n = 0;
	int s = 0;
	for (int i = 0; i < velkost; i++){
		if (word[i] == 'a' || word[i] == 'A'){
		       a++;	
		}
		if (word[i] == 'n' || word[i] == 'N'){
		       n++;
		}
		if (word[i] == 's' || word[i] == 'S'){
			s++;
		}
	}
	if (a == 3 && n == 2 && s == 1){
		return true;
	}
	return false;
}

	


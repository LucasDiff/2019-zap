#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"

int get_word(char secret[]){
	// check if file exists first and is readable
	FILE *fp = fopen(WORDLIST_FILENAME, "rb");
	if( fp == NULL ){
		fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
		return 1;
	}

	// get the filesize first
	struct stat st;
	stat(WORDLIST_FILENAME, &st);
	long int size = st.st_size;

	do{
		// generate random number between 0 and filesize
		long int random = (rand() % size) + 1;
		// seek to the random position of file
		fseek(fp, random, SEEK_SET);
		// get next word in row ;)
		int result = fscanf(fp, "%*s %20s", secret);
		if( result != EOF )
			break;
	}while(1);

	fclose(fp);

	return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[]){
	int sum = 0;
	for ( int i = 0; i < strlen(secret); i++){
		for ( int a = 0; a < strlen(letters_guessed) ; a++){
			if (secret[i] == letters_guessed[a]){
				sum = (int) sum + 1;
				break;
			}
		}
	}
	if (sum == strlen(secret)){
		return 1;
	}
	else return 0;	       
}

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){
	int sum = 0;
	int l = 0;
	int size = strlen(secret);
	for (int a = 0; a < size; a++){
		guessed_word[a] = '_';
		l = a;
	}
	for ( int i = 0; i < size; i++){
		for ( int a = 0; a < strlen(letters_guessed); a++){
			if ( secret[i] != letters_guessed[a]){
				sum += 1;
			}
		}
		if ( sum != strlen(letters_guessed)){
			guessed_word[i] = secret[i];
		}
		sum = 0;	       
	}
	guessed_word[l + 1] = '\0';
}

void get_available_letters(const char letters_guessed[], char available_letters[]){
	char lol[] = "abcdefghijklmnopqrstuvwxyz";
	int sum = 0, count = 0, counter = 0;
	int size = strlen(lol);
	int k = 0;
	int sizee = strlen(letters_guessed);
	for ( int i = 0; i < size; i++){
		for ( int a = 0; a < size; a++){
			if (  lol[i] == letters_guessed[a]){
				sum = 1;
			}
		}
		if ( sum != 1){
			available_letters[counter] = lol[i] ;
			counter += 1;
		}
		else {
			count += 1;
		}
		sum = 0;
		k = i;
	}
	available_letters[k + 1 - sizee] = '\0';
}

void hangman(const char secret[]){
	int g = 8, sum =0, h = 8, l = 0, size = 0;
	char guess;
	char secrett[strlen(secret)];
	char abeceda[]= "abcdefghijklmnopqrstuvwxyz";
	for (int w = 0; 0 < strlen(secret); w++){
		secrett[w] = '_';
		l = w;
	}
	secrett[l + 1] = '\0';
	size = strlen(secret);
	printf("Welcome to the game, Hangman!\n");
	printf("I am thinking of a word that is %d letters long.\n", size);
		printf("---------------\n");
	for ( int i = 0; i < g &&  secret != secrett; i++){
                g += 1;
		printf("You have %d guesses left.\n", h);
		printf("Available letters : %s", abeceda);
		printf("\n");
		printf("Please guess a letter: ");
		scanf("%c", &guess);
		for (int a = 0; a < size; a++){
			if (guess == secret[a]){
			       secrett[a] = guess;
			       sum = 1;
			}
		}
                if (sum == 1){ 
			printf("Good guess: %s", secrett);
		}
		else if(sum == 0) {
			printf("Oops! That letter is not in my word: %s", secrett);
			g += -1;
			h += -1;
			} 
		printf("\n");
                sum = 0;
		printf("---------------\n");
	}
	if (secrett == secret){
		printf("Congratulations, you won!");
	}
	else printf("Sorry, you ran out of guesses. The word was %s.", secret);
}




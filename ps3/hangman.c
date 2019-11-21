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
	printf("Welcome to the game, Hangman!\n");
	printf("I am thinking of a word that is %d letters long.\n", (int)strlen(secret));
	int idx_of_letters_guessed = 0;
	char op[50], letters_guessed[50], available_letters[50], guess[50];
        for ( int g = 8; g > 0; g--){
		printf("-------------\n");
		printf("You have %d guesses left.\n", g);
		get_available_letters(letters_guessed, available_letters);
		printf("Available letters: %s", available_letters);
		printf("\n");
		printf("Please guess a letter: ");
		scanf("%49s", guess);
		if (strlen(guess) > 1) {
                if (is_word_guessed(secret, guess)) {
			printf("Congratulations, you won!\n");
			return;
		}
		else {
			printf("Sorry, bad guess, the word was %s.\n", secret);
			return;
		}
		}
		if (strchr(letters_guessed, guess[0])){
			printf("Oops, you have already guessed that letter:");
			for (int a; a < strlen(op); a++){
				printf(" %c", op[a]);
			}
			printf("\n");
			g++;
			continue;
		}
		letters_guessed[idx_of_letters_guessed] = guess[0];
	        idx_of_letters_guessed ++;
	        get_guessed_word(secret, letters_guessed, op);
		if (strchr(secret, guess[0]) != NULL){
		        printf("Good guess:");
			int lengthofop = strlen(op);
			for ( int j =0; j< lengthofop; j++){
			printf(" %c", op[j]);
			}
			printf("\n"); 
			g++;
		}
		else {
			printf("Oops! That letter is not in my word:");
			int lengthofop = strlen(op);
			for ( int j =0; j< lengthofop; j++){
			printf(" %c", op[j]);
			}
			printf("\n"); 
		}
		if (is_word_guessed(secret, letters_guessed)){
				printf("-------------\n");
				printf("Congratulation, you won!\n");
				return;
				}
	}
	printf("-------------\n");
	printf("Sorry, you ran out of guessed. The word was %s.", secret);
}

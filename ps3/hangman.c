#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"

int get_word(char secret[]){
	FILE *fp = fopen(WORDLIST_FILENAME, "rb");
	if( fp == NULL ){
		fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
		return 1;
	}

	struct stat st;
	stat(WORDLIST_FILENAME, &st);
	long int size = st.st_size;

	do{
		long int random = (rand() % size) + 1;
		fseek(fp, random, SEEK_SET);
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
	for ( int i = 0; i < strlen(secret); i++){
		for ( int a = 0; a < strlen(letters_guessed); a++){
			if ( secret[i] != letters_guessed[a]){
				sum += 1;
			}
		}
		if ( sum == strlen(letters_guessed)){
			printf("_");
		}
		else printf("%c", secret[i]);
		sum = 0;
	}
	printf("\n");
}

void get_available_letters(const char letters_guessed[], char available_letters[]){
	char abeceda[]= "abcdefghijklmnoprstuvwxyz";
	int sum = 0, count = 0;
	for ( int i = 0; i < strlen(abeceda); i++){
		for ( int a = 0; a < strlen(abeceda); a++){
			if (  abeceda[i] == letters_guessed[a]){
				sum = 1;
			}
		}
		if ( sum != 1){
			printf("%c",abeceda[i]);
		}
		else {
			count += 1;
		}
		sum = 0;
	}	
	printf("\n");
}

void hangman(const char secret[]){
	int g = 8, sum =0;
	char letters_guessed;
	char secrett[strlen(secret)];
	char abeceda[]= "abcdefghijklmnoprstuvwxyz";
	for (int w = 0; 0 < strlen(secret); w++){
		secrett[w] = '_';
	}
	printf("Welcome to the game, Hangman!\n");
	printf("I am thinking of a word that is %ld letters long\n", strlen(secret));
	for ( int i = 0; i < g &&  secret != secrett; i++){
                g += 1;
		printf("You have %d guesses\n", g);
		printf("Available letters : ");
		get_available_letters( "", abeceda);
		printf("Please guess a letter\n");
		scanf("%c", &letters_guessed);
		for (int a = 0; a < strlen(secret); a++){
			if (letters_guessed == secret[a]){
			       secrett[a] = letters_guessed;
			       sum = 1;
			}
		}
                if (sum == 1){ 
			printf("Good guess: %s", secrett);
		}
		else if(sum == 0) {
			printf("Oops! That letter is not in my word: %s", secrett);
			g += -1;
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


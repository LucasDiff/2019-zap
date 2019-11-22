#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void encode_char(const char character, bool bits[8]);
char decode_byte(const bool bits[8]);
int main() {
	bool bits[8];
	encode_char('A', bits[8]);
	for(int i = 0; i < 8; i++){
		    printf("%d", bits[i]);
	}
	printf("\n");
	return 0;
}
void encode_char(const char character, bool bits[8]){ 
        int ascii_value = character;
	int a = ascii_value;
	int div = 128;
	for (int j = 0; j < 8; j++){
	         if ( a >= div){
		       a = a - div;
                       div = div / 2;
                       bool bits[j] = true;
		 }
		 else { 
			 div = div / 2;
		       bool bits[j] = false;
		 }
	}
	return;
}
char decode_byte(const bool bits[8]){
	int div = 128;
	int sum = 0;
	for (int a = 0; a < 8; a++){
		if (bits[a] == 1){
			sum = sum + div;
			div = div / 2;
		}
	}
	char n = sum;
	return n;
}

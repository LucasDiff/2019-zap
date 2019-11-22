#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
void encode_char(const char character, bool bits[8]);
char decode_byte(const bool bits[8]);
int main() {
	bool bits[8] = {0,1,0,0,0,0,0,1};
	printf("%c\n", decode_byte(bits));
	return 0;
}
void encode_char(const char character, bool bits[8]){ 
	int a = character;
	int div = 128;
	for (int j = 0; j < 8; j++){
	         if ( a >= div){
		       a = a - div;
                       div = div / 2;
                       bits[j] = 1;
		 }
		 else { 
			 div = div / 2;
		       bits[j] = 0;
		 }
	}
	return;
}
char decode_byte(const bool bits[8]){
	int z = 0;
	int sum = 0;
	for (int a = 0; a < 8; a++){
		if (bits[7 - a] == 1){
			z = pow(2, a);	
			sum = sum + z;
		}
	}
	char n = (char)sum;
	printf("%d", sum);
	return n;
}

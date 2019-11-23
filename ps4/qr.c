#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
void encode_char(const char character, bool bits[8]);
char decode_byte(const bool bits[8]);
void encode_string(const char string[], bool bytes[strlen(string)+1][8]);
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]);
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);
int main() {
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
	return n;
}
void encode_string(const char string[], bool bytes[strlen(string)+1][8]){
	bool bits[8];
	for (int i = 0; i < strlen(string) + 1; i++){
		encode_char(string[i], bits);
		for (int a = 0; a < 8; a++){
			bytes [i][a] = bits[a]; 
		}
		if (string[i] == '\0'){
			for (int c = 0; c < 8; c++){
				bytes [i][c] = 0; 
			}
		}
	}
	return;
}
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]){
	for (int c = 0; c < rows; c++){
		int z = 0;
		int sum = 0;
		for (int a = 0; a < 8; a++){
			if (bytes[c][7 - a] == 1){
				z = pow(2, a);	
				sum = sum + z;
			}
		}
		char n = (char)sum;
		string[c] = n;
	}
}

void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
	int a = 0;
	int e = 0;
	int g = 0;
	if (rows % 3 != 0){
		g = 1;
	}
	for (int d = 0; d < offset; d++){
		for (int i = 0; i < cols; i++){
			for (int c = 0; c < 8; c++){
				blocks[a + c] [i] = bytes[e] [c];

			}
			e = e + 1;
		}
		a = a + 8;
	}
        if ( g == 1){
	for (int p = 0; p < 8; p++){
	blocks[p + 8][cols] = 0;
	}	
	}
}
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
	int a = 0;
	int e = 0;
	int f = 0;
	for (int d = 0; d < offset; d++){
		for (int i = 0; i < cols; i++){
			for (int c = 0; c < 8; c++){
				bytes[e][c] = blocks[a + c] [i];
				f = f + bytes[e][c]; 
			}
			if (f == 0){
				return;
			}
			f = 0;
			e = e + 1;
		}
		a = a + 8;
	}	
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float lift_a_car(const int stick_length, const int human_weight, const int car_weight);
float unit_price(const float pack_price, const int rolls_count, const int pieces_count);
int collatz(const int number);
int opposite_number(const int n, const int number);
void counter(const int input_array[], const int array_size, int result_array[2]);
int array_min(const int input_array[], const int array_size);
int array_max(const int input_array[], const int array_size);
int main(){
	return 0; 
}
float lift_a_car(const int stick_length, const int human_weight, const int car_weight){   
	float r2;
        r2 = ((stick_length * human_weight / ( human_weight + car_weight)) * 100)/ 100;
	return r2;
}
float unit_price(const float pack_price, const int rolls_count, const int pieces_count){   
	float up;
	up = ((rolls_count * pieces_count / pack_price / 100) * 100) / 100;
        return up;
}
int collatz(const int number){
	int size, n;
        n = number;
        size = 	1;
	for ( size = 1; n != 1; size++){  
		if ((n % 2)==0){
			n = n / 2;
		}
		else n = n * 3 + 1; 
	}
	return size;
}
int opposite_number(const int n, const int number){
	int on;
	if ( (n+1) / 2  > number){
		 on = (int) number + ( n / 2);
	}
	else if ( (n+1) / 2 < number){
		on = (int) number - ( n / 2);
	}
	else if ( number == (n+1) / 2){
		on = 0;
	}
	else 
		on= (n+1) / 2;
	return on;
} 
void counter(const int input_array[], const int array_size, int result_array[2]){
	for ( int i = 0; array_size >= i; i = i + 2){
		result_array[0] = result_array[0] + input_array[i];
		result_array[1] = result_array[1] + input_array[ i - 1 ];
	}
}
int array_min(const int input_array[], const int array_size){
	int cislo = 9999999,i;
	if (array_size == 0){
		return -1;
	}
	for ( i = 0 ; i <= array_size; i++){
		if ( cislo > input_array[i]){ 
		cislo = input_array[i];
		}
	}
	return cislo;
} 
int array_max(const int input_array[], const int array_size){
	int cislo = 0,i;
	if (array_size == 0){
		return -1;
	}
	for ( i = 0 ; i <= array_size; i++){
		if ( cislo < input_array[i]){ 
		cislo = input_array[i];
		}
	}
	return cislo;
} 



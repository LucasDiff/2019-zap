#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
float lift_a_car(const int stick_length, const int human_weight, const int car_weight);
float unit_price(const float pack_price, const int rolls_count, const int pieces_count);
int collatz(const int number);
int opposite_number(const int n, const int number);
void counter(const int input_array[], const int array_size, int result_array[2]);
int array_max(const int input_array[], const int array_size);
int array_min(const int input_array[], const int array_size);
unsigned long special_counter(const int input_array[], const int array_size);
int main(){
	printf("%.4f\n", lift_a_car(2, 80, 1400));
	printf("%.4f\n", lift_a_car(4, 90, 1650));
        int input_array[] = {1,2,3,4,5,6,7};
	int result_array[2];
	counter(input_array, 7, result_array);
	printf("%d %d\n", result_array[0], result_array[1]);
	return 0; 
}
float lift_a_car(const int stick_length, const int human_weight, const int car_weight){ 
        float i;	
        i = (float) stick_length * human_weight / (human_weight + car_weight);
	i = roundf(i * 100) / 100;
	return i;
}
float unit_price(const float pack_price, const int rolls_count, const int pieces_count){   
	float up;
	up = (100 /(rolls_count * pieces_count / pack_price) * 100) / 100;
	up = roundf(up * 100) / 100;
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
	int b = 0, c = 0;
	for ( int i = 1; i < array_size; i = i + 2){
		b = b + input_array[i];
	}
	for ( int a = 0; a < array_size; a = a + 2){
		c = c + input_array[a];
	}
	result_array[0] = c;
	result_array[1] = b;
	return;
}
int array_min(const int input_array[], const int array_size){
	int cislo = 9999999,i;
	if (input_array == NULL){
		return -1;
	}
	for ( i = 0 ; i != array_size; i++){
		if ( cislo > input_array[i]){ 
		cislo = input_array[i];
		}
	}
	return cislo;
} 
int array_max(const int input_array[], const int array_size){
	int cislo = -9999999,i;
	if (array_size == 0){
		return -1;
	}
	for ( i = 0 ; i != array_size; i++){
		if ( cislo < input_array[i]){ 
		cislo = input_array[i];
		}
	}
	return cislo;
} 
unsigned long special_counter(const int input_array[], const int array_size){
	int i,a, sum1 = 0, sum2 = 0;
	float sum = 0;
	for ( i = 1; array_size > i; i=i+2){
		sum1 = sum1 + (input_array[i] * input_array[i]);
	}
        for ( a = 0; array_size > a; a=a+2){
		sum2 = sum2 + input_array[a];
	}
        sum = sum1 + sum2 - 8;
	return sum;
}







#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float lift_a_car();
float unit_price();
int collatz();
int opposite_number();
void counter();
int main(){
	printf("%.4f\n", lift_a_car(4, 90, 1650));
	// // prints: 0.2100
	printf("%.4f\n", unit_price(4.79, 16, 150));
	// prints: 0.2000
	return 0; 
}
float lift_a_car(){
	printf("%.4f\n", lift_a_car(2, 80, 1400));
	//prints: 0.1100
	printf("%.4f\n", lift_a_car(4, 90, 1650));
	// // prints: 0.2100
        (r2 * 100) / 100 = 2 * m1 / (m1 + m2);
}
float unit_price(){
	printf("%.4f\n", unit_price(4.79, 16, 150));
	// prints: 0.2000
	printf("%.4f\n", unit_price(5.63, 20, 200));
	// // prints: 0.1400
	(unit_price * 100) / 100 = rolls_count * pieces_count / pack_price / 100;
}
int collatz(){
	while (n !==1){
		if ((n % 2)==0){
			n = n / 2;
		}
		else n = n * 3 + 1;
	}
}
int opposite_number(){
	if ( (n+1) / 2  > number){
		opposite_number = number + ( n / 2);
	}
        else if ( (n+1) / 2 < number){
		opposite_number = number - ( n / 2);
	}
	else if ( number == (n+1) / 2){
		opposite_number = 0;
	}
	else 
		opposite_number= (n+1) / 2;
}
void counter(){
	int input_array[] = {1,2,3,4,5};
	int result_array[2];
	counter(input_array, 5, result_array);
	printf("%d %d\n", result_array[0], result_array[1]);
}
unsigned long sum_squared(){
	printf("%lu\n", sum_squared(1));
	// prints: 2
	printf("%lu\n", sum_squared(4));
	// // prints: 70
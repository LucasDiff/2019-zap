#include <superkarel.h>
int main(){
	turn_on("task_5.kw");
	set_step_delay(100);
	while(front_is_clear()){
		step();
	}
	while (no_beepers_present()){
	if (front_is_blocked()){
		turn_left();
	}
	put_beeper();
	step();
	}
	turn_left();
	step();
	turn_left();
	step();
	step();
	while(not_facing_north()){
		turn_left();
	}
	turn_off();
	return 0;
} 

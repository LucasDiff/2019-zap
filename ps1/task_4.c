#include <superkarel.h>
void turn_right();
void check();
void moveup();
void repair();
int main() {
	set_step_delay(150);
	turn_on("task_4.kw");
	turn_right();
	repair();
	while(front_is_clear() && left_is_clear() ){
		if(beepers_present()){
			pick_beeper();
		}
		check();
		if (facing_south()){
			repair();
		}
		else moveup();
		step();
	}
		if(beepers_present()){
			pick_beeper();
		}
		check();
		if (facing_south()){
			repair();
		}
		else moveup();
		turn_off();
		return 0;
}
void turn_right(){
	turn_left();
	turn_left();
	turn_left();
}
void repair(){
	turn_left();
	turn_left();
	while (front_is_clear()){
		step();
	}
	turn_left();
	turn_left();
	while(front_is_clear()){
		if(no_beepers_present()){
			put_beeper();
		}
			step();
	}
	turn_left();
	if (no_beepers_present()){
		put_beeper();
	}
}
void check(){
	turn_left();
	while(front_is_clear() && no_beepers_present()){
		step();
		if(beepers_present()){
			turn_left();
			turn_left();
		}
	}
}
void moveup(){
	turn_left();
	turn_left();
	while (front_is_clear()){
		step();
	}
	turn_left();
}



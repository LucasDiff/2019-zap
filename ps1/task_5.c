#include <superkarel.h>
void check();
void kruh();
void turn_right();
int main(){
	turn_on("task_5.kw");
	set_step_delay(100);
	while(not_facing_west()){
		turn_left();
	}
	while(front_is_clear()){
		step();
	}
	turn_left();
	while(front_is_clear()){
		step();
	}
	turn_left();
	while(front_is_clear()){
		step();
		put_beeper();
	}
	while (beepers_present()){
		check();
	}
	turn_left();
	turn_left();
	step();
	turn_right();
	while(front_is_clear()){
		step();
		put_beeper();
	}
	while(beepers_present()){
		check();
	}
	turn_left();
	turn_left();
	step();
	put_beeper();
	turn_left();
	turn_left();
	while(front_is_clear()){
		step();
	}
	turn_left();
	kruh();
	turn_left();
	step();
	while(no_beepers_present()){
		step();
	}
	pick_beeper();
	while(not_facing_north()){
		turn_left();
	}

	turn_off();
	return 0;
} 
void check(){
	while(beepers_present()){
		turn_left();
		turn_left();
		pick_beeper();
		if (no_beepers_present()){
			step();
		}
		while(beepers_present()&& front_is_clear()){
			step();
			if (no_beepers_present()){
				turn_left();
				turn_left(); 
				step();
				pick_beeper();
				step();
			}
		}
	}
}
void kruh(){
	while(no_beepers_present()){
	if (front_is_blocked()){
		turn_left();
	put_beeper();
	step();
	put_beeper();
	} 
	else 
		put_beeper();
	step();
	}
		if (front_is_blocked()){
			turn_left();
			turn_left();
			step();
			pick_beeper();
			turn_left();
			turn_left();
	}
}
void turn_right(){
	turn_left();
	turn_left();
	turn_left();
}

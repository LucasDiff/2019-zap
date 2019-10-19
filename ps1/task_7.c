#include <superkarel.h>
void turn_right();
void check();
void doit();
bool checkey();
int main(){
	turn_on("task_77.kw"); 
	set_step_delay(100);
	while(front_is_clear()){
		put_beeper();
		step();
	}
	put_beeper();
	turn_left();
	turn_left();
	while(front_is_clear()){
		step();
	}
	turn_left();
	turn_left();
	if(left_is_clear()){
	check();
	if(checkey()){
		while(not_facing_east()){
			turn_left();
		}
		pick_beeper();
		pick_beeper();
		step();
	}
		while(not_facing_east()){
			turn_left();
		}
		step();
	}

	while(front_is_clear()){
		while(left_is_blocked() && front_is_clear()){
			step();
		}
	check();
	if(checkey()){
		pick_beeper();
		pick_beeper();
	}
	turn_left();
	turn_left();
	if(front_is_clear()){
	step();
	}
	while(left_is_blocked()&& front_is_clear()){
		step();
	}
	}
	turn_left();
	turn_left();
	while (front_is_clear()){
		pick_beeper();
		step();
	}
	pick_beeper();
	turn_left();
	turn_left();
	while(front_is_clear()){
		if(beepers_present()){
			turn_left();
			step();
			put_beeper();
			turn_left();
turn_left();
			step();
			turn_left();
			pick_beeper();
		}
		step();
	}
	if(beepers_present()){
			pick_beeper();
			turn_left();
			step();
			turn_left();
			turn_left();
			put_beeper();
			step();
			turn_left();
	}
	turn_off();
	return 0;
}
bool checkey(){
	pick_beeper();
	pick_beeper();
	if(no_beepers_present()){
        put_beeper();
	put_beeper();
	return false;
	}
	else put_beeper();
	put_beeper();
	return true;
}
void turn_right(){
	turn_left();
	turn_left();
	turn_left();
}
void check(){
	if (left_is_clear()){
	put_beeper();
	turn_left();
	step();
	while(no_beepers_present()){
			step();
			if(right_is_clear()){
				turn_right();
			}
			if (front_is_blocked()){
			while(front_is_blocked()){
			turn_left();
			}
			}
	}
	put_beeper();
	}
}

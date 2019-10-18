#include <superkarel.h>
void check();
bool checkey();
int main(){
	turn_on("task_6.kw");
	set_step_delay(100);
	while(checkey()== false){
		step();
		if(beepers_present()){check();
		}
	}
	pick_beeper();
	pick_beeper();
	turn_off();
	return 0;
}
void check(){
       	while(beepers_present()){
	pick_beeper();
	if (no_beepers_present()){
		while(not_facing_north()){
			turn_left();
		}
	}
	else pick_beeper();
	if (no_beepers_present()){
		while(not_facing_west()){
				turn_left();
				}
				}
	else pick_beeper();
	if (no_beepers_present()){
		while(not_facing_south()){
			turn_left();
		}
	}
	else pick_beeper();
	if (no_beepers_present()){
		while(not_facing_east()){
			turn_left();
		}
	}
	else put_beeper();
}
}
bool checkey(){
	if(no_beepers_present()){
		return false;
	}
	else
       	while(beepers_present()){
	pick_beeper();
	if (no_beepers_present()){
		put_beeper();
	}
	else pick_beeper();
	if (no_beepers_present()){
		put_beeper();
		put_beeper();
				}
	else pick_beeper();
	if (no_beepers_present()){
		put_beeper();
		put_beeper();
		put_beeper();
	}
	else pick_beeper();
	if (no_beepers_present()){	
		put_beeper();
		put_beeper();
		put_beeper();
		put_beeper();
	}
	else
		pick_beeper();
	return true;
	}
	
}

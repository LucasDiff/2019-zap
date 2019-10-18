#include <superkarel.h>
bool check();
int main(){
	turn_on("task_6.kw");
	set_step_delay(100);
	while(front_is_clear()){
		step();
		if(beepers_present() && check()){
		break;
		}
	}
	turn_off();
	return 0;
}
bool check(){
       	while(1){
	pick_beeper();
	if (no_beepers_present()){
		while(not_facing_north()){
			turn_left();
		}
		return false;
	}
	pick_beeper();
	if (no_beepers_present()){
		while(not_facing_west()){
				turn_left();
		}
		return false;
	}
	pick_beeper();
	if (no_beepers_present()){
		while(not_facing_south()){
			turn_left();
		}
			return false;
	}
	pick_beeper();
	if (no_beepers_present()){
		while(not_facing_east()){
			turn_left();
		}
		return false;
	}
	pick_beeper();
	return true;
}
}


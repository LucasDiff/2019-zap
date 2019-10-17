#include <superkarel.h>
int main() {
turn_on("task_2.kw");
set_step_delay(150);
while(no_beepers_present()){
	if (front_is_clear()){
		step();
	}
	else turn_left();
}
pick_beeper();
turn_left();
turn_left();
while(front_is_clear() || right_is_clear()){
	if (front_is_clear()){
		step();
	}
        else if(right_is_clear()){
        turn_left();
	turn_left();
	turn_left();
	}
}

turn_off();
return 0;
} 

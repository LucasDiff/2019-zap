#include <superkarel.h>
void turn_right();
void zober();
void daj();
void dajdaj();
bool check();
int main(){
	set_step_delay(50);
	turn_on("task_3.kw");
	zober();
	daj();
	turn_left();
	while(front_is_clear()){
		step();
		turn_left();
		zober();
		dajdaj();
	}
	turn_left();
turn_left();
	step();
step();
step();
turn_right();
	while(no_beepers_present()){
		step();
	}
		turn_left();
while(front_is_clear()){
		step();
}
		turn_left();
		while(front_is_clear()){
step();
}
turn_left();
turn_left();
turn_off();
return 0;
} 
void turn_right(){
	turn_left();
	turn_left();
	turn_left();
} 
void zober(){
	while (front_is_clear()){
		if (beepers_present()){
			pick_beeper();
		}
		step();
	}
	if (beepers_present()){
		pick_beeper();
	}
	turn_left();
	turn_left();
}
void daj(){
	while (front_is_clear() && beepers_in_bag()){
		if (right_is_blocked()){
		put_beeper();
		
			step();
		}
		else step();
	}
	while (front_is_clear()){
		step();
}
}
void dajdaj(){
	while (front_is_clear() && beepers_in_bag()){
		if(check()){
		put_beeper();
		step();
		}
		else step();
	}
		while(front_is_clear()){
			step();
		}
	
	turn_left();
}
bool check(){
	turn_right();
	step();
	if (beepers_present()){
		turn_left();
		turn_left();
		step();
		turn_right();
		return true;
	}	
		turn_left();
		turn_left();
		step();
		turn_right();
		return false;
}
        

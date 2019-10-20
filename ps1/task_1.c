#include <superkarel.h>
void climb();
void climp();
int main(){
turn_on("task_1.kw");
set_step_delay(150);
put_beeper();
pick_beeper();
put_beeper();
while(no_beepers_in_bag()){
if(right_is_blocked() && front_is_blocked()){
	climb();
}
else if(right_is_blocked() && front_is_clear()){
while (front_is_clear()){ step();}}
else while(right_is_blocked() && front_is_clear()){
	step();
}
}
turn_left();
turn_left();
while(no_beepers_present()){
	if (left_is_blocked() && front_is_blocked()){
		climp();
}
else if(left_is_blocked() && front_is_clear()){
while (front_is_clear()){ step();}}
else while(left_is_blocked()&& front_is_clear() ){
	step();
}
}
pick_beeper();
turn_off();
return 0;
} 
        void climb(){
	turn_left();
	while (right_is_blocked() && front_is_clear() ){
		step();
	}	
	turn_left();
	turn_left();
	turn_left();
	step();
	while (right_is_blocked()){
		step();
	}
        turn_left();
	turn_left();
	turn_left();
	step();
	while (right_is_blocked() && front_is_clear() ){
		step();
	}
       turn_left();
       while(front_is_clear()){
           step();
       }
       if (beepers_present()){
	       pick_beeper();
       }
} 
void climp(){
	turn_left();
	turn_left();
	turn_left();
	while(left_is_blocked() && front_is_clear() ){
		step();
	}
	turn_left();
	step();
	while(left_is_blocked() && front_is_clear()){
		step();
}
turn_left();
step();
while (left_is_blocked() && front_is_clear()){
	step();
}
turn_left();
turn_left();
turn_left();
}

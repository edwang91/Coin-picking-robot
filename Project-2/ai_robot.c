#include "essential_files.c"
#include "peak_detector.h"


void ai_robot(void){
	
	if(coin_detect() != 0){ //coin detect 
		stop_robot(); 
		move_robot_back(); 
		delay_ms(50); 
		stop_robot(); 
		move_arm();
		
	}

	while(line_detector() != 0){ //line detect 
		//stop_robot(); 
		rotate_robot_right(); 
		}
	
	
	move_robot_fwd(); 
	
	
}
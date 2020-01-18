#include <XC.h>

#define MAGNET_POWER LATAbits.LATA4

unsigned int speed=80;


void move_robot_fwd(void){
	set_Wheel_Left(speed,0); 
	set_Wheel_Right(speed,0); 
}

void move_robot_back(void){
	set_Wheel_Left(speed,1); 
	set_Wheel_Right(speed,1); 
}

void rotate_robot_right(void){
	set_Wheel_Left(speed,0); 
	set_Wheel_Right(speed,1); 
}



void stop_robot(void){
	set_Wheel_Left(0,0); 
	set_Wheel_Right(0,0); 
}

void move_arm(void) {
	set_Arm_Base(65,10); 
	set_Arm_Magnet(155,10); //Move arm to middle and move magnet down
	MAGNET_POWER = 0;
	delay_ms(1000); 
	
	set_Arm_Base(65,10); //Sweeping motion to pick up coin 
	set_Arm_Magnet(10,25); //Move arm up 
	delay_ms(1000);
	
	//Move and drop coin 
	set_Arm_Base(35,15); 
	set_Arm_Magnet(45,15); 
	delay_ms(1000);
	MAGNET_POWER = 1;
	
	//NEED TO DISENGAGE MAGNET HERE 

	set_Arm_Base(65,10); 	
	set_Arm_Magnet(10,10); //Initial Pos. 
	delay_ms(1000);
	
	
}

	

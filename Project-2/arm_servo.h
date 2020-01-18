#include "arm_servo.c"


//Prototypes
void __ISR(_TIMER_2_VECTOR, IPL4SOFT) ArmPWM(void);
void SetupTimer2 (void);
void delay_ms (int msecs);
void set_Arm_Base(int req_angle,int delay);
void set_Arm_Magnet(int req_angle,int delay);

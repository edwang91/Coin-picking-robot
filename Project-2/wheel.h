#include "wheel.c"


//Prototypes
void __ISR(_TIMER_1_VECTOR, IPL5SOFT) WheelPWM(void);
void SetupTimer1 (void);
void set_Wheel_Left(int pwm, char reverse);
void set_Wheel_Right(int pwm, char reverse);

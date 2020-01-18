#include <XC.h>
#include <sys/attribs.h>

#include "uart.h"
#include "wheel.h"
#include "arm_servo.h"

#include "coin_detector.h"
#include "line_detector.h"

#include "movement.h"


// Configuration Bits (somehow XC32 takes care of this)
#pragma config FNOSC = FRCPLL       // Internal Fast RC oscillator (8 MHz) w/ PLL
#pragma config FPLLIDIV = DIV_2     // Divide FRC before PLL (now 4 MHz)
#pragma config FPLLMUL = MUL_20     // PLL Multiply (now 80 MHz)
#pragma config FPLLODIV = DIV_2     // Divide After PLL (now 40 MHz)
#pragma config FWDTEN = OFF         // Watchdog Timer Disabled
#pragma config FPBDIV = DIV_1       // PBCLK = SYCLK
#pragma config FSOSCEN = OFF        // Secondary Oscillator Enable (Disabled)

#define SYSCLK 40000000L



void main(void){
	
	DDPCON = 0;
	
	//Set-up motor pins
	TRISBbits.TRISB0 = 0;
	TRISBbits.TRISB1 = 0;
	TRISBbits.TRISB2 = 0;
	TRISBbits.TRISB3 = 0;
	
	
	//Set-up arm servo pins (magnet and base, resp.) and electromagnet power
	TRISAbits.TRISA2 = 0; 
	TRISAbits.TRISA3 = 0;
	TRISAbits.TRISA4 = 0;
	
	
	//Set as analog input for peak detector for perimeter.
    ANSELBbits.ANSB12 = 1;   // set RB12 (AN12, pin 23 of DIP28) as analog pin
    TRISBbits.TRISB12 = 1;   // set RB12 as an input
	
	//Set digital input for coin detector.
	ANSELB &= ~(1<<6); // Set RB6 as a digital I/O
    TRISB |= (1<<6);   // configure pin RB6 as input
    CNPUB |= (1<<6);   // Enable pull-up resistor for RB6
	

	//Initial Configurations
	UART2Configure(115200); // Configure UART2 for a baud rate of 115200
	ADCConf();
	SetupTimer1();
	SetupTimer2();
	INTCONbits.MVEC = 1;	//Enable Multi-vector Interrupts
	
	
	//Initial Values
	set_Wheel_Left(0,0);
	set_Wheel_Right(0,0);
	
	set_Arm_Base(62,25);
	set_Arm_Magnet(0,25);
	delay_ms(1000);
	
	
	//Infinite Loop
	while(1){
		ai_robot();
		//set_Wheel_Left(50,0);
		//set_Wheel_Right(50,0);
	
	}




}
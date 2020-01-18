#include "coin_detector.c"

//Prototypes
void wait_1ms(void);
void waitms(int len);
long int GetPeriod (int n);
void freq_initialize(void);
int coin_detect(void); //Return 1 if coin is detected, else 0 
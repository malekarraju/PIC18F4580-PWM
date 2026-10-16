#include <p18f4580.h>

void MSdelay(unsigned int);

void main(void)
{
    unsigned int duty_cycle;

    TRISCbits.TRISC2 = 0;   // Set CCP1 pin as output

    PR2 = 1023;              // PWM period value
    CCPR1L = 1;               // Initial duty-cycle value

    T2CON = 0;                // No prescaler, Timer2 OFF
    CCP1CON = 0x0C;            // CCP1 PWM mode
    TMR2 = 0;                  // Reset Timer2

    T2CONbits.TMR2ON = 1;     // Turn ON Timer2

    while(1)
    {
        // Increase duty cycle
        for(duty_cycle = 1; duty_cycle < 1023; duty_cycle++)
        {
            CCPR1L = duty_cycle;
            MSdelay(50);
        }

        MSdelay(1500);

        // Decrease duty cycle
        for(duty_cycle = 1023; duty_cycle > 1; duty_cycle--)
        {
            CCPR1L = duty_cycle;
            MSdelay(50);
        }

        MSdelay(1500);
    }
}

void MSdelay(unsigned int val)
{
    unsigned int i, j;

    for(i = 0; i <= val; i++)
        for(j = 0; j < 165; j++);
}

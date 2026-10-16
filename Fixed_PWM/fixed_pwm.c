#include <p18f4580.h>

#define Led PORTCbits.RC2

void main(void)
{
    TRISCbits.RC2 = 0;      // RC2/CCP1 as output

    CCP1CON = 0x0C;         // CCP1 in PWM mode

    PR2 = 11;               // PWM period value
    CCPR1L = 1;             // PWM duty-cycle value

    // Timer2 configuration
    T2CONbits.T2CKPS1 = 1;  // Prescaler selection
    T2CONbits.T2CKPS0 = 0;  // Prescaler = 1:16

    T2CONbits.TMR2ON = 1;   // Start Timer2

    TMR2 = 0;               // Reset Timer2

    while(1)
    {
    }
}

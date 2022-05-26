/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18456
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "mcc_generated_files/mcc.h"
#include "main.h"

int RandomNumber;
int Ticks = 0;
unsigned long Seeed = 1;
int Anodo = 1;
int Catodo = 0;

void lightall(void) {
    LA_SEG_A = Catodo;
    LA_SEG_B = Catodo;
    LA_SEG_C = Catodo;
    LA_SEG_D = Catodo;
    LA_SEG_E = Catodo;
    LA_SEG_F = Catodo;
    LA_SEG_G = Catodo;
    LA_SEG_DP = Catodo;
}

void clearall(void) {
    LA_SEG_A = Anodo;
    LA_SEG_B = Anodo;
    LA_SEG_C = Anodo;
    LA_SEG_D = Anodo;
    LA_SEG_E = Anodo;
    LA_SEG_F = Anodo;
    LA_SEG_G = Anodo;
    LA_SEG_DP = Anodo;
}

void anim(void) {
    clearall();
    __delay_ms(125);
    LA_SEG_F = Anodo;
    LA_SEG_A = Catodo;

    __delay_ms(125);
    LA_SEG_A = Anodo;
    LA_SEG_B = Catodo;

    __delay_ms(125);
    LA_SEG_B = Anodo;
    LA_SEG_C = Catodo;

    __delay_ms(125);
    LA_SEG_C = Anodo;
    LA_SEG_D = Catodo;

    __delay_ms(125);
    LA_SEG_D = Anodo;
    LA_SEG_E = Catodo;

    __delay_ms(125);
    LA_SEG_E = Anodo;
    LA_SEG_F = Catodo;
}

void one(void) {
    LA_SEG_A = Anodo;
    LA_SEG_B = Catodo;
    LA_SEG_C = Catodo;
    LA_SEG_D = Anodo;
    LA_SEG_E = Anodo;
    LA_SEG_F = Anodo;
    LA_SEG_G = Anodo;
}

void two(void) {
    LA_SEG_A = Catodo;
    LA_SEG_B = Catodo;
    LA_SEG_C = Anodo;
    LA_SEG_D = Catodo;
    LA_SEG_E = Catodo;
    LA_SEG_F = Anodo;
    LA_SEG_G = Catodo;
}

void three(void) {
    LA_SEG_A = Catodo;
    LA_SEG_B = Catodo;
    LA_SEG_C = Catodo;
    LA_SEG_D = Catodo;
    LA_SEG_E = Anodo;
    LA_SEG_F = Anodo;
    LA_SEG_G = Catodo;
}

void four(void) {
    LA_SEG_A = Anodo;
    LA_SEG_B = Catodo;
    LA_SEG_C = Catodo;
    LA_SEG_D = Anodo;
    LA_SEG_E = Anodo;
    LA_SEG_F = Catodo;
    LA_SEG_G = Catodo;
}

void five(void) {
    LA_SEG_A = Catodo;
    LA_SEG_B = Anodo;
    LA_SEG_C = Catodo;
    LA_SEG_D = Catodo;
    LA_SEG_E = Anodo;
    LA_SEG_F = Catodo;
    LA_SEG_G = Catodo;
}

void six(void) {
    LA_SEG_A = Catodo;
    LA_SEG_B = Anodo;
    LA_SEG_C = Catodo;
    LA_SEG_D = Catodo;
    LA_SEG_E = Catodo;
    LA_SEG_F = Catodo;
    LA_SEG_G = Catodo;
}

void rundice(void) {
    RandomNumber = (((unsigned long) rand() + Seeed) % 6) + 1;

    TMR6_StartTimer();

    switch (RandomNumber) {
        case 1: one();
            break;
        case 2: two();
            break;
        case 3: three();
            break;
        case 4: four();
            break;
        case 5: five();
            break;
        case 6: six();
            break;
        default: clearall();
            break;
    }
}

void HandleTicks(void) {
    // add your TMR4 interrupt custom code
    // or set custom function using TMR4_SetInterruptHandler()
    if (Ticks >= 2) {
        TMR4_StopTimer();
        Ticks = 0;
        rundice();
    } else {
        Ticks++;
        anim();
    }
}

void HandleIDLE(void) {
    clearall();
    TMR6_StopTimer();
    TMR2_StopTimer();
    SLEEP(); // wait for interrupt
    NOP(); // ensure instruction pre-fetched while sleeping is safe to execute on awakening
}

void HandleSwitch(void) {
    TMR6_StopTimer();
    TMR2_StartTimer();
    Ticks = 0;
    TMR4_StartTimer();
    anim();
    //Seeed++;
    // Add some randomness
    Seeed = Seeed + TMR2_ReadTimer();
}

/*
                         Main application
 */
void main(void) {
    //    TR_SEG_A = 0; // set C3 as output
    //    TR_SEG_B = 0;
    //    TR_SEG_C = 0;
    //    TR_SEG_D = 0;
    //    TR_SEG_E = 0;
    //    TR_SEG_F = 0;
    //    TR_SEG_G = 0;

    //int RandomNumber;

    // initialize the device
    SYSTEM_Initialize();
    //clearall();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    //lightall();
    TMR2_StartTimer();
    TMR4_StopTimer();
    TMR6_StopTimer();
    // Set Default Interrupt Handler
    TMR4_SetInterruptHandler(HandleTicks);
    TMR6_SetInterruptHandler(HandleIDLE);
    IOCBF4_SetInterruptHandler(HandleSwitch);
    //TMR2_SetInterruptHandler(HandleTicks);

    while (1) {
        // Add your application code
    }
}
/**
 End of File
 */
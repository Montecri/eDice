/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
//#ifndef XC_HEADER_TEMPLATE_H
// #define	XC_HEADER_TEMPLATE_H

#ifndef MAIN_H
#define	MAIN_H

#include <xc.h> // include processor files - each processor file is guarded.  

    //IO_RA7_SetHigh(); // A
    //IO_RA6_SetHigh(); // B
    //IO_RB2_SetHigh(); // C
    //IO_RB1_SetHigh(); // D
    //IO_RB0_SetHigh(); // E
    //IO_RA0_SetHigh(); // F
    //IO_RA1_SetHigh(); // G
    //IO_RB3_SetHigh(); // DP

    //IO_RB3_SetLow(); // A
    //IO_RB2_SetLow(); // B
    //IO_RB1_SetLow(); // C
    //IO_RB0_SetLow(); // D
    //IO_RA6_SetLow(); // E
    //IO_RA7_SetLow(); // F
    //IO_RA0_SetLow(); // G
    //IO_RA1_SetLow(); // DP

#define TR_SEG_A TRISBbits.TRISB3
#define LA_SEG_A LATBbits.LATB3

#define TR_SEG_B TRISBbits.TRISB2
#define LA_SEG_B LATBbits.LATB2

#define TR_SEG_C TRISBbits.TRISB1
#define LA_SEG_C LATBbits.LATB1

#define TR_SEG_D TRISBbits.TRISB0
#define LA_SEG_D LATBbits.LATB0

#define TR_SEG_E TRISAbits.TRISA6
#define LA_SEG_E LATAbits.LATA6

#define TR_SEG_F TRISAbits.TRISA7
#define LA_SEG_F LATAbits.LATA7

#define TR_SEG_G TRISAbits.TRISA0
#define LA_SEG_G LATAbits.LATA0

#define TR_SEG_DP TRISAbits.TRISA1
#define LA_SEG_DP LATAbits.LATA1

extern int Ticks;

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation
void clearall(void);

void anim(void);

void one(void);

void two(void);

void three(void);

void four(void);

void five(void);

void six(void);

void rundice(void);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */


#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pic18f4550.h>
#include "configbits.h"
#include "lib4550.h"
#define _XTAL_FREQ 4000000

int contadorA = 1;
int contadorB = 1;

void main() {
    system_inicializacion();
    serialinit();

//    BUZZER_CONF = OUTPUT;
//    BUZZER_WRITE = 0;

    if (buttonA);
    if (buttonB);


    while (1) {

    }

}

void ONbuttonA_pressed() {

    if (buttonA && buttonAflag) {
        buttonApressedcounter++;
        buttonApressedcounter2++;
    }


    if (buttonA && !buttonAflag) { //as soon as it's pressed
        buttonAflag = 1;
        buttonApressedcounter = 0;
        buttonApressedcounter2 = 0;
        //your code here
        int velocidad1 = 100;
        int velocidad2 = 150;
        int velocidad3 = 254;
        buzzer(2000, 100);

        switch (contadorA) {
            case 1: analogWrite(_PC2, velocidad1);
                contadorA++;
                LED6 = 1;
                break;
            case 2: analogWrite(_PC2, velocidad2);
                LED6 = 0;
                contadorA++;
                LED5 = 1;
                break;
            case 3: analogWrite(_PC2, velocidad3);
                LED5 = 0;
                contadorA++;
                LED4 = 1;
                break;
            case 4: analogWrite(_PC2, 1);
                LED4 = 0;
                contadorA = 1;
                break;
        }


    }

    if (!buttonA && buttonAflag && buttonApressedcounter2 < 399) { //relase button before 2 sec
        buttonAflag = 0;

        //your code here


    }

    if (buttonA && buttonApressedcounter == 399) { //keep pressing during 2 sec
        buttonApressedcounter = 0;
        buttonApressedcounter2 = 400;
        //your code here

    }
    if (!buttonA) buttonAflag = 0;

}

// Agregar botón B

void ONbuttonB_pressed() {

    if (buttonB && buttonBflag) {
        buttonBpressedcounter++;
        buttonBpressedcounter2++;
    }


    if (buttonB && !buttonBflag) { //as soon as it's pressed
        buttonBflag = 1;
        buttonBpressedcounter = 0;
        buttonBpressedcounter2 = 0;

        switch (contadorB) {
            case 1:
                contadorB++;
                LED3 = 1;
                buzzer(1800, 100);
                __delay_ms(5000);
                LED6 = 0;
                LED5 = 0;
                LED4 = 0;
                LED3 = 0;
                analogWrite(_PC2, 1);
                contadorA = 1;
                break;
            case 2:
                contadorB++;
                LED2 = 1;
                buzzer(1800, 100);
                __delay_ms(5000);
                LED2 = 0;
                __delay_ms(5000);
                LED6 = 0;
                LED5 = 0;
                LED4 = 0;
                LED3 = 0;
                analogWrite(_PC2, 1);
                contadorA = 1;
                break;
        }


    }

    if (!buttonB && buttonBflag && buttonBpressedcounter2 < 399) { //relase button before 2 sec
        buttonBflag = 0;

        //your code here


    }

    if (buttonB && buttonBpressedcounter == 399) { //keep pressing during 2 sec
        buttonBpressedcounter = 0;
        buttonBpressedcounter2 = 400;
        //your code here


    }
    if (!buttonB) buttonBflag = 0;

}

void every5ms() {

}
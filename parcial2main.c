#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pic18f4550.h>
#include "configbits.h"
#include "lib4550.h"
#define _XTAL_FREQ 4000000

int contadorA = 0;
int contadorB = 0;
int ms = 0;
int i = 0;
int velocidad1 = 100;
int velocidad2 = 150;
int velocidad3 = 200;

void a() {
    switch (contadorA) {
        case 1: analogWrite(_PC2, velocidad1);
            LED6 = 1;
            break;

        case 2: analogWrite(_PC2, velocidad2);
            LED6 = 0;
            LED5 = 1;
            break;

        case 3: analogWrite(_PC2, velocidad3);
            LED5 = 0;
            LED4 = 1;
            break;

        case 4: analogWrite(_PC2, 0);
            LED4 = 0;
            contadorA = 0;
            LED5 = 0;
            LED6 = 0;
            break;
    }
}

void b() {
    switch (contadorB) {
        case 1:
            //contadorB++;
            LED3 = 1; //se enciende LED3 compuerta B4
            buzzer(1800, 100); //suena bip
            ms = 0; //empieza en 0 los segundos
            for (int i = 0; i < 5000; i++) { //ciclo for para los 
                if (contadorB != 1) {
                    break;
                }
                if (contadorB == 1) {
                    __delay_ms(1);
                    ms++;
                }
                if (ms == 4998) {
                    LED3 = 0;
                    LED4 = 0;
                    LED5 = 0;
                    LED6 = 0;
                    analogWrite(_PC2, 1);
                    buzzer(2000, 100);
                    buzzer(1800, 100);
                    buzzer(1600, 100);
                    contadorA = 0;
                    contadorB = 0;

                }
            }
            //__delay_ms(5000);
            //rutina final

            break;
        case 2:
            LED3 = 1;
            LED2 = 1;
            buzzer(1800, 100);
            ms = 0;
            for (int i = 0; i < 10000; i++) {
                if (contadorB != 2) {
                    break;
                }
                if (contadorB == 2) {
                    __delay_ms(1);
                    ms++;
                }
                if (contadorB > 2) {
                    break;
                }
                if (ms == 4998) {
                    LED2 = 0;
                }
                if (ms == 9998) {
                    LED3 = 0;
                    LED4 = 0;
                    LED5 = 0;
                    LED6 = 0;
                    analogWrite(_PC2, 1);
                    buzzer(2000, 100);
                    buzzer(1800, 100);
                    buzzer(1600, 100);
                    contadorA = 0;
                    contadorB = 0;
                }
            }
            break;

        case 3:
            LED3 = 1;
            LED2 = 1;
            LED1 = 1;
            buzzer(1800, 100);
            ms = 0;
            for (int i = 0; i < 15000; i++) {
                if (contadorB != 3) {
                    break;
                }
                if (contadorB == 3) {
                    __delay_ms(1);
                    ms++;
                }
                if (contadorB > 3) {
                    break;
                }
                if (ms == 4998) {
                    LED1 = 0;
                }
                if (ms == 9998) {
                    LED2 = 0;
                }
                if (ms == 14998) {
                    LED3 = 0;
                    LED4 = 0;
                    LED5 = 0;
                    LED6 = 0;
                    analogWrite(_PC2, 1);
                    buzzer(2000, 100);
                    buzzer(1800, 100);
                    buzzer(1600, 100);
                    contadorA = 0;
                    contadorB = 0;
                }
            }
            break;
        case 4:
            LED3 = 1;
            LED2 = 1;
            LED1 = 1;
            LED0 = 1;
            buzzer(1800, 100);
            ms = 0;
            for (int i = 0; i < 20000; i++) {
                if (contadorB != 4) {
                    break;
                }
                if (contadorB == 4) {
                    __delay_ms(1);
                    ms++;
                }
                if (contadorB > 4) {
                    break;
                }
                if (ms == 4998) {
                    LED0 = 0;
                }
                if (ms == 9998) {
                    LED1 = 0;
                }
                if (ms == 14998) {
                    LED2 = 0;
                }
                if (ms == 19998) {
                    LED3 = 0;
                    LED4 = 0;
                    LED5 = 0;
                    LED6 = 0;
                    analogWrite(_PC2, 1);
                    buzzer(2000, 100);
                    buzzer(1800, 100);
                    buzzer(1600, 100);
                    contadorA = 0;
                    contadorB = 0;
                }
            }
            break;

        case 5:
            buzzer(1800, 100);
            if (contadorB != 5) {
                break;
            }
            if (contadorB == 5) {
                LED3 = 0;
                LED2 = 0;
                LED1 = 0;
                LED0 = 0;
                contadorB = 0;
            }
    }
}

void main() {
    system_inicializacion();
    serialinit();

    BUZZER_CONF = OUTPUT;
    BUZZER_WRITE = 0;


    while (1) {
        a();
        b();
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
        contadorA++;
        buzzer(2000, 100);

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
        contadorB++;

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
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pic18f4550.h>
#include "configbits.h"
#include "lib4550.h"
#define _XTAL_FREQ 4000000


char a = 48;
char b = 48;
char c = 48;
char d = 48;

int contador = 1;

int variable = 0;

void printNumber(int data) {

    a = 48;
    b = 48;
    c = 48;
    d = 48;

    for (data = data; data > 999; data = data - 1000) d++;
    for (data = data; data > 99; data = data - 100) c++;
    for (data = data; data > 9; data = data - 10) b++;
    for (data = data; data > 0; data = data - 1) a++;
}

void programa1() {
    serialout_st("Temperatura en grados C:");
    __delay_ms(2000);
    int temperatura = 0;
    int contador;
    while (1) {
        temperatura = get_temp();
        printNumber(temperatura);
        serialout(12);
        serialout(c);
        serialout(b);
        __delay_ms(500);
        if (temperatura > 312) {
            serialout(12);
            serialout_st("Temperatura excedida: ALERTA");
            for (contador = 0; contador < 5; contador++) {
                LED_BUILTIN = 1;
                __delay_us(200);
                LED_BUILTIN = 0;
                __delay_us(200);
                LED_BUILTIN = 1;
                __delay_us(200);
                LED_BUILTIN = 0;
                __delay_us(200);
                LED_BUILTIN = 1;
                __delay_us(200);

                if (contador == 5) {
                    contador == 100;
                    LED_BUILTIN = 0;
                }
            }
        } else {
            LED_BUILTIN = 0;
        }
    }
    __delay_ms(500);

}

void programa2() {
    serialout_st("Nivel de luz:");
    __delay_ms(2000);
    int luz = 0;
    while (1) {
        LED_BUILTIN = 0;
        luz = get_lightlevel();
        printNumber(luz);
        serialout(12);
        serialout(d);
        serialout(c);
        serialout(b);
        serialout(a);
        __delay_ms(500);
        if (luz > 504) {
            LED_BUILTIN = 1;
        } else {
            LED_BUILTIN = 0;
        }
        __delay_ms(500);
    }
}

void programa3() {
    serialout_st("Analog read en voltaje:");
    __delay_ms(2000);
    int nivel = 0;
    while (1) {
        nivel = analogRead(_AN2);
        nivel = nivel / 2.44;
        printNumber(nivel);
        serialout(12);
        serialout(c);
        serialout_st(".");
        serialout(b);
        serialout(a);
        serialout_st("V");
        __delay_ms(500);
    }
}

void main() {
    system_inicializacion();
    serialinit();

    //    if (buttonA && buttonB) programa3();
    //    if (buttonA) programa1();
    //    if (buttonB) programa2();


    //    CCPR1L = 0b00111110;
    //    CCP1CONbits.DC1B1 = 1;
    //    CCP1CONbits.DC1B0 = 0;
    //    
    //    int numero = 125;
    //    CCPR2L = numero >> 2;
    //    CCP2CONbits.DC2B = numero & 0b11;

    if (buttonA);
    if (buttonB);


    while (1) {

        //        for (int i = 0; i <= 170; i++) {
        //            switch (i) {
        //                case 85: analogWrite(_PC1, 85);
        //                    __delay_ms(500);
        //                    break;
        //                case 128: analogWrite(_PC1, 128);
        //                    __delay_ms(500);
        //                    break;
        //                case 170: analogWrite(_PC1, 170);
        //                    __delay_ms(500);
        //                    break;
        //            }
        //        }
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


        //        if (variable <= 254) {
        //            variable += 15;
        //            analogWrite(_PC1, variable);
        //        }
            switch (contador) {
                case 1: analogWrite(_PC2, velocidad1);
                    contador++;
                    PORTB_WRITE = 0b00000001;
                    break;
                case 2: analogWrite(_PC2, velocidad2);
                    contador++;
                    PORTB_WRITE = 0b00000010;
                    break;
                case 3: analogWrite(_PC2, velocidad3);
                    contador++;
                    PORTB_WRITE = 0b00000100;
                    break;
                case 4: analogWrite(_PC2, 1);
                    contador = 1;
                    PORTB_WRITE = 0b00000000;
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
        //your code here
        //        if (variable >= 15) {
        //            variable -= 15;
        //            analogWrite(_PC1, variable);
        //        }
        int velocidad2 = 190;
        analogWrite(_PC2, velocidad2);


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
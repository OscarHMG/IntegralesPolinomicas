/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: OscarHMG
 *
 * Created on September 5, 2016, 9:49 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define func(x) (a*(pow(x,2))+b*(pow(x,1))+c)

int menuOp();
double trapezoidalIntegral(double a,double b,double c,double left,double right,int N);
void menu();
void ingresoFuncPolinomial();

int main()
{
    menu();
    return 0;
}

double trapezoidalIntegral(double a,double b,double c,double left,double right,int N){
    double integral, h, sum;
    h = (right-left)/N; //Saco subintervalos entre [a,b]
    sum = (func(left)+func(right))/2;//Evaluo la funcion dada en los puntos a y b
    int i=1;
    while(i < N)
    {
      sum=sum+(func(left+(i)*h));
      i++;
    }
    integral=h*sum;
    return integral;
}

int menuOp(){
    int opcion;
    printf("\t\tIntegracion de Funciones Polinomicas de 2do Grado\n\n");
    printf("MENU\n\n");
    printf("1. Calcular la integral de una funcion polinomica.\n");
    printf("0. Salir del programa\n"); 
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void menu(){
    int opcion;
    opcion = menuOp();
    
    while(opcion!=0 && opcion!=1){
        printf("\nIngrese una opcion Valida");
        system("cls");
        opcion = menuOp();
    }
    switch(opcion){
        case 1:
            ingresoFuncPolinomial();
            
            break;
        case 0:
            printf("\n\tUd. ha cerrado el programa.\n");
            printf("\t\t\nAutor: Ricardo Santander.");
            exit(0);
            break;
    }
    
}

void ingresoFuncPolinomial(){
    double a,b,c,limIzq, limDer;
    int N;
    printf("\n\nEc. Polinomial de la forma: ax^2 + bx + c\n\n");
    printf("Coeficiente Cuadratico: ");
    scanf("%lf",&a);
    printf("Coeficiente Lineal: ");
    scanf("%lf",&b);
    printf("Coeficiente Constante: ");
    scanf("%lf",&c);
    printf("Limite Izquierdo: ");
    scanf("%lf",&limIzq);   
    printf("Limite Izquierdo: ");
    scanf("%lf",&limDer);
    printf("SubIntervalos: ");
    scanf("%d",&N);        
    printf("Integral de %.2lf x^2 + %.2lf x + %.2lf",a,b,c);
    printf("\nRespuesta: %lf",trapezoidalIntegral(a,b,c,limIzq,limDer,N));
    system("PAUSE");
    system("cls");
    menu();
}


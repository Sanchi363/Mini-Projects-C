//A basic calculator which performs operation like:
//Addition, Subtraction, Multiplication, Division on two numbers:
#include <stdio.h>
void main(){
float a,b;
char ch;
printf("Select the operator:('+','-','*','/'):");
scanf("%c",&ch);
    printf("\nEnter first number:");
    scanf("%f",&a);
    printf("\nEnter second  number:");
    scanf("%f",&b);
   
    switch(ch){
        case '+' : printf("\nResult: %f",a+b); break;
        case '-' : printf("\nResult: %f",a-b); break;
        case '*' : printf("\nResult: %f",a*b); break;
        case '/' : printf("\nResult: %f",a/b); break;
        default  : printf("\nInvalid case"); 
    }
}
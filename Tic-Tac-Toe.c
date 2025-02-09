#include <stdio.h>
#include <stdlib.h>
//Tic-Tac-Toe games which consists of two players:
void main(){
    int a,b=0,k=1;
    char arr[3][3],n;
    printf("Player 1 makes a choice ('X' or 'O') and the other one will be automatically allocated to the player 2");
    printf("\nPlayer 1:");
    char c1,c2;
    scanf("%c",&c1);
    if(c1=='X'){
        c2='O';
    }else{
        c2='X';
    }
    printf("\nPlayer 1 chose %c",c1);
    printf("\nPlayer 2 chose %c",c2);
    arr[0][0]='1';
    arr[0][1]='2';
    arr[0][2]='3';
    arr[1][0]='4';
    arr[1][1]='5';
    arr[1][2]='6';
    arr[2][0]='7';
    arr[2][1]='8';
    arr[2][2]='9';
    k=1;
    n=c1;        
    printf("\nPlayer %d",k);
        printf("\nSelect the position  of %c from 1 to 9 with the reference given below.",n);
        printf("\n\n");
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                printf("%c  ",arr[i][j]);
            }
            printf("\n\n");
        }
        printf("\nChoose position:");
        scanf("%d",&a);
        if(a==1){
            arr[0][0]=n;
        }
        else if(a==2){
            arr[0][1]=n;
        }
        else if(a==3){
            arr[0][2]=n;
        }
        else if(a==4){
            arr[1][0]=n;
        }
        else if(a==5){
            arr[1][1]=n;
        }
        else if(a==6){
            arr[1][2]=n;
        }
        else if(a==7){
            arr[2][0]=n;
        }
        else if(a==8){
            arr[2][1]=n;
        }
        else {
             arr[2][2]=n;
        }
        k=2;

    for(int m=1; m<9; m++){
        printf("\n\n");
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                printf("%c  ",arr[i][j]);
            }
            printf("\n\n");
        }
        b=0;
        if(k==1){
            n=c1;
        }else{
            n=c2;
        }
        printf("Player %d",k);
        printf("\nSelect the position  of %c from 1 to 9 with the reference given above.",n);
        printf("\nPlease note that you can't use already marked fields");
        printf("\nChoose position:");
        scanf("%d",&a);
        if(a==1){
            arr[0][0]=n;
        }
        else if(a==2){
            arr[0][1]=n;
        }
        else if(a==3){
            arr[0][2]=n;
        }
        else if(a==4){
            arr[1][0]=n;
        }
        else if(a==5){
            arr[1][1]=n;
        }
        else if(a==6){
            arr[1][2]=n;
        }
        else if(a==7){
            arr[2][0]=n;
        }
        else if(a==8){
            arr[2][1]=n;
        }
        else {
             arr[2][2]=n;
        }
        int sum=0;
        int p=0;
        int j=0;
        for(int i=0; i<3;i++){
            sum=0;
            if((arr[p][j]==arr[p][j+1])&&(arr[p][j]==arr[p][j+2])){
                sum=1;
                break;
            }
            p=p+1;
            j=0;
        }
        if(sum==1){
            printf("\n\n");
            for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                printf("%c  ",arr[i][j]);
            }
            printf("\n\n");
            }
            printf("\nGame ends");
            printf("\nPlayer %d wins!!!",k);
            break;
        }
        p=0;
        for(int i=0; i<3; i++){
            sum=0;
            j=0;
            if((arr[j][p]==arr[j+1][p])&&(arr[j][p]==arr[j+2][p])){
                sum=1;
                break;
            }
            p=p+1;
            j=0;
        }
        if(sum==1){
            printf("\n\n");
            for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                printf("%c  ",arr[i][j]);
            }
            printf("\n\n");
        }   printf("\nGame ends");
            printf("\nPlayer %d wins!!!",k);
            break;
        }
        sum=0;
        if((arr[0][0]==arr[1][1])&&(arr[0][0]==arr[2][2])){
            sum=1;
        }
        if(sum==1){
            printf("\n\n");
            for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                printf("%c  ",arr[i][j]);
            }
            printf("\n\n");
        }   printf("\nGame ends");
            printf("\nPlayer %d wins!!!",k);
            break;
           }
        sum=0;
        if((arr[0][2]==arr[1][1])&&(arr[1][1]==arr[2][0])){
            sum=1;
        }
        if(sum==1){
            printf("\n\n");
            for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                printf("%c  ",arr[i][j]);
            }
            printf("\n\n");
        }
            printf("\nGame ends");
            printf("\nPlayer %d wins!!!",k);
            break;
        }
        if(k==2){
            k=1;
        }else{
            k=2;
        }
        b=1;
    }
    if(b==1){
        printf("\n\n");
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                printf("%c  ",arr[i][j]);
            }
            printf("\n\n");
        }
        printf("\n Game draw");
    }
}    
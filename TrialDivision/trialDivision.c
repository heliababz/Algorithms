/*
 ============================================================================
 Name        : trialDivision.c
 Author      : Helia Aghababazadeh
 Version     :
 Copyright   : Your copyright notice
 Description : Trial Division
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int trialDivision(int n){    
    int i = 1;
    
    double k = ceil(sqrt(n));
    if(!(n%5)&&(n!=5)) 
        return 5;
    else if (!(n%3)&&(n!=3))
        return 3;
    else if (!(n%2)&&(n!=2))
        return 2;

    while(i<= k/6){
    
        if(!(n%(6*i+1)))
            return 6*i+1; 
        else if (!(n%(6*i+5)))
            return 6*i+5;
        i+=1;
    }
    return 0;
}

int main(int argc, char**argv){
    int n, td = 0;
    printf("Enter integer N>1: \n");
    scanf("%d", &n);
    
    if(n<2)
        printf("Entered number must be larger than 1\n");
    else{ 
	td = trialDivision(n);
        if(td)
            printf("Composite! One factor is: %d\n", td);
        else
            printf("Prime\n");    
    }
}

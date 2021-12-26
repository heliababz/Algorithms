//**********************************************************//
//Programmer: Helia Aghababazadeh
// Program: crt.c
//Description: Chinese Remainder Theorem
//**********************************************************//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int gcdExtended(int a, int b, int *x, int *y); //code from GeeksForGeeks
int modInverse(int a, int m); //code from GeeksForGeeks

int main(int argc, char **argv) {

    //create file pointers
	FILE *infp = fopen ("input.txt", "r");
    FILE *outfp = fopen("output.txt", "w");
    //variable declaration
    int n, ans, mult, lenC;
    int *a, *m, *v, *c;

    //read first input (n = number of mod constraints)
    fscanf (infp, "%d", &n);
    fprintf(stderr, "n=%d\n", n);
    lenC = (n*(n-1))/2;

    //allocate memory
    a = (int*) malloc(n*sizeof(int));
    m = (int*) malloc(n*sizeof(int));
    v = (int*) malloc(n*sizeof(int));
    c = (int*) malloc(lenC*sizeof(int));

    int i, j, k;
    //Read Inputs
    for (i=0; i<n; i++){
        fscanf(infp, "%d", &a[i]);
        fscanf(infp, "%d", &m[i]);
    }

    //close input file pointer
    fclose(infp);

    //Calculate the inverses (cij)
    k=0;
    for (j=1; j<n; j++){
        for (i=0; i<j; i++){
            c[k]=modInverse(m[i], m[j]);
            k++;
        }
    }

    //Calculate the vs
    k=0;
    for(j=0; j<n; j++){
        v[j] = a[j] % m[j];
        for (i=0; i<j; i++){
            v[j] = ((v[j]-v[i])*c[k]) % m[j];
            if (v[j]<0){
                v[j] = v[j] + m[j];
            }
            k++;
        }
    }
    
    //write cij and vj to output file
    for (i=0; i< lenC; i++){
        fprintf(outfp, "c[%d] = %d, ", i, c[i]);
    }
    fprintf(outfp, "\n\n");
    for (i =0; i<n; i++){
        fprintf(outfp, "v[%d] = %d, ", i, v[i]);
    }
    fprintf(outfp, "\n\n");

    //calculate answer a = v1 + v2m1 + v3m2m1 + ...
    ans = v[0];
    mult = 1;
    for (j=1; j<n; j++){
        mult *= m[j-1];
        ans += mult*v[j];
    }

    //write answer to output file
    fprintf(outfp,"%d", ans);

    //free allocated memory
    free(a);
    free(c);
    free(v);
    free(m);
    //close output file pointer
    fclose(outfp);
}

int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

int modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        printf("Inverse doesn't exist\n"); 
    else
    { 
        // m is added to handle negative x 
        int res = (x%m + m) % m; 
        return (res);
        //cout << "Modular multiplicative inverse is " << res; 
    }
    return -1; 
}


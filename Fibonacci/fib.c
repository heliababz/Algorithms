#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int cmpfn(const void *a, const void *b){
    return (*(int*) a - *(int*) b);
}


int main (int argc, char **argv){

    FILE *infp, *outfp;
    char *infilename;
    int k, n, *A;
    
    if (argc == 2){
        infilename = argv[1];
        infp = fopen (infilename, "r");
    }else {
        infp = fopen("rosalind_2sum.txt", "r");
    }
    assert(infp != NULL);

    fscanf(infp, "%d", &k);
    fscanf(infp, "%d", &n);

    fprintf(stderr, "k= %d, n = %d\n", k, n);

    A = (int *) malloc (2 * n * sizeof(int));
    assert(A!=NULL);
    int i;

    for (i = 0; i < n ; i++){
        A[2*i] = 0;
        A[2*i+1] = i;
    }

    outfp = fopen("output_2sum.txt", "w");
    int ki;
    for (ki = 0; ki< k; ki++){
        //Read a row
        for (i = 0; i<n; i++){
            fscanf (infp, "%d", &A[2*i]);
            A[2*i+1] = i;
        }
        
        //fprintf(stderr, "\n");

        //Sort
        qsort(A, n, 2*sizeof(int), cmpfn);
        //Find the indices
        int ind1 = -1;
        int ind2 = -1;
        int pos1 =0;
        int pos2 = n-1;

        while ((pos1 < pos2) && (A[2*pos1] <= 0) && (A[2*pos2] >=0)){
            //fprintf (stderr, "Begin: ki: %d, pos1: %d, pos2: %d, ind1: %d ind2, %d, A[2*pos1]: %d, A[2*pos2]: %d\n", ki, pos1, pos2, ind1, ind2, A[2*pos1], A[2*pos2]);
            if ((A[2*pos1] + A[2*pos2]) ==0){
                ind1 = A[2*pos1+1];
                ind2 = A[2*pos2+1];
                break;
            }else{
                if ((A[2*pos1] + A[2*pos2])<0){
                    pos1++;
                }else{
                    pos2--;
                }
            }
            //fprintf (stderr, "End  : ki: %d, pos1: %d, pos2: %d, ind1: %d ind2, %d, A[2*pos1*2]: %d, A[2*pos2]: %d\n", ki, pos1, pos2, ind1, ind2, A[2*pos1], A[2*pos2]);
        }
        //fprintf(stderr, "HERE\n");

        if (ind1 == -1){
            //fprintf(stderr, "Before\n");
            fprintf(outfp, "-1\n");
            //fprintf(stderr, "After\n");
        }else{
            if (ind1 < ind2){
                fprintf(outfp, "%d %d\n", ind1+1, ind2+1);
            }else{
                fprintf(outfp, "%d %d\n", ind2+1, ind1+1);
            }
        }
    }
    fclose(infp);
    fclose(outfp);

    free(A);
    return 0;
}

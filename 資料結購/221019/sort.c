#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 4,294,967,295

void Selection_sort(unsigned *num, unsigned N);
void Quick_sort(unsigned *num, unsigned l, unsigned r);
void swap(unsigned *a, unsigned *b);
unsigned rang(void);

int main(){
    unsigned *num, N, i;
    time_t tm;
    //printf("%u", rang());
    srand((unsigned)time(0)+getpid());    //RAND_MAX
    scanf("%u", &N);
    num = (unsigned*)malloc(sizeof(unsigned) * N);

    for(i = 0; i < N; i++){
        num[i] = rang()/(unsigned)RAND_MAX*rand()/RAND_MAX*rand() + 1;
        printf("%10u ", num[i]);
        if(i % 10 == 0 && i != 0) printf("\n");
    }
    printf("\n\n");

    tm = clock();
    Selection_sort(num, N);
    for(i = 0; i < N; i++){
        printf("%10u ", num[i]);
        if(i % 10 == 0 && i != 0) printf("\n");
    }
    printf("execution time: %u", clock()-tm);
    tm = clock();


    free(num);
    return 0;
}

void Selection_sort(unsigned *num, unsigned N){
    unsigned i, j, min;
    for(i = 0; i < N-1; i++){
        min = i;
        for(j = i+1; j < N; j++){
            if(num[j] < num[min]) min = j;
        }
        swap(&num[min], &num[i]);
    }
}

void Quick_sort(unsigned *num, unsigned l, unsigned r){
    unsigned p, i, j;
    i = l; j = r; p = l;

}

void swap(unsigned *a, unsigned *b){
    unsigned t = *a;
    *a = *b;
    *b = t;
}

unsigned rang(void){
    return (unsigned int)(1<<32) - 1;
}

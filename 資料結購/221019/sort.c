#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 4,294,967,295

void Selection_sort(unsigned *num, unsigned N);
void Quick_sort(unsigned *num, unsigned l, unsigned r);
void swap(unsigned *a, unsigned *b);
unsigned rang(void);

int main(){
    unsigned *num, N, i, *numQ;
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
    numQ = num;

    tm = clock();
    Selection_sort(num, N);
    for(i = 0; i < N; i++){
        printf("%10u ", num[i]);
        if(i % 10 == 0 && i != 0) printf("\n");
    }
    printf("\n");
    printf("Selection_sort execution time: %u\n\n", clock()-tm);
    
	tm = clock();
	Quick_sort(numQ, 0, N-1);
	for(i = 0; i < N; i++){
        printf("%10u ", numQ[i]);
        if(i % 10 == 0 && i != 0) printf("\n");
    }
    printf("\n");
    printf("Quick_sort execution time: %u\n", clock()-tm);
	

    free(num);
    free(numQ);
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
    i = l+1; j = r; p = l;
    if(r-l < 2) return;
	while(i < j){
		if(num[i] > num[p]){
			if(num[j] >= num[p]) j--;
			else if(num[j] < num[p]){
				swap(&num[i++],&num[j--]);
			}
		}else i++;
	}
	if(j != l+1) swap(&num[p], &num[j]);
	
	Quick_sort(num, l, j-1);
	Quick_sort(num, i+1, r);
}

void swap(unsigned *a, unsigned *b){
    unsigned t = *a;
    *a = *b;
    *b = t;
}

unsigned rang(void){
    return (unsigned int)(1<<32) - 1;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define MAX 4,294,967,295

void Selection_sort(unsigned *num, unsigned N);
void Quick_sort(unsigned *num, unsigned l, unsigned r);
void swap(unsigned *a, unsigned *b);
unsigned rang(void);

int main(){
    unsigned *num, N, i, *numQ;
    clock_t tm;
    double tm_sec_S, tm_sec_Q;
    //printf("%u", rang());
    srand((unsigned)time(0)+getpid());    //RAND_MAX
    scanf("%u", &N);
    num = (unsigned*)malloc(sizeof(unsigned int) * N);
    numQ = (unsigned*)malloc(sizeof(unsigned int) * N);

    for(i = 0; i < N; i++){
        num[i] =  rang()/RAND_MAX*rand()/RAND_MAX*rand()+ rand()+1 ;
        numQ[i] = num[i];
        if(i % 10 == 0 && i != 0) printf("\n");
        printf("%10u ", num[i]);

    }
    printf("\n\n");

    tm = clock();
    Selection_sort(num, N);
    for(i = 0; i < N; i++){
    	if(i % 10 == 0 && i != 0) printf("\n");
        printf("%10u ", num[i]);
    }
    printf("\n");
    tm_sec_S = (clock()-tm);
    printf("Selection_sort execution time: %.5fs\n\n", difftime(clock(),tm)/1000);
    //printf("Selection_sort execution time: %u\n\n", (clock()-tm));

	tm = clock();
	Quick_sort(numQ, 0, N-1);
	for(i = 0; i < N; i++){
		if(i % 10 == 0 && i != 0) printf("\n");
        printf("%10u ", numQ[i]);
    }
    printf("\n");
    tm_sec_Q = (clock()-tm);
    printf("Quick_sort execution time: %.5fs\n\n", difftime(clock(),tm)/1000);
    //printf("Quick_sort execution time: %u\n\n", clock()-tm);





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
    unsigned p, i, j, c;
    p = l; i = l+1; j = r;
    if(l < r){
		while(1){
			while(i < r && num[i] < num[p]) i++;
			while(j >= i && num[j] >= num[p]) j--;
//			printf("%3u%3u\n", i, j);
			if(i >= j) break;
			else swap(&num[i++], &num[j--]);

//			for(c = l; c <= r; c++){
//				printf("%u ", num[c]);
//			}printf("\ni = %u j = %u\n", i, j);
//			system("pause");
		}
		swap(&num[j], &num[p]);

		Quick_sort(num, l, j);
		Quick_sort(num, i, r);
	}
	return;

}

void swap(unsigned *a, unsigned *b){
    unsigned t = *a;
    *a = *b;
    *b = t;
}

unsigned rang(void){
    return (unsigned int)(1<<32) - 1;
}

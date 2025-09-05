#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void memory_leak() {
        printf("memory leak start ...");

        delay_ms(3000);

        int *ptr_ = (int*) malloc (sizeof(int) * 100);
}

void out_of_memory() {
        printf("out of memory start ...");

        static int  count = 0;
        printf("%d",count);
        out_of_memory();

        sleep(3000);
}

void stack_overflow() {
        printf("stack overflow start ...");

        sleep(3000)

        char big_arr[8 * 1024 *1024];//create array 8MB in stack frame
}

void main (int argc, char *argv[]) {
        //choose programme
        printf("choose fault :\n");
        printf("./memory_lab stack_overflow \n");
        printf("./memory_lab memory_leak\n");

        //compair argc
        if (argc != 2) {
                printf("syntax fault !");
                exit(0);
        }

        //compair argv[] with stack_overflow
        if (strcmp(argv[1], "stack_overflow") == 0) {
                stack_overflow();
        }

        //compair argv[] with memory_leak
        if (strcmp(argv[1], "memory_leak") == 0) {
                memory_leak();
        }

        //compair argv[] with out_of_memory
        if (strcmp(argv[1], "out_of_memory") == 0) {
                out_of_memory();
        }

}
Type  :

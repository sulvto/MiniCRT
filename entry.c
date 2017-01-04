//
// Created by sulvto on 17-1-4.
//

#include "minicrt.h"

extern int main(int argc, char *argv[]);


static void crt_fatal_error(const char *msg) {
    // printf("fatal error: %s", msg);
    exit(1);
}

void mini_crt_entry(void) {
    int ret;
    int argc;
    char **argv;
    char *ebp_reg = 0;
    asm("movl %%ebp,%0 \n":"=r"(ebp_reg));
    argc = *(int *) (ebp_reg + 4);
    argv = (char **) (ebp_reg + 4);
    if (!mini_crt_heap_init()) {
        crt_fatal_error("heap initialize failed");
    }
    if (!mini_crt_io_init()) {
        crt_fatal_error("IO initialize failed");
    }
    ret = main(argc, argv);
    exit(ret);
}

void exit(int exitCode){
    asm("movl %0,%%ebx \n\t"
        "movl $1,%%eax \n\t"
        "int $0X80 \n\t"
        "hlt \n\t"::"m" (exitCode));
}



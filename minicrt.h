//
// Created by sulvto on 17-1-4.
//

#ifndef MINICRT_MINICRT_H
#define MINICRT_MINICRT_H

static void crt_fatal_error(const char *msg);

void mini_crt_entry(void);

void exit(int);

void free(void *ptr);

void *malloc(unsigned size);

int mini_crt_heap_init();


#endif //MINICRT_MINICRT_H

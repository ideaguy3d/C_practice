//
// Created by julius on 1/7/2020.
//

#include "stdio.h"
#include "ap.h"


int morePoints() {
    int x = 2;

    int *ptX = &x;

    printf("\n----\nx = %d\n", x);
    printf("ptX = %d\n", *ptX);

    return 0;
}
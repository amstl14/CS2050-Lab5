/* 
 * File:   head.h
 * Author: Art
 *
 * Created on May 1, 2015, 12:48 PM
 */

#ifndef HEAD_H
#define	HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list1 {
    char *positive;
    struct list1 *next;
};

typedef struct list1 LIST1;

struct list2 {
    char *negative;
    struct list2 *next;
};


typedef struct list2 LIST2;


LIST1* positive_list(char argv[1]);
LIST2* negative_list(char argv[2]);
void freePos(LIST1* temp);
void freeNeg(LIST2* temp);
void print(int numPositive, int numNegative, char* file);



#endif
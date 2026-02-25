#ifndef LISTDIN_H
#define LISTDIN_H

#include "Boolean.h"
#include <stdbool.h>

#define IDX_MIN 0
#define IDX_UNDEF -1

typedef int ElType;
typedef int IdxType;

typedef struct {
    ElType *buffer;
    int nEff;
    int capacity;
} ListDin;

#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

void CreateListDin(ListDin *l, int capacity);
void dealocateList(ListDin *l);
int listLength(ListDin l);
IdxType getFirstIdx(ListDin l);
IdxType getLastIdx(ListDin l);
boolean isIdxValid(ListDin l, IdxType i);
boolean isIdxEff(ListDin l, IdxType i);
boolean isEmpty(ListDin l);
boolean isFull(ListDin l);
void readList(ListDin *l);
void printList(ListDin l);
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus);
boolean isListEqual(ListDin l1, ListDin l2);
IdxType indexOf(ListDin l, ElType val);
void extremeValues(ListDin l, ElType *max, ElType *min);
void copyList(ListDin lIn, ListDin *lOut);

#endif

#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "List_tag.h"
#include <iostream>
#include "List_artikel.h"

using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define child(P) P->child
#define parent(P) P->parent

typedef struct elmList_relasi *address_relasi;

struct elmList_relasi {
    address_relasi next;
    address_relasi prev;
    address_tag child;
    address_artikel parent;
};

struct List_relasi {
    address_relasi first;
    address_relasi last;
};

void createListRelasi(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(List_relasi &L, address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter(List_relasi &L, address_relasi Prec, address_relasi &P);
void dealokasiRelasi(address_relasi &P);
void printInfoRelasi(List_relasi L);

address_relasi alokasiRelasi(address_artikel P, address_tag C);
address_relasi cariElmRelasi(List_relasi L, int x);
address_relasi cariElmRelasiHuruf(List_relasi L, address_artikel P, address_tag C);
void deleteRelasi (List_relasi &L, address_artikel P);

#endif // LIST_RELASI_H_INCLUDED

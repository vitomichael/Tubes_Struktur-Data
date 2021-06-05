#ifndef LIST_ARTIKEL_H_INCLUDED
#define LIST_ARTIKEL_H_INCLUDED
#include <iostream>

using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define child(P) P->child

typedef string infotype_artikel;
typedef struct elmList_artikel *address_artikel;

struct elmList_artikel {
    infotype_artikel info;
    address_artikel next;
    address_artikel prev;
};

struct List_artikel {
    address_artikel first;
    address_artikel last;
};

void createListArtikel(List_artikel &L);
void insertFirst(List_artikel &L, address_artikel P);
void insertAfter(List_artikel &L, address_artikel Prec, address_artikel P);
void insertLast(List_artikel &L, address_artikel P);
void deleteFirst(List_artikel &L, address_artikel &P);
void deleteLast(List_artikel &L, address_artikel &P);
void deleteAfter(List_artikel &L, address_artikel Prec, address_artikel &P);
void dealokasiAtikel(address_artikel &P);
void printInfoArtikel(List_artikel L);

address_artikel alokasiArtikel(infotype_artikel x);
address_artikel cariElmArtikel(List_artikel L, int x);
address_artikel cariElmArtikelHuruf(List_artikel L, infotype_artikel x);


#endif // LIST_ARTIKEL_H_INCLUDED

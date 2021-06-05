#ifndef LIST_TAG_H_INCLUDED
#define LIST_TAG_H_INCLUDED
#include <iostream>

using namespace std;

#define next(P) P->next
#define first(L) L.first
#define last(L) L.last
#define prev(P) P->prev
#define info(P) P->info

typedef string infotype_tag;
typedef struct elmList_tag *address_tag;

struct elmList_tag {
    infotype_tag info;
    address_tag next;
    address_tag prev;
};

struct List_tag{
    address_tag first;
    address_tag last;
};

void createListTag(List_tag &L);
void insertFirst(List_tag &L, address_tag P);
void insertLast(List_tag &L, address_tag P);
void insertAfter(List_tag &L, address_tag Prec, address_tag P);
void deleteFirst(List_tag &L, address_tag &P);
void deleteLast(List_tag &L, address_tag &P);
void deleteAfterTag(List_tag &L, address_tag Prec, address_tag &P);
void dealokasiTag(address_tag &P);
void printInfoTag(List_tag L);

address_tag alokasiTag(infotype_tag x);
address_tag cariElmTag(List_tag L, int x);
address_tag cariElmTagHuruf(List_tag L, infotype_tag x);


#endif // LIST_TAG_H_INCLUDED

#include "List_tag.h"

void createListTag(List_tag &L){
    first(L) = NULL;
    last(L) = NULL;
}

void insertFirst(List_tag &L, address_tag P){
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_tag &L, address_tag P){
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfter(List_tag &L, address_tag Prec, address_tag P){
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        if (Prec == last(L)) {
            insertLast(L, P);
        } else if (Prec != last(L)){
            prev(P) = Prec;
            next(P) = next(Prec);
            prev(next(Prec)) = P;
            next(Prec) = P;
        } else {
            cout << "Prec Tidak Ditemukan" << endl << endl;
        }
    }
}

void deleteFirst(List_tag &L, address_tag &P){
    if (first(L) == NULL) {
        cout << "Isi List Tag Kosong" << endl << endl;
    } else {
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            P = first(L);
            first(L) = next(P);
            prev(first(L)) = NULL;
        }
    }
}

void deleteLast(List_tag &L, address_tag &P){
    if (first(L) == NULL) {
        cout << "Isi List Artikel Kosong" << endl << endl;
    } else
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            address_tag Q;
            P = last(L);
            Q = prev(last(L));
            last(L) = Q;
            next(Q) = NULL;
            prev(P) = NULL;
    }
}

void deleteAfterTag(List_tag &L, address_tag Prec, address_tag &P){
    if (first(L) == NULL) {
        cout << "Isi List Tag Kosong" << endl << endl;
    } else {
        if (first(L) == last(L)) {
            P = first(L);
            next(P) = first(L);
            prev(first(L)) = NULL;
        } else {
            if (Prec != NULL) {
                P = prev(Prec);
                next(P) = next(Prec);
                prev(next(Prec)) = P;
                prev(Prec) = NULL;
                next(Prec) = NULL;
            }   else {
            cout << "Prec Tidak Ditemukan" << endl << endl;
            }
        }
    }
}

//void dealokasiTag(address_tag &P){
//    delete p;
//}

void printInfoTag(List_tag L){
    if(first(L) == NULL) {
        cout << "List Tag Kosong" << endl;
    } else {
        address_tag P = first(L);
        int i = 0;
        while (P != NULL) {
            i++;
            cout << i << ". Tag yang tersedia: " << info(P) << endl;
            P = next(P);
        }
    }
}

address_tag alokasiTag(infotype_tag x){
    address_tag P = new elmList_tag;

    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

address_tag cariElmTag(List_tag L, int x){
    address_tag P = first(L);

    int i = 1;
    while (P != NULL) {
        if(i == x){
            return P;
        }
        i++;
        P = next(P);
    }
    return NULL;
}

address_tag cariElmTagHuruf(List_tag L, infotype_tag x){
    address_tag Q = first(L);

    while (Q != NULL) {
        if (info(Q) == x) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

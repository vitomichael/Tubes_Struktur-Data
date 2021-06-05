#include "List_relasi.h"

void createListRelasi(List_relasi &L){
    first(L) = NULL;
    last(L) = NULL;
}

void insertFirst(List_relasi &L, address_relasi P){
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_relasi &L, address_relasi P){
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfter(List_relasi &L, address_relasi Prec, address_relasi P){
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

void deleteFirst(List_relasi &L, address_relasi &P){
    if (first(L) == NULL) {
        cout << "Isi List Relasi Kosong" << endl << endl;
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

void deleteLast(List_relasi &L, address_relasi &P){
    if (first(L) == NULL) {
        cout << "Isi List Relasi Kosong" << endl << endl;
    } else
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            address_relasi Q;
            P = last(L);
            Q = prev(last(L));
            last(L) = Q;
            next(Q) = NULL;
            prev(P) = NULL;

    }
}

void deleteAfter(List_relasi &L, address_relasi Prec, address_relasi &P){
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
            cout << "Prec Tidak Ditemukan" << endl;
            }
        }
    }
}

//void dealokasiRelasi(address_relasi &P){
//    delete p;
//}

void printInfoRelasi(List_relasi L){
    address_relasi P = first(L);

    if (first(L) == NULL) {
        cout << "Tidak ada relasi yang tersedia" << endl;
    } else {
        int i = 0;
        while (P != NULL) {
            i++;
            cout << i << ". Artikel " << info(parent(P)) << " memiliki tag dengan nama " << info(child(P)) << endl;
            P = next(P);
        }
    }
}

void deleteRelasi (List_relasi &L, address_artikel P) {
    address_relasi Q = first(L);
    bool ada;

    if (first(L) == NULL) {
        cout << "Tidak ada relasi yang tersedia" << endl;
    } else {
        while (Q != NULL) {
            ada = false;
            if (parent(Q) == P) {
                //Ini delete anaknya
                ada = true;
                child(Q) = NULL;
                parent(Q) = NULL;
            }
            Q = next(Q);
            if (ada) {
                delete prev(Q);
            }
        }
    }
}

address_relasi alokasiRelasi(address_artikel P, address_tag C){
    address_relasi Q = new elmList_relasi;

    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    prev(P) = NULL;
    return Q;
}

address_relasi cariElmRelasi(List_relasi L, int x){
    address_relasi P = first(L);

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

address_relasi cariElmRelasiHuruf(List_relasi L, address_artikel P, address_tag C){
    address_relasi Q = first(L);

    while (Q != NULL) {
        if (parent(Q) == P && child(Q) == C) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

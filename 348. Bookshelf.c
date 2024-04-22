#include <stdio.h>
#include <stdlib.h>

int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;    
        }
        p = buf;
    }
    return *p++;
}

int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}

int search_book(long long int bookshelf, int book_id){
    unsigned long long int ll_book_id = book_id;
    for (int i=7; i>=0; --i){
        if((ll_book_id << i*8) == (bookshelf & (ll_book_id << i*8)))
            return i;
    }
    return -1;
}

int main() {
    int x;
    long long int bookshelf = 0;
    int bookshelf_books = 0;
    while (ReadInt(&x)) {
        int idx = search_book(bookshelf, x);
        long long int llx = x;
        if (idx != -1){
            bookshelf = (bookshelf >> ((idx+1) * 8) << ((idx+1) * 8)) | (bookshelf << ((7-idx+1) * 8) >> ((7-idx)) * 8) | llx;
            // printf("found - ");
        }
        else{
            // printf("not found - ");
            bookshelf = bookshelf << 8 | llx;
        }
    }

    // output your answer
    for (int i=7; i>=0; --i){
        if (i == 7)
            printf("%llu", (bookshelf & (255ULL << (i * 8))) >> i*8);
        else
            printf(" %llu", (bookshelf & (255ULL << (i * 8))) >> i*8);
    }
    printf("\n");
    return 0;
}
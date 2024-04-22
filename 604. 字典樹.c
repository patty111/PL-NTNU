#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Trie_t {
    struct Trie_t *child[26];
    int val;
} Trie;

Trie trie[300000];
int top = 1;

// 加字串到樹裏面的函式
static void
add_trie(Trie *t, const char *str, int val);

// 查詢函式
static int
query(Trie *t, const char *str);

int main(){
    
    return 0;
}
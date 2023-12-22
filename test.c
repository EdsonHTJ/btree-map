#include<stdlib.h>
#include<stdio.h>
#include "btree.h"
#include <assert.h>
#include <string.h>


void test_add_entry() {
    btree_t* btree = new_btree();
    add_entry(btree, "entry_1", sizeof("entry_1"), "value_1", sizeof("value_1"));
    value_t* value = find_entry(btree, "entry_1", sizeof("entry_1"));
    assert(value != NULL);
    assert(memcmp(value->value, "value_1", sizeof("value_1")) == 0);
    free_tree(btree);
}

void test_entry_list() {
    btree_t* btree = new_btree();
    add_entry(btree, "entry_1", sizeof("entry_1"), "value_1", sizeof("value_1"));
    add_entry(btree, "entry_2", sizeof("entry_2"), "value_2", sizeof("value_2"));
    add_entry(btree, "entry_3", sizeof("entry_3"), "value_3", sizeof("value_3"));
    add_entry(btree, "entry_4", sizeof("entry_4"), "value_4", sizeof("value_4"));
    add_entry(btree, "entry_5", sizeof("entry_5"), "value_5", sizeof("value_5"));
    entry_list_t* list = list_entries(btree);
    assert(list->len == 5);
    assert(memcmp(list->entries[0].key.key, "entry_1", sizeof("entry_1")) == 0);
    assert(memcmp(list->entries[0].value.value, "value_1", sizeof("value_1")) == 0);
    assert(memcmp(list->entries[1].key.key, "entry_2", sizeof("entry_2")) == 0);
    assert(memcmp(list->entries[1].value.value, "value_2", sizeof("value_2")) == 0);
    assert(memcmp(list->entries[2].key.key, "entry_3", sizeof("entry_3")) == 0);
    assert(memcmp(list->entries[2].value.value, "value_3", sizeof("value_3")) == 0);
    assert(memcmp(list->entries[3].key.key, "entry_4", sizeof("entry_4")) == 0);
    assert(memcmp(list->entries[3].value.value, "value_4", sizeof("value_4")) == 0);
    assert(memcmp(list->entries[4].key.key, "entry_5", sizeof("entry_5")) == 0);
    assert(memcmp(list->entries[4].value.value, "value_5", sizeof("value_5")) == 0);
    free_tree(btree);
    free_entry_list(list);
}


int main() {
    test_add_entry();
    test_entry_list();
    printf("All tests passed!\n");
    return 0;
}
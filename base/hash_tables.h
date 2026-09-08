#ifndef SCAS_LIB_HASH_TABLES_H
#define SCAS_LIB_HASH_TABLES_H

#include <stdbool.h>
#include <stdint.h>

typedef uint32_t (*hash_fn)(void *key);
typedef bool     (*for_each_fn)(void *ctx, void *key, void *val);
typedef bool     (*del_fn)(void *key, void *val);
typedef bool     (*cmp_fn)(void *key1, void *key2);

typedef struct scas_hash_item {
    void *key;
    void *val;
    struct scas_hash_item *next;
} scas_hash_item_t;

typedef struct scas_hash_table {
    scas_hash_item_t   **items;
    uint32_t            n_items;
    hash_fn             hash;
    cmp_fn              cmp;
} scas_hash_table_t;

scas_hash_table_t *scas_hash_table_init(uint32_t n_items, hash_fn hash, cmp_fn cmp);

scas_status_t scas_hash_item_add(scas_hash_table_t *hash_table, void *key, void *val);

void scas_hash_item_for_each(scas_hash_table_t *hash_table, void *ctx, for_each_fn for_each);

void *scas_hash_item_find(scas_hash_table_t *hash_table, void *key);

void scas_hash_item_del(scas_hash_table_t *hash_table, void *key, del_fn del);

void scas_hash_table_deinit(scas_hash_table_t *hash_tbl, del_fn del);

#endif


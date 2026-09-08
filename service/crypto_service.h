#ifndef SCAS_CRYPTO_SERVICE_H
#define SCAS_CRYPTO_SERVICE_H

#define SCAS_CLIENT_MAGIC_LEN 32

typedef struct scas_client_metadata {
    uint8_t client_magic[SCAS_CLIENT_MAGIC_LEN];
    struct scas_client_metadata *next;
} scas_client_metadata_t;

typedef struct scas_context {
    int server_fd;
} scas_context_t;

#endif


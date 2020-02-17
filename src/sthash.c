#define _DEFAULT_SOURCE
#include <string.h>
#include <stdlib.h>
#include <mbedtls/md.h>
#include "sthash.h"

static int ready;

static mbedtls_md_context_t md_ctx;
static size_t hash_len;

int sthash_init(const unsigned char *key, size_t key_len)
{
    if (ready)
    {
        return 0;
    }
    mbedtls_md_init(&md_ctx);
    if (mbedtls_md_setup(&md_ctx, mbedtls_md_info_from_type(MBEDTLS_MD_SHA256), 1) || mbedtls_md_hmac_starts(&md_ctx, key, key_len))
    {
        mbedtls_md_free(&md_ctx);
        return -1;
    }
    hash_len = (size_t)mbedtls_md_get_size(md_ctx.md_info);
    ready = 1;
    return 0;
}

static void filter(unsigned char *msg, size_t msg_len)
{
    unsigned char temp;
    for (size_t i = 0; i < msg_len; i++)
    {
        temp = msg[i];
        msg[i] = msg[temp % msg_len];
        msg[temp % msg_len] = temp;
    }
}

size_t sthash_do(const unsigned char *msg, unsigned char *hash_out, size_t msg_len)
{
    mbedtls_md_hmac_update(&md_ctx, msg, msg_len);
    mbedtls_md_hmac_finish(&md_ctx, hash_out);
    mbedtls_md_hmac_reset(&md_ctx);
    filter(hash_out, hash_len);
    return hash_len;
}

void sthash_reset(void)
{
    if (ready)
    {
        mbedtls_md_free(&md_ctx);
        ready = 0;
        hash_len = 0;
    }
}

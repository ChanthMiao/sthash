#ifndef sthashs_H
#define sthashs_H
#ifdef __cplusplus
extern "C"
{
#endif
    int sthash_init(const unsigned char *key, size_t key_len);
    size_t sthash_do(const unsigned char *msg, unsigned char *hash_out, size_t msg_len);
    void sthash_reset(void);
#ifdef __cplusplus
}
#endif
#endif

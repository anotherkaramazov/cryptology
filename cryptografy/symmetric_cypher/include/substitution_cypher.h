#ifndef __SUBSTITUTION_CYPHER__
#define __SUBSTITUTION_CYPHER__
int substitution_setup(const char** replacement, size_t len);
char* substitution_crypt(const char *plain_text);
char* substitution_decrypt(const char *cypher_text);
#endif

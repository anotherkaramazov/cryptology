#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "symmetric_cypher.h"
#include "substitution_cypher.h"

int test_substitution_cypher() {
  printf("substitution tests\n");
  char **replacement;
  const char* plain_text = "ABBA";
  char* cypher_text;
  char* result_text;

// int substitution_setup(const char** replacement, size_t len);
// char* substitution_crypt(const char *plain_text);
// char* substitution_derypt(const char *cypher_text);


  // building the replacement table
  replacement = (char**)malloc(sizeof(char*)*3);
  *(replacement+0) = (char*)malloc(sizeof(char)*3);
  strcpy(*(replacement+0), "Ak");
  *(replacement+1) = (char*)malloc(sizeof(char)*3);
  strcpy(*(replacement+1), "Bd");
  *(replacement+2) = (char*)malloc(sizeof(char)*3);
  strcpy(*(replacement+2), "Cw");

  int result = substitution_setup((const char**)replacement, 3);
  printf("plain_text: %s\n", plain_text);
  cypher_text = substitution_crypt(plain_text);
  printf("cypher_text: %s\n", cypher_text);
  result_text = substitution_decrypt(cypher_text);
  printf("result_text: %s\n", result_text);

  return result;
}

int main(int argc, char** argv) {
  printf("symemtric cypher\n");

  int return_value = test_substitution_cypher();
  return return_value;
}

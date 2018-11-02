#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include"substitution_cypher.h"

char** replacement_list;
size_t replacement_list_len;

char replace_char(char target, int order) {
  int i;
  int index;

  index = 1;
  if (order == 1) index = 0;
  if(target == '\0' || target == '\n') return target;

  for(i=0; i<replacement_list_len; i++) {
    if( replacement_list[i][order] == target ) {
      return replacement_list[i][index];
    }
  }
  return ' ';
}

int substitution_setup(const char** replacement, size_t len) {
  int i;
  if (!replacement) return 1;

  replacement_list = (char**)malloc(sizeof(char*)*len);
  for(i=0; i<len; i++) {
    if(replacement[i][0] && replacement[i][1] ) {
      replacement_list[i] = (char*)malloc(sizeof(char)*3); 
      replacement_list[i][0] = replacement[i][0];
      replacement_list[i][1] = replacement[i][1];
      replacement_list[i][2] = '\0';
    }
  }
  replacement_list_len = len;
  return 0;
}

char* substitution_crypt(const char *plain_text) {
  char* str;
  size_t len = strlen(plain_text);
  int i;

  str = malloc(sizeof(char)*len+1);
  for(i=0; i<len; i++) {
    str[i] = replace_char(plain_text[i], 0);
  }
  str[i] = '\0';

  return str;
}

char* substitution_decrypt(const char *cypher_text) {
  char* str;
  size_t len = strlen(cypher_text);
  int i;

  str = (char *)malloc(sizeof(char)*len+1);
  for(i=0; i<len; i++) {
    *(str+i) = replace_char(*(cypher_text+i), 1);
  }
  str[i] = '\0';

  return str;
}


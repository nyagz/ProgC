#include <ctype.h>
#include <string.h>
#include "revwords.h"

int i, j;

void reverse_substring(char str[], int start, int end) {
  /* TODO */
  for (int i = start, j = end; i < j; i++, j--){
    char c = str[i];
    str[i] = str[j], str[j] = c;
  }
}

int find_next_start(char str[], int len, int i) { 
  for(; i < len; i++){
    char thisChar = str[i];
    if ((thisChar >= 'A' && thisChar <= 'Z') || (thisChar >= 'a' && thisChar <= 'z')){
      return i;
    }
  }
  return -1;
}

int find_next_end(char str[], int len, int i) {
  for(; i < len; i++){
    char thisChar = str[i];
    if ((thisChar < 'A' || thisChar >'Z') && (thisChar < 'a' || thisChar > 'z')){
      return i;
    }
  }
  return len;
}

void reverse_words(char s[]) { 
  int length = strlen(s);
  int nextStart = find_next_start(s, length, 0);
  while (nextStart >= 0){
    int nextEnd = find_next_end(s, length, nextStart);
    reverse_substring(s, nextStart, nextEnd - 1);
    nextStart = find_next_start(s, length, nextEnd);
  }
}

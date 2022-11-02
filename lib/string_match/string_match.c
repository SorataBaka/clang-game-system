#include "string_match.h"
boolean MatchString(char * a, char * b){
  int stringLength = 0;
  int currentIndex = 0;
  while(a[currentIndex++] != '\0') stringLength++;
  boolean isMatch = true;
  for(int i = 0; i < stringLength; i++){
    if(a[i] != b[i]){
      isMatch = false;
      break;
    }
  }
  return isMatch;
}
/*
  HttpGet.cpp - Library to get values of HTTP GET paramters.
  Created by Matthias Keim, August 12, 2018.
  Released into the public domain.
*/

#include "Arduino.h"
#include "HttpGet.h"

HttpGet::HttpGet(String *headerArg) {
    header = headerArg;
}

bool HttpGet::isSet(String key) {

  int indexOfKey = header->indexOf(key);
  int endOfKey = indexOfKey + key.length();
  
  if(indexOfKey != -1 && header->charAt(endOfKey) == '=') {
    return true;
  } else {
    return false;
  }

}

String HttpGet::get(String key) {

  String returnVal = "";

  if(isSet(key)) {

    int indexOfKey = header->indexOf(key);
    
    if(indexOfKey != -1) {
      int headerLength = header->length();
      int keyLength = key.length();
      int startOfValue = indexOfKey + keyLength + 1;
      int endOfValue;
  
      for(int c = startOfValue; c < headerLength; c++) {
        //Most of the times the character on the end of the line will be 13
        if(header->charAt(c) == '&' || header->charAt(c) == '\n' || (header->charAt(c) >= 0 && header->charAt(c) <= 32)) { 
          endOfValue = c;
          break;
        }
      }
  
  
      returnVal = header->substring(startOfValue, endOfValue);
      
    }
  }

  return returnVal;

}
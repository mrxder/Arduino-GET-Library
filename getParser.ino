String getGETValue(String key, String *header) {

  String returnVal = "";

  int indexOfKey = header->indexOf(key);
  
  if(indexOfKey != -1) {
    int headerLength = header->length();
    int keyLength = key.length();
    int startOfValue = indexOfKey + keyLength + 1;
    int endOfValue;

    for(int c = startOfValue; c < headerLength; c++) {
      if(header->charAt(c) == '&' || header->charAt(c) == '\n') {
        endOfValue = c;
        break;
      }
    }


    returnVal = header->substring(startOfValue, endOfValue);
    
  }

  return returnVal;
  
}

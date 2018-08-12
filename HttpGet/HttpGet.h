/*
  HttpGet.h - Library to get values of HTTP GET paramters.
  Created by Matthias Keim, August 12, 2018.
  Released into the public domain.
*/

#ifndef HttpGet_h
#define HttpGet_h

#include "Arduino.h"

class HttpGet 
{
    public:
        HttpGet(String *header);
        bool isSet(String key);
        String get(String key);

    private:
        String *header;


};

#endif

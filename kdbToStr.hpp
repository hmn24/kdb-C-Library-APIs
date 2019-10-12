#include <iostream>
#include <string.h>

#define KXVER 3
#include "k.h"

extern "C" {

// Taken from https://code.kx.com/v2/kb/regex/
Z __inline S c2s(S s,J n){S r=(S)malloc(n+1);R r?memcpy(r,s,n),r[n]=0,r:(S)krr((S)"wsfull");}

// Converts a kdb+ sym or string to a C string (with thanks to Kevin Smyth)
static S kdb2str(K kdbStr) {return kdbStr->t == -KS ? kdbStr->s : c2s((S) kC(kdbStr), kdbStr->n);}

}
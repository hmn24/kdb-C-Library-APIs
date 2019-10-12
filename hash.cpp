#include <iostream>
#include <string.h>
#include <unordered_map>
#include <functional> // for hash<class template> class 

#define KXVER 3
#include "k.h"

typedef std::unordered_map<std::string,std::string> stringmap;

extern "C" {

// Taken from https://code.kx.com/v2/kb/regex/
Z __inline S c2s(S s,J n){S r=(S)malloc(n+1);R r?memcpy(r,s,n),r[n]=0,r:(S)krr((S)"wsfull");}

// Converts a kdb+ sym or string to a C string (with thanks to Kevin Smyth)
static S kdb2str(K kdbStr) {return kdbStr->t == -KS ? kdbStr->s : c2s((S) kC(kdbStr), kdbStr->n);}

// C++ UnorderedMap Hash Function from http://www.cplusplus.com/reference/unordered_map/unordered_map/hash_function/
K cppMapHash(K input) {
        
    P(!(input->t == -KS || input->t == KC), krr((S) "type")); // Check the types

    stringmap mymap;
    stringmap::hasher fn = mymap.hash_function();

    try {return kj((J) fn(kdb2str(input)));} 
    catch (std::exception &e) {return krr((S) e.what());}
 }

// C++ fast Standard Functional Hash Function from https://www.geeksforgeeks.org/stdhash-class-in-c-stl/
K cppStdHash(K input) {
        
    P(!(input->t == -KS || input->t == KC), krr((S) "type")); // Check the types

    std::hash<std::string> stdHash;

    try {return kj((J) stdHash(kdb2str(input)));} 
    catch (std::exception &e) {return krr((S) e.what());}
 }

}




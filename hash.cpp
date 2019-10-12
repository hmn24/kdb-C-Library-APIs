#include <unordered_map>
#include <functional> // for hash<class template> class 
#include "kdbToStr.hpp"

typedef std::unordered_map<std::string,std::string> stringmap;

extern "C" {

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




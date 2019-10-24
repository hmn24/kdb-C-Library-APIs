#include <unordered_map>
#include <functional> // for hash<class template> class 
#include "kdbToStr.hpp"

#define tryCatch(x) try{R x;} catch(std::exception &e) {R krr((S) e.what());} 
#define hashTypeChk(x) P(!(x->t == -KS || x->t == KC), krr((S) "type"))

typedef std::unordered_map<std::string,std::string> stringmap;
stringmap mymap;
std::hash<std::string> stdHash;

extern "C" {

// C++ UnorderedMap Hash Function from http://www.cplusplus.com/reference/unordered_map/unordered_map/hash_function/
K cppMapHash(K input) {
    hashTypeChk(input);
    tryCatch(kj((J) mymap.hash_function()(kdb2str(input))));
 }

// Check that the hashes from unordered_map are equivalent 
K cppMapHashEquals(K expr_one, K expr_two) {
    hashTypeChk(expr_one);
    hashTypeChk(expr_two);
    tryCatch(kb((I) mymap.key_eq()(kdb2str(expr_one), kdb2str(expr_two))));
 }

// C++ fast Standard Functional Hash Function from https://www.geeksforgeeks.org/stdhash-class-in-c-stl/
K cppStdHash(K input) {
    hashTypeChk(input);
    tryCatch(kj((J) stdHash(kdb2str(input))));
 }

}




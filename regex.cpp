#include <boost/regex.hpp>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define KXVER 3
#include "k.h"

extern "C" {

// Taken from https://code.kx.com/v2/kb/regex/
Z __inline S c2s(S s,J n){S r=(S)malloc(n+1);R r?memcpy(r,s,n),r[n]=0,r:(S)krr((S)"wsfull");}

// Converts a kdb+ sym or string to a C string (with thanks to Kevin Smyth)
static S kdb2str(K kdbStr) {return kdbStr->t == -KS ? kdbStr->s : c2s((S) kC(kdbStr), kdbStr->n);}

// Regex match function
K regexMatch(K input, K expr) {
    
    P(!((input->t == -KS) || (input->t == KC)), krr((S) "type")); // Check the types
    P(expr->t != KC, krr((S) "type"));     
    
    try {
        return kb((bool) boost::regex_match(kdb2str(input), boost::regex {kdb2str(expr)}));
    } catch (std::exception &e) {
        return krr(strdup(e.what()));
    }
 }

// Regex search function
K regexSearch(K input, K expr) {
    
    P(input->t != KC || expr->t != KC, krr((S) "type")); // Check the types
    
    // Regex tokens - Only first one represents complete match, the rest are subtokens 
    boost::smatch what;

    try {
        return boost::regex_search(std::string(kdb2str(input)), what, boost::regex{kdb2str(expr)}) ? kp((S) what.str().c_str()) : kp((S) "");
    } catch (std::exception &e) {
        return krr(strdup(e.what()));
    }
 }

// Regex replace function
K regexReplace(K input, K expr, K replace) {

    P(input->t != KC || expr->t != KC || replace->t != KC, krr((S) "type")); // Check the types

    try {
        std::string op = boost::regex_replace(std::string(kdb2str(input)), boost::regex{kdb2str(expr)}, std::string(kdb2str(replace)));
        return kp((S) op.c_str());
    } catch (std::exception &e) {
        return krr(strdup(e.what()));
    }

 }

}


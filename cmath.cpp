#include <iostream>
#include <cmath>

#define KXVER 3
#include "k.h"

extern "C" {

F getVal(K x){    
    P(xt == -KB, (F)x->g);
    P(xt == -KH, (F)x->h);
    P(xt == -KI || xt == -KM || xt == -KD || xt == -KU || xt == -KV || xt == -KT, (F)x->i);
    P(xt == -KJ || xt == -KP || xt == -KN, (F)x->j);
    P(xt == -KE, (F)x->e);
    P(xt == -KF, (F)x->f);
    throw("TYPE");
 }

K hypotCPP(K x, K y) {
    try {
        R kf(hypot(getVal(x), getVal(y)));
    } 
    catch (const char* &param) {
        R krr((S) param);
    }
 }

K fdimCPP(K x, K y) {
    try {
        R kf(fdim(getVal(x), getVal(y)));
    } 
    catch (const char* &param) {
        R krr((S) param);
    }
 }

K erfCPP(K x) {
    try {
        R kf(erf(getVal(x)));
    } 
    catch (const char* &param) {
        R krr((S) param);
    }
 }

K tgammaCPP(K x) {
    try {
        R kf(tgamma(getVal(x)));
    } 
    catch (const char* &param) {
        R krr((S) param);
    }
 }

}

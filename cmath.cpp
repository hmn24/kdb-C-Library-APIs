#include <iostream>
#include <cmath>

#define KXVER 3
#include "k.h"

extern "C" {

F getVal(K x){    
    if(xt == -KB) {R (F) x->g;}
    if(xt == -KH) {R (F) x->h;}
    if(xt == -KI || xt == -KM || xt == -KD || xt == -KU || xt == -KV || xt == -KT) {R (F) x->i;}
    if(xt == -KJ || xt == -KP || xt == -KN) {R (F) x->j;}
    if(xt == -KE) {R (F) x->e;}
    if(xt == -KF) {R (F) x->f;}
    throw("TYPE");
 }

K hypotCPP(K x, K y) {
    try {
        R kf(fdim(getVal(x), getVal(y)));
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

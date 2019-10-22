#include <iostream>
#include <cmath>

#define KXVER 3
#include "k.h"

#define tryCatch(x) try{R x;} catch(const char* &p) {R krr((S) p);} 

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
    tryCatch(kf(hypot(getVal(x), getVal(y))));
 }

K fdimCPP(K x, K y) {
    tryCatch(kf(fdim(getVal(x), getVal(y))));
 }

K erfCPP(K x) {
    tryCatch(kf(erf(getVal(x))));
 }

K tgammaCPP(K x) {
    tryCatch(kf(tgamma(getVal(x))));
 }

}

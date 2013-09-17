/** 
 * Fonctions et macros générales utiles
 * 
 * @author Philippe TILLET phil.tillet@gmail.com
 * @author Marc BLANC-PATIN marc.blancpatin@gmail.com
 * 
 */
#ifndef UTILS_H
#define UTILS_H

template<class T>
T max(T a, T b) {
    if (a > b) {
        return a;
    }
    return b;
}

template<class T>
T min(T a, T b) {
    if (a < b) {
        return a;
    }
    return b;
}

#endif

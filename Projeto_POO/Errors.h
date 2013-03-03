/* 
 * File:   Errors.h
 * Author: Vitor
 *
 * Created on 3 de Março de 2013, 13:43
 */

#ifndef ERRORS_H
#define	ERRORS_H


#include <string>
using namespace std;

class PercistenceError {
    string erro;
public:
    string what();
    PercistenceError(string);
};

inline PercistenceError::PercistenceError(string erro) {
    this->erro = erro;
}

inline string PercistenceError::what(string erro) {
    return this->erro;
}

class LogicError {
    string erro;
public:
    string what();
    LogicError(string);
};

inline LogicError::LogicError(string erro) {
    this->erro = erro;
}

inline string LogicError::what(string erro) {
    return this->erro;
}

#endif	/* ERRORS_H */


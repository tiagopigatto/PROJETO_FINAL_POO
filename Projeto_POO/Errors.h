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
/** \class PercistenceError
 *  \brief Essa é a classe responsável por gerir os erros que podem aparecer na camada de persitência 
 */
class PercistenceError {
    string erro;    /**< Variavel que armazena o erro*/
public:
    /*! \fn what()
     *  \brief Funcao que recebe o erro da camada de persistência 
     */      
    string what();  
    /*! \fn PercistenceError(string)
     *  \brief Funcao que descobre o que o erro enviado pela persitência significa 
     *  \param string : erro da lógica da persistência.
     */       
    PercistenceError(string);
};

inline PercistenceError::PercistenceError(string erro) {
    this->erro = erro;
}

inline string PercistenceError::what(string erro) {
    return this->erro;
}
/** \class LogicError
 *  \brief Essa é a classe responsável por gerir os erros que podem aparecer na camada de persitência 
 */
class LogicError {
    string erro;    /**< Variavel que armazena o erro*/
public:
    /*! \fn what()
     *  \brief Funcao que recebe o erro da camada lógica de negócio 
     */      
    string what();  
    /*! \fn LogicError(string)
     *  \brief Funcao que descobre o que o erro enviado pela lógica de negócio significa
     *  \param string : erro da lógica de negócio. 
     */     
    LogicError(string);
};

inline LogicError::LogicError(string erro) {
    this->erro = erro;
}

inline string LogicError::what(string erro) {
    return this->erro;
}

#endif	/* ERRORS_H */


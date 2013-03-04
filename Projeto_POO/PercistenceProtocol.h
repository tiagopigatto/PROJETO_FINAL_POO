/**
 * \file   PercistenseProtocol.h
 * \brief  Esta é classe que será responsável por inicializar a camada de persistência 
 */


#ifndef PERCISTENCEPROTOCOL_H
#define	PERCISTENCEPROTOCOL_H

#include "Comand.h"
#include "Errors.h"
/*! \class PercistenceProtocol
 *  \brief Essa é a classe abstrata que gera os métodos que serão usados camada de persistência
 */
class PercistenceProtocol
{
public:

    /*! \fn virtual void exec(ACommand *) throw (PercistenceError)
     *  \brief Método responsável por inicializar a classe
     *	\param ACommand = Comando abstrato
     */           	
    virtual void exec(ACommand *) throw (PercistenceError) = 0;
    /*! \fn virtual ~PercistenceProtocol(){}
     *  \brief Método responsável por descontruir a classe
     */    
    virtual ~PercistenceProtocol(){}
};


#endif	/* PERCISTENCEPROTOCOL_H */


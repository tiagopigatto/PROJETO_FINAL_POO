/**
 * \file   PercistenceProtocol.h
 * \brief  Este e o cabecalho do
 * \n protocolo de persistencia.\n
  */

#ifndef PERCISTENCEPROTOCOL_H
#define	PERCISTENCEPROTOCOL_H

#include "Comand.h"
#include "Errors.h"

/** \class PersistenceProtocol
 *  \brief Essa e a classe responsavel por criar um protocolo de persitência
 */
class PercistenceProtocol
{
public:
    /** \fn   virtual void exec(ACommand *) throw (PercistenceError) = 0;
     *  \brief executar um comando abstrato implementando design pattern command
     */
    virtual void exec(ACommand *) throw (PercistenceError) = 0;

        /** \fn virtual ~PercistenceProtocol(){}
     *  \brief Destruidora do protocolo
     */

    virtual ~PercistenceProtocol(){}
};


#endif	/* PERCISTENCEPROTOCOL_H */


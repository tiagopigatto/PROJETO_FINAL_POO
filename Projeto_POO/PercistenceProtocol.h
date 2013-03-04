/* 
 * File:   PercistenceProtocol.h
 * Author: Vitor
 *
 * Created on 2 de Março de 2013, 18:06
 */

#ifndef PERCISTENCEPROTOCOL_H
#define	PERCISTENCEPROTOCOL_H

#include "Comand.h"
#include "Errors.h"

class PercistenceProtocol
{
public:
    virtual void exec(ACommand *) throw (PercistenceError) = 0;
    virtual ~PercistenceProtocol(){}
};


#endif	/* PERCISTENCEPROTOCOL_H */


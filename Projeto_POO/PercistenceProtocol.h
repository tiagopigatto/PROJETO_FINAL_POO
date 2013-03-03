/* 
 * File:   PercistenceProtocol.h
 * Author: Vitor
 *
 * Created on 2 de Março de 2013, 18:06
 */

#ifndef PERCISTENCEPROTOCOL_H
#define	PERCISTENCEPROTOCOL_H

#include "Percistencia.h"

class PercistenceProtocol
{
public:
    virtual ~PercistenceProtocol(){};
    virtual void exec(ACommand *);
};


#endif	/* PERCISTENCEPROTOCOL_H */


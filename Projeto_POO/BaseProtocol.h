/* 
 * File:   BaseProtocol.h
 * Author: Vitor
 *
 * Created on 2 de Março de 2013, 18:27
 */

#ifndef BASEPROTOCOL_H
#define	BASEPROTOCOL_H

class BaseProtocol
{
public:
    virtual ~ProtocoloInt(){};
    virtual void executar() = 0;
};


#endif	/* BASEPROTOCOL_H */


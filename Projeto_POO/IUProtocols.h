/* 
 * File:   IUProtocols.h
 * Author: Vitor
 *
 * Created on 2 de Março de 2013, 18:27
 */

#ifndef IUPROTOCOLS_H
#define	IUPROTOCOLS_H

#include "ProtocoloLN.h"

class BaseProtocol
{
public:
    virtual ~ProtocoloInt(){};
    virtual void executar() = 0;
};



class IUUserProtocol {
public:
    virtual User* exec(User*, int*) = 0;
    virtual void setLogicProtocol(UserProtocol *) = 0;
    virtual ~IUUserProtocol() = 0;
};

class IUComentProtocol {
public:
    virtual Coment* exec(User*, int*) = 0;
    virtual void setLogicProtocol(ComentProtocol *) = 0;
    virtual ~IUComentProtocol() = 0;
};

class IUPostProtocol {
public:
    virtual void exec(User*, int*) = 0;
    virtual void setLogicProtocol(PostProtocol *) = 0;
    virtual void ~IUPostProtocol() = 0;
};
#endif	/* IUPROTOCOLS_H */


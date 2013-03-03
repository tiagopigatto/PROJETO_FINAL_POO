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
    virtual void exec();
    virtual ~ProtocoloInt(){};
    virtual void executar() = 0;
};

class IUUserProtocol : BaseProtocol {
public:
    virtual void exec() = 0;
    virtual void setUser(User) = 0;
    virtual User getUser() = 0;
    virtual void setLogicProtocol(UserProtocol *) = 0;
    virtual ~IUUserProtocol() = 0;
};

class IUComentProtocol : BaseProtocol{
public:
    virtual void exec() = 0;    
    virtual void setLogicProtocol(ComentProtocol *) = 0;
    virtual ~IUComentProtocol() = 0;
};

class IUPostProtocol : BaseProtocol{
public:
    virtual void exec() = 0;
    virtual void setUser(User) = 0;
    virtual void setLogicProtocol(PostProtocol *) = 0;
    virtual void ~IUPostProtocol() = 0;
};
#endif	/* IUPROTOCOLS_H */


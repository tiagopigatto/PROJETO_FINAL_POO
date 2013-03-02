/* 
 * File:   IUProtocols.h
 * Author: Vitor
 *
 * Created on 2 de Março de 2013, 18:27
 */

#ifndef IUPROTOCOLS_H
#define	IUPROTOCOLS_H

#include "ProtocoloLN.h"
#include "BaseProtocol.h"

class IUUserProtocol : public BaseProtocol {
public:
    virtual void setLogicProtocol(UserProtocol *) = 0;
};

class IUComentProtocol : public BaseProtocol {
public:
    virtual void setLogicProtocol(ComentProtocol *) = 0;
};

class IUPostProtocol : public BaseProtocol {
public:
    virtual void setLogicProtocol(PostProtocol *) = 0;
};
#endif	/* IUPROTOCOLS_H */


/* 
 * File:   controler.h
 * Author: Vitor
 *
 * Created on 21 de Fevereiro de 2013, 01:41
 */

#ifndef PROTOCOLOS_H
#define	PROTOCOLOS_H

#include "TiposBasicos.h"
#include "BaseProtocol.h"
#include "PercistenceProtocol.h"

class UserProtocol : public BaseProtocol
{
public:
    virtual void cadastrar(User *) = 0;
    virtual void update(User *) = 0;
    virtual void deleta(Identify *) = 0;
    virtual User pesquisa(Identify *) = 0;
    virtual User pesquisa(UserName *) = 0;
    virtual void setPercistence(PercistenceProtocol *) = 0;

    ProtocoloUsuario(){}
    ~ProtocoloUsuario(){}

};

class ComentProtocol : public BaseProtocol
{
public:
    virtual void cadastrar(Coment *) = 0;
    virtual void update(Coment *) = 0;
    virtual void deleta(Identify *) = 0;
    virtual Coment pesquisa(Identify *) = 0;
    virtual void setPercistence(PercistenceProtocol *) = 0;
    
    ProtocoloComent(){};
    ~ProtocoloComent(){};

};

class PostProtocol : public BaseProtocol
{
public:
    virtual void cadastrar(Post *) = 0;
    virtual void update(Post *) = 0;
    virtual void deleta(Identify *) = 0;
    virtual Post pesquisa(Identify *) = 0;
    virtual void setPercistence(PercistenceProtocol *) = 0;
    
    ProtocoloPost(){};
    ~ProtocoloPost(){};
};
        

#endif	/* CONTROLER_H */


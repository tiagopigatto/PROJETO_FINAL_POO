/* 
 * File:   controler.h
 * Author: Vitor
 *
 * Created on 21 de Fevereiro de 2013, 01:41
 */

#ifndef PROTOCOLOS_H
#define	PROTOCOLOS_H

#include "Entidades.h"
#include "PercistenceProtocol.h"
#include <list>


class UserProtocol
{
public:
    virtual void autenticar(User *) = 0;
    virtual void cadastrar(User *) = 0;
    virtual void update(User *) = 0;
    virtual void deletar(User *) = 0;
    virtual list Listar() = 0;
    
    virtual void setPercistence(PercistenceProtocol *) = 0;
    
    virtual ~ProtocoloUsuario(){}
};

class PostProtocol : public BaseProtocol
{
public:
    virtual void novo(Post *) = 0;
    virtual void update(Post *) = 0;
    virtual void deleta(Post *) = 0;
    virtual list listar() = 0;
    virtual list listar(User *) = 0;
    
    virtual void setPercistence(PercistenceProtocol *) = 0;
    
    virtual ~ProtocoloPost(){};
};

class ComentProtocol : public BaseProtocol
{
public:
    virtual void novo(Coment *) = 0;
    virtual void update(Coment *) = 0;
    virtual void deleta(Coment *) = 0;
    virtual void pegar(Coment *) = 0;
    virtual list listar(Post *) = 0;
    
    virtual void setPercistence(PercistenceProtocol *) = 0;
    virtual ~ProtocoloComent(){};

};

        

#endif	/* CONTROLER_H */


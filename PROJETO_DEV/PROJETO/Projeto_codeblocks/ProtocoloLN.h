/**
 * \file   ProtocoloLN.h
 * \brief  Este e o cabecalho do modulo da classe ProtocoloLN
 * \n responsável por implementar os protocolos das controladoras \n
 */

#ifndef PROTOCOLOS_H
#define	PROTOCOLOS_H

#include "Entidades.h"
#include "PercistenceProtocol.h"
#include <list>

/** \class UserProtocol
 *  \brief Protocolo de controle da controladora de usuario
 */
class UserProtocol
{
public:
    virtual void autenticar(User) = 0;
    virtual void cadastrar(User) = 0;
    virtual void update(User) = 0;
    virtual void deletar(User) = 0;
    virtual list<User> Listar() = 0;

    virtual void setPercistence(PercistenceProtocol *) = 0;

    virtual ~UserProtocol(){}
};

class PostProtocol
{
public:
    virtual void novo(Post) = 0;
    virtual void update(Post) = 0;
    virtual void deleta(Post) = 0;
    virtual list<Post> listar() = 0;
    virtual list<Post> listarPorUser(Post) = 0;
    virtual Post pegar(Post) = 0;

    virtual void setPercistence(PercistenceProtocol *) = 0;

    virtual ~PostProtocol(){};
};

class ComentProtocol
{
public:
    virtual void novo(Coment) = 0;
    virtual void update(Coment) = 0;
    virtual void deleta(Coment) = 0;
    virtual Coment pegar(Coment) = 0;
    virtual list<Coment> listar(Coment) = 0;

    virtual void setPercistence(PercistenceProtocol *) = 0;
    virtual ~ComentProtocol(){};

};



#endif	/* CONTROLER_H */


/**
 * \file   IUProtocols.h
 * \brief  Este e o cabecalho do modulo das classes entidades que definem as
 * \n entidades do sistema neste caso estes sao:\n
 */

#ifndef IUPROTOCOLS_H
#define	IUPROTOCOLS_H

#include "ProtocoloLN.h"

/*! \class IUUserProtocol
 *  \brief Essa é a classe abstrata que gera os métodos que serão usados pelos protocolos de interface
 */
class IUUserProtocol{
public:
    /*! \fn void exec()
     *  \brief Método responsável por inicializar a classe
     */
    virtual void exec() = 0;

    /*! \fn void setUser()
     *  \brief Método responsável por setar usuario
     */
    virtual void setUser(User *) = 0;

    /*! \fn User* getUser()
     *  \brief Método responsável por pegar usuario
     */
    virtual User* getUser() = 0;

    /*! \fn voidsetLogicProtocol(UserProtocol *)
     *  \brief Método responsável por setar a llogica de percistencia
     */
    virtual void setLogicProtocol(UserProtocol *) = 0;

    /*! \fn ~IUUserProtocol()
     *  \brief Método responsável por destruir
     */
    virtual ~IUUserProtocol(){}
};

/*! \class IUPostProtocol
 *  \brief Essa é a classe abstrata que gera os métodos que serão usados pelos protocolos de interface
 */
class IUPostProtocol{
public:
    /*! \fn void exec()
     *  \brief Método responsável por inicializar a classe
     */
    virtual void exec() = 0;

    /*! \fn void setUser(User*)
     *  \brief Método responsável setar usuario
     */
    virtual void setUser(User*) = 0;

    /*! \fn Post* getPost()
     *  \brief Método responsável pegar o post
     */
    virtual Post* getPost() = 0;

    /*! \fn void setLogicProtocol()
     *  \brief Método responsável por inicializar a classe
     */
    virtual void setLogicProtocol(PostProtocol *) = 0;

    /*! \fn ~IUPostProtocol()
     *  \brief Método responsável por inicializar a classe
     */
    virtual ~IUPostProtocol(){}
};

/*! \class IUComentProtocol
 *  \brief Essa é a classe abstrata que gera os métodos que serão usados pelos protocolos de interface
 */
class IUComentProtocol{
public:
    /*! \fn void exec()
     *  \brief Método responsável por inicializar a classe
     */
    virtual void exec() = 0;

    /*! \fn void setUser(User*)
     *  \brief Método responsável por setar usuario
     */
    virtual void setUser(User*) = 0;

    /*! \fn void setPost(Post*)
     *  \brief Método responsável por setar post
     */
    virtual void setPost(Post*) = 0;

    /*! \fn void setLogicProtocol(ComentProtocol*)
     *  \brief Método responsável por setar a logica
     */
    virtual void setLogicProtocol(ComentProtocol *) = 0;

    /*! \fn ~IUComentProtocol()
     *  \brief Método responsável por destruir
     */
    virtual ~IUComentProtocol(){}
};


#endif	/* IUPROTOCOLS_H */


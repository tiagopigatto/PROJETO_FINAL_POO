/* 
 * File:   IUProtocols.h
 * Author: Vitor
 *
 * Created on 2 de Março de 2013, 18:27
 */

#ifndef IUPROTOCOLS_H
#define	IUPROTOCOLS_H

#include "ProtocoloLN.h"
/*! \class BaseProtocol
 *  \brief Essa é a classe abstrata que gera os métodos que serão usados pelos protocolos de interface
 */
class BaseProtocol
{
public:
    /*! \fn exec()
     *  \brief Método responsável por inicializar a classe
     */        
    virtual void exec();
    /*! \fn ~ProtocoloInt(){}
     *  \brief Método responsável por inicializar a classe
     */        
    virtual ~ProtocoloInt(){};
    /*! \fn executar()
     *  \brief Método responsável por inicializar a classe
     */        
    virtual void executar() = 0;
};
/*! \class BaseProtocol
 *  \brief Essa é a classe abstrata que gera os métodos que serão usados pelos protocolos de interface
 */
class IUUserProtocol : BaseProtocol {
public:
    /*! \fn exec()
     *  \brief Método responsável por inicializar a classe
     */        
    virtual void exec() = 0;
    virtual void setUser(User) = 0;
    virtual User getUser() = 0;
    virtual void setLogicProtocol(UserProtocol *) = 0;
    virtual ~IUUserProtocol() = 0;
};
/*! \class BaseProtocol
 *  \brief Essa é a classe abstrata que gera os métodos que serão usados pelos protocolos de interface
 */
class IUComentProtocol : BaseProtocol{
public:
    /*! \fn exec()
     *  \brief Método responsável por inicializar a classe
     */           
    virtual void exec() = 0;
    virtual void setUser(User) = 0;
    virtual void setPost(Post) = 0;
    virtual void setLogicProtocol(ComentProtocol *) = 0;
    virtual ~IUComentProtocol() = 0;
};
/*! \class BaseProtocol
 *  \brief Essa é a classe abstrata que gera os métodos que serão usados pelos protocolos de interface
 */
class IUPostProtocol : BaseProtocol{
public:
    /*! \fn exec()
     *  \brief Método responsável por inicializar a classe
     */          
    virtual void exec() = 0;
    virtual void setUser(User) = 0;
    virtual Post getPost() = 0;
    virtual void setLogicProtocol(PostProtocol *) = 0;
    virtual void ~IUPostProtocol() = 0;
};
#endif	/* IUPROTOCOLS_H */


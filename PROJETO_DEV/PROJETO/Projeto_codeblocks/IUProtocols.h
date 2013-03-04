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
class IUUserProtocol{
public:
    /*! \fn exec()
     *  \brief Método responsável por inicializar a classe
     */        
    virtual void exec() = 0;
    virtual void setUser(User *) = 0;
    virtual User* getUser() = 0;
    virtual void setLogicProtocol(UserProtocol *) = 0;
    virtual ~IUUserProtocol(){}
};

/*! \class BaseProtocol
 *  \brief Essa é a classe abstrata que gera os métodos que serão usados pelos protocolos de interface
 */
class IUPostProtocol{
public:
    /*! \fn exec()
     *  \brief Método responsável por inicializar a classe
     */          
    virtual void exec() = 0;
    virtual void setUser(User*) = 0;
    virtual Post* getPost() = 0;
    virtual void setLogicProtocol(PostProtocol *) = 0;
    virtual ~IUPostProtocol(){}
};

/*! \class BaseProtocol
 *  \brief Essa é a classe abstrata que gera os métodos que serão usados pelos protocolos de interface
 */
class IUComentProtocol{
public:
    /*! \fn exec()
     *  \brief Método responsável por inicializar a classe
     */           
    virtual void exec() = 0;
    virtual void setUser(User*) = 0;
    virtual void setPost(Post*) = 0;
    virtual void setLogicProtocol(ComentProtocol *) = 0;
    virtual ~IUComentProtocol(){}
};


#endif	/* IUPROTOCOLS_H */


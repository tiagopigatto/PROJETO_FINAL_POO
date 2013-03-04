/**
 * \file   IUProtocols.h
 * \brief  Esta é classe que será responsável por inicializar a camada de interface 
 */

#ifndef IUPROTOCOLS_H
#define	IUPROTOCOLS_H

#include "ProtocoloLN.h"
/*! \class IUUserProtocol
 *  \brief Essa é a classe abstrata que gera os métodos que serão usados pelos protocolos de interface
 */
class IUUserProtocol{
public:
    /*! \fn virtual void exec()
     *  \brief Método responsável por inicializar a classe
     */        
    virtual void exec() = 0;
    /*! \fn virtual void setUser(User *)
     *  \brief Método responsável por colocar um usário
     *  \param User = Objeto de usuário
     */        
    virtual void setUser(User *) = 0;
    /*! \fn virtual User* getUser()
     *  \brief Método responsável receber um usuário
     */        
    virtual User* getUser() = 0;
    /*! \fn virtual void setLogicProtocol(UserProtocol *) 
     *  \brief Método responsável por inicializar a camda lógica de usuário
     *  \param UserProtocol = Variavel que armazea o protocolo do usuário
     */        
    virtual void setLogicProtocol(UserProtocol *) = 0;
    /*! \fn virtual ~IUUserProtocol(){}
     *  \brief Método responsável por descontruir a classe
     */        
    virtual ~IUUserProtocol(){}
};

/*! \class IUPostProtocol
 *  \brief Essa é a classe abstrata que gera os métodos que serão usados pelos protocolos de interface
 */
class IUPostProtocol{
public:
    /*! \fn virtual void exec()
     *  \brief Método responsável por inicializar a classe
     */           
    virtual void exec() = 0;
    /*! \fn virtual void setUser(User *)
     *  \brief Método responsável por colocar um usário
     *  \param User = Objeto de usuário
     */    
    virtual void setUser(User*) = 0;
    /*! \fn vvirtual Post* getPost()
     *  \brief Método responsável receber um post
     */       
    virtual Post* getPost() = 0;
    /*! \fn virtual void setLogicProtocol(PostProtocol *) 
     *  \brief Método responsável por inicializar a camda lógica de postagem
     *  \param PostProtocol = Variavel que armazea o protocolo do post
     */        
    virtual void setLogicProtocol(PostProtocol *) = 0;
    /*! \fn virtual ~IUPostProtocol(){}
     *  \brief Método responsável por descontruir a classe
     */        
    virtual ~IUPostProtocol(){}
};

/*! \class IUComentProtocol
 *  \brief Essa é a classe abstrata que gera os métodos que serão usados pelos protocolos de interface
 */
class IUComentProtocol{
public:
    /*! \fn exec()
     *  \brief Método responsável por inicializar a classe
     */           
    virtual void exec() = 0;
    /*! \fn virtual void setUser(User *)
     *  \brief Método responsável por colocar um usário
     *  \param User = Objeto de usuário
     */    
    virtual void setUser(User*) = 0;
    /*! \fn virtual void setPost(Post*)
     *  \brief Método responsável por colocar um post
     *  \param Post = Objeto de postagem
     */ 
    virtual void setPost(Post*) = 0;
    /*! \fn  virtual void setLogicProtocol(ComentProtocol *)
     *  \brief Método responsável por inicializar a camda lógica de comentários
     *  \param ComentProtocol = Variavel que armazea o protocolo do comentário
     */        
    virtual void setLogicProtocol(ComentProtocol *) = 0;
    /*! \fn virtual ~IUComentProtocol(){}
     *  \brief Método responsável por descontruir a classe
     */       
    virtual ~IUComentProtocol(){}
};


#endif	/* IUPROTOCOLS_H */


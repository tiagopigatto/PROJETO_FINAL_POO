/**
 * \file   ProtocolLN.h
 * \brief  Esta é classe que será responsável por inicializar a camada de lógica de negócio 
 */


#ifndef PROTOCOLOS_H
#define	PROTOCOLOS_H

#include "Entidades.h"
#include "PercistenceProtocol.h"
#include <list>

/*! \class UserProtocol
 *  \brief Essa é a classe abstrata que gera os métodos que serão utilizados na camada de persistência de usuário
 */
class UserProtocol
{
public:
    /*! \fn virtual void autenticar(User)
     *  \brief Método responsável por autenticar um usário
     *  \param User = Objeto de usuário
     */  
    virtual void autenticar(User) = 0;
    /*! \fn virtual void cadastrar(User)
     *  \brief Método responsável por cadastrar um usário
     *  \param User = Objeto de usuário
     */  
    virtual void cadastrar(User) = 0;
    /*! \fn virtual void update(User)
     *  \brief Método responsável por atualizar um usário
     *  \param User = Objeto de usuário
     */  
    virtual void update(User) = 0;
    /*! \fn virtual void deletar(User)
     *  \brief Método responsável por deletar um usário
     *  \param User = Objeto de usuário
     */  
    virtual void deletar(User) = 0;
    /*! \fn virtual list<User> Listar()
     *  \brief Método responsável por listar os usários
     */      
    virtual list<User> Listar() = 0;
   /*! \fn virtual void setPercistence(PercistenceProtocol *)
     *  \brief Método responsável por inicializar a camada de persistência
     *  \param PercistenceProtocol = Variavel que armazea o protocolo do persitência
     */            
    virtual void setPercistence(PercistenceProtocol *) = 0;
    /*! \fn virtual ~UserProtocol(){}
     *  \brief Método responsável por descontruir a classe
     */     
    virtual ~UserProtocol(){}
};
/*! \class PercistenceProtocol
 *  \brief Essa é a classe abstrata que gera os métodos que serão usados camada de persistência
 */
class PostProtocol
{
public:
    /*! \fn virtual void novo(Post)
     *  \brief Método responsável por adicionar um post
     *  \param Post = Objeto de post
     */ 
    virtual void novo(Post) = 0;
    /*! \fn virtual void update(Post)
     *  \brief Método responsável por atualizar um post
     *  \param Post = Objeto de post
     */ 
    virtual void update(Post) = 0;
    /*! \fn virtual void deleta(Post)
     *  \brief Método responsável por deletar um post
     *  \param Post = Objeto de post
     */ 
    virtual void deleta(Post) = 0;
    /*! \fn virtual list<Post> listar()
     *  \brief Método responsável por listar todos os posts
     */ 
    virtual list<Post> listar() = 0;
    /*! \fn virtual list<Post> listarPorUser(Post)
     *  \brief Método responsável por listar os posts de um user
     *  \param Post = Objeto de post
     */ 
    virtual list<Post> listarPorUser(Post) = 0;
    /*! \fn virtual Post pegar(Post)
     *  \brief Método responsável por pegar um post
     *  \param Post = Objeto de post
     */ 
    virtual Post pegar(Post) = 0;
   /*! \fn virtual void setPercistence(PercistenceProtocol *)
     *  \brief Método responsável por inicializar a camada de persistência
     *  \param PercistenceProtocol = Variavel que armazea o protocolo do persitência
     */        
    virtual void setPercistence(PercistenceProtocol *) = 0;
    /*! \fn virtual ~PostProtocol(){}
     *  \brief Método responsável por descontruir a classe
     */        
    virtual ~PostProtocol(){};
};
/*! \class PercistenceProtocol
 *  \brief Essa é a classe abstrata que gera os métodos que serão usados camada de persistência
 */
class ComentProtocol
{
public:
    /*! \fn virtual void novo(Coment)
     *  \brief Método responsável por adicionar um coment
     *  \param Coment = Objeto de coment
     */ 
    virtual void novo(Coment) = 0;
    /*! \fn virtual void update(Coment)
     *  \brief Método responsável por atualizar um coment
     *  \param Coment = Objeto de coment
     */ 
    virtual void update(Coment) = 0;
    /*! \fn virtual void deleta(Coment)
     *  \brief Método responsável por deletar um coment
     *  \param Coment = Objeto de coment
     */ 
    virtual void deleta(Coment) = 0;
    /*! \fn virtual Coment pegar(Coment)
     *  \brief Método responsável por pegar um coment
     *  \param Coment = Objeto de coment
     */ 
    virtual Coment pegar(Coment) = 0;
    /*! \fn virtual list<Coment> listar(Coment)
     *  \brief Método responsável por listar os comentários de um post
     *  \param Coment = Objeto de coment
     */ 
    virtual list<Coment> listar(Coment) = 0;
   /*! \fn virtual void setPercistence(PercistenceProtocol *)
     *  \brief Método responsável por inicializar a camada de persistência
     *  \param PercistenceProtocol = Variavel que armazea o protocolo do persitência
     */     
    virtual void setPercistence(PercistenceProtocol *) = 0;
    /*! \fn virtual ~ComentProtocol(){}
     *  \brief Método responsável por descontruir a classe
     */   
    virtual ~ComentProtocol(){};

};

        

#endif	/* CONTROLER_H */


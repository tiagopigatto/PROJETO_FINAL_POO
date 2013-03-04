#ifndef LOGICA_NEGOCIO_H
#define	LOGICA_NEGOCIO_H

#include "Entidades.h"
#include "ProtocoloLN.h"
/*! \class LNUser 
 *  \brief Essa é a classe responsável pela lógica de negócios para um usuário.
 */
class LNUser : UserProtocol {
    private:
        PercistenceProtocol percistence;
public:
    /*! \fn autenticar(User)
     *  \brief Método responsável por autenticar um usuário
     *  \param User =  objeto de um usuário
     */     
    bool autenticar(User) = 0;
    /*! \fn cadastrar(User)
     *  \brief Método responsável por cadastar um usuário
     *  \param User =  objeto de um usuário
     */     
    void cadastrar(User) = 0;
    /*! \fn update(User)
     *  \brief Método responsável por atualizar um usuário
     *  \param User =  objeto de um usuário
     */     
    void update(User) = 0;
    /*! \fn deletar(User)
     *  \brief Método responsável por deletar um usuário
     *  \param User =  objeto de um usuário
     */     
    void deletar(User) = 0;
    /*! \fn Listar()
     *  \brief Método responsável por listar os usuários
     */     
    list Listar() = 0;

    /*! \fn setPercistence(PercistenceProtocol *)
     *  \brief Método responsável por ativar um protocolo de persitência
     *  \param PercistenceProtocol = protocolo de persitência  
     */ 
    void setPercistence(PercistenceProtocol *) = 0;
    /*! \fn LNUser
     *  \brief Método responsável por construir a classe  
     */ 
    LNUser() {
    };
    /*! \fn ~LNUser()
     *  \brief Método responsável por descontruir a classe  
     */ 
    ~LNUser() {
    };
};
/*! \class LNUser()
 *  \brief Essa é a classe responsável pela lógica de negócios para uma postagems.
 */
class LNPost : ComentProtocol {
public:
    /*! \fn novo(Post)
     *  \brief Método responsável por criar uma postagem
     *  \param Post =  objeto de um post
     */     
    void novo(Post) = 0;
    /*! \fn update(Post)
     *  \brief Método responsável por atualizar uma postagem
     *  \param Post =  objeto de um post
     */    
    void update(Post) = 0;
    /*! \fn deleta(Post)
     *  \brief Método responsável por deletar uma postagem
     *  \param Post =  objeto de um post
     */    
    void deleta(Post) = 0;
    /*! \fn listar(Post)
     *  \brief Método responsável por listar todas as postagens
     *  \param Post =  objeto de um post
     */    
    list listar(Identify) = 0;
    /*! \fn listarPorUser(Post)
     *  \brief Método responsável por listar as postagens por usuário 
     *  \param Post =  objeto de um post
     */    
    list listarPorUser(Identify) = 0;
    /*! \fn setPercistence(PercistenceProtocol *)
     *  \brief Método responsável por ativar um protocolo de persitência
     *  \param PercistenceProtocol = protocolo de persitência  
     */ 
    void setPercistence(PercistenceProtocol *) = 0;
    /*! \fn LNComent()
     *  \brief Método responsável por construir a classe  
     */ 
    LNComent();
    /*! \fn ~LNComent()
     *  \brief Método responsável por construir a classe  
     */ 
    ~LNComent();

};

class LNComent : PostProtocol {
public:
     /*! \fn novo(Coment)
     *  \brief Método responsável por criar uma comentário
     *  \param Coment =  objeto de um comentário
     */ 
    void novo(Coment) = 0;
     /*! \fn update(Coment)
     *  \brief Método responsável por atualizar um comentário
     *  \param Coment =  objeto de um comentário
     */ 
    void update(Coment) = 0;
     /*! \fn deleta(Coment)
     *  \brief Método responsável por deletar uma comentário
     *  \param Coment =  objeto de um comentário
     */ 
    void deleta(Coment) = 0;
     /*! \fn pegar(Coment)
     *  \brief Método responsável por pegar uma comentário
     *  \param Coment =  objeto de um comentário
     */ 
    void pegar(Coment) = 0;
     /*! \fn listar(Post)
     *  \brief Método responsável por listar todos os comentários de um post
     *  \param Coment =  objeto de um comentário
     */ 
    list listar(Post) = 0;
    /*! \fn setPercistence(PercistenceProtocol *)
     *  \brief Método responsável por ativar um protocolo de persitência
     *  \param PercistenceProtocol = protocolo de persitência  
     */ 
    virtual void setPercistence(PercistenceProtocol *) = 0;
    /*! \fn LNPost()
     *  \brief Método responsável por construir a classe  
     */ 
    LNPost();
    /*! \fn ~LNPost()
     *  \brief Método responsável por construir a classe  
     */ 
    ~LNPost();

};


#endif	/* LOGOCANEGOCIO_H */


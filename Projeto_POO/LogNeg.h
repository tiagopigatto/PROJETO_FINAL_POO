#ifndef LOGICA_NEGOCIO_H
#define	LOGICA_NEGOCIO_H

#include "Entidades.h"
#include "ProtocoloLN.h"
#include <stdexcept>
#include <iostream>
#include <string>


using namespace std;

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
    void autenticar(User);
    /*! \fn cadastrar(User)
     *  \brief Método responsável por cadastar um usuário
     *  \param User =  objeto de um usuário
     */
    void cadastrar(User);
    /*! \fn update(User)
     *  \brief Método responsável por atualizar um usuário
     *  \param User =  objeto de um usuário
     */
    void update(User);
    /*! \fn deletar(User)
     *  \brief Método responsável por deletar um usuário
     *  \param User =  objeto de um usuário
     */
    void deletar(User);
    /*! \fn Listar()
     *  \brief Método responsável por listar os usuários
     */
    list Listar();

    /*! \fn setPercistence(PercistenceProtocol *)
     *  \brief Método responsável por ativar um protocolo de persitência
     *  \param PercistenceProtocol = protocolo de persitência  
     */
    void setPercistence(PercistenceProtocol *);

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
private:
    PercistenceProtocol percistence;
public:
    /*! \fn novo(Post)
     *  \brief Método responsável por criar uma postagem
     *  \param Post =  objeto de um post
     */
    void novo(Post);
    /*! \fn update(Post)
     *  \brief Método responsável por atualizar uma postagem
     *  \param Post =  objeto de um post
     */
    void update(Post);
    /*! \fn deleta(Post)
     *  \brief Método responsável por deletar uma postagem
     *  \param Post =  objeto de um post
     */
    void deleta(Post);
    /*! \fn listar(Post)
     *  \brief Método responsável por listar todas as postagens
     *  \param Post =  objeto de um post
     */
    list listar();
    /*! \fn listarPorUser(Post)
     *  \brief Método responsável por listar as postagens por usuário 
     *  \param Post =  objeto de um post
     */
    list listarPorUser(User usuario);
    /*! \fn pegar(Post)
     *  \brief Método responsável por pegar uma postagens
     *  \param Post =  objeto de um post
     */
    Post pegar(Post);


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
private:
    PercistenceProtocol percistence;
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
    Coment pegar(Coment) = 0;
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


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
    /*! \fn void autenticar(User)
     *  \brief Método responsável por autenticar um usuário
     *  \param User =  objeto de um usuário
     */
    void autenticar(User);
    /*! \fn void cadastrar(User)
     *  \brief Método responsável por cadastar um usuário
     *  \param User =  objeto de um usuário
     */
    void cadastrar(User);
    /*! \fn void update(User)
     *  \brief Método responsável por atualizar um usuário
     *  \param User =  objeto de um usuário
     */
    void update(User);
    /*! \fn void deletar(User)
     *  \brief Método responsável por deletar um usuário
     *  \param User =  objeto de um usuário
     */
    void deletar(User);
    /*! \fn list Listar()
     *  \brief Método responsável por listar os usuários
     */
    list Listar();

    /*! \fn void setPercistence(PercistenceProtocol *)
     *  \brief Método responsável por ativar um protocolo de persitência
     *  \param PercistenceProtocol = protocolo de persitência  
     */
    void setPercistence(PercistenceProtocol *);

    /*! \fn LNUser()
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
    /*! \fn void novo(Post)
     *  \brief Método responsável por criar uma postagem
     *  \param Post =  objeto de um post
     */
    void novo(Post);
    /*! \fn void update(Post);
     *  \brief Método responsável por atualizar uma postagem
     *  \param Post =  objeto de um post
     */
    void update(Post);
    /*! \fn void deleta(Post)
     *  \brief Método responsável por deletar uma postagem
     *  \param Post =  objeto de um post
     */
    void deleta(Post);
    /*! \fn list listar()
     *  \brief Método responsável por listar todas as postagens
     */
    list listar();
    /*! \fn list listarPorUser(User usuario)
     *  \brief Método responsável por listar as postagens por usuário 
     *  \param usuario = Objeto de um usuário
     */
    list listarPorUser(User usuario);
    /*! \fn Post pegar(Post);
     *  \brief Método responsável por pegar uma postagens
     *  \param Post =  objeto de um post
     */
    Post pegar(Post);


    /*! \fn void setPercistence(PercistenceProtocol *) = 0;
     *  \brief Método responsável por ativar um protocolo de persitência
     *  \param PercistenceProtocol = protocolo de persitência  
     */
    void setPercistence(PercistenceProtocol *);
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
    /*! \fn oid novo(Coment)
     *  \brief Método responsável por criar uma comentário
     *  \param Coment =  objeto de um comentário
     */
    void novo(Coment);
    /*! \fn void update(Coment)
     *  \brief Método responsável por atualizar um comentário
     *  \param Coment =  objeto de um comentário
     */
    void update(Coment);
    /*! \fn void deleta(Coment)
     *  \brief Método responsável por deletar uma comentário
     *  \param Coment =  objeto de um comentário
     */
    void deleta(Coment);
    /*! \fn  Coment pegar(Coment)
     *  \brief Método responsável por pegar uma comentário
     *  \param Coment =  objeto de um comentário
     */
    Coment pegar(Coment);
    /*! \fn list listar(Post)
     *  \brief Método responsável por listar todos os comentários de um post
     *  \param Coment =  objeto de um comentário
     */
    list listar(Post);
    /*! \fn virtual void setPercistence(PercistenceProtocol *)
     *  \brief Método responsável por ativar um protocolo de persitência
     *  \param PercistenceProtocol = protocolo de persitência  
     */
    virtual void setPercistence(PercistenceProtocol *);
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


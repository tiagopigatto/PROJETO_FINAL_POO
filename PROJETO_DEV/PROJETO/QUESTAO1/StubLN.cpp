#ifndef TIME
#define TIME

#include "Entidades.h"
#include "ProtocoloLN.h"
#include "Comand.h"
#include "Errors.h"
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

class LNUser : UserProtocol {
private:
    PercistenceProtocol *percistence;
public:
    /*! \fn autenticar(User)
     *  \brief M�todo respons�vel por autenticar um usu�rio
     *  \param User =  objeto de um usu�rio
     */
    void autenticar(User);
    /*! \fn cadastrar(User)
     *  \brief M�todo respons�vel por cadastar um usu�rio
     *  \param User =  objeto de um usu�rio
     */
    void cadastrar(User);
    /*! \fn update(User)
     *  \brief M�todo respons�vel por atualizar um usu�rio
     *  \param User =  objeto de um usu�rio
     */
    void update(User);
    /*! \fn deletar(User)
     *  \brief M�todo respons�vel por deletar um usu�rio
     *  \param User =  objeto de um usu�rio
     */
    void deletar(User);
    /*! \fn Listar()
     *  \brief M�todo respons�vel por listar os usu�rios
     */
    list<User> Listar();

    /*! \fn setPercistence(PercistenceProtocol *)
     *  \brief M�todo respons�vel por ativar um protocolo de persit�ncia
     *  \param PercistenceProtocol = protocolo de persit�ncia
     */
    void setPercistence(PercistenceProtocol *) {
    };

    /*! \fn LNUser
     *  \brief M�todo respons�vel por construir a classe
     */
    LNUser() {
    };

    /*! \fn ~LNUser()
     *  \brief M�todo respons�vel por descontruir a classe
     */
    ~LNUser() {
    };
};

void autenticar(User user) {
    string nome;
    UserName usuario;
    nome = user.getName().getValue();
    if (nome == "Pedro") {
        throw new LogicError("erro");
    }
}

void cadastrar(User user) {
};

void update(User user) {
};

void deletar(User) {
};

list<User> Listar() {
    User user;
    int i;
    std::list<User> lista;

    user.getName().setValue("vitor");
    user.getPassword().setValue("12345");
    user.getIdentify().setValue("123456");
    lista.push_back(user);

    user.getName().setValue("vitor1");
    user.getPassword().setValue("1234534");
    user.getIdentify().setValue("12345624");
    lista.push_back(user);

    user.getName().setValue("vito213r");
    user.getPassword().setValue("12321345");
    user.getIdentify().setValue("1234543546");
    lista.push_back(user);

    user.getName().setValue("vito2134214r");
    user.getPassword().setValue("12321421445");
    user.getIdentify().setValue("12345621");
    lista.push_back(user);

    user.getName().setValue("vi4214rdas");
    user.getPassword().setValue("vit214rsda");
    user.getIdentify().setValue("12312445");
    lista.push_back(user);

    return lista;
}

/*! \class LNUser()
 *  \brief Essa � a classe respons�vel pela l�gica de neg�cios para uma postagems.
 */
class LNPost : PostProtocol {
public:
    /*! \fn novo(Post)
     *  \brief M�todo respons�vel por criar uma postagem
     *  \param Post =  objeto de um post
     */
    void novo(Post);
    /*! \fn update(Post)
     *  \brief M�todo respons�vel por atualizar uma postagem
     *  \param Post =  objeto de um post
     */
    void update(Post);
    /*! \fn deleta(Post)
     *  \brief M�todo respons�vel por deletar uma postagem
     *  \param Post =  objeto de um post
     */
    void deleta(Post);
    /*! \fn listar(Post)
     *  \brief M�todo respons�vel por listar todas as postagens
     *  \param Post =  objeto de um post
     */
    list<Post> listar();
    /*! \fn listarPorUser(Post)
     *  \brief M�todo respons�vel por listar as postagens por usu�rio
     *  \param Post =  objeto de um post
     */
    list<Post> listarPorUser(Post);
    /*! \fn setPercistence(PercistenceProtocol *)
     *  \brief M�todo respons�vel por ativar um protocolo de persit�ncia
     *  \param PercistenceProtocol = protocolo de persit�ncia
     */
    void setPercistence(PercistenceProtocol *);

    /*! \fn LNComent()
     *  \brief M�todo respons�vel por construir a classe
     */
    LNPost() {
    };

    /*! \fn ~LNComent()
     *  \brief M�todo respons�vel por construir a classe
     */
    ~LNPost() {
    };

};

void novo(Post) {
};

void update(Post) {
};

void deleta(Post) {
};

list<Post> listarPorUser(Identify) {
    std::list<Post> lista;

    return lista;
};

list<Post> LNPost::listar() {
    Post post;
    int i;
    std::list<Post> lista;
    post.getAuthorIdentify().setValue("11112222");
    post.getPostText().setValue("sdasdasdasj");
    post.getPostIdentify().setValue("12223344");
    lista.push_back(post);


    post.getAuthorIdentify().setValue("111122334");
    post.getPostText().setValue("112334443254325324");
    post.getPostIdentify().setValue("213123712");
    lista.push_back(post);


    post.getAuthorIdentify().setValue("23123123");
    post.getPostText().setValue("23123123");
    post.getPostIdentify().setValue("23123123");
    lista.push_back(post);


    post.getAuthorIdentify().setValue("231231233123");
    post.getPostText().setValue("231231233123");
    post.getPostIdentify().setValue("231231233123");
    lista.push_back(post);




};

class LNComent : ComentProtocol {
public:
    /*! \fn novo(Coment)
     *  \brief M�todo respons�vel por criar uma coment�rio
     *  \param Coment =  objeto de um coment�rio
     */
    void novo(Coment);
    /*! \fn update(Coment)
     *  \brief M�todo respons�vel por atualizar um coment�rio
     *  \param Coment =  objeto de um coment�rio
     */
    void update(Coment);
    /*! \fn deleta(Coment)
     *  \brief M�todo respons�vel por deletar uma coment�rio
     *  \param Coment =  objeto de um coment�rio
     */
    void deleta(Coment);
    /*! \fn pegar(Coment)
     *  \brief M�todo respons�vel por pegar uma coment�rio
     *  \param Coment =  objeto de um coment�rio
     */
    Coment pegar(Coment);
    /*! \fn listar(Post)
     *  \brief M�todo respons�vel por listar todos os coment�rios de um post
     *  \param Coment =  objeto de um coment�rio
     */
    list<Coment> listar();

    /*! \fn setPercistence(PercistenceProtocol *)
     *  \brief M�todo respons�vel por ativar um protocolo de persit�ncia
     *  \param PercistenceProtocol = protocolo de persit�ncia
     */
    virtual void setPercistence(PercistenceProtocol *) {
    };

    /*! \fn LNPost()
     *  \brief M�todo respons�vel por construir a classe
     */
    LNComent() {
    }

    /*! \fn ~LNPost()
     *  \brief M�todo respons�vel por construir a classe
     */
    ~LNComent() {
    }

};

void novo(Coment coment) {
};

void update(Coment coment) {
};

void deleta(Coment coment) {
};

Coment pegar(Coment comento) {
    Coment coment;
        coment.getAuthorIdentify().setValue("123124");
        coment.getComentText().setValue("123124");
        coment.getPostIdentify().setValue("123124");
        coment.getComentIdentify().setValue("123124");
        return coment;
};

list<Coment>  LNComent::listar() {
    Coment coment;
    int i;
    std::list<Coment> lista;
    for (i = 0; i < 5; i++) {
        coment.getAuthorIdentify().setValue("123124");
        coment.getComentText().setValue("123124");
        coment.getPostIdentify().setValue("123124");
        coment.getComentIdentify().setValue("123124");
        lista.push_back(coment);
    }
    return lista;
}
#endif
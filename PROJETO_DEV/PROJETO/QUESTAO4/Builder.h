/**
 * \file   Builder.h
 * \brief  Este e o cabecalho do modulo das classe Builder que será
 * \n responsável por realizar a intengração de todas as classes do programa \n
 */

#ifndef BUILDER
#define BUILDER



#include "IUProtocols.h"

#include "InterUsu.h"
#include "StubLN.cpp"


/** \class Builder
 *  \brief Essa e a classe responsavel por ser linkar as classes do programa.
 */
class Builder {
private:
    //Functions
    //Start Protocolo IU

    /*! \fn IUUserProtocol* startIUUserProtocol()
     *  \brief Funcao contrutora responsável por incializar a controladora de usuário que poderá ser controlada pelo protocolo de controle de usuário
     */
    IUUserProtocol* startIUUserProtocol();
    /*! \fn IUComentProtocol* startIUComentProtocol()
     *  \brief Funcao contrutora responsável por incializar a controladora de comentário que poderá ser controlada pelo protocolo de controle de comentário
     */
    IUComentProtocol* startIUComentProtocol();
    /*! \fn IUPostProtocol startIUPostProtocol()
     *  \brief Funcao contrutora responsável por incializar a controladora de post que poderá ser controlada pelo protocolo de controle de post
     */
    IUPostProtocol* startIUPostProtocol();

    //Star Protocolos LN
    /*! \fn UserProtocol* startUserProtocol()
     *  \brief Função contrutora da camada lógica de negócio de usuário
     */
    UserProtocol* startUserProtocol();
    /*! \fn ComentProtocol* startComentProtocol()
     *  \brief Função contrutora da camada lógica de negócio de comentário
     */
    ComentProtocol* startComentProtocol();
    /*! \fn PostProtocol* startPostProtocol()
     *  \brief Função contrutora da camada lógica de negócio de post
     */
    PostProtocol* startPostProtocol();

    //Start Protocol de Percistence
    /*! \fn PercistenceProtocol* startPercistenceProtocol()
     *  \brief Funcao contrutora responsável por incializar a camda de persistência
     */
    PercistenceProtocol* startPercistenceProtocol();

    //controladoras
    /*! \fn InitialIUControler* startIUControler()
     *  \brief Funcao responsável por iniciar a classe que irá controlar as interfaces
     */
    InitialIUControler* startIUControler();

    //Variaveis de Instacia
    //protocolos de InterfaceUsuario
    IUUserProtocol *iuUserProtocol;     /**< Variavel que contém o protocolo da interface de usuário User*/
    IUComentProtocol *iuComentProtocol; /**< Variavel que contém o  protocolo da interface de usuário Comentário*/
    IUPostProtocol *iuPostProtocol;     /**< Variavel que contém o  protocolo da interface de usuário Post*/

    //protocolos de Logica de Negocio
    UserProtocol *usersProtocol;        /**< Variavel que contém o protocolo da lógica de negócio User*/
    ComentProtocol *comentsProtocol;    /**< Variavel que contém o protocolo da lógica de negócio Coment*/
    PostProtocol *postsProtocol;        /**< Variavel que contém o protocolo da lógica de negócio Post*/

    //protocolos de Percistencia

    //Controladoras de Interface Usuario
    InitialIUControler *initialIUControler;     /**< Variavel que contém o protocolo da interface de usuário principal*/

public:
    Builder();
    ~Builder();
};

#endif

inline IUUserProtocol* Builder::startIUUserProtocol() {
    return new UserControler();
}

inline IUComentProtocol* Builder::startIUComentProtocol() {
    return new ComentControler();
};

inline IUPostProtocol* Builder::startIUPostProtocol() {
    return new PostControler();
};

inline UserProtocol* Builder::startUserProtocol() {
    return new LNUser();
}

inline PostProtocol* Builder::startPostProtocol() {
    return new LNPost();
}

inline ComentProtocol* Builder::startComentProtocol() {
    return new LNComent();
}

inline PercistenceProtocol* Builder::startPercistenceProtocol() {
    return new PersistenceControler();
}

inline InitialIUControler* Builder::startIUControler() {
    return new InitialIUControler();
}

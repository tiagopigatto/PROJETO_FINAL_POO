#ifndef LOGICA_NEGOCIO_H
#define	LOGICA_NEGOCIO_H

#include "Entidades.h"
#include "ProtocoloLN.h"

class LNUser : UserProtocol {
    private:
        PercistenceProtocol percistence;
public:
    void autenticar(User *) = 0;
    void cadastrar(User *) = 0;
    void update(User *) = 0;
    void deletar(User *) = 0;
    list Listar() = 0;

    void setPercistence(PercistenceProtocol *) = 0;

    LNProjeto() {
    };

    ~LNProjeto() {
    };
};

class LNPost : ComentProtocol {
public:
    void novo(Post *) = 0;
    void update(Post *) = 0;
    void deleta(Post *) = 0;
    list listar(Identify *) = 0;
    list listarPorUser(Identify *) = 0;

    void setPercistence(PercistenceProtocol *) = 0;

    LNComent();
    ~LNComent();

};

class LNComent : PostProtocol {
public:
    void novo(Coment *) = 0;
    void update(Coment *) = 0;
    void deleta(Coment *) = 0;
    void pegar(Coment *) = 0;
    list listar(Post *) = 0;

    virtual void setPercistence(PercistenceProtocol *) = 0;

    LNPost();
    ~LNPost();

};


#endif	/* LOGOCANEGOCIO_H */


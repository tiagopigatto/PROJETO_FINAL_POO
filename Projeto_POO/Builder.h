#ifndef BUILDER
#define BUILDER

#include "ProtocoloLN.h"
#include "PercistenceProtocol.h"
#include "IUProtocols.h"

#include "InterUsu.h"

class Builder {
private:
    //Functions
    //Start Protocolo IU
    IUUserProtocol* startIUUserProtocol();
    IUComentProtocol* startIUComentProtocol();
    IUPostProtocol* startIUPostProtocol();

    //Star Protocolos LN
    UserProtocol* startUserProtocol();
    ComentProtocol* startComentProtocol();
    PostProtocol* startPostProtocol();

    //Start Protocol de Percistence
    PercistenceProtocol* startPercistenceProtocol();

    //controladoras
    InitialIUControler* startIUControler();

    //Variaveis de Instacia
    //protocolos de InterfaceUsuario
    IUUserProtocol *iuUserProtocol;
    IUComentProtocol *iuComentProtocol;
    IUPostProtocol *iuPostProtocol;

    //protocolos de Logica de Negocio
    UserProtocol *usersProtocol;
    ComentProtocol *comentsProtocol;
    PostProtocol *postsProtocol;

    //protocolos de Percistencia
    PercistenceProtocol *percistenceProtocol;

    //Controladoras de Interface Usuario
    InitialIUControler *initialIUControler;

public:
    Builder();
    ~Builder();
};

#endif

inline IUUserProtocol* Builder::startIUUserProtocol() {
    return new IUUserProtocol();
}

inline IUComentProtocol* Builder::startIUComentProtocol() {
    return new IUComentProtocol();
};

inline IUPostProtocol* Builder::startIUPostProtocol() {
    return new IUPostProtocol();
};

inline UserProtocol* Builder::startUserProtocol() {
    return new UserProtocol();
}

inline PostProtocol* Builder::startPostProtocol() {
    return new PostProtocol();
}

inline ComentProtocol* Builder::startPostProtocol() {
    return new ComentProtocol();
}

inline PercistenceProtocol* Builder::startPercistenceProtocol() {
    return new PercistenceProtocol();
}

inline InitialIUControler* Builder::startIUControler() {
    return new InitialIUControler();
}
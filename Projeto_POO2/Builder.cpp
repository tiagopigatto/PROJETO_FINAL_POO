
#include "Builder.h"

Builder::Builder() {
    //startando protocolos de Percistencia
    this->percistenceProtocol = this->startPercistenceProtocol();

    //startando Controladora Base
    this->usersProtocol = this->startUserProtocol();
    this->postsProtocol = this->startPostProtocol();
    this->comentsProtocol = this->startComentProtocol();

    //setando os protocolos de percistencia na logica
    this->usersProtocol->setPercistence(this->percistenceProtocol);
    this->comentsProtocol->setPercistence(this->percistenceProtocol);
    this->postsProtocol->setPercistence(this->percistenceProtocol);

    //startando protocolos de IU
    this->iuUserProtocol = this->startIUUserProtocol();
    this->iuPostProtocol = this->startIUPostProtocol();
    this->iuComentProtocol = this->startIUComentProtocol();

    //setando os protocolos de logica na iu
    this->iuUserProtocol->setLogicProtocol(this->usersProtocol);
    this->iuComentProtocol->setLogicProtocol(this->comentsProtocol);
    this->iuPostProtocol->setLogicProtocol(this->postsProtocol);

    //startando a controladora
    this->initialIUControler = this->startIUControler();

    //setando os protocolos das outras interfaces
    this->initialIUControler->setUserProtocol(this->iuUserProtocol);
    this->initialIUControler->setComentProtocol(this->iuComentProtocol);
    this->initialIUControler->setPostProtocol(this->iuPostProtocol);

    //comencando

    this->initialIUControler->exec();
}

Builder::~Builder() {
    delete this->initialIUControler;

    delete this->iuComentProtocol;
    delete this->iuPostProtocol;
    delete this->iuUserProtocol;

    delete this->postsProtocol;
    delete this->usersProtocol;
    delete this->comentsProtocol;

    delete this->percistenceProtocol;
}
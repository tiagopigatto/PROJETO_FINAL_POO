#ifndef TESTEUSU
#include "LogNeg.h"

void LNUser::autenticar(User* usuario)
{
    try{
        
    UserCommand command = new CommandPegaUser(usuario);
    percistence->exec(command);
    
    catch(Invalid_Argument e)
    {
        
    }
    
    
    
}

void LNUser::cadastrar(User*) {

}

void LNUser::deletar(User*) {

}

void LNUser::update(User*) {

}

list LNUser::Listar(Identify*) {

}

void LNUser::setPercistence(PercistenceProtocol *percistence) {
    this->percistence = percistence;
}

void LNPost::novo(Post*) {

}

void LNPost::deleta(Identify*) {
}

void LNPost::update(Post*) {

}

Post LNPost::listar(Identify*) {
}


void LNComent::novo(Coment*) {

}

void LNComent::deleta(Identify*) {

}

void LNComent::update(Coment*) {

}

Coment LNComent::listar(Identify*) {

}

#endif
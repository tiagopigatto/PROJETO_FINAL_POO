#ifndef TESTEUSU
#include "LogNeg.h"

bool LNUser::autenticar(User usuario) {
    User bancoUser;
    UserCommand *command;
    try {
        command = new CommandFindUser();
        command->setUser(usuario);
        percistence->exec(command);
        bancoUser = command->getUser();
    } catch (Invalid_Argument e) {

    }
    if(bancoUser.getName().getValue() == usuario.getName().getValue())
    {
       if(bancoUser.getIdentify().getValue() == usuario.getIdentify().getValue())
       {
           if(bancoUser.getPassword().getValue() == usuario.getPassword().getValue()){
               return true;
           }
       }
    }
    return false;


}

void LNUser::cadastrar(User* usuario) {
    UserCommand *command;
    try {
        command = new CommandCreateUser();
        command->setUser(usuario);
        percistence->exec(command);
        bancoUser = command->getUser();
    } catch (Invalid_Argument e) {

    }
}

void LNUser::deletar(User* usuario) {
    UserCommand *command;
    try {
        command = new CommandDeleteUser();
        command->setUser(usuario);
        percistence->exec(command);
        bancoUser = command->getUser();
    } catch (Invalid_Argument e) {

    }
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
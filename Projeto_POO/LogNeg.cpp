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
    } catch (PercistenceError e) {
        throw e;
    }
    if (bancoUser.getName().getValue() == usuario.getName().getValue()) {
        if (bancoUser.getIdentify().getValue() == usuario.getIdentify().getValue()) {
            if (bancoUser.getPassword().getValue() == usuario.getPassword().getValue()) {
                return;
            }
        }
    }
    throw new LogicError();
}

void LNUser::cadastrar(User usuario) {
    UserCommand *command;
    try {
        command = new CommandCreateUser();
        command->setUser(usuario);
        percistence->exec(command);
    } catch (PercistenceError e) {
        throw e;
    }
}

void LNUser::deletar(User usuario) {
    UserCommand *command;
    try {
        command = new CommandDeleteUser();
        command->setUser(usuario);
        percistence->exec(command);
    } catch (PercistenceError e) {
        throw e;
    }
}

void LNUser::update(User usuario) {
    UserCommand *command;
    try {
        command = new CommandUpdateUser();
        command->setUser(usuario);
        percistence->exec(command);
    } catch (PercistenceError e) {
        throw e;
    }
}

list LNUser::Listar() {
    UserCommand *command;
    list time = list<User>;
    try {
        command = new CommandFindUsers();
        percistence->exec(command);
        time = command->getList();
    } catch (PercistenceError e) {
        throw e;
    }
    return time;
}

void LNUser::setPercistence(PercistenceProtocol *percistence) {
    this->percistence = percistence;
}

void LNPost::novo(Post post) {
    PostCommand *command;
    try {
        command = new CommandCreatePost();
        command->setPost(post);
        percistence->exec(command);
    } catch (PercistenceError e) {
        throw e;
    }
}

void LNPost::deleta(Post post) {
    PostCommand *command;
    try {
        command = new CommandDeletePost();
        command->setPost(post);
        percistence->exec(command);
    } catch (PercistenceError e) {
        throw e;
    }

}

void LNPost::update(Post post) {
    PostCommand *command;
    try {
        command = new CommandUpdatePost();
        command->setPost(post);
        percistence->exec(command);
    } catch (PercistenceError e) {
        throw e;
    }
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
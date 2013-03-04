#include "LogNeg.h"
using namespace std;

void LNUser::autenticar(User usuario) {
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
    throw new LogicError("nao logo");
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

list<User> LNUser::Listar() {
    UserCommand *command;
    list<User> time;
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

Post LNPost::pegar(Post post) {
    Post BDpost;
    PostCommand *command;
    try {
        command = new CommandFindPost();
        command->setPost(post);
        percistence->exec(command);
        BDpost = command->getPost();
    } catch (PercistenceError e) {
        throw e;
    }
    return BDpost;
}

list<Post> LNPost::listarPorUser(Post post) {
    PostCommand *command;
    std::list<Post> time;
    try {
        command = new CommandFindUserPost();
        command->setPost(post);
        percistence->exec(command);
        time = command->getList();
    } catch (PercistenceError e) {
        throw e;
    }
    return time;
}

list<Post> LNPost::listar() {
    PostCommand *command;
    std::list<Post> time;
    try {
        command = new CommandFindAllPost();
        percistence->exec(command);
        time = command->getList();
    } catch (PercistenceError e) {
        throw e;
    }
    return time;
}

void LNPost::setPercistence(PercistenceProtocol *percistence) {
    this->percistence = percistence;
}

void LNComent::novo(Coment coment) {
    ComentCommand *command;
    try {
        command = new CommandCreateComent();
        command->setComent(coment);
        percistence->exec(command);
    } catch (PercistenceError e) {
        throw e;
    }
}

void LNComent::deleta(Coment coment) {
    ComentCommand *command;
    try {
        command = new CommandDeleteComent();
        command->setComent(coment);
        percistence->exec(command);
    } catch (PercistenceError e) {
        throw e;
    }
}

void LNComent::update(Coment coment) {

    ComentCommand *command;
    try {
        command = new CommandUpdateComent();
        command->setComent(coment);
        percistence->exec(command);
    } catch (PercistenceError e) {
        throw e;
    }
}

Coment LNComent::pegar(Coment coment) {

    ComentCommand *command;
    try {
        command = new CommandUpdateComent();
        percistence->exec(command);
        coment = command->getComent();
    } catch (PercistenceError e) {
        throw e;
    }
    return coment;
}

list<Coment> LNComent::listar(Coment coment) {
    ComentCommand *command;
    std::list<Coment> time;
    try {
        command = new CommandFindPostComents();
        command->setComent(coment);
        percistence->exec(command);
        time = command->getList();
    } catch (PercistenceError e) {
        throw e;
    }
    return time;
}



void LNComent::setPercistence(PercistenceProtocol *percistence) {
    this->percistence = percistence;
}

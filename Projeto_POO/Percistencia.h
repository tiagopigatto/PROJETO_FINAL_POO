#ifndef COMANDS
#define COMANDS

#include <list>
#include "TiposBasicos.h"
#include "sqlite3.h"

class PersistenceControler : public PercistenceProtocol {
public:
    //executa
    void executar(ACommand*);
};

inline void PercistenceControler(ACommand *command) {
    command->execute();
}

class ACommand {
protected:
    char *sql, *end;
    int retval, i;
    int q_cnt = 5, q_size = 150;
    char **queries;
    char valida_name[11];
    // definindo ponteiros
    sqlite3_stmt *stmt;
    sqlite3 *handle;
    void conect();
    void desconect();

public:
    virtual void execute() = 0;
};

//Usuário

class UserCommand : protected ACommand {
protected:
    User user;
    list users = list<User>;

public:
    void setUser(User user);
    User getUser();
    list getList();
};

inline void UserCommand::setUser(User user) {
    this->user = user;
}

inline User UserCommand::getUser() {
    return this->user;
}

inline list UserCommand::getList() {
    return this->users;
}




class PostCommand : protected ACommand {
protected:
    Post post;
    list posts = list<Post>;

public:
    void setUser(Post post);
    Post getUser();
    list getList();
};

inline void PostCommand::setUser(Post post) {
    this->post = post;
}

inline Post PostCommand::getUser() {
    return this->post;
}

inline list PostCommand::getList() {
    return this->posts;
}




class ComentCommand : protected ACommand {
protected:
    Coment coment;
    list coments = list<User>;

public:
    void setComent(Coment coment);
    Coment getComent();
    list getList();
};

inline void ComentCommand::setComent(Coment coment) {
    this->coment = coment;
}

inline Coment ComentCommand::getComent() {
    return this->coment;
}

inline list ComentCommand::getList() {
    return this->coments;
}




class CommandCreateUser : public UserCommand {
public:
    void execute();
};

class CommandFindUser : public UserCommand {
public:
    void execute();
};

class CommandFindUsers : public UserCommand {
public:
    void execute();
};

class CommandUpdateUser : public UserCommand {
public:
    void execute();
};

class CommandDeleteUser : public UserCommand {
public:
    void execute();
};




class CommandCreatePost : public ComentCommand {
public:
    void execute();
};

class CommandUpdatePost : public ComentCommand {
public:
    void execute();
};

class CommandDeletePost : public ComentCommand {
public:
    void execute();
};

class CommandFindPost : public ACommand {
public:
    void execute();
};

class CommandFindAllPost : public ACommand {
public:
    void execute();
};

class CommandFindUserPost : public ACommand {
public:
    void execute();
};


//Comentários

class CommandCreateComent : public ComentCommand {
public:
    void execute();

};

class CommandUpdateComent : public ComentCommand {
public:
    void execute();
};

class CommandDeleteComent : public ComentCommand {
public:
    void execute();
};

class CommandFindComent : public ComentCommand {
public:
    void execute();

}; //POst

class CommandFindPostComents : public ComentCommand {
public:
    void execute();

};

#endif
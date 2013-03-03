#ifndef COMANDS
#define COMANDS

#include <list>
#include "TiposBasicos.h"

class PersisteceControler : public PercistenceProtocol {
private:
    sqlite3 *bd;
public:
    //faz a conceçao
    PercistenceControler();

    //finaliza a conecçao
    ~PercistenceControler();

    //executa
    void executar(ACommand*);

};

class Result {
private:

public:

};

class ACommand {
protected:

    IReciever *pReciever_;
public:

    ACommand(IReciever *reciever)
    : pReciever_(reciever) {
    }
    virtual void Execute() = 0;
};

//Usuário

class UserCommand : protected ACommand {
protected:
    User *user;
    std::list<User> mylist;
    list users = mylist;
public:
    void setUser(User *user);
    User* getUser();
    list getList();

};

inline void UserCommand::setUser(User *user) {
    this->user = user;
}

inline User UserCommand::getUser() {
    return this->user;
}

inline list UserCommand::getList() {
    return this->users;
}

class CadastraUser : public UserCommand {
public:

    CadastrarUser(IReciever *reciever)
    : ACommand(reciever) {

    }

    int Execute() {
        pReciever_->SetAction(TYPES::ACTION_LIST::CADASTRAUSER);
        return pReciever_->GetResult();
    }
};

class UpdateUser : public ACommand {
public:

    UpdateUser(IReciever *reciever)
    : ACommand(reciever) {

    }

    int Execute() {
        pReciever_->SetAction(TYPES::ACTION_LIST::UPDATEUSER);
        return pReciever_->GetResult();
    }
};

class DeleteUser : public ACommand {
public:

    DeleteUser(IReciever *reciever)
    : ACommand(reciever) {

    }

    int Execute() {
        pReciever_->SetAction(TYPES::ACTION_LIST::DELETEUSER);
        return pReciever_->GetResult();
    }
};

class FindUserN : public ACommand {
public:

    FindUserN(IReciever *reciever)
    : ACommand(reciever) {

    }

    int Execute() {
        pReciever_->SetAction(TYPES::ACTION_LIST::FINDUSERN);
        return pReciever_->GetResult();
    }
};

class FindUserID : public ACommand {
public:

    FindUserID(IReciever *reciever)
    : ACommand(reciever) {

    }

    int Execute() {
        pReciever_->SetAction(TYPES::ACTION_LIST::FINDUSERID);
        return pReciever_->GetResult();
    }
};
//Comentários

class CadastraComent : public ACommand {
public:

    CadastraComent(IReciever *reciever)
    : ACommand(reciever) {

    }

    int Execute() {
        pReciever_->SetAction(TYPES::ACTION_LIST::CADASTRACOMENT);
        return pReciever_->GetResult();
    }
};

class UpdateComent : public ACommand {
public:

    UpdateComent(IReciever *reciever)
    : ACommand(reciever) {

    }

    int Execute() {
        pReciever_->SetAction(TYPES::ACTION_LIST::UPDATECOMENT);
        return pReciever_->GetResult();
    }
};

class DeleteComent : public ACommand {
public:

    DeleteComent(IReciever *reciever)
    : ACommand(reciever) {

    }

    int Execute() {
        pReciever_->SetAction(TYPES::ACTION_LIST::DELETECOMENT);
        return pReciever_->GetResult();
    }
};

class FindComent : public ACommand {
public:

    FindComent(IReciever *reciever)
    : ACommand(reciever) {

    }

    int Execute() {
        pReciever_->SetAction(TYPES::ACTION_LIST::FINDCOMENT);
        return pReciever_->GetResult();
    }
};
//POst

class CadastraPost : public ACommand {
public:

    CadastraPost(IReciever *reciever)
    : ACommand(reciever) {

    }

    int Execute() {
        pReciever_->SetAction(TYPES::ACTION_LIST::CADASTRAPOST);
        return pReciever_->GetResult();
    }
};

class UpdatePost : public ACommand {
public:

    UpdatePost(IReciever *reciever)
    : ACommand(reciever) {

    }

    int Execute() {
        pReciever_->SetAction(TYPES::ACTION_LIST::UPDATEPOST);
        return pReciever_->GetResult();
    }
};

class DeletePost : public ACommand {
public:

    DeletePost(IReciever *reciever)
    : ACommand(reciever) {

    }

    int Execute() {
        pReciever_->SetAction(TYPES::ACTION_LIST::DELETEPOST);
        return pReciever_->GetResult();
    }
};

class FindPost : public ACommand {
public:

    FindPost(IReciever *reciever)
    : ACommand(reciever) {

    }

    int Execute() {
        pReciever_->SetAction(TYPES::ACTION_LIST::FINDPOST);
        return pReciever_->GetResult();
    }
};

#endif

#ifndef OPERANDS
#define OPERANDS

#include "TiposBasicos.h"
#include "Entidades.h"
#include "sqlite3.h"

/*  \file   Operacoes.h 
    \brief  Este e o cabecalho resposavel por gerenciar os comandos BD nas tabelas: 
    \n Os comandos são na ordem da classe:\n 
    Criar um novo usário\n
    Atualizar um usuário\n
    Deletar um usuario\n                      
    Procurar um nome na tabela user\n
    Procurar um id na tabela user\n
    Criar um novo comentárion
    Atualizar um comentário\n
    Deletar um comentário\n
    Procurar um id na tabela coment\n
    Criar um novo post\n
    Atualizar um post\\n
    Deletar um post\n
    Procurar um id na tabela post\n            
 */
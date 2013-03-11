/*
 * File:   Comand.h
 * Author: Vitor
 *
 * Created on 4 de Março de 2013, 02:07
 */

#ifndef COMAND_H
#define	COMAND_H

#include <list>
#include <string.h>
#include "Entidades.h"
#include "sqlite3.h"

/*! \class ACommad
 *  \brief Esse e a classe abstrata de comandos
 */
class ACommand {
protected:
    char *sql, *end;    /**< Variavel que armazena o comando a ser realizado em sqp*/   /**< Variavel que serve para finalizar o BD*/
    int retval, i;      /**< Variavel que verifica se tudo ocorreu bem*/   /**< Contador*/
    int q_cnt, q_size;    /**< Variavel que armazena o identificador unico do Usuario*/   /**< Variavel que armazena o identificador unico do Usuario*/
    char **queries;         /**< Variavel que armazena as consultas*/
    char valida_name[11];   /**< Variavel para validar se um nome já existi*/
    // definindo ponteiros
    sqlite3_stmt *stmt;     /**< Variavel que armazena algo escrito*/
    sqlite3 *handle;        /**< Variavel que armazena o o banco de dados*/
    /*! \fn void conect();
     *  \brief Método responsável por conectar do banco de dados
     */
    void conect();
    /*! \fn void desconect()
     *  \brief Método responsável por desconectar do banco de dados
     */
    void desconect();

public:
    /*! \fn virtual void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    virtual void execute() = 0;
};

/** \class ACommand
 *  \brief Essa é a classe abstrata de comandos da persistência
 */

/** \class UserCommand
 *  \brief Classe que possui todos os comandos que podem ser realizados para um usuário
 */
class UserCommand : public ACommand {
protected:
    User user;      /**< Variavel que contém o objeto de um usuário*/
    std::list<User> users;    /**< Variavel que contém uma lista de objetos de usuários*/

public:
   /*! \fn void setUser(User user)
     *  \brief Método responsável por adicionar um usuário no banco de dados
     *  \param User = Objeto de um usuário
     */
    void setUser(User user);
   /*! \fn User getUser()
     *  \brief Método responsável pegar um usuário do banco de dados
     */
    User getUser();
   /*! \fn list getList()
     *  \brief Método responsável receber uma lista com os usuários de um banco de dados
     */
    list<User> getList();
};

inline void UserCommand::setUser(User user) {
    this->user = user;
}

inline User UserCommand::getUser() {
    return this->user;
}

inline list<User> UserCommand::getList() {
    return this->users;
}


/** \class PostCommand
 *  \brief Classe que possui todos os comandos que podem ser realizados para um post
 */
class PostCommand : public ACommand {
protected:
    Post post;          /**< Variavel que contém o objeto de um post*/
    std::list<Post> posts;    /**< Variavel que contém uma lista de objetos de postagens*/

public:
   /*! \fn void setPost(Post post)
     *  \brief Método responsável por adicionar um post no banco de dados
     *  \param Post = Objeto de um post
     */
    void setPost(Post post);
   /*! \fn Post getPost()
     *  \brief Método responsável por pegar um post do banco de dados
     */
    Post getPost();
   /*! \fn list getList()
     *  \brief Método responsável gerar uma lista com os posts do banco de dados
     */
    list<Post> getList();
};

inline void PostCommand::setPost(Post post) {
    this->post = post;
}

inline Post PostCommand::getPost() {
    return this->post;
}

inline list<Post> PostCommand::getList() {
    return this->posts;
}



/** \class ComentCommand
 *  \brief Classe que possui todos os comandos que podem ser realizados para um post
 */
class ComentCommand : public ACommand {
protected:
    Coment coment;           /**< Variavel que contém o objeto de um comentário*/
    std::list<Coment> coments;  /**< Variavel que contém uma lista de objetos de comentários*/

public:
   /*! \fn void setComent(Coment coment)
     *  \brief Método responsável por adicionar um comentário no banco de dados
     *  \param Coment = Objeto de um comentário
     */
    void setComent(Coment coment);
   /*! \fn Coment getComent()
     *  \brief Método responsável por adicionar um comentário no banco de dados
     */
    Coment getComent();
   /*! \fn list getList()
     *  \brief Método responsável por listar os comentários de um post do banco de dados
     */
    list<Coment> getList();
};

inline void ComentCommand::setComent(Coment coment) {
    this->coment = coment;
}

inline Coment ComentCommand::getComent() {
    return this->coment;
}

inline list<Coment> ComentCommand::getList() {
    return this->coments;
}



/** \class CommandCreateUser
 *  \brief Classe que irá procurar se já existe um id ou um nome ,igual ao do objeto, no bd, se esse não existir irá adicionar o obj.
 */
class CommandCreateUser : public UserCommand {
public:
    /*! \fn void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};
/** \class CommandFindUser
 *  \brief Classe que irá procurar um usuário pelo id e o colocara no objeto.
 */
class CommandFindUser : public UserCommand {
public:
    /*! \fn void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};
/** \class  CommandFindUsers
 *  \brief Classe que irá listar todos os usuários.
 */
class CommandFindUsers : public UserCommand {
public:
    /*! \fn void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};
/** \class  CommandUpdateUser
 *  \brief Classe que irá atualizar um usuário no banco de dados, caso esse exista.
 */
class CommandUpdateUser : public UserCommand {
public:
    /*! \fn void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};
/** \class  CommandDeleteUser
 *  \brief Classe que irá deletar um usuário no banco de dados, caso esse exista.
 */
class CommandDeleteUser : public UserCommand {
public:
    /*! \fn void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};



/** \class CommandCreatePost
 *  \brief Classe que irá procurar se já existe um id,igual ao do objeto, no bd, se esse não existir irá adicionar o obj.
 */
class CommandCreatePost : public PostCommand {
public:
    /*! \fn void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};
/** \class CommandUpdatePost
 *  \brief Classe que irá atualizar um post no banco de dados, caso esse exista.
 */
class CommandUpdatePost : public PostCommand {
public:
    /*! \fn void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};
/** \class CommandDeletePost
 *  \brief Classe que irá deletar um post no banco de dados, caso esse exista.
 */
class CommandDeletePost : public PostCommand {
public:
    /*! \fn void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};
/** \class CommandFindPost
 *  \brief Classe que irá procurar um post pelo id, se encontrar o coloca em um objeto Post.
 */
class CommandFindPost : public PostCommand {
public:
    /*! \fn void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};
/** \class CommandFindAllPost
 *  \brief Classe que irá listar todos os posts.
 */
class CommandFindAllPost : public PostCommand {
public:
    /*! \fn void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};
/** \class CommandFindUserPost
 *  \brief Classe que retorna os posts de um usário que estão no banco de dados.
 */
class CommandFindUserPost : public PostCommand {
public:
    /*! \fn void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};


//Comentários
/** \class CommandCreateComent
 *  \brief Classe que irá procurar se já existe um id,igual ao do objeto, no bd, se esse não existir irá adicionar o obj.
 */
class CommandCreateComent : public ComentCommand {
public:
    /*! \fn void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();

};
/** \class CommandUpdateComent
 *  \brief Classe que irá atualizar um comentário no banco de dados, caso esse exista.
 */
class CommandUpdateComent : public ComentCommand {
public:
    /*! \fn void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};
/** \class CommandDeleteComent
 *  \brief Classe que irá deletar um comentário no banco de dados, caso esse exista.
 */
class CommandDeleteComent : public ComentCommand {
public:
    /*! \fn void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};
/** \class CommandFindComent
 *  \brief Classe que irá procurar um cometário pelo id, se encontrar o coloca em um objeto Coment.
 */
class CommandFindComent : public ComentCommand {
public:
    /*! \fn void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
   void execute();

}; //POst

/** \class CommandFindPostComents
 *  \brief Classe que irá procurar os comentários de um post, se encontrar os coloca em um lista de objetos Coment.
 */
class CommandFindPostComents : public ComentCommand {
public:
    /*! \fn void execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();

};


#endif	/* COMAND_H */


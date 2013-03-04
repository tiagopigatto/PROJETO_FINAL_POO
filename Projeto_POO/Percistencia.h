#ifndef COMANDS
#define COMANDS

#include <list>
#include "TiposBasicos.h"
#include "sqlite3.h"

/** \class PersistenceControler
 *  \brief Essa e a classe responsavel por criar uma controladora de persitência
 */
class PersistenceControler : public PercistenceProtocol {
public:
    //executa
    /*! \fn executar(ACommand*)
     *  \brief Método responsável por iniciar a execuçaõ da classe
     *  \param ACommand = Command Abstrato
     */    
    void executar(ACommand*);
};

inline void PercistenceControler(ACommand *command) {
    command->execute();
}
/** \class ACommand
 *  \brief Essa é a classe abstrata de comandos da persistência
 */
class ACommand {
protected:
    char *sql, *end;    /**< Variavel que armazena o comando a ser realizado em sqp*/   /**< Variavel que serve para finalizar o BD*/           
    int retval, i;      /**< Variavel que verifica se tudo ocorreu bem*/   /**< Contador*/
    int q_cnt = 5, q_size = 150;    /**< Variavel que armazena o identificador unico do Usuario*/   /**< Variavel que armazena o identificador unico do Usuario*/
    char **queries;         /**< Variavel que armazena as consultas*/
    char valida_name[11];   /**< Variavel para validar se um nome já existi*/
    // definindo ponteiros
    sqlite3_stmt *stmt;     /**< Variavel que armazena algo escrito*/
    sqlite3 *handle;        /**< Variavel que armazena o o banco de dados*/
    /*! \fn conect()
     *  \brief Método responsável por conectar do banco de dados
     */ 
    void conect();
    /*! \fn desconect()
     *  \brief Método responsável por desconectar do banco de dados
     */ 
    void desconect();

public:
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */   
    virtual void execute() = 0;
};

/** \class UserCommand
 *  \brief Classe que possui todos os comandos que podem ser realizados para um usuário
 */
class UserCommand : protected ACommand {
protected:
    User user;      /**< Variavel que contém o objeto de um usuário*/
    list users = list<User>;    /**< Variavel que contém uma lista de objetos de usuários*/

public:
   /*! \fn setUser(User)
     *  \brief Método responsável por adicionar um usuário no banco de dados
     *  \param User = Objeto de um usuário
     */     
    void setUser(User user);
   /*! \fn getUser()
     *  \brief Método responsável pegar um usuário do banco de dados
     */   
    User getUser();
   /*! \fn getList()
     *  \brief Método responsável receber uma lista com os usuários de um banco de dados
     */  
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


/** \class PostCommand
 *  \brief Classe que possui todos os comandos que podem ser realizados para um post
 */
class PostCommand : protected ACommand {
protected:
    Post post;          /**< Variavel que contém o objeto de um post*/
    list posts = list<Post>;    /**< Variavel que contém uma lista de objetos de postagens*/

public:
   /*! \fn setPost(Post)
     *  \brief Método responsável por adicionar um post no banco de dados
     *  \param Post = Objeto de um post
     */      
    void setPost(Post post);
   /*! \fn getPost()
     *  \brief Método responsável por pegar um post do banco de dados
     */  
    Post getPost();
   /*! \fn getList()
     *  \brief Método responsável gerar uma lista com os posts do banco de dados
     */  
    list getList();
};

inline void PostCommand::setPost(Post post) {
    this->post = post;
}

inline Post PostCommand::getPost() {
    return this->post;
}

inline list PostCommand::getList() {
    return this->posts;
}



/** \class ComentCommand
 *  \brief Classe que possui todos os comandos que podem ser realizados para um post
 */
class ComentCommand : protected ACommand {
protected:
    Coment coment;           /**< Variavel que contém o objeto de um comentário*/
    list coments = list<User>;  /**< Variavel que contém uma lista de objetos de comentários*/      

public:
   /*! \fn setComent(Coment)
     *  \brief Método responsável por adicionar um comentário no banco de dados
     *  \param Coment = Objeto de um comentário
     */    
    void setComent(Coment coment);  
   /*! \fn getComent()
     *  \brief Método responsável por adicionar um comentário no banco de dados
     */    
    Coment getComent();
   /*! \fn getList()
     *  \brief Método responsável por listar os comentários de um post do banco de dados
     */    
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
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};

class CommandFindUser : public UserCommand {
public:
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};

class CommandFindUsers : public UserCommand {
public:
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};

class CommandUpdateUser : public UserCommand {
public:
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};

class CommandDeleteUser : public UserCommand {
public:
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};




class CommandCreatePost : public PostCommand {
public:
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};

class CommandUpdatePost : public PostCommand {
public:
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};

class CommandDeletePost : public PostCommand {
public:
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};

class CommandFindPost : public ACommand {
public:
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};

class CommandFindAllPost : public ACommand {
public:
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};

class CommandFindUserPost : public ACommand {
public:
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};


//Comentários

class CommandCreateComent : public ComentCommand {
public:
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();

};

class CommandUpdateComent : public ComentCommand {
public:
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};

class CommandDeleteComent : public ComentCommand {
public:
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();
};

class CommandFindComent : public ComentCommand {
public:
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */    
   void execute();

}; //POst

class CommandFindPostComents : public ComentCommand {
public:
    /*! \fn execute()
     *  \brief Método responsável por iniciar a execução da classe
    */
    void execute();

};

#endif
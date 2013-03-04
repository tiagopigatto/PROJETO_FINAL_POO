/*
 * File:   InterfaceUsuario.h
 * Author: Vitor
 *
 * Created on 13 de Fevereiro de 2013, 12:36
 */

#ifndef INTERFACEUSUARIO_H
#define INTERFACEUSUARIO_H

#include "ProtocoloLN.h"
#include "IUProtocols.h"
#include "PercistenceProtocol.h"

#include "Entidades.h"

#include "Errors.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <list>
using namespace std;

#define LIMPATELA system("cls");

//login aqui

//seta quais os serciços que vao poder ser providos

/*! \class InitialIUControler 
 *  \brief Essa é a classe que cria a primeira interface que conecta as intefarces para comando de usuário, post e comentário
 */
class InitialIUControler {
private:
    //Constantes para identificar a opção escolhida
    static const unsigned short int NUMERO_OPCOES = 4;  /**< Variavel que armazena a quantidade de o~pções na interface*/
    static const unsigned short int OPCAO_USUARIO = 1;  /**< Variavel que armazena o número da opção de usuário*/
    static const unsigned short int OPCAO_POSTAGEM = 2; /**< Variavel que armazena o número da opção de postagem*/
    static const unsigned short int OPCAO_LISTA_POSTAGENS = 3;  /**< Variavel que armazena o número da opção de cometário*/
    static const unsigned short int OPCAO_ENCERRAR = 4; /**< Variavel que armazena o número da opção de finalizar a aplicação*/

    //protocolos
    IUUserProtocol *userProto;  /**< Variavel que contém o protocolo da interface de usuário User*/
    IUPostProtocol *postProto;  /**< Variavel que contém o  protocolo da interface de usuário Post*/
    IUComentProtocol *comentProto;  /**< Variavel que contém o  protocolo da interface de usuário Comentário*/

    //Usuario / postagem
    User *user;  /**< Variável que armazena é responsável por armazenar um objeto de usuário*/
    Post *post;  /**< Variável que armazena é responsável por armazenar um objeto de post*/ 

    //metodos
    /*! \fn void showOptions()
     *  \brief Método responsável por apresentar na tela as opções que o usuário possui
     */    
    void showOptions();

public:
    InitialIUControler()
    {
        user = NULL;
        post = NULL;
    }
    //metodos
    /*! \fn void setUserControler(IUUserProtocol *userProto)
     *  \brief Método responsável por abrir a interface de usuário
     *  \param userProto: protocolo da interface de usuário
     */        
    void setUserProtocol(IUUserProtocol *userProto);
    /*! \fn void setPostControler(IUPostProtocol *postProto)
     *  \brief Método responsável por abrir a interface de post
     *  \param postProto: protocolo da interface de post
     */     
    void setPostProtocol(IUPostProtocol *postProto);
    /*! \fn void setComentControler(IUComentProtocol *comentProto)
     *  \brief Método responsável por abrir a interface de comentário
     *  \param comentProto: protocolo da interface de comentário
     */     
    void setComentProtocol(IUComentProtocol *comentProto);
    /*! \fn void exec()
     *  \brief Método responsável por inicializar a interface
     */    
    void exec();
};
/*! \class UserControler 
 *  \brief Essa é a classe que cria a interface de comandos de usuário
 */
class UserControler : public IUUserProtocol {
private:
    User *user;  /**< Variável que armazena é responsável por armazenar um objeto de usuário*/                 
    UserProtocol *protocol;     /**< Variavel que contém o protocolo da interface de usuário User*/

    //SEM LOGAR
    static const unsigned int N_LOGIN = 1;  /**< Variavel que armazena o valor da opção de login*/
    static const unsigned int N_CADASTRO = 2;   /**< Variavel que armazena o valor da opção de cadastro*/

    //LOGADO
    static const unsigned int N_MODIFICAR = 1;  /**< Variavel que armazena o valor da opção de modiicar*/
    static const unsigned int N_DELETAR = 2;    /**< Variavel que armazena o valor da opção de deletar*/
    static const unsigned int N_DESLOGAR = 3;   /**< Variavel que armazena o valor da opção de deslogar*/

    //SEMPRE
    static const unsigned int N_LIST_USUARIOS = 4;  /**< Variavel que armazena o valor da opção de lista de usuários*/
    static const unsigned int N_SAIR = 5;           /**< Variavel que armazena o valor da opção de sair*/

    //METODOS
    /*! \fn void showScreen()
     *  \brief Método responsável por apresentar a interface de usuário para o usuário
     */      
    void showScreen();

    /*! \fn void logar()
     *  \brief Método responsável por apresentar os comandos necessários para realizar um login
     */      
    void logar();
    /*! \fn void cadastrar()
     *  \brief Método responsável por apresentar os comandos necessários para realizar um cadastro
     */      
    void cadastrar();
    /*! \fn void showList()
     *  \brief Método responsável por apresentar as listas com todos os usuários
     */          
    void showList();
    /*! \fn void deletar()
     *  \brief Método responsável por apresentar os comandos necessários para realizar deletar um usuário
     */          
    void deletar();
    /*! \fn void modificar()
     *  \brief Método responsável por apresentar os comandos necessários para realizar modificar um usuário
     */          
    void modificar();
                
public:
     /*! \fn void setLogicProtocol(UserProtocol * protocol)
     *  \brief Método responsável por acionar o protocolo da camada lógica
     *  \param protocol = Protocolo da camada.
     */ 
    void setLogicProtocol(UserProtocol * protocol);
    
    UserControler();
    
        
    /*! \fn void exec()
     *  \brief Método responsável por inicializar a interface
     */
    void exec();
    
    void setUser(User*);
    User* getUser();
    

};

inline UserControler :: UserControler()
{
    user = NULL;
}


inline void UserControler :: setUser(User* user)
{
    this -> user = user;
}

inline User* UserControler :: getUser()
{
    return this -> user;
}


inline void UserControler :: setLogicProtocol(UserProtocol *protocol)
{
    this->protocol = protocol;
}

/*! \class PostControler
 *  \brief Essa é a classe que cria a interface de comandos de post
 */
class PostControler : public IUPostProtocol {
private:
    User *user;  /**< Variável que armazena é responsável por armazenar um objeto de usuário*/
    Post *post;  /**< Variável que armazena é responsável por armazenar um objeto de post*/ 
    PostProtocol *protocol; /**< Variável que armazena o protocolo post*/ 
    //LOGADO
    static const unsigned int N_LISTAMEUSPOSTS = 1;     /**< Variavel que armazena o valor da opção de apresentar a lista de posts*/
    static const unsigned int N_MODIFICAPOST = 2;       /**< Variavel que armazena o valor da opção de modificar um post*/
    static const unsigned int N_DELETAPOST = 3;         /**< Variavel que armazena o valor da opção de deletar um post*/
    static const unsigned int N_CRIAPOST = 4;           /**< Variavel que armazena o valor da opção de criar um post*/
    static const unsigned int N_AVALIAPOST = 5;         /**< Variavel que armazena o valor da opção de avaliar um post*/

    //SEMPRE
    static const unsigned int N_LISTATODOSPOSTS = 6;        /**< Variavel que armazena o valor da opção de listar os posts*/
    static const unsigned int N_VERPOSTSDETALHADO = 7;      /**< Variavel que armazena o valor da opção de ver um post detalhadamente*/
    static const unsigned int N_SAIR = 8;                   /**< Variavel que armazena o valor da opção de sair*/

    //METODOS
    /*! \fn void showScreen()
     *  \brief Método responsável por apresentar a interface de post para o usuário
     */ 
    void showScreen();
    
    /*! \fn void  listaMeus()
     *  \brief Método responsável por apresentar os posts de um usuário na tela
     */     
    void listaMeus();
    /*! \fn void modifica()
     *  \brief Método responsável por apresentar os comandos necessários para modificar um comentário
     */ 
    void modifica();
    /*! \fn void deleta()
     *  \brief Método responsável por apresentar os comandos necessários para deletar um post
     */ 
    void deleta();
    /*! \fn void cria()
     *  \brief Método responsável por apresentar os comandos necessários para realizar criar um novo post
     */ 
    void cria();
    /*! \fn void avalia()
     *  \brief Método responsável por apresentar os comandos necessários para avaliar um post
     */ 
    void avalia();
    /*! \fn void showlist()
     *  \brief Método responsável por apresentar uma lista com todos os posts de todos os usuários
     */ 
    void showlist();
    /*! \fn void mostra()
     *  \brief Método responsável por mostrar um post na tela
     */ 
    void mostra();
    
public:
    PostControler();
    /*! \fn void exec()
     *  \brief Método responsável por inicializar a interface
     */    
    void exec();
    
    void setUser(User*);
    Post* getPost();
    void setLogicProtocol(PostProtocol *);
};

inline void PostControler :: setLogicProtocol(PostProtocol *protocol)
{
    this->protocol = protocol;
}

inline PostControler :: PostControler()
{
    user = NULL;
    post = NULL;
}

inline void PostControler :: setUser(User* user)
{
    this -> user = user;
}

inline Post* PostControler :: getPost()
{
    return this -> post;
}

/*! \class ComentControler
 *  \brief Essa é a classe que cria a interface de comandos de comentário
 */
class ComentControler : public IUComentProtocol {
private:
    User *user;  /**< Variável que armazena é responsável por armazenar um objeto de usuário*/
    Post *post;  /**< Variável que armazena é responsável por armazenar um objeto de post*/
    ComentProtocol *protocol;   /**< Variável que armazena o protocolo comentário*/ 

    //LOGADO
    static const unsigned int N_DELETACOMENT = 1;   /**< Variavel que armazena o valor da opção deletar um comentário*/
    static const unsigned int N_MODIFICACOMENT = 2; /**< Variavel que armazena o valor da opção de modificar um comentário*/
    static const unsigned int N_FAZCOMENT = 3;      /**< Variavel que armazena o valor da opção de criar um comentário*/

    //SEMPRE
    static const unsigned int N_LISTACOMENT = 4;    /**< Variavel que armazena o valor da opção de listar os comentários de um post*/
    static const unsigned int N_MOSTRACOMENT = 5;   /**< Variavel que armazena o valor da opção de apresentar o comentário*/
    static const unsigned int N_SAIR = 6;           /**< Variavel que armazena o valor da opção de sair*/

    //METODOS
    /*! \fn void showScreen()
     *  \brief Método responsável por apresentar a interface de comentário para o usuário
     */ 
    void showScreen();
    
    //METODOS /implementar
    /*! \fn void deleta()
     *  \brief Método responsável por apresentar os comandos necessários para deletar um comentário
     */ 
    void deleta();
    /*! \fn void modifica()
     *  \brief Método responsável por apresentar os comandos necessários para modificar um comentário
     */ 
    void modifica();
    /*! \fn void cria()
     *  \brief Método responsável por apresentar os comandos necessários para realizar criar um novo comentário
     */ 
    void cria();
    /*! \fn void lista()
     *  \brief Método responsável por apresentar uma lista com todos os comentários de um post
     */ 
    void lista();
    /*! \fn void show()
     *  \brief Método responsável por mostrar um comentário na tela
     */ 
    void show();
    
public:
    /*! \fn void exec()
     *  \brief Método responsável por inicializar a interface
     */
    void exec();
    void setUser(User*);
    void setPost(Post*);
    void setLogicProtocol(ComentProtocol *);
    
};

inline void ComentControler :: setLogicProtocol(ComentProtocol *protocol)
{
    this->protocol = protocol;
}

inline void ComentControler :: setUser(User* user)
{
    this -> user = user;
}

inline void ComentControler :: setPost(Post* post)
{
    this -> post = post;
}



inline void InitialIUControler::setUserProtocol(IUUserProtocol* userProto) {
    this->userProto = userProto;
}

inline void InitialIUControler::setPostProtocol(IUPostProtocol* postProto) {
    this->postProto = postProto;
}

inline void InitialIUControler::setComentProtocol(IUComentProtocol* comentProto) {
    this->comentProto = comentProto;
}


#endif  /* INTERFACEUSUARIO_H */


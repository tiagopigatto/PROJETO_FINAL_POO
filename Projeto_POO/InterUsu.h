/*
 * File:   InterfaceUsuario.h
 * Author: Vitor
 *
 * Created on 13 de Fevereiro de 2013, 12:36
 */

#ifndef INTERFACEUSUARIO_H
#define INTERFACEUSUARIO_H

#include "ProtocoloLN.h"
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
    User *user = NULL;  /**< Variável que armazena é responsável por armazenar um objeto de usuário*/
    Post *post = NULL;  /**< Variável que armazena é responsável por armazenar um objeto de post*/ 

    //metodos
    /*! \fn showOptions()
     *  \brief Método responsável por apresentar na tela as opções que o usuário possui
     */    
    void showOptions();

public:
    //metodos
    /*! \fn (IUUserProtocol *userProto)
     *  \brief Método responsável por abrir a interface de usuário
     *  \param userProto: protocolo da interface de usuário
     */        
    void setUserControler(IUUserProtocol *userProto);
    /*! \fn (IUPostProtocol *postProto)
     *  \brief Método responsável por abrir a interface de post
     *  \param postProto: protocolo da interface de post
     */     
    void setPostControler(IUPostProtocol *postProto);
    /*! \fn setComentControler(IUComentProtocol *comentProto)
     *  \brief Método responsável por abrir a interface de comentário
     *  \param comentProto: protocolo da interface de comentário
     */     
    void setComentControler(IUComentProtocol *comentProto);
    /*! \fn exec()
     *  \brief Método responsável por inicializar a interface
     */    
    void exec();
};

class UserControler : public IUUserProtocol {
private:
    User *user = NULL;  /**< Variável que armazena é responsável por armazenar um objeto de usuário*/                 
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
    /*! \fn showScreen()
     *  \brief Método responsável por apresentar a interface de usuário para o usuário
     */      
    void showScreen();

    /*! \fn logar()
     *  \brief Método responsável por realizar as tarefas necessárias para a realização de um login pelas camadas inferiores
     */      
    void logar();
    /*! \fn cadastrar()
     *  \brief Método responsável por realizar as tarefas necessárias para realizar o cadastro pelas camadas inferiores
     */      
    void cadastrar();
    /*! \fn cadastrar()
     *  \brief Método responsável por realizar as tarefas necessárias para realizar o cadastro pelas camadas inferiores
     */          
    void showList();
    void deletar();
    void modificar();
    setLogicProtocol(UserProtocol * protocol) = 0;
    
public:
    void exec();

};

inline void UserControler :: setLogicProtocol(UserProtocol *protocol)
{
    this->protocol = protocol;
}


class PostControler : public IUPostProtocol {
private:
    User *user = NULL;
    Post *post = NULL;
    PostProtocol *protocol;
    //LOGADO
    static const unsigned int N_LISTAMEUSPOSTS = 1;
    static const unsigned int N_MODIFICAPOST = 2;
    static const unsigned int N_DELETAPOST = 3;
    static const unsigned int N_CRIAPOST = 4;
    static const unsigned int N_AVALIAPOST = 5;

    //SEMPRE
    static const unsigned int N_LISTATODOSPOSTS = 6;
    static const unsigned int N_VERPOSTSDETALHADO = 7;
    static const unsigned int N_SAIR = 8;

    //METODOS
    void showScreen();
    
    //METODOS A IMPLEMTAR / PEGAR PIGATTO
    listaMeus();
    modifica();
    deleta();
    cria();
    avalia();
    showlist();
    mostra();
    
public:
    void exec();
};

class ComentControler : public IUComentProtocol {
private:
    User user;
    Post post;


    //LOGADO
    static const unsigned int N_DELETACOMENT = 1;
    static const unsigned int N_MODIFICACOMENT = 2;
    static const unsigned int N_FAZCOMENT = 3;

    //SEMPRE
    static const unsigned int N_LISTACOMENT = 4;
    static const unsigned int N_MOSTRACOMENT = 5;
    static const unsigned int N_SAIR = 6;

    //METODOS
    void showScreen();
    
    //METODOS /implementar
    deleta();
    modifica();
    cria();
    lista();
    show();
    
public:
    void exec();
};

inline void InitialIUControler::setUserControler(IUUserProtocol* userProto) {
    this->userProto = userProto;
}

inline void InitialIUControler::setPostControler(IUPostProtocol* postProto) {
    this->postProto = postProto;
}

inline void InitialIUControler::setUserControler(IUComentProtocol* comentProto) {
    this->comentProto = comentProto;
}


#endif  /* INTERFACEUSUARIO_H */


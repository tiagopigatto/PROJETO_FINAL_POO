/*
 * File:   InterfaceUsuario.h
 * Author: Vitor
 *
 * Created on 13 de Fevereiro de 2013, 12:36
 */

#ifndef INTERFACEUSUARIO_H
#define	INTERFACEUSUARIO_H

#include "ProtocoloLN.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <list>

using namespace std;


class BasicScreen {
protected:
    virtual void showScreen() = 0;
    virtual void verOptions() = 0;
public:
    BasicScreen();
    virtual void telaExec();
    void exec();
};

class InitialIUControler : public BasicScreen
{
private:
  //Constantes para identificar a opção escolhida
  static const unsigned short int NUMERO_OPCOES   = 5;
  static const unsigned short int OPCAO_USUARIO  = 1;
  static const unsigned short int OPCAO_LISTA_USUARIOS   = 2;
  static const unsigned short int OPCAO_LISTAS_POSTAGENS     = 3;
  static const unsigned short int OPCAO_ENCERRAR  = 5;
  
  //protocolos
  BaseProtocol *user;
  BaseProtocol *post;
  BaseProtocol *coment;
  
  //
  User *user = NULL;
  Coment *coment = NULL;
  
public:
    void setUserControler(BaseProtocol *user);
    void setPostControler(BaseProtocol *post);
    void setComentControler(BaseProtocol *coment);
};

inline void InitialIUControler::setUserControler(BaseProtocol* user)
{
    this->user = user;
}

inline void InitialIUControler::setPostControler(BaseProtocol* post)
{
    this->post = post;
}


inline void InitialIUControler::setUserControler(BaseProtocol* coment)
{
    this->coment = coment;
}



class StartPage : public BasicScreen {


private:
    static const unsigned int N_OPCOES = 6;
    static const unsigned int N_LOGIN = 1;
    static const unsigned int N_CADASTRO = 2;
    static const unsigned int N_LIU = 3;
    static const unsigned int N_LIP = 4;
    static const unsigned int N_LP = 5;
    static const unsigned int N_SAIR = 6;

public:
    void showScreen();
    void verOptions();

    string nomeUsuario;
    string senhaUsuario;
    string identUsuario;

    User *user;
    MenuLogin menu;

};

class PostPageAut : public BasicScreen {
    User *usuariologado;
    Post *postatual;
private:
    static const unsigned int N_OPCOES = 5;
    static const unsigned int N_MOSTRAPOST = 1;
    static const unsigned int N_MOSTRACOMENT = 2;
    static const unsigned int N_COMENTPOST = 3;
    static const unsigned int N_AVALIAPOST = 4;
    static const unsigned int N_SAIR = 5;

public:
    void showScreen();
    void verOptions();

    string comentario;
    string identificador;
    string nota;
};

class PostPageNAut : public BasicScreen {
private:
    static const unsigned int N_OPCOES = 3;
    static const unsigned int N_MOSTRAPOST = 1;
    static const unsigned int N_MOSTRACOMENT = 2;
    static const unsigned int N_SAIR = 3;

public:
    void showScreen();
    void verOptions();
};

class MenuLogin : public BasicScreen {
    User *usuariologado;
private:
    static const unsigned int N_OPCOES = 6;
    static const unsigned int N_ALTERAR = 1;
    static const unsigned int N_ENCERRAR = 2;
    static const unsigned int N_POSTAR = 3;
    static const unsigned int N_LISTAR_POST = 4;
    static const unsigned int N_LISTAR_IDENT = 5;
    static const unsigned int N_SAIR = 6;

public:
    void showScreen();
    void verOptions();

    User user;
    Password password;
    Identify identify;

    string textPost;
    string identPost;
};


#endif	/* INTERFACEUSUARIO_H */


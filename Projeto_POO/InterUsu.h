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
#define LIMPATELA system("cls");


class InitialIUControler{
private:
    //Constantes para identificar a opção escolhida
    static const unsigned short int NUMERO_OPCOES = 4;
    static const unsigned short int OPCAO_USUARIO = 1;
    static const unsigned short int OPCAO_LISTA_USUARIOS = 2;
    static const unsigned short int OPCAO_LISTA_POSTAGENS = 3;
    static const unsigned short int OPCAO_ENCERRAR = 4;

    //protocolos
    IUUserProtocol *userProto;
    IUPostProtocol *postProto;
    IUComentProtocol *comentProto;

    //Usuario / postagem
    User *user = NULL;
    Post *post = NULL;
    
    //Pilha opcoes
    int option[2];
    
    //metodos
    showOptions();
    
public:
    void setUserControler(IUUserProtocol *userProto);
    void setPostControler(IUPostProtocol *postProto);
    void setComentControler(IUComentProtocol *comentProto);
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

class UserControler : public IUUserProtocol {
private:
    static const unsigned int N_OPCOES = 6;
    static const unsigned int N_LOGIN = 1;
    static const unsigned int N_CADASTRO = 2;
    static const unsigned int N_LIST_USER_POSTS = 3;
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

class PostPageAut : public IUPostProtocol {
    User *userlogado;
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


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

//login aqui

//seta quais os serciços que vao poder ser providos

class InitialIUControler {
private:
    //Constantes para identificar a opção escolhida
    static const unsigned short int NUMERO_OPCOES = 4;
    static const unsigned short int OPCAO_USUARIO = 1;
    static const unsigned short int OPCAO_POSTAGEM = 2;
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
    User User;

    static const unsigned int N_OPCOES = 7;
    //SEM LOGAR
    static const unsigned int N_LOGIN = 1;
    static const unsigned int N_CADASTRO = 2;

    //LOGADO
    static const unsigned int N_MODIFICAR = 3;
    static const unsigned int N_DELETAR = 4;
    static const unsigned int N_DESLOGAR = 5;

    //SEMPRE
    static const unsigned int N_LIST_USUARIOS = 6;
    static const unsigned int N_SAIR = 7;

    //METODOS
    void showScreen();
    void verOptions();

};

class PostControler : public IUPostProtocol {
private:
    User user;
    Post post;
    static const unsigned int N_OPCOES = 5;
    //LOGADO
    static const unsigned int N_LISTASMEUSPOSTS = 1;
    static const unsigned int N_MODIFICAPOST = 2;
    static const unsigned int N_DELETAPOST = 3;
    static const unsigned int N_CRIAPOST = 4;
    static const unsigned int N_AVALIAPOST = 5;

    //SEMPRE
    static const unsigned int N_LISTATODOSPOSTS = 4;
    static const unsigned int N_VERPOSTSDETALHADO = 4;
    static const unsigned int N_SAIR = 5;

    //METODOS
    void showScreen();
    void verOptions();
};

class ComentControler : public IUComentProtocol {
private:
    static const unsigned int N_OPCOES = 3;

    //LOGADO
    static const unsigned int N_DELETACOMMET = 1;
    static const unsigned int N_MODIFICACOMENT = 2;
    static const unsigned int N_FAZCOMENT = 2;

    //SEMPRE
    static const unsigned int N_LISTACOMENT = 2;
    static const unsigned int N_MOSTRACOMENT = 2;
    static const unsigned int N_SAIR = 3;

    //METODOS
    void showScreen();
    void verOptions();
};



#endif	/* INTERFACEUSUARIO_H */


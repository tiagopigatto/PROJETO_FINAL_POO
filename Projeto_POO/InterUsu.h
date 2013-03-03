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

class UserControler : public IUUserProtocol {
private:
    User *user = NULL;

    //SEM LOGAR
    static const unsigned int N_LOGIN = 1;
    static const unsigned int N_CADASTRO = 2;

    //LOGADO
    static const unsigned int N_MODIFICAR = 1;
    static const unsigned int N_DELETAR = 2;
    static const unsigned int N_DESLOGAR = 3;

    //SEMPRE
    static const unsigned int N_LIST_USUARIOS = 4;
    static const unsigned int N_SAIR = 5;

    //METODOS
    void showScreen();
    void verOptions();
    
    //METODOS A IMPLEMTAR / PEGAR PIGATTO
    void logar();
    void cadastrar();
    void showList();
    void deletar();
    void modificar();
    
public:
    void exec();

};

class PostControler : public IUPostProtocol {
private:
    User *user = NULL;
    Post *post = NULL;
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
    void verOptions();
    
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
    User *user = NULL;
    Post *post = NULL;

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
    void verOptions();
    
public:
    deleta();
    modifica();
    cria();
    lista();
    show();
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


#endif	/* INTERFACEUSUARIO_H */


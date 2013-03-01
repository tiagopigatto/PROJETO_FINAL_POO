/* 
 * File:   main.cpp
 * Author: Vitor
 *
 * Created on 15 de Dezembro de 2012, 22:14
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include "TiposBasicos.h"
#include "Entidades.h"
#include "testestipos.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Realizacao de testes com argumentos validos e invalidos" << endl;

    //Teste do tipo básico NomeUsuario
    TesteTBUserName nomeusuario;
    nomeusuario.run();

    //Teste do tipo básico Senha
    TesteTBPassword senha;
    senha.run();

    //Teste do tipo básico Ident
    TesteTBIdentify ident;
    ident.run();

    //Teste do tipo básico Post
    TesteTBPostText post;
    post.run();

    //Teste do tipo básico Comment
    TesteTBComentText comment;
    comment.run();

    //Teste do tipo básico Date
    TesteTBDate date;
    date.run();

    //Teste dp tipo básico Avalia
    TesteTBEvaluation avalia;
    avalia.run();

    cout << "Todos os testes foram realizados com sucesso!" << endl;
    cin.get();
    return 0;
}


#include<cstdlib>
#include<iostream>
#include<stdexcept>

#include "testestipos.h"
using std::invalid_argument;
void StarTesteTipos::exec()
{
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
}

void TesteBasico::run() {
    setUp();
    printCondition();
    testeValido();
    testeInvalido();
    tearDown();
}

//Codificação da classe TesteTBNomeUsuario

void TesteTBUserName::testeValido() {
    try {
        string NomeUsuario_Valido = "Tiago Piga";
        nomeusuario->setValue(NomeUsuario_Valido);
        if (nomeusuario->getValue() != NomeUsuario_Valido) {
            cout << "Teste de valor valido para Nome do Usuario falhou!" << endl;
            cout << "Erro: " << "valor alterado" << endl;
        } else {
            cout << "Teste de valor valido para Nome do Usuario realizado com sucesso!" << endl;
        }
    } catch (invalid_argument& e) {
        cout << "Teste de valor valido para Nome do Usuario falhou!" << endl;
        cout << "Erro: " << e.what() << endl;
    }
}

void TesteTBUserName::testeInvalido() {
    try {
        string NomeUsuario_Invalido = "Tiago Pigatto";
        nomeusuario->setValue(NomeUsuario_Invalido);
        cout << "Teste de valor invalido para Nome do Usuario falhou!" << endl;
        cout << "Erro: " << "O valor passou pela validacao" << endl;
    } catch (invalid_argument& e) {
        cout << "Teste de valor invalido para Nome do Usuario realizado com sucesso!" << endl;
    }

}

//Codificação da classe TesteTBSenha

void TesteTBPassword::testeValido() {
    try {
        string Senha_Valido = "123456";
        senha->setValue(Senha_Valido);
        if (senha->getValue() != Senha_Valido) {
            cout << "Teste de valor valido para Senha falhou!" << endl;
            cout << "Erro: " << "valor alterado" << endl;
        } else {
            cout << "Teste de valor valido para Senha realizado com sucesso!" << endl;
        }
    } catch (invalid_argument& e) {
        cout << "Teste de valor valido para Senha falhou!" << endl;
        cout << "Erro: " << e.what() << endl;
    }
}

void TesteTBPassword::testeInvalido() {
    try {
        string Senha_Invalido = "1234567";
        senha->setValue(Senha_Invalido);
        cout << "Teste de valor invalido para Senha falhou!" << endl;
        cout << "Erro: " << "O valor passou pela validacao" << endl;
    } catch (invalid_argument& e) {
        cout << "Teste de valor invalido para Senha realizado com sucesso!" << endl;
    }

}

//COdificação da classe TesteTBIdent

void TesteTBIdentify::testeValido() {
    try {
        string Ident_Valido = "123456";
        ident->setValue(Ident_Valido);
        if (ident->getValue() != Ident_Valido) {
            cout << "Teste de valor valido para Identidade realizado com sucesso!" << endl;
            cout << "Erro: " << "valor alterado" << endl;
        } else {
            cout << "Teste de valor valido para Identidade realizado com sucesso!" << endl;
        }
    } catch (invalid_argument& e) {
        cout << "Teste de valor valido para Identidade realizado com sucesso!" << endl;
        cout << "Erro: " << e.what() << endl;
    }
}

void TesteTBIdentify::testeInvalido() {
    try {
        string Ident_Invalido = "1234567";
        ident->setValue(Ident_Invalido);
        cout << "Teste de valor invalido para Identidade realizado com sucesso!" << endl;
        cout << "Erro: " << "O valor passou pela validacao" << endl;
    } catch (invalid_argument& e) {
        cout << "Teste de valor invalido para Identidade realizado com sucesso!" << endl;
    }

}

//Codificação da classe TesteTBPost

void TesteTBPostText::testeValido() {
    try {
        string Post_Valido = "TESTANDO";
        post->setValue(Post_Valido);
        if (post->getValue() != Post_Valido) {
            cout << "Teste de valor valido para Postagem realizado com sucesso!" << endl;
            cout << "Erro: " << "valor alterado" << endl;
        } else {
            cout << "Teste de valor valido para Postagem realizado com sucesso!" << endl;
        }
    } catch (invalid_argument& e) {
        cout << "Teste de valor valido para Postagem realizado com sucesso!" << endl;
        cout << "Erro: " << e.what() << endl;
    }

}

void TesteTBPostText::testeInvalido() {
    try {
        string Post_Invalido = "Esse texto possui mais de 30 caracteres por isso ele e invalido!";
        post->setValue(Post_Invalido);
        cout << "Erro: " << "O valor passou pela validacao" << endl;
        cout << "Teste de valor invalido para Postagem falhou!" << endl;
    } catch (invalid_argument& e) {
        cout << "Teste de valor invalido para Postagem realizado com sucesso!" << endl;
    }
}

//Codificação da classe TesteTBComment

void TesteTBComentText::testeValido() {
    try {
        string Comment_Valido = "TESTANDO";
        comment->setValue(Comment_Valido);
        if (comment->getValue() != Comment_Valido) {
            cout << "Teste de valor valido para Comentario falhou!" << endl;
            cout << "Erro: " << "valor alterado" << endl;
        } else {
            cout << "Teste de valor valido para Comentario realizado com sucesso!" << endl;
        }
    } catch (invalid_argument& e) {
        cout << "Teste de valor valido para Comentario falhou!" << endl;
        cout << "Erro: " << e.what() << endl;
    }
}

void TesteTBComentText::testeInvalido() {
    try {
        string Comment_Invalido = "Esse texto possui mais de 30 caracteres por isso ele e invalido!";
        comment->setValue(Comment_Invalido);
        cout << "Erro: " << "O valor passou pela validacao" << endl;
        cout << "Teste de valor invalido para Comentario falhou!" << endl;
    } catch (invalid_argument& e) {
        cout << "Teste de valor invalido para Comentario realizado com sucesso!" << endl;
    }
    
}

//Codificação da classe TesteTBDate

void TesteTBDate::testeValido() {
    try {
        string Date_Valido = "02-12-1992";
        date->setValue(Date_Valido);
        if (date->getValue() != Date_Valido){
            cout << "Teste de valor valido para Data falhou!" << endl;
            cout << "Erro: " << "valor alterado" << endl;
        } else {
            cout << "Teste de valor valido para Data realizado com sucesso!" << endl;
        }
    } catch (invalid_argument& e) {
        cout << "Teste de valor valido para Data falhou!" << endl;
        cout << "Erro: " << e.what() << endl;
    }
}

void TesteTBDate::testeInvalido() {
    try {
        string Date_Invalido = "02-12-19992";
        date->setValue(Date_Invalido);
        cout << "Erro: " << "O valor passou pela validacao" << endl;
        cout << "Teste de valor invalido para Data falhou!" << endl;
    } catch (invalid_argument& e) {
        cout << "Teste de valor invalido para Data realizado com sucesso!" << endl;
    }
}

//Codificação da classe TesteTBAvalia

void TesteTBEvaluation::testeValido() {
    try {
        string Avalia_Valido = "4";
        avalia->setValue(Avalia_Valido);
        if (avalia->getValue() != Avalia_Valido)
        {
            cout << "Teste de valor valido para Avaliacao falhou!" << endl;
            cout << "Erro: " << "valor alterado" << endl;
        } else {
             cout << "Teste de valor valido para Avaliacao realizado com sucesso!" << endl;
        }
    } catch (invalid_argument& e) {
         cout << "Teste de valor valido para Avaliacao falhou!" << endl;
        cout << "Erro: " << e.what() << endl;
    }
   
}

void TesteTBEvaluation::testeInvalido() {
    try {
        string Avalia_Invalido = "7";
        avalia->setValue(Avalia_Invalido);
        cout << "Erro: " << "O valor passou pela validacao" << endl;
        cout << "Teste de valor invalido para Avaliacao falhou!" << endl;
    } catch (invalid_argument& e) {
        cout << "Teste de valor invalido para Avaliacao realizado com sucesso!" << endl;
    }
}

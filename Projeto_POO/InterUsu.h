/*
 * File:   InterfaceUsuario.h
 * Author: Vitor
 *
 * Created on 13 de Fevereiro de 2013, 12:36
 */

#ifndef INTERFACEUSUARIO_H
#define	INTERFACEUSUARIO_H

class BasicScreen {
protected:
    virtual void showScreen() = 0;
    virtual void verOptions() = 0;
public:
    BasicScreen(User user);
    virtual void telaExec();
    void exec();
};

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

};

class PostPageAut : public BasicScreen {
private:
    static const unsigned int N_OPCOES = 3;
    static const unsigned int N_APOST = 1;
    static const unsigned int N_SUBCOMENT = 2;
    static const unsigned int N_SAIR = 3;

public:
    void showScreen();
    void verOptions();
};

class PostPageNAut : public BasicScreen {
private:
    static const unsigned int N_OPCOES = 2;
    static const unsigned int N_MOSTEXTO = 1;
    static const unsigned int N_SUBCOMENT = 2;

public:
    void showScreen();
    void verOptions();
};

class MenuLogin : public BasicScreen {
private:
    static const unsigned int N_OPCOES = 5;
    static const unsigned int N_ALTERAR = 1;
    static const unsigned int N_ENCERRAR = 2;
    static const unsigned int N_POSTAR = 3;
    static const unsigned int N_LISTAR_POST = 4;
    static const unsigned int N_LISTAR_IDENT = 5;

public:
    void showScreen();
    void verOptions();
};


#endif	/* INTERFACEUSUARIO_H */


/* 
 * File:   InterfaceUsuario.h
 * Author: Vitor
 *
 * Created on 13 de Fevereiro de 2013, 12:36
 */

#ifndef INTERFACEUSUARIO_H
#define	INTERFACEUSUARIO_H

class BasicScreen {
private:
    virtual void showDetails();
    virtual void showOptions();

public:
    BasicScreen(User user);
    void exec();
};

class StartPage : public BasicScreen {
};

class PostPage : public BasicScreen {
};

class ComentPage : public BasicScreen {
};


#endif	/* INTERFACEUSUARIO_H */


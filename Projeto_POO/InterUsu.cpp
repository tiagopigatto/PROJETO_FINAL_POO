#include "InterUsu.h"
#include "IUProtocols.h"

void InitialIUControler::showOptions() {

    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;
    cout << "1. Usuario." << endl;
    cout << "2. Postagem" << endl;
    cout << "4. Sair." << endl;

}

void InitialIUControler::exec() {

    short int option;
    while (1) {
        if (this->option[1] == -1) {
            this->showOptions();
            cin >> option[0];
            
            switch (option[0]) {
                case OPCAO_USUARIO:
                    userProto->setUser(user);
                    userProto.exec();
                    user = userProto.getUser();
                case OPCAO_POSTAGEM:
                    postProto->setUser(user);
                    this->user = postProto.exec();
                    
                case OPCAO_LISTA_POSTAGENS:
                    this->post = postProto.exec();
                case OPCAO_ENCERRAR:
                    return;
                default:
                    cout << "Digite um opcao valida";
            }
        } else {

        }
    }
}


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
        this->showOptions();
        cin >> option;

        switch (option) {
            case OPCAO_USUARIO:
                userProto->setUser(user);
                userProto.exec();
                user = userProto.getUser();
            case OPCAO_POSTAGEM:
                postProto->setUser(user);
                this->user = postProto->exec();
                post = postProto->getPost();

                if (post != NULL) {
                    comentProto->setUser(user);
                    comentProto->setPost(post);
                    comentProto->exec();
                }

            case OPCAO_ENCERRAR:
                return;
            default:
                cout << "Digite um opcao valida";
        }

    }
}

void UserControler::showScreen() {
    int i = 1;
    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;
    if (user == NULL) {
        cout << i++ << ". Login." << endl;
        cout << i++ << " Cadastrar" << endl;
    } else {
        cout << i++ << ". Modificar." << endl;
        cout << i++ << ". Deletar" << endl;
        cout << i++ << ". Deslogar." << endl;
    }
    cout << i++ << ". Listar Usuarios." << endl;
    cout << i << ". Sair." << endl;

}

void UserControler::exec() {
    int option;
    while (1) {
        LIMPATELA
        showScreen();
        cin >> option;
        if (user == NULL) {
            switch (option) {
                case N_LOGIN:
                    this->logar();
                case N_CADASTRO:
                    this->cadastrar();
                case (N_LIST_USUARIOS - 1):
                    this->showList();
                case (N_SAIR - 1):
                    return;
                default:
                    cout << "Digite Uma Opçao valida";
            }
        } else {
            switch (option) {
                case N_MODIFICAR:
                    this->modificar();
                case N_DELETAR:
                    this->deletar();
                    return;
                case N_DESLOGAR:
                    delete user;
                    user = NULL;
                    return;
                case N_LIST_USUARIOS:
                    this->showList();
                case N_SAIR - 1:
                    return;
                default:
                    cout << "Digite Uma Opçao valida";
            }
        }
    }
}

void UserControler :: logar()
{
    
}

void UserControler :: cadastrar()
{
    
}

void UserControler :: showList()
{
    
}

void UserControler :: deletar()
{
    
}

void UserControler :: modificar()
{
    
}



void PostControler::showScreen() {
    int i = 1;
    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;
    if (user != NULL) {
        cout << i++ << ". Lista meus Posts." << endl;
        cout << i++ << ". Modifica Post" << endl;
        cout << i++ << ". Deleta Post" << endl;
        cout << i++ << ". Cria Post" << endl;
        cout << i++ << ". Avalia Post" << endl;
    }
    cout << i++ << ". Listar Posts." << endl;
    cout << i++ << ". Ver Posts Detalhado." << endl;
    cout << i << ". Sair." << endl;

}

void PostControler::exec() {
    int option;
    while (1) {
        LIMPATELA
        showScreen();
        cin >> option;
        if (user != NULL) {
            switch (option) {
                case N_LISTAMEUSPOSTS:
                    this->listaMeus();
                case N_MODIFICAPOST:
                    this->modifica();
                case N_DELETAPOST:
                    this->deleta();
                case N_CRIAPOST:
                    this->cria();
                case N_AVALIAPOST:
                    this->avalia();
                case N_LISTATODOSPOSTS:
                    this->showlist();
                case N_VERPOSTSDETALHADO:
                    this->mostra();
                    return;
                case N_SAIR:
                    return;
                default:
                    cout << "Digite Uma Opçao valida";
            }
        } else {
            switch (option) {
                case (N_LISTATODOSPOSTS - 5):
                    this->showlist();
                case (N_VERPOSTSDETALHADO - 5):
                    this->mostra();
                    return;
                case (N_SAIR - 5):
                    return;
                default:
                    cout << "Digite Uma Opçao valida";
            }
        }
    }
}

void PostControler :: listaMeus()
{
    
}

void PostControler :: modifica()
{
    
}

void PostControler :: deleta()
{
    
}

void  PostControler :: cria()
{
    
}

void PostControler :: avalia()
{
    
}

void PostControler :: showlist()
{
    
}

void PostControler :: mostra()
{
    
}




void ComentControler::showScreen() {
    int i = 1;
    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;
    if (user != NULL) {
        cout << i++ << ". Deleta comentario." << endl;
        cout << i++ << ". Modifica comentario" << endl;
        cout << i++ << ". Faz comentario" << endl;
    }
    cout << i++ << ". Listar Comentarios." << endl;
    cout << i++ << ". Mostra Comentario." << endl;
    cout << i << ". Sair." << endl;

}

void ComentControler::exec() {
    int option;
    while (1) {
        LIMPATELA
        showScreen();
        cin >> option;
        if (user != NULL) {
            switch (option) {
                case N_DELETACOMENT:
                    this->deleta();
                case N_MODIFICACOMENT:
                    this->modifica();
                case N_FAZCOMENT:
                    this->cria();
                case N_LISTACOMENT:
                    this->lista();
                case N_MOSTRACOMENT:
                    this->show();
                case N_SAIR:
                    return;
                default:
                    cout << "Digite Uma Opçao valida";
            }
        } else {
            switch (option) {
                case (N_LISTACOMENT - 3):
                    this->lista();
                case (N_MOSTRACOMENT - 3):
                    this->show();
                case (N_SAIR - 3):
                    return;
                default:
                    cout << "Digite Uma Opçao valida";
            }
        }
    }
}

void ComentControler :: deleta()
{
    
}

void ComentControler :: modifica()
{
    
}


void ComentControler :: cria()
{
    
}

void ComentControler :: lista()
{
    
}

void ComentControler :: show()
{
    
}
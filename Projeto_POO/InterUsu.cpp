#include "InterUsu.h"

void InitialIUControler::showOptions() {

    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;
    cout << "1. Opcoes de Usuario." << endl;
    cout << "2. Listar Usuarios." << endl;
    cout << "3. Listar Posts." << endl;
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
                    this->user = userProto.exec(this->user, option);
                case OPCAO_LISTA_USUARIOS:
                    this->user = userProto.exec(this->user, option);
                case OPCAO_LISTA_POSTAGENS:
                    this->post = postProto.exec(this->post, option);
                case OPCAO_ENCERRAR:
                    return;
                default:
                    cout << "Digite um opcao valida";
            }
        } else {

        }
    }
}

void StartPage::showScreen() {
    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;
    cout << "1. Fazer login." << endl;
    cout << "2. Realizar cadastro." << endl;
    cout << "3. Listar identificadores dos usu�rios." << endl;
    cout << "4. Listar identificadores das postagens." << endl;
    cout << "5. Listar postagens." << endl;
    cout << "6. Sair." << endl;
}

void StartPage::verOptions() {
    unsigned int opc;
    bool acheck;
    while (true) {
        opc = 0;
        while (opc == 0 || opc > N_OPCOES) {
            LIMPATELA;
            showScreen();
            cout << "Digite uma opcao: "
                    cin >> opc;
        }
        switch (opc) {
            case N_LOGIN:
                cout << "**********************************" << endl;
                cout << "********** SISTEMA BLOG **********" << endl;
                cout << "**********************************" << endl;
                cout << "PAGINA DE LOGIN" << endl;

                cout << "Digite o nome de usuario: ";
                cin >> nomeUsuario;
                cout << "Digite a senha do usuario: "
                        cin >> senhaUsuario;
                cout << "Digite o identificador do usuario: "
                        cin << identUsuario;

                try {
                    UserName name = new UserName(nomeUsuario);
                    Password senha = new Password(senhaUsuario);
                    Identify identificador = new Identify(identUsuario);
                    user = new User(name, senha, identificador);
                    bool acheck = loginUser(user);
                    if (acheck == 0) {
                        cout << "N�o encontrou o usu�rio!" << endl;
                        break;
                    }
                    postlogado = new PostPageAut();
                    postlogado.usuariologado = user;

                    menu = new MenuLogin();
                    menu.usuariologado = user;
                    MenuLogin verifica;
                    menu.verOptions();
                } catch (invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                    system("PAUSE");
                    return;
                }

                break;
            case N_CADASTRO:
                cout << "**********************************" << endl;
                cout << "********** SISTEMA BLOG **********" << endl;
                cout << "**********************************" << endl;
                cout << "PAGINA DE CADASTRO" << endl;

                cout << "Digite o nome de usuario: ";
                cin >> nomeUsuario;
                cout << "Digite a senha do usuario: "
                        cin >> senhaUsuario;
                cout << "Digite o identificador do usuario: "
                        cin << identUsuario;
                try {
                    UserName name = new UserName(nomeUsuario);
                    Password senha = new Password(senhaUsuario);
                    Identify identificador = new Identify(identUsuario);
                    user = new User(name, senha, identificador);
                    //joga no banco de daddos
                } catch (invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                    system("PAUSE");
                    return;
                }
                break;
            case N_LIU:
                //Chama a fun��o que lista os identificadores dos usuarios
                break;
            case N_LIP:
                //Chama a fun��o que lista os identificadores das postagens
                break;
            case N_LP:
                //Chama a fun��o que lista as postagens
                break;
            case N_SAIR:
                //Encerra o programa
                break;

        }

    }

}

void PostPageAut::showScreen() {
    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;
    cout << "PAGINA DO POST" << endl
    cout << "1. Mostrar postagem." << endl;
    cout << "2. Mostrar coment�rios." << endl;
    cout << "3. Comentar postagem." << endl;
    cout << "4. Avaliar postagem." << endl;
    cout << "5. Sair." << endl;
}

void PostPageAut::verOptions() {
    unsigned int opc;
    while (true) {
        opc = 0;
        while (opc == 0 || opc > N_OPCOES) {
            LIMPATELA;
            showScreen();
            cout << "Digite uma opcao: "
                    cin >> opc;
        }
        switch (opc) {
            case N_MOSTRAPOST:
                //mostra o texto da postagem
                break;
            case N_MOSTRACOMENT:
                //mostra os comentarios da postagem
                break;
            case N_COMENTPOST:
                cout << "Digite o coment�rio: ";
                cin >> comentario;
                cout << "Digite o identificador da postagem: ";
                cin << identificador;

                try {
                    ComentText comentario = new ComentText(comentario);
                    Identify comentId = new Identify(identificador);
                    //setar a data do comentario (banco de dados ou manual?)
                    comment = new Coment(usuariologado.getAuthorIdentify(), postatual.getPostIdentify(), comentId, comentario, /*DATA*/);
                } catch (invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                    system("PAUSE");
                    return;
                }

                break;
            case N_AVALIAPOST:
                int numnotas;
                cout << "Digite uma nota de 0 a 5 para esta postagem: ";
                cin >> nota;
                break;

                try {
                    postatual.setEvaluation(new Evaluation(nota));
                } catch (invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                    system("PAUSE");
                    return;
                }

            case N_SAIR:
                //volta omenu
                break;

        }

    }
}

void PostPageNAut::showScreen() {
    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;
    cout << "PAGINA DO POST (NAO AUTENTICADO)" << endl
    cout << "1. Mostrar postagem." << endl;
    cout << "2. Mostrar coment�rios." << endl;
    cout << "3. Sair." << endl;
}

void PostPageNAut::verOptions() {
    unsigned int opc;
    while (true) {
        opc = 0;
        while (opc == 0 || opc > N_OPCOES) {
            LIMPATELA;
            showScreen();
            cout << "Digite uma opcao: "
                    cin >> opc;
        }
        switch (opc) {
            case N_MOSTRAPOST:
                //mostra a postagem selecionada
                break;
            case N_MOSTRACOMENT:
                //mostra os comentarios da postagem
                break;
            case N_SAIR:
                //volta omenu
                break;

        }

    }
}

void MenuLogin::showScreen() {
    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;
    cout << "PAGINA DO USUARIO" << endl
    cout << "1. Alterar dados." << endl;
    cout << "2. Encerrar conta." << endl;
    cout << "3. Fazer postagem." << endl;
    cout << "4. Listar postagens." << endl;
    cout << "5. Listar identificadores." << endl;
    cout << "6. Sair." << endl;
}

void MenuLogin::verOptions() {
    unsigned int opc;
    while (true) {
        opc = 0;
        while (opc == 0 || opc > N_OPCOES) {
            LIMPATELA;
            showScreen();
            cout << "Digite uma opcao: "
                    cin >> opc;
        }
        switch (opc) {
            case N_ALTERAR:
                cout << "**********************************" << endl;
                cout << "********** SISTEMA BLOG **********" << endl;
                cout << "**********************************" << endl;
                cout << "PAGINA DE ALTERACAO DE USUARIO" << endl;

                cout << "Digite o nome de usuario: ";
                cin >> nomeUsuario;
                cout << "Digite a senha do usuario: "
                        cin >> senhaUsuario;
                cout << "Digite o identificador do usuario: "
                        cin << identUsuario;

                try {
                    UserName name = new UserName(nomeUsuario);
                    Password senha = new Password(senhaUsuario);
                    Identify identificador = new Identify(identUsuario);
                    user = new User(name, senha, identificador);

                    postlogado = new PostPageAut();
                    postlogado.usuariologado = user;

                    menu = new MenuLogin();
                    menu.usuariologado = user;
                    MenuLogin verifica;
                } catch (invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                    system("PAUSE");
                    return;
                }
                break;
            case N_ENCERRAR:
                //deleta do BD
                break;
            case N_POSTAR:
                cout >> "Digite o texto da postagem: ";
                cin << textoPost;
                cout >> "Digite o identificador da postagem: ";
                cin << identPost;

                try {
                    PostText texto = new PostText(textoPost);
                    Identify ident = new Identify(identPost);
                    post = new Post(usuariologado.getIdentify(), ident, texto, /*DATA*/);
                } catch (invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                    system("PAUSE");
                    return;
                }


                break;
            case N_LISTAR_POST:
                //mostra os comentarios da postagem
                break;
            case N_LISTAR_IDENT:
                //mostra os comentarios da postagem
                break;
            case N_SAIR:
                //volta omenu
                break;

        }

    }
}

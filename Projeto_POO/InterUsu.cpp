
#include "InterUsu.h"

#define LIMPATELA system("cls");

void StartPage::showScreen()
{
    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;
    cout << "1. Fazer login." << endl;
    cout << "2. Realizar cadastro." << endl;
    cout << "3. Listar identificadores dos usuários." << endl;
    cout << "4. Listar identificadores das postagens." << endl;
    cout << "5. Listar postagens." << endl;
    cout << "6. Sair." << endl;
}

void StartPage::verOptions()
{
    unsigned int opc;
    bool acheck;
    while(true)
    {
        opc = 0;
        while(opc==0 || opc > N_OPCOES)
        {
            LIMPATELA;
            showScreen();
            cout << "Digite uma opcao: "
                 cin >> opc;
        }
        switch(opc)
        {
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
            user = new User();
            try
            {
                UserName name = new UserName(nomeUsuario);
                Password senha = new Password(senhaUsuario);
                Identify identificador = new Identify(identUsuario);
                bool acheck = loginUser(user);
                if(acheck == 0){
                    cout << "Não encontrou o usuário!" << endl;
                    break;
                }
                postlogado = new PostPageAut();
                postlogado.usuariologado = user;

                menu = new MenuLogin();
                menu.usuariologado = user;
                MenuLogin verifica;
                menu.verOptions();
            }
            catch(invalid_argument& e)
            {
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
            user = new User();
            try
            {
                UserName name = new UserName(nomeUsuario);
                Password senha = new Password(senhaUsuario);
                Identify identificador = new Identify(identUsuario);
            }
            catch(invalid_argument& e)
            {
                cout << "Error: " << e.what() << endl;
                system("PAUSE");
                return;
            }
            break;
        case N_LIU:
            //Chama a função que lista os identificadores dos usuarios
            break;
        case N_LIP:
            //Chama a função que lista os identificadores das postagens
            break;
        case N_LP:
            //Chama a função que lista as postagens
            break;
        case N_SAIR:
            //Encerra o programa
            break;

        }

    }

}

void PostPageAut::showScreen()
{
    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;
    cout << "PAGINA DO POST" << endl
    cout << "1. Mostrar postagem." << endl;
    cout << "2. Mostrar comentários." << endl;
    cout << "3. Comentar postagem." << endl;
    cout << "4. Avaliar postagem." << endl;
    cout << "5. Sair." << endl;
}

void PostPageAut::verOptions()
{
    unsigned int opc;
    while(true)
    {
        opc = 0;
        while(opc==0 || opc > N_OPCOES)
        {
            LIMPATELA;
            showScreen();
            cout << "Digite uma opcao: "
                 cin >> opc;
        }
        switch(opc)
        {
        case N_MOSTRAPOST:
            //usuario seleciona o ID da postagem
            break;
        case N_MOSTRACOMENT:
            //mostra os comentarios da postagem
            break;
        case N_COMENTPOST:
            cout << "Digite o comentário: ";
            cin >> comentario;

            comment = new Coment();
            try{
            ComentText comentario = new ComentText(comentario);
            comment.authorIdentify = usuariologado.getAuthorIdentify();
            comment.postIdentify = postatual.getPostIdentify();
            //setar o identificador do comentario (banco de dados ou manual?)
            //setar a data do comentario (banco de dados ou manual?)
            }
            catch(invalid_argument& e)
            {
                cout << "Error: " << e.what() << endl;
                system("PAUSE");
                return;
            }

            break;
        case N_AVALIAPOST:
            cout << "Digite uma nota de 0 a 5 para esta postagem: ";
            cin >> nota;
            break;
        case N_SAIR:
            //volta omenu
            break;

        }

    }
}

void PostPageNAut::showScreen()
{
    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;
    cout << "PAGINA DO POST (NAO AUTENTICADO)" << endl
         cout << "1. Mostrar postagem." << endl;
    cout << "2. Mostrar comentários." << endl;
    cout << "3. Sair." << endl;
}

void PostPageNAut::verOptions()
{
    unsigned int opc;
    while(true)
    {
        opc = 0;
        while(opc==0 || opc > N_OPCOES)
        {
            LIMPATELA;
            showScreen();
            cout << "Digite uma opcao: "
                 cin >> opc;
        }
        switch(opc)
        {
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

void MenuLogin::showScreen()
{
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

void MenuLogin::verOptions()
{
    unsigned int opc;
    while(true)
    {
        opc = 0;
        while(opc==0 || opc > N_OPCOES)
        {
            LIMPATELA;
            showScreen();
            cout << "Digite uma opcao: "
                 cin >> opc;
        }
        switch(opc)
        {
        case N_ALTERAR:
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
            user = new User();
            try
            {
                UserName name = new UserName(nomeUsuario);
                Password senha = new Password(senhaUsuario);
                Identify identificador = new Identify(identUsuario);
                bool acheck = loginUser(user);
                if(acheck == 0){
                    cout << "Não encontrou o usuário!" << endl;
                    break;
                }
                postlogado = new PostPageAut();
                postlogado.usuariologado = user;

                menu = new MenuLogin();
                menu.usuariologado = user;
                MenuLogin verifica;
                menu.verOptions();
            }
            catch(invalid_argument& e)
            {
                cout << "Error: " << e.what() << endl;
                system("PAUSE");
                return;
            }

            break;
        case N_ENCERRAR:
            //mostra os comentarios da postagem
            break;
        case N_POSTAR:
            //mostra os comentarios da postagem
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


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

            try{
                //digitar funçao de login
            }
            catch(invalid_argument& e){
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

            try{
            username.setValue(nomeUsuario);
            password.setValue(senhaUsuario);
            identificador.setValue(identUsuario);
            }
            catch(invalid_argument& e){
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
            //mostra a postagem selecionada
            break;
        case N_MOSTRACOMENT:
            //mostra os comentarios da postagem
            break;
        case N_COMENTPOST:
            //abre para comentar a pagina
            break;
        case N_AVALIAPOST:
            //abre para avaliar a postagem
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

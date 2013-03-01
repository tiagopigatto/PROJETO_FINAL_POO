
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
            //verifica login e loga o usuario no sistema
            break;
        case N_CADASTRO:
            //mostra a pagina de cadastro
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
    cout << "PAGINA DO USUARIO" << endl
    cout << "1. Postar." << endl;
    cout << "2. Listar postagens" << endl;
    cout << "3. Sair." << endl;
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
        case N_LOGIN:
            //verifica login e loga o usuario no sistema
            break;
        case N_CADASTRO:
            //mostra a pagina de cadastro
            break;
        case N_SAIR:
            //Encerra o programa
            break;

        }

    }
}

void PostPageNAut::showScreen()
{

}

void PostPageNAut::showScreen()
{

}

void MenuLogin::showScreen()
{

}

void MenuLogin::verOptions()
{

}

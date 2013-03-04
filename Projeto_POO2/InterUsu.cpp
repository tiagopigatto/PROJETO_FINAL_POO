#include "InterUsu.h"

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
                userProto->exec();
                user = userProto->getUser();
            case OPCAO_POSTAGEM:
                postProto->setUser(user);
                postProto->exec();
                post = postProto->getPost();

                if (post != NULL) {
                    comentProto->setUser(user);
                    comentProto->setPost(post);
                    comentProto->exec();
                }

            case OPCAO_ENCERRAR:
                return;
            default:
                cout << "Digite uma opcao valida";
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
        cout << i++ << ". Cadastrar" << endl;
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
                    break;
                case N_CADASTRO:
                    this->cadastrar();
                    break;
                case (N_LIST_USUARIOS - 1):
                    this->showList();
                    break;
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
                    deletar();
                    return;
                case N_LIST_USUARIOS:
                    this->showList();
                case N_SAIR:
                    return;
                default:
                    cout << "Digite Uma Opçao valida";
            }
        }
    }
}

void UserControler::logar() {
    string nome;
    string senha;
    string id;

    char option;

    UserName username;
    Password password;
    Identify identify;

    User user;
    while (1) {
        cout << "**********************************" << endl;
        cout << "********** SISTEMA BLOG **********" << endl;
        cout << "**********************************" << endl;
        cout << "Digite o seu identificador" << endl;
        cin >> id;
        cout << "Digite o seu nome de usuario" << endl;
        cin >> nome;
        cout << "Digite a sua senha" << endl;
        cin >> senha;

        try {
            username.setValue(nome);
            password.setValue(senha);
            identify.setValue(id);
        } catch (invalid_argument e) {
            cout << "Nome de Usuario, senha ou identificador Incorreto";

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;
        }

        user.setName(username);
        user.setIdentify(identify);
        user.setPassword(password);
        try {
            protocol->autenticar(user);
        } catch (LogicError time) //nao bateu
        {
            cout << "Nome de Usuario, senha ou identificador Incorreto";

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;
        } catch (PercistenceError time) //erro no banco de dados
        {
            cout << time.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;
        }
        User *pont = new User(user.getName(), user.getPassword(), user.getIdentify());

        this->user = pont;
        return;
    }
}

void UserControler::cadastrar() {
    string nome;
    string senha;
    string id;

    char option;

    UserName username;
    Password password;
    Identify identify;

    User user;
    while (1) {
        cout << "**********************************" << endl;
        cout << "********** SISTEMA BLOG **********" << endl;
        cout << "**********************************" << endl;
        cout << "Digite o seu identificador que deseja" << endl;
        cin >> id;
        cout << "Digite o seu nome de usuario que deseja" << endl;
        cin >> nome;
        cout << "Digite a senha que deseja" << endl;
        cin >> senha;

        try {
            username.setValue(nome);
            password.setValue(senha);
            identify.setValue(id);
        } catch (invalid_argument e) {
            cout << e.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;
        }

        user.setName(username);
        user.setIdentify(identify);
        user.setPassword(password);
        try {
            protocol->cadastrar(user);
        } catch (PercistenceError time) //erro no banco de dados
        {
            cout << time.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;

        }

        User *pont = new User(user.getName(), user.getPassword(), user.getIdentify());
        this->user = pont;

        return;
    }
}

void UserControler::showList() {
    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;

    std::list<User> mylist;
    std::list<User>::iterator it;
    mylist = protocol->Listar();
    UserName username;
    Identify id;
    User user;

    for (it = mylist.begin(); it != mylist.end(); ++it) {
        user = *it;
        username = user.getName();
        id = user.getIdentify();
        cout << "Usuario: ";

        cout << username.getValue() << endl;
        cout << "Com numero de ID: ";

        cout << id.getValue() << endl;
    }
}

void UserControler::deletar() {
    try {
        User user;
        Identify id;
        user.setIdentify((this->user)->getIdentify());
        protocol->deletar(user);
        delete this->user;
        this->user = NULL;
    } catch (PercistenceError time) //erro no banco de dados
    {
        cout << time.what();
    }
}

void UserControler::modificar() {
    string nome;
    string senha;
    string id;

    char option;

    UserName username;
    Password password;

    User *user = new User();

    while (1) {
        cout << "**********************************" << endl;
        cout << "********** SISTEMA BLOG **********" << endl;
        cout << "**********************************" << endl;
        cout << "Digite o seu novo nome de usuario que deseja" << endl;
        cin >> nome;
        cout << "Digite a sua nova senha que deseja" << endl;
        cin >> senha;
        try {
            username.setValue(nome);
            password.setValue(senha);
        } catch (invalid_argument e) {
            cout << e.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;
        }
        user->setIdentify(this->user->getIdentify());
        user->setName(username);
        user->setPassword(password);
        try {
            User time;
            time.setIdentify(user->getIdentify());
            time.setPassword(user->getPassword());
            time.setName(user->getName());
            protocol->update(time);
        } catch (PercistenceError time) //erro no banco de dados
        {
            cout << time.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;

        }
        this->user = user;
        return;
    }
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

void PostControler::listaMeus() {
    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;
    Post post;
    post.setAuthorIdentify(user->getIdentify());

    std::list<Post> mylist;
    std::list<Post>::iterator it;
    mylist = protocol->listarPorUser(post);

    for (it = mylist.begin(); it != mylist.end(); ++it) {
        cout << "Postagem do usuario: ";
        cout << ((Identify) ((Post) * it).getAuthorIdentify()).getValue() << endl;
        cout << "ID da postagem: ";
        cout << ((Identify) ((Post) * it).getPostIdentify()).getValue() << endl;
        cout << "Postado no dia: ";
        cout << ((Date) ((Post) * it).getDate()).getValue() << endl;
        cout << "Avaliacao do post: ";
        cout << ((Evaluation) ((Post) * it).getEvaluation()).getValue() << endl;
    }
}

void PostControler::modifica() {
    string id;
    string texto;

    char option;

    Identify ident;
    PostText posttext;


    User *user;
    Post postagem;

    user = this->user;
    while (1) {
        cout << "**********************************" << endl;
        cout << "********** SISTEMA BLOG **********" << endl;
        cout << "**********************************" << endl;
        cout << "Digite o id do post que quer modificar" << endl;
        cin >> id;
        cout << "Digite o texto" << endl;
        cin >> texto;

        try {
            ident.setValue(id);
            posttext.setValue(texto);
        } catch (invalid_argument e) {
            cout << e.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;
        }

        postagem.setPostText(posttext);
        try {
            protocol->novo(postagem);
        } catch (PercistenceError time) //erro no banco de dados
        {
            cout << time.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;

        }
        Post *post;
        post->setAuthorIdentify(postagem.getAuthorIdentify());
        post->setDate(postagem.getDate());
        post->setEvaluation(postagem.getEvaluation());
        post->setPostIdentify(postagem.getPostIdentify());
        post->setPostText(postagem.getPostText());


        this->post = post;
        return;
    }
}

void PostControler::deleta() {
    string id;


    char option;

    Identify ident;


    User user;
    Post postagem;

    while (1) {
        cout << "**********************************" << endl;
        cout << "********** SISTEMA BLOG **********" << endl;
        cout << "**********************************" << endl;
        cout << "Digite o id do post que quer deletar" << endl;
        cin >> id;

        try {
            ident.setValue(id);
        } catch (invalid_argument e) {
            cout << e.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;
        }

        try {
            protocol->novo(postagem);
        } catch (PercistenceError time) //erro no banco de dados
        {
            cout << time.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;

        }
        Post *post;
        post->setAuthorIdentify(postagem.getAuthorIdentify());
        post->setDate(postagem.getDate());
        post->setEvaluation(postagem.getEvaluation());
        post->setPostIdentify(postagem.getPostIdentify());
        post->setPostText(postagem.getPostText());


        this->post = post;


        return;
    }
}

void PostControler::cria() {
    string id;
    string texto;
    string data;
    string nota = "5";

    char option;

    Identify ident;
    PostText posttext;
    Date date;
    Evaluation evaluation;

    evaluation.setValue(nota);

    Post postagem;

    while (1) {
        cout << "**********************************" << endl;
        cout << "********** SISTEMA BLOG **********" << endl;
        cout << "**********************************" << endl;
        cout << "Digite o id do seu post" << endl;
        cin >> id;
        cout << "Digite o texto" << endl;
        cin >> texto;
        cout << "Digite a data (DD-MM-AAAA)" << endl;
        cin >> data;

        try {
            ident.setValue(id);
            posttext.setValue(texto);
            date.setValue(data);
        } catch (invalid_argument e) {
            cout << e.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;
        }

        postagem.setAuthorIdentify(this->user->getIdentify());
        postagem.setPostIdentify(ident);
        postagem.setPostText(posttext);
        postagem.setDate(date);
        postagem.setEvaluation(evaluation);

        try {
            protocol->novo(postagem);
        } catch (PercistenceError time) //erro no banco de dados
        {
            cout << time.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;

        }
        Post *post;
        post->setAuthorIdentify(postagem.getAuthorIdentify());
        post->setDate(postagem.getDate());
        post->setEvaluation(postagem.getEvaluation());
        post->setPostIdentify(postagem.getPostIdentify());
        post->setPostText(postagem.getPostText());


        this->post = post;
        return;
    }
}

void PostControler::avalia() {
    string id;
    string nota;

    char option;

    Identify ident;
    Evaluation evaluation;


    User user;
    Post postagem;

    while (1) {
        cout << "**********************************" << endl;
        cout << "********** SISTEMA BLOG **********" << endl;
        cout << "**********************************" << endl;
        cout << "Digite o id do post que quer avaliar" << endl;
        cin >> id;
        cout << "Digite a nota " << endl;
        cin >> nota;

        try {
            ident.setValue(id);
            evaluation.setValue(nota);
        } catch (invalid_argument e) {
            cout << e.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;
        }

        postagem.setPostIdentify(ident);
        postagem.setEvaluation(evaluation);

        try {
            protocol->novo(postagem);
        } catch (PercistenceError time) //erro no banco de dados
        {
            cout << time.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;

        }
        Post *post;
        post->setAuthorIdentify(postagem.getAuthorIdentify());
        post->setDate(postagem.getDate());
        post->setEvaluation(postagem.getEvaluation());
        post->setPostIdentify(postagem.getPostIdentify());
        post->setPostText(postagem.getPostText());


        this->post = post;
        return;
    }
}

void PostControler::showlist() {
    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;

    std::list<Post> mylist;
    std::list<Post>::iterator it;
    
    this->post = post;
    mylist = protocol->listar();

    for (it = mylist.begin(); it != mylist.end(); ++it) {
        cout << "Postagem do usuario: ";
        cout << ((Identify) ((Post) * it).getAuthorIdentify()).getValue() << endl;
        cout << "ID da postagem: ";
        cout << ((Identify) ((Post) * it).getPostIdentify()).getValue() << endl;
        cout << "Postado no dia: ";
        cout << ((Date) ((Post) * it).getDate()).getValue() << endl;
        cout << "Avaliacao do post: ";
        cout << ((Evaluation) ((Post) * it).getEvaluation()).getValue() << endl;
    }
}

void PostControler::mostra() {
    string id;
    char option;
    Identify ident;
    Post postagem;

    while (1) {
        cout << "**********************************" << endl;
        cout << "********** SISTEMA BLOG **********" << endl;
        cout << "**********************************" << endl;
        cout << "Digite o id do Post" << endl;
        cin >> id;

        try {
            ident.setValue(id);
        } catch (invalid_argument e) {
            cout << e.what();
            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;
        }

        postagem.setPostIdentify(ident);


        try {
            
            postagem = protocol->pegar(postagem);
        } catch (PercistenceError time) //erro no banco de dados
        {
            cout << time.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;

        }
        
        Post *post;
        post->setAuthorIdentify(postagem.getAuthorIdentify());
        post->setDate(postagem.getDate());
        post->setEvaluation(postagem.getEvaluation());
        post->setPostIdentify(postagem.getPostIdentify());
        post->setPostText(postagem.getPostText());
        this->post = post;
        return;
    }

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

void ComentControler::deleta() {
    string id;

    char option;

    Identify ident;

    Coment coment;

    while (1) {
        cout << "**********************************" << endl;
        cout << "********** SISTEMA BLOG **********" << endl;
        cout << "**********************************" << endl;
        cout << "Digite o id do comentario que quer deletar" << endl;
        cin >> id;

        try {
            ident.setValue(id);
        } catch (invalid_argument e) {
            cout << e.what();
            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;
        }

        coment.setComentIdentify(ident);


        try {
            protocol->novo(coment);
        } catch (PercistenceError time) //erro no banco de dados
        {
            cout << time.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;

        }
        return;
    }
}

void ComentControler::modifica() {
    string texto;
    string id;

    char option;

    Identify ident;
    ComentText comentext;

    Coment coment;

    while (1) {
        cout << "**********************************" << endl;
        cout << "********** SISTEMA BLOG **********" << endl;
        cout << "**********************************" << endl;
        cout << "Digite o id do comentario que quer modificar" << endl;
        cin >> id;
        cout << "Digite o texto" << endl;
        cin >> texto;

        try {
            ident.setValue(id);
            comentext.setValue(texto);
        } catch (invalid_argument e) {
            cout << e.what();
            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;
        }

        coment.setComentIdentify(ident);
        coment.setComentText(comentext);


        try {
            protocol->novo(coment);
        } catch (PercistenceError time) //erro no banco de dados
        {
            cout << time.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;

        }
        return;
    }
}

void ComentControler::cria() {
    string texto;
    string id;
    string data;

    char option;

    Identify ident;
    ComentText comentext;
    Date date;

    Coment coment;

    while (1) {
        cout << "**********************************" << endl;
        cout << "********** SISTEMA BLOG **********" << endl;
        cout << "**********************************" << endl;
        cout << "Digite o id do seu comentario" << endl;
        cin >> id;
        cout << "Digite o texto" << endl;
        cin >> texto;
        cout << "Digite a data (DD-MM-AAAA)" << endl;
        cin >> data;

        try {
            ident.setValue(id);
            comentext.setValue(texto);
            date.setValue(data);
        } catch (invalid_argument e) {
            cout << e.what();
            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;
        }

        coment.setAuthorIdentify(user->getIdentify());
        coment.setPostIdentify(post->getPostIdentify());
        coment.setComentIdentify(ident);
        coment.setComentText(comentext);
        coment.setDate(date);


        try {
            protocol->novo(coment);
        } catch (PercistenceError time) //erro no banco de dados
        {
            cout << time.what();

            cout << "Deseja Tentar Novamente(s, n)" << endl;
            cin >> option;
            if (option == 's' || option == 'S')
                continue;
            else
                return;

        }
        return;
    }

}

void ComentControler::lista() {
    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;
    Coment coment;
    coment.getPostIdentify();

    std::list<Coment> mylist;
    std::list<Coment>::iterator it;

    mylist = protocol->listar(coment);

    for (it = mylist.begin(); it != mylist.end(); ++it) {
        cout << "Comentario do usuario: ";
        cout << ((Identify) ((Coment) * it).getAuthorIdentify()).getValue() << endl;
        cout << "No post com ID: ";
        cout << ((Identify) ((Coment) * it).getPostIdentify()).getValue() << endl;
        cout << "ID do comentario: ";
        cout << ((Identify) ((Coment) * it).getComentIdentify()).getValue() << endl;
        cout << "Comentado no dia: ";
        cout << ((Date) ((Coment) * it).getDate()).getValue() << endl;
    }
}

void ComentControler::show() {
    string comentario;
    Coment coment;
    ComentText texto;
    cout << "**********************************" << endl;
    cout << "********** SISTEMA BLOG **********" << endl;
    cout << "**********************************" << endl;
    cout << "Digite o ID do comentario que deseja ver: ";
    cin >> comentario;
    Identify id;
    id.setValue(comentario);
    coment.setComentIdentify(id);

    coment = protocol->pegar(coment);
    texto = coment.getComentText();
    comentario = texto.getValue();
    cout << comentario << endl;
}

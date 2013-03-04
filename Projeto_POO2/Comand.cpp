#include "Comand.h"

void ACommand::conect() {
    q_cnt = 5;
    q_size = 150;
    queries = (char**) malloc(sizeof (char) * q_cnt * q_size);
    retval = sqlite3_open("POO", &handle);
    sql = (char *) malloc(sizeof (char) * q_size);
    if (retval != 0) {

    }
}

void ACommand::desconect() {
    free(sql);
    sqlite3_close(handle);
}

void CommandCreateUser::execute() {

    this->conect();
    strcpy(sql, "INSERT INTO user VALUES('");
    strcat(sql, ((user.getIdentify()).getValue()).c_str());
    strcat(sql, "','");
    strcat(sql, (user.getName()).getValue().c_str());
    strcat(sql, "','");
    strcat(sql, (user.getPassword()).getValue().c_str());
    strcat(sql, "')");
    // executa nosso comando no banco 
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
    if (retval) {
        /** ID ou NOME já existe **/
    }
    this->desconect();
}

void CommandFindUser::execute() {
    this->conect();
    int ind = 0;

    strcpy(sql, "SELECT * FROM user WHERE name = '");
    strcat(sql, (user.getName()).getValue().c_str());
    strcat(sql, "'");
    queries[ind++] = sql;
    retval = sqlite3_prepare_v2(handle, queries[ind - 1], -1, &stmt, 0);
    // caso de erro
    if (retval) {
        //da trhro
    }
    Identify ident;
    UserName name;
    Password senha;
    const char *val;
    //Status
    retval = sqlite3_step(stmt);
    while (1) {
        if (retval == SQLITE_ROW) {
            val = (const char*) sqlite3_column_text(stmt, 0);
            ident.setValue(val);
            user.setIdentify(ident);

            val = (const char*) sqlite3_column_text(stmt, 1);
            name.setValue(val);
            user.setName(name);

            val = (const char*) sqlite3_column_text(stmt, 2);
            senha.setValue(val);
            user.setPassword(senha);

        } else if (retval == SQLITE_DONE) {
            break;
        }
    }
}

void CommandDeleteUser::execute() {
    this->conect();
    strcpy(sql, "UPDATE user SET name = '");
    strcat(sql, (user.getName()).getValue().c_str());
    strcpy(sql, ", password = '");
    strcat(sql, (user.getPassword()).getValue().c_str());
    strcat(sql, "' WHERE Identify = '");
    strcat(sql, (user.getIdentify()).getValue().c_str());
    strcat(sql, "'");
    // executa nosso comando no banco 
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
    if (retval) {
        /** NOME já existe **/
    }
}

void CommandFindUsers::execute() {
    int ind = 0;
    std::list<User> mylist;

    UserName nome;
    Password senha;
    Identify ident;

    User user;

    strcpy(sql, "SELECT * FROM user WHERE *");
    queries[ind++] = sql;
    retval = sqlite3_prepare_v2(handle, queries[ind - 1], -1, &stmt, 0);

    // caso de erro
    if (retval) {

    }
    const char *val;
    //Status
    retval = sqlite3_step(stmt);
    while (1) {
        if (retval == SQLITE_ROW) {
            val = (const char*) sqlite3_column_text(stmt, 0);
            ident.setValue(val);
            user.setIdentify(ident);

            val = (const char*) sqlite3_column_text(stmt, 1);
            nome.setValue(val);
            user.setName(nome);


            val = (const char*) sqlite3_column_text(stmt, 2);
            senha.setValue(val);
            user.setPassword(senha);

            mylist.push_back(user);

        } else if (retval == SQLITE_DONE) {
            break;
        }
    }
    users = mylist;

}

void CommandUpdateUser::execute() {
    this->conect();
    strcpy(sql, "UPDATE user SET name = '");
    strcat(sql, (user.getName()).getValue().c_str());
    strcpy(sql, ", password = '");
    strcat(sql, (user.getPassword()).getValue().c_str());
    strcat(sql, "' WHERE Identify = '");
    strcat(sql, (user.getIdentify()).getValue().c_str());
    strcat(sql, "'");
    // executa nosso comando no banco 
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
    if (retval) {
        /** NOME já existe **/
    }
}

void CommandCreatePost::execute() {
    this->conect();
    char aba[50];
    itoa((post.getEvaluation()).getVoteNumber(), aba, 10);

    strcpy(sql, "INSERT INTO post VALUES('");
    strcat(sql, (post.getPostIdentify()).getValue().c_str());
    strcat(sql, "','");
    strcat(sql, (post.getPostText()).getValue().c_str());
    strcat(sql, "','");
    strcat(sql, (post.getDate()).getValue().c_str());
    strcat(sql, "','");
    strcat(sql, (post.getEvaluation()).getValue().c_str());
    strcat(sql, "','");
    strcat(sql, (post.getAuthorIdentify()).getValue().c_str());
    strcat(sql, "','");
    strcat(sql, aba);
    strcat(sql, "')");
    // executa nosso comando no banco 
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
    if (retval) {
        /** ID já existe **/
    }
};

void CommandUpdatePost::execute() {
    this->conect();
    strcpy(sql, "UPDATE post SET postText = '");
    strcat(sql, (post.getPostText()).getValue().c_str());
    strcpy(sql, ", date = '");
    strcat(sql, (post.getDate()).getValue().c_str());
    ;
    strcat(sql, "' WHERE postIdentify = '");
    strcat(sql, (post.getPostIdentify()).getValue().c_str());
    strcat(sql, "'");
    // executa nosso comando no banco 
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
    if (retval) {
        /** Atualizar ID q n existe **/
    }

};

void CommandDeletePost::execute() {
    this->conect();
    strcpy(sql, "DELETE FROM post WHERE postIdentify = '");
    strcat(sql, (post.getPostIdentify()).getValue().c_str());
    strcat(sql, "'");
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
};

void CommandFindAllPost::execute() {
    this->conect();
    int ind = 0;
    std::list<Post> mylist;

    Post post;

    Identify id;
    PostText text;
    Date date;
    Evaluation eval;



    strcpy(sql, "SELECT * FROM post WHERE *");
    retval = sqlite3_prepare_v2(handle, queries[ind - 1], -1, &stmt, 0);
    // caso de erro
    if (retval) {
    }
    //Status
    retval = sqlite3_step(stmt);
    const char *val;
    while (1) {
        if (retval == SQLITE_ROW) {
            val = (const char*) sqlite3_column_text(stmt, 0);
            id.setValue(val);
            post.setPostIdentify(id);

            val = (const char*) sqlite3_column_text(stmt, 1);
            text.setValue(val);
            post.setPostText(text);


            val = (const char*) sqlite3_column_text(stmt, 2);
            date.setValue(val);
            post.setDate(date);


            val = (const char*) sqlite3_column_text(stmt, 3);
            eval.setValue(val);


            val = (const char*) sqlite3_column_text(stmt, 4);
            id.setValue(val);
            post.setAuthorIdentify(id);


            val = (const char*) sqlite3_column_text(stmt, 4);
            eval.setVoteNumber(atoi(val));
            post.setEvaluation(eval);


            mylist.push_back(post);
        } else if (retval == SQLITE_DONE) {
            break;
        }
    }
    posts = mylist;
};

void CommandFindUserPost::execute() {
    this->conect();
    int ind = 0;
    std::list<Post> mylist;

    Post post;

    Identify id;
    PostText text;
    Date date;
    Evaluation eval;



    strcpy(sql, "SELECT * FROM post WHERE User_Identify = '");
    strcat(sql, (post.getAuthorIdentify()).getValue().c_str());
    strcat(sql, "'");
    retval = sqlite3_prepare_v2(handle, queries[ind - 1], -1, &stmt, 0);
    const char *val;
    // caso de erro
    if (retval) {

    }
    //Status
    retval = sqlite3_step(stmt);
    while (1) {
        if (retval == SQLITE_ROW) {
            val = (const char*) sqlite3_column_text(stmt, 0);
            id.setValue(val);
            post.setPostIdentify(id);

            val = (const char*) sqlite3_column_text(stmt, 1);
            text.setValue(val);
            post.setPostText(text);

            val = (const char*) sqlite3_column_text(stmt, 2);
            date.setValue(val);
            post.setDate(date);

            val = (const char*) sqlite3_column_text(stmt, 3);
            eval.setValue(val);

            val = (const char*) sqlite3_column_text(stmt, 4);
            id.setValue(val);
            post.setAuthorIdentify(id);


            val = (const char*) sqlite3_column_text(stmt, 5);
            eval.setVoteNumber(atoi(val));
            post.setEvaluation(eval);


            mylist.push_back(post);
        } else if (retval == SQLITE_DONE) {
            break;
        }
    }
    posts = mylist;
};

void CommandFindPost::execute() {
    this->conect();
    int ind = 0;

    Post post;

    Identify id;
    PostText text;
    Date date;
    Evaluation eval;



    strcpy(sql, "SELECT * FROM post WHERE User_Identify = '");
    strcat(sql, (post.getAuthorIdentify()).getValue().c_str());
    strcat(sql, "'");
    retval = sqlite3_prepare_v2(handle, queries[ind - 1], -1, &stmt, 0);
    // caso de erro
    if (retval) {

    }
                const char *val;
    //Status
    retval = sqlite3_step(stmt);
    while (1) {
        if (retval == SQLITE_ROW) {
val = (const char*) sqlite3_column_text(stmt, 0);
            id.setValue(val);
            post.setPostIdentify(id);


val = (const char*) sqlite3_column_text(stmt, 1);
            text.setValue(val);
            post.setPostText(text);


val = (const char*) sqlite3_column_text(stmt, 2);
            date.setValue(val);
            post.setDate(date);


val = (const char*) sqlite3_column_text(stmt, 3);
            eval.setValue(val);


val = (const char*) sqlite3_column_text(stmt, 4);
            id.setValue(val);
            post.setAuthorIdentify(id);


val = (const char*) sqlite3_column_text(stmt, 5);
            eval.setVoteNumber(atoi(val));
            post.setEvaluation(eval);

        } else if (retval == SQLITE_DONE) {
            break;
        }
    }
    this->post = post;
};

void CommandCreateComent::execute() {
    this->conect();
    //ADD a entidade no BD
    strcpy(sql, "INSERT INTO coment VALUES('");
    strcat(sql, (coment.getComentIdentify()).getValue().c_str());
    strcat(sql, "','");
    strcat(sql, (coment.getComentText()).getValue().c_str());
    strcat(sql, "','");
    strcat(sql, (coment.getDate()).getValue().c_str());
    strcat(sql, "','");
    strcat(sql, (coment.getAuthorIdentify()).getValue().c_str());
    strcat(sql, "','");
    strcat(sql, (coment.getPostIdentify()).getValue().c_str());
    strcat(sql, "')");
    // executa nosso comando no banco 
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
    if (retval) {
        /** ID já existe **/
    }
};

void CommandUpdateComent::execute() {
    this->conect();
    strcpy(sql, "UPDATE coment SET comentText = '");
    strcat(sql, (coment.getComentText()).getValue().c_str());
    strcpy(sql, ", date = '");
    strcat(sql, (coment.getDate()).getValue().c_str());
    strcat(sql, "' WHERE comentIdentify = '");
    strcat(sql,
            (coment.getComentIdentify()).getValue().c_str());
    strcat(sql, "'");
    // executa nosso comando no banco 
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
    if (retval) {
        /** BUG **/
    }

};

void CommandDeleteComent::execute() {
    this->conect();
    //Delete na entidade no BD            
    strcpy(sql, "DELETE FROM coment WHERE comentIdentify = '");
    strcat(sql, (coment.getComentIdentify()).getValue().c_str());
    strcat(sql, "'");
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
};

void CommandFindPostComents::execute() {
    this->conect();
    std::list<Coment> mylist;

    Coment coment;

    Identify id;
    ComentText text;
    Date date;

    int ind = 0;
    strcpy(sql, "SELECT * FROM coment WHERE Post_post_Identify = '");
    strcat(sql, (coment.getPostIdentify()).getValue().c_str());
    strcat(sql, "'");

    queries[ind++] = sql;
    retval = sqlite3_prepare_v2(handle, queries[ind - 1], -1, &stmt, 0);
    // caso de erro
    if (retval) {

    }
    //Status
                const char *val;
    retval = sqlite3_step(stmt);
    while (1) {
        if (retval == SQLITE_ROW) {
val = (const char*) sqlite3_column_text(stmt, 0);
            id.setValue(val);
            coment.setComentIdentify(id);


val = (const char*) sqlite3_column_text(stmt, 1);
            text.setValue(val);
            coment.setComentText(text);


val = (const char*) sqlite3_column_text(stmt, 2);
            date.setValue(val);
            coment.setDate(date);


val = (const char*) sqlite3_column_text(stmt, 3);
            id.setValue(val);
            coment.setAuthorIdentify(id);


            val = (const char*) sqlite3_column_text(stmt, 4);
            id.setValue(val);
            coment.setPostIdentify(id);


            mylist.push_back(coment);
        } else if (retval == SQLITE_DONE) {
            break;
        }
    }
    coments = mylist;
};

void CommandFindComent::execute() {
    this->conect();


    Coment coment;

    Identify id;
    ComentText text;
    Date date;

    int ind = 0;
    strcpy(sql, "SELECT * FROM coment WHERE comentIdentify = '");
    strcat(sql, (coment.getComentIdentify()).getValue().c_str());
    strcat(sql, "'");

    queries[ind++] = sql;
    retval = sqlite3_prepare_v2(handle, queries[ind - 1], -1, &stmt, 0);
    // caso de erro
    if (retval) {
    }
    //Status
                const char *val;
    retval = sqlite3_step(stmt);
    while (1) {
        if (retval == SQLITE_ROW) {
val = (const char*) sqlite3_column_text(stmt, 0);
            id.setValue(val);
            coment.setComentIdentify(id);


val = (const char*) sqlite3_column_text(stmt, 1);
            text.setValue(val);
            coment.setComentText(text);


val = (const char*) sqlite3_column_text(stmt, 2);
            date.setValue(val);
            coment.setDate(date);


val = (const char*) sqlite3_column_text(stmt, 3);
            id.setValue(val);
            coment.setAuthorIdentify(id);


val = (const char*) sqlite3_column_text(stmt, 4);
            id.setValue(val);
            coment.setPostIdentify(id);

        } else if (retval == SQLITE_DONE) {
            break;
        }
    }
    this->coment = coment;
};




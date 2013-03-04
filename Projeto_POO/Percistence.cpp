#include "Percistencia.h"

void ACommand::conect() {
    queries = malloc(sizeof (char) * q_cnt * q_size);
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

    this->conect()

    strcpy(sql, "INSERT INTO user VALUES('");
    strcat(sql, (user.getIdentify()).getValue());
    strcat(sql, "','");
    strcat(sql, (user.getName()).getValue());
    strcat(sql, "','");
    strcat(sql, (user.getPassword()).getValue);
    strcat(sql, "')");
    // executa nosso comando no banco 
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
    if (retval) {
        /** ID ou NOME já existe **/
    }
    this->desconect();
}

void CommandFindUser::execute() {
    int ind = 0;

    strcpy(sql, "SELECT * FROM user WHERE name = '");
    strcat(sql, (user.getName()).getValue());
    strcat(sql, "'");
    queries[ind++] = sql;
    retval = sqlite3_prepare_v2(handle, queries[ind - 1], -1, &stmt, 0);
    // caso de erro
    if (retval) {
        printf("db selecionado com erro\n");
        return -1;
    }
    Identify ident;
    UserName name;
    Password senha;

    //Status
    retval = sqlite3_step(stmt);
    while (1) {
        if (retval == SQLITE_ROW) {
            const char *val = (const char*) sqlite3_column_text(stmt, 0);
            ident.setValue(val);
            user.setIdentify(ident);
            free(val);

            const char *val = (const char*) sqlite3_column_text(stmt, 1);
            name.setValue(val);
            user.setName(name);
            free(val);

            const char *val = (const char*) sqlite3_column_text(stmt, 2);
            senha.setValue(val);
            user.setPassword(senha);
            free(val);

        } else if (retval == SQLITE_DONE) {
            break;
        }
    }
}

void CommandDeleteUser::execute() {
    strcpy(sql, "UPDATE user SET name = '");
    strcat(sql, (user.getName()).getValue());
    strcpy(sql, ", password = '");
    strcat(sql, (user.getPassword()).getValue());
    strcat(sql, "' WHERE Identify = '");
    strcat(sql, (user.getIdentify()).getValue());
    strcat(sql, "'");
    // executa nosso comando no banco 
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
    if (retval) {
        /** NOME já existe **/
    }
}

void CommandFindUsers::execute() {
    int ind = 0;
    std::list<int> mylist;

    UserName nome;
    Password senha;
    Identify ident;

    User user;

    strcpy(sql, "SELECT * FROM user WHERE *");
    queries[ind++] = sql;
    retval = sqlite3_prepare_v2(handle, queries[ind - 1], -1, &stmt, 0);

    // caso de erro
    if (retval) {
        printf("db selecionado com erro\n");
        return -1;
    }

    //Status
    retval = sqlite3_step(stmt);
    while (1) {
        if (retval == SQLITE_ROW) {
            const char *val = (const char*) sqlite3_column_text(stmt, 0);
            ident.setValue(val);
            user.setIdentify(ident);
            free(val);

            const char *val = (const char*) sqlite3_column_text(stmt, 1);
            nome.setValue(val);
            user.setName(nome);
            free(val);

            const char *val = (const char*) sqlite3_column_text(stmt, 2);
            senha.setValue(val);
            user.setPassword(senha);
            free(val);

            mylist.push_back(user);

        } else if (retval == SQLITE_DONE) {
            break;
        }
    }
    users = mylist;

}

void CommandUpdateUser::execute() {
    strcpy(sql, "UPDATE user SET name = '");
    strcat(sql, (user.getName()).getValue());
    strcpy(sql, ", password = '");
    strcat(sql, (user.getPassword()).getValue());
    strcat(sql, "' WHERE Identify = '");
    strcat(sql, (user.getIdentify()).getValue());
    strcat(sql, "'");
    // executa nosso comando no banco 
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
    if (retval) {
        /** NOME já existe **/
    }
}

void CommandCreatePost::execute() {
    strcpy(sql, "INSERT INTO post VALUES('");
    strcat(sql, (post.getPostIdentify()).getValue());
    strcat(sql, "','");
    strcat(sql, (post.getPostText()).getValue());
    strcat(sql, "','");
    strcat(sql, (post.getDate()).getValue());
    strcat(sql, "',NULL,'");
    strcat(sql, (post.getAuthorIdentify()).getValue());
    strcat(sql, "',0)");
    // executa nosso comando no banco 
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
    if (retval) {
        /** ID já existe **/
    }
};

void CommandUpdatePost::execute() {
    strcpy(sql, "UPDATE post SET postText = '");
    strcat(sql, (post.getPostText()).getValue());
    strcpy(sql, ", date = '");
    strcat(sql, (post.getDate()).getValue());;
    strcat(sql, "' WHERE postIdentify = '");
    strcat(sql, (post.getPostIdentify()).getValue());
    strcat(sql, "'");
    // executa nosso comando no banco 
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
    if (retval) {
        /** Atualizar ID q n existe **/
    }

};

void CommandDeletePost::execute() {
        strcpy(sql, "DELETE FROM post WHERE postIdentify = '");
        strcat(sql, (post.getPostIdentify()).getValue());
        strcat(sql, "'");
        retval = sqlite3_exec(handle, sql, 0, 0, 0);
};

void CommandFindAllPost::execute() {
};

void CommandFindUserPost::execute() {
};

void CommandFindPost::execute() {
};

void CommandCreateComent::execute() {
    //ADD a entidade no BD
    strcpy(sql, "INSERT INTO coment VALUES('");
    strcat(sql, (coment.getComentIdentify()).getValue());
    strcat(sql, "','");
    strcat(sql, (coment.getComentText()).getValue());
    strcat(sql, "','");
    strcat(sql, (coment.getDate()).getValue());
    strcat(sql, "','");
    strcat(sql, (coment.getAuthorIdentify()).getValue());
    strcat(sql, "','");
    strcat(sql, (coment.getPostIdentify()).getValue());
    strcat(sql, "')");
    // executa nosso comando no banco 
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
    if (retval) {
        /** ID já existe **/
    }
};

void CommandUpdateComent::execute() {
    strcpy(sql, "UPDATE coment SET comentText = '");
    strcat(sql, (coment.getComentText()).getValue());
    strcpy(sql, ", date = '");
    strcat(sql, (coment.getDate()).getValue());
    strcat(sql, "' WHERE comentIdentify = '");
    strcat(sql, (coment.getComentIdentify()).getValue());
    strcat(sql, "'");
    // executa nosso comando no banco 
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
    if (retval) {
        /** BUG **/
    }

};

void CommandDeleteComent::execute() {
    //Delete na entidade no BD            
    strcpy(sql, "DELETE FROM coment WHERE comentIdentify = '");
    strcat(sql, (coment.getComentIdentify()).getValue());
    strcat(sql, "'");
    retval = sqlite3_exec(handle, sql, 0, 0, 0);
};

void CommandFindPostComents::execute() {
};

void CommandFindComent::execute() {
};



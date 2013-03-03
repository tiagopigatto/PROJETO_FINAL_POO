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
    strcat(sql, user.getIdentify().getValue());
    strcat(sql, "','");
    strcat(sql, user.getName().getValue());
    strcat(sql, "','");
    strcat(sql, user.getPassword().getValue);
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
    strcat(sql, user.getName());
    strcat(sql, "'");
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
            user.setIdentify(val);
            free(val);
            const char *val = (const char*) sqlite3_column_text(stmt, 1);
            user.setName(val);
            free(val);
            const char *val = (const char*) sqlite3_column_text(stmt, 2);
            user.setPassword(val);
            free(val);
        } else if (retval == SQLITE_DONE) {
            break;
        }
    }
}

void CommandDeleteUser::execute() {
    strcpy(sql, "UPDATE user SET name = '");
    strcat(sql, user.getName().getValue());
    strcpy(sql, ", password = '");
    strcat(sql, user.getPassword().getValue());
    strcat(sql, "' WHERE Identify = '");
    strcat(sql, user.getIdentify().getValue());
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
    
}

void CommandUpdateUser::execute() {
}

void CommandCreatePost::execute() {
};

void CommandUpdatePost::execute() {
};

void CommandDeletePost::execute() {
};

void CommandFindAllPost::execute() {
};

void CommandFindUserPost::execute() {
};

void CommandFindPost::execute() {
};

void CommandCreateComent::execute() {
};

void CommandUpdateComent::execute() {
};

void CommandDeleteComent::execute() {
};

void CommandFindPostComents::execute() {
};

void CommandFindComent::execute() {
};



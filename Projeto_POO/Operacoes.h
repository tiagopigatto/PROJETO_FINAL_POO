#pragma once
#include "IReciever.h"
#include "Entidades.h"
#include "sqlite3.h"

class Operacoes : public IReciever {
    User user_;
    Post post_;
    Coment coment_;
    TYPES::ACTION_LIST currentAction;

public:

    //Entidades

    Operacoes(User user)
    : user_(user) {
    }

    Operacoes(Coment coment)
    : coment_(coment) {
    }

    Operacoes(Post post)
    : post_(post) {
    }

    void SetAction(TYPES::ACTION_LIST action) {
        currentAction = action;
    }
    //Ações

    int GetResult() {

        char *sql, *end;
        int retval, i;
        int q_cnt = 5, q_size = 150, ind = 0;
        char **queries = malloc(sizeof (char) * q_cnt * q_size);
        char valida_name[11];
        // definindo ponteiros
        sqlite3_stmt *stmt;
        sqlite3 *handle;
        // abrindo seu banco, antes de rodar o programa crie um banco com SQLite
        retval = sqlite3_open("POO", &handle);
        // caso de erro na conexão vai mostrar msg
        if (retval) {
            /** Erro no banco **/
        }
        int result;
        //Abrir sql aqui, fechar no fim de cada operação
        if (currentAction == TYPES::ACTION_LIST::CADASTRAUSER) {
            //Sem verificação de existência do nome no BD
            //ADD a entidade no BD
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "INSERT INTO user VALUES('");
            strcat(sql, user_.getIdentify());
            strcat(sql, "','");
            strcat(sql, user_.getName());
            // vai aidionar no banco o numero de tell 43432222
            strcat(sql, "','");
            strcat(sql, user_.getPassword());
            strcat(sql, "')");
            // executa nosso comando no banco 
            retval = sqlite3_exec(handle, sql, 0, 0, 0);
            if (retval) {
                /** ID já existe **/
            }
        } else if (currentAction == TYPES::ACTION_LIST::UPDATEUSER) {
            //Sem verificação de existência do ID no BD
            //Update na entidade no BD
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "UPDATE user SET name = '");
            strcat(sql, user_.getName());
            strcpy(sql, ", password = '");
            strcat(sql, user_.getPassword());
            strcat(sql, "' WHERE Identify = '");
            strcat(sql, user_.getIdentify());
            strcat(sql, "'");
            // executa nosso comando no banco 
            retval = sqlite3_exec(handle, sql, 0, 0, 0);
        } else if (currentAction == TYPES::ACTION_LIST::DELETEUSER) {
            //Sem verificação de existência do ID no BD
            //Delete na entidade no BD            
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "DELETE FROM user WHERE Identify = '");
            strcat(sql, user_.getIdentify());
            strcat(sql, "'");
            retval = sqlite3_exec(handle, sql, 0, 0, 0);
        } else if (currentAction == TYPES::ACTION_LIST::FINDUSERN) {
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "SELECT * FROM user WHERE name = '");
            strcat(sql, user_.getName());
            strcat(sql, "'");
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
                    const char *val = (const char*) sqlite3_column_text(stmt, 1);
                    user_.setIdentify(val);
                    free(val);
                    const char *val = (const char*) sqlite3_column_text(stmt, 2);
                    user_.setName(val);
                    free(val);
                    const char *val = (const char*) sqlite3_column_text(stmt, 1);
                    user_.setPassword(val);
                    free(val);
                } else if (retval == SQLITE_DONE) {
                    break;
                }
            }
        } else if (currentAction == TYPES::ACTION_LIST::FINDUSERID) {

        }

        // fecha a conexão
        free(sql);
        sqlite3_close(handle);
        return result;
    }
};

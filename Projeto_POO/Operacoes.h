/**
 * \file   Operacoes.h
 * \brief  Este e o cabecalho resposável por gerenciar os comandos SQL nas tabelas: 
 * \n Os comandos são na ordem da classe:\n
 * Criar um novo usário\n
 * Atualizar um usuário\n
 * Deletar um usuário\n
 * Procurar um nome na tabela user\n
 * Procurar um id na tabela user\n
* Criar um novo comentárion
 * Atualizar um comentário\n
 * Deletar um comentário\n
 * Procurar um id na tabela coment\n
* Criar um novo post\n
 * Atualizar um post\\n
 * Deletar um post\n
 * Procurar um id na tabela post\n
 */

#include "IReciever.h"
#include "Entidades.h"
#include "sqlite3.h"

class Operacoes : public IReciever {
    User user_;
    Post post_;
    Coment coment_;
    TYPES::ACTION_LIST currentAction;

public:

    //! Construtor de entidades
    /*!
     Podem ser geradas usadas as entidades user, coment ou post para realizar
     * operções no banco de dados
    */

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
        if (currentAction == TYPES::ACTION_LIST::CADASTRAUSER) {
            //Sem verificação de existência do nome no BD
            //ADD a entidade no BD
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "INSERT INTO user VALUES('");
            strcat(sql, user_.getIdentify());
            strcat(sql, "','");
            strcat(sql, user_.getName());
            strcat(sql, "','");
            strcat(sql, user_.getPassword());
            strcat(sql, "')");
            // executa nosso comando no banco 
            retval = sqlite3_exec(handle, sql, 0, 0, 0);
            if (retval) {
                /** ID ou NOME já existe **/
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
            if (retval) {
                /** NOME já existe **/
            }
        } else if (currentAction == TYPES::ACTION_LIST::DELETEUSER) {
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
                    const char *val = (const char*) sqlite3_column_text(stmt, 0);
                    user_.setIdentify(val);
                    free(val);
                    const char *val = (const char*) sqlite3_column_text(stmt, 1);
                    user_.setName(val);
                    free(val);
                    const char *val = (const char*) sqlite3_column_text(stmt, 2);
                    user_.setPassword(val);
                    free(val);
                } else if (retval == SQLITE_DONE) {
                    break;
                }
            }
        } else if (currentAction == TYPES::ACTION_LIST::FINDUSERID) {
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "SELECT * FROM user WHERE Identify = '");
            strcat(sql, user_.getIdentify());
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
                    const char *val = (const char*) sqlite3_column_text(stmt, 0);
                    user_.setIdentify(val);
                    free(val);
                    const char *val = (const char*) sqlite3_column_text(stmt, 1);
                    user_.setName(val);
                    free(val);
                    const char *val = (const char*) sqlite3_column_text(stmt, 2);
                    user_.setPassword(val);
                    free(val);
                } else if (retval == SQLITE_DONE) {
                    break;
                }
            }
        } else if (currentAction == TYPES::ACTION_LIST::CADASTRACOMENT) {
            //ADD a entidade no BD
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "INSERT INTO coment VALUES('");
            strcat(sql, coment_.getComentIdentify());
            strcat(sql, "','");
            strcat(sql, coment_.getComentText());
            strcat(sql, "','");
            strcat(sql, coment_.getDate());
            strcat(sql, "','");
            strcat(sql, coment_.getAuthorIdentify());
            strcat(sql, "','");
            strcat(sql, coment_.getPostIdentify());
            strcat(sql, "')");
            // executa nosso comando no banco 
            retval = sqlite3_exec(handle, sql, 0, 0, 0);
            if (retval) {
                /** ID já existe **/
            }
        } else if (currentAction == TYPES::ACTION_LIST::UPDATECOMENT) {
            //Update na entidade no BD
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "UPDATE coment SET comentText = '");
            strcat(sql, coment_.getComentText());
            strcpy(sql, ", date = '");
            strcat(sql, coment_.getDate());
            strcat(sql, "' WHERE comentIdentify = '");
            strcat(sql, coment_.getComentIdentify());
            strcat(sql, "'");
            // executa nosso comando no banco 
            retval = sqlite3_exec(handle, sql, 0, 0, 0);
            if (retval) {
                /** BUG **/
            }
        } else if (currentAction == TYPES::ACTION_LIST::DELETECOMENT) {
            //Delete na entidade no BD            
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "DELETE FROM coment WHERE comentIdentify = '");
            strcat(sql, coment_.getComentIdentify());
            strcat(sql, "'");
            retval = sqlite3_exec(handle, sql, 0, 0, 0); 
        } else if (currentAction == TYPES::ACTION_LIST::FINDCOMENT) {
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "SELECT * FROM coment WHERE comentIdentify = '");
            strcat(sql, coment_.getComentIdentify());
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
                    const char *val = (const char*) sqlite3_column_text(stmt, 0);
                    coment_.setComentIdentify(val);
                    free(val);
                    const char *val = (const char*) sqlite3_column_text(stmt, 1);
                    coment_.setComentText(val);
                    free(val);
                    const char *val = (const char*) sqlite3_column_text(stmt, 2);
                    coment_.setDate(val);
                    const char *val = (const char*) sqlite3_column_text(stmt, 3);
                    coment_.setAuthorIdentify(val);
                    const char *val = (const char*) sqlite3_column_text(stmt, 4);
                    coment_.setPostIdentify(val);
                    free(val);
                } else if (retval == SQLITE_DONE) {
                    break;
                }
            }
        } else if (currentAction == TYPES::ACTION_LIST::CADASTRAPOST) {
            //ADD a entidade no BD
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "INSERT INTO post VALUES('");
            strcat(sql, post_.getPostIdentify());
            strcat(sql, "','");
            strcat(sql, post_.getPostText());
            strcat(sql, "','");
            strcat(sql, post_.getDate());
            strcat(sql, "',NULL,'");
            strcat(sql, post_.getAuthorIdentify());
            strcat(sql, "')");
            // executa nosso comando no banco 
            retval = sqlite3_exec(handle, sql, 0, 0, 0);
            if (retval) {
                /** ID já existe **/
            }
        } else if (currentAction == TYPES::ACTION_LIST::UPDATEPOST) {
            //Update na entidade no BD
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "UPDATE post SET postText = '");
            strcat(sql, post_.getPostText());
            strcpy(sql, ", date = '");
            strcat(sql, post_.getDate());
            strcat(sql, "' WHERE postIdentify = '");
            strcat(sql, post_.getPostIdentify());
            strcat(sql, "'");
            // executa nosso comando no banco 
            retval = sqlite3_exec(handle, sql, 0, 0, 0);
            if (retval) {
                /** Atualizar ID q n existe **/
            }
        } else if (currentAction == TYPES::ACTION_LIST::DELETEPOST) {
            //Delete na entidade no BD            
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "DELETE FROM post WHERE postIdentify = '");
            strcat(sql, post_.getPostIdentify());
            strcat(sql, "'");
            retval = sqlite3_exec(handle, sql, 0, 0, 0); 
        } else if (currentAction == TYPES::ACTION_LIST::FINDPOST) {
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "SELECT * FROM post WHERE postIdentify = '");
            strcat(sql, post_.getPostIdentify());
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
                    const char *val = (const char*) sqlite3_column_text(stmt, 0);
                    post_.setPostIdentify(val);
                    free(val);
                    const char *val = (const char*) sqlite3_column_text(stmt, 1);
                    post_.setPostText(val);
                    free(val);
                    const char *val = (const char*) sqlite3_column_text(stmt, 2);
                    post_.setDate(val);
                    const char *val = (const char*) sqlite3_column_text(stmt, 3);
                    post_.setEvaluation(val);
                    const char *val = (const char*) sqlite3_column_text(stmt, 4);
                    post_.setAuthorIdentify(val);
                    free(val);
                } else if (retval == SQLITE_DONE) {
                    break;
                }
            }
        }
        // fecha a conexão
        free(sql);
        sqlite3_close(handle);
        return result;
    }
};

/**
 * \file   Operacoes.h
 * \brief  Este e o cabecalho resposável por gerenciar os comandos BD nas tabelas: 
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
//e ai queo q será? isso apareceu dps que comecei a comentar

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
    //! Recebe os resultados

    /*!
     Construtor que gerencia as operações em sql e também o retorno dessas operações.
     */


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

        /*! \brief Cadastra Usuário No BD
         *
         *
         * Recebe o objeto User e apartir dele é gerado uma linha no BD, no entanto isso só ocorre caso\n
         * não exista nem um indentificador nem um nome igual na tabela
         */
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
        }
            /*! \brief Atualiza Usuário No BD
             *
             *
             * Recebe o objeto User e apartir dele são atualizados o nome e a senha, se existir um identificador e o novo nome não
             * existir ainda.
             */
        else if (currentAction == TYPES::ACTION_LIST::UPDATEUSER) {
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
        }            /*! \brief Deleta Usuário No BD
        *
        *
        * Recebe o objeto endereço que deve ser deletado e apartir dele faz um drop Delete na linha 
        */
        else if (currentAction == TYPES::ACTION_LIST::DELETEUSER) {
            //Delete na entidade no BD            
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "DELETE FROM user WHERE Identify = '");
            strcat(sql, user_.getIdentify());
            strcat(sql, "'");
            retval = sqlite3_exec(handle, sql, 0, 0, 0);
        }
            /*! \brief Procura um nome de Usuário No BD
             *
             *
             * Recebe um Name e procura na tabela se esse existe, caso sim armazena as informações dele em um objeto User 
             */
        else if (currentAction == TYPES::ACTION_LIST::FINDUSERN) {
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
        }            /*! \brief Procura um id de Usuário No BD
        *
        *
        * Recebe um identificador e procura na tabela se esse existe, caso sim armazena as informações dele em um objeto User 
        */
        else if (currentAction == TYPES::ACTION_LIST::FINDUSERID) {
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
        }
            /*! \brief Cadastra Comentário No BD
             *
             *
             * Recebe o objeto Coment e apartir dele é gerado uma linha no BD, no entanto isso só ocorre caso\n
             * não exista o identificador do comentário na tabela
             */
        else if (currentAction == TYPES::ACTION_LIST::CADASTRACOMENT) {
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
        }
            /*! \brief Atualiza Comentário No BD
             *
             *
             * Recebe o objeto Coment e apartir dele é gerado uma linha no BD, no entanto isso só ocorre caso\n
             * não exista o identificador do comentário na tabela
             */
        else if (currentAction == TYPES::ACTION_LIST::UPDATECOMENT) {
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
        }
            /*! \brief Deleta Comentário No BD
             *
             *
             * Recebe o id de um Comentário e apartir dele é feito um delete na linha caso essa exista.
             */
        else if (currentAction == TYPES::ACTION_LIST::DELETECOMENT) {
            //Delete na entidade no BD            
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "DELETE FROM coment WHERE comentIdentify = '");
            strcat(sql, coment_.getComentIdentify());
            strcat(sql, "'");
            retval = sqlite3_exec(handle, sql, 0, 0, 0);
        }
            /*! \brief Procura um id de Comentário No BD
             *
             *
             * Recebe o id de busca e caso encontre coloca os valores da linha em um objeto Coment
             */
        else if (currentAction == TYPES::ACTION_LIST::FINDCOMENT) {
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
        }
            /*! \brief Cadastra um Post No BD
             *
             *
             * Recebe o objeto Post e armazena no Banco de Dados, só armazena se o id do Post não existir
             */
        else if (currentAction == TYPES::ACTION_LIST::CADASTRAPOST) {
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
            strcat(sql, "',0)");
            // executa nosso comando no banco 
            retval = sqlite3_exec(handle, sql, 0, 0, 0);
            if (retval) {
                /** ID já existe **/
            }
        }
            /*! \brief Atualiza um Post No BD
             *
             *
             * Recebe o id de um Post e atualiza seu texto, data e avaliação se esse post existir
             */
        else if (currentAction == TYPES::ACTION_LIST::UPDATEPOST) {
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
        }
            /*! \brief Deleta um Post No BD
             *
             *
             * Recebe o id de um Post e deleta a linha em que ele se encontra
             */
        else if (currentAction == TYPES::ACTION_LIST::DELETEPOST) {
            //Delete na entidade no BD            
            sql = (char *) malloc(sizeof (char) * q_size);
            strcpy(sql, "DELETE FROM post WHERE postIdentify = '");
            strcat(sql, post_.getPostIdentify());
            strcat(sql, "'");
            retval = sqlite3_exec(handle, sql, 0, 0, 0);
        }
            /*! \brief Encontra um Post pelo id No BD
             *
             *
             * Recebe o id de um Post e o armazena no objeto Post
             */
        else if (currentAction == TYPES::ACTION_LIST::FINDPOST) {
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

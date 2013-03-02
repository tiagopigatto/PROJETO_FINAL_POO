
#ifndef OPERANDS
#define OPERANDS

#include "TiposBasicos.h"
#include "Entidades.h"
#include "sqlite3.h"

/*  \file   Operacoes.h 
    \brief  Este e o cabecalho resposavel por gerenciar os comandos BD nas tabelas: 
    \n Os comandos são na ordem da classe:\n 
    Criar um novo usário\n
    Atualizar um usuário\n
    Deletar um usuario\n                      
    Procurar um nome na tabela user\n
    Procurar um id na tabela user\n
    Criar um novo comentárion
    Atualizar um comentário\n
    Deletar um comentário\n
    Procurar um id na tabela coment\n
    Criar um novo post\n
    Atualizar um post\\n
    Deletar um post\n
    Procurar um id na tabela post\n            
 */

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


    int GetResult();
    
private:
    void CriaUser(char *,int , sqlite3 *);
    void UpdateUser(char *,int , sqlite3 *);
    void DeleteUser(char *,int , sqlite3 *);
    void FindUserN(char *,int , sqlite3 *, char **,sqlite3_stmt);
    void FindUserID(char *,int , sqlite3 *, char **,sqlite3_stmt);
};

/**
 * \file   TiposBasicos.h
 * \brief  Este e o cabecalho do modulo das classes tipos basicos que definem os
 * \n tipos basicos do sistema neste caso estes sao:\n
 * Nome de Usuario\n
 * Senha\n
 * Identificador\n
 * Texto do Comentario\n
 * Texto da Postagem\n
 * Data\n
 * Avaliaçao\n
 */

#ifndef TIPOSBASICOS_H
#define	TIPOSBASICOS_H

//Includes
#include <string>
#include <stdexcept>
#include <cstdlib>

namespace TYPES
{
	enum ACTION_LIST
	{
        CADASTRAUSER,
        UPDATEUSER,
        DELETEUSER,
        FINDUSERN,
        FINDUSERID,

        CADASTRACOMENT,
        UPDATECOMENT,
        DELETECOMENT,
        FINDCOMENT,

        CADASTRAPOST,
        UPDATEPOST,
        DELETEPOST,
        FINDPOST
	};
};

class IReciever
{
public:
	virtual void SetAction(TYPES::ACTION_LIST action) = 0;
	virtual int GetResult() = 0;
};

using namespace std;

//Defines

//Variaveis Globais

//Declaracoes de Classes
namespace TYPES {

    enum ACTION_LIST {
        CADASTRAUSER,
        UPDATEUSER,
        DELETEUSER,
        FINDUSERN,
        FINDUSERID,

        CADASTRACOMENT,
        UPDATECOMENT,
        DELETECOMENT,
        FINDCOMENT,

        CADASTRAPOST,
        UPDATEPOST,
        DELETEPOST,
        FINDPOST
    };
};

class IReciever {
public:
    virtual void SetAction(TYPES::ACTION_LIST action) = 0;
    virtual int GetResult() = 0;
};



/** \class BasicType
 *  \brief Essa e a classe responsavel por ser um padrao de classe para clases tipos basicos       \n
 *      tendo os metodos obrigratorios para todas essas e os mentodos mais gerais ja implemtados\n
 *      inline garantindo uma economia de memoria.
 */
class BasicType {
protected:
    string value; /**< Esta string e usada para armazenar as informaçoes repassadas de cada classe apos a validaçao destas*/

    /** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
    virtual void validate(const string& value) throw (invalid_argument) = 0;
public:

    /*! \fn void setValue(const string& value) throw (invalid_argument);
     *  \brief Da set no valor do compo nome do usuario.
     *  \param value : o nome do Usuario.
     *  \exception std::invalid_argument o argumeto e invalido
     */
    void setValue(const string& value) throw (invalid_argument);

    /*! \fn string getValue() const;
     *  \brief Pega o valor armazendo value.
     *  \return O o string que pode variar de conteudo a partir de que classe se usa.
     */
    string getValue() const;
};

/** \class UserName
 *  \brief Essa e a classe responsavel reprensentar o nome do ususario no sistema
 *
 */
class UserName : public BasicType {
private:
    /** \fn void validate(const string& value) throw (invalid_argument)
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido.
     */void validate(const string& value) throw (invalid_argument);
public:

    /*! \fn UserName() throw (invalid_argument);
     *  \brief Funcao contrutora do  nome usuario quando nao ha paramentros, essa apenas inicia um novo nome usuario \n
     *  com todos os termos iquais a null
     *  \exception std::invalid_argument quando a classe nao pode ser vazia.
     */
    UserName() throw (invalid_argument);

    /*! \fn User UserName(const string& value) throw (invalid_argument);
     *  \brief Funcao contrutora do nome do usuario quando todos os termos sao passados no momento da criacao \n
     *  essa ira setar todos o termos passados
     *  \param value : o Nome do Usuario.
     *  \exception std::invalid_argument o argumeto e invalido.
     */
    UserName(const string& value) throw (invalid_argument);

};

/** \class Password
 *  \brief Essa e a classe responsavel por resprendentar a senha do usuario no sistema
 */
class Password : public BasicType {
private:
    /** \fn void validate(const string& value) throw (invalid_argument)
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido.
     */
    void validate(const string& value) throw (invalid_argument);
public:
    /*! \fn Password() throw (invalid_argument);
     *  \brief Funcao contrutora da senha quando nao ha paramentros, essa apenas inicia um novo senha \n
     *  com todos os termos iquais a null
     *  \exception std::invalid_argument quando a classe nao pode ser vazia.
     */
    Password() throw (invalid_argument);

    /*! \fn Password(const string& value) throw (invalid_argument);
     *  \brief Funcao contrutora do senha quando todos os termos sao passados no momento da criacao \n
     *  essa ira setar todos o termos passados
     *  \param value : o senha do Usuario.
     *  \exception std::invalid_argument o argumeto e invalido.
     */
    Password(const string& value) throw (invalid_argument);

};

/** \class Identify
 *  \brief Essa e a classe responsavel por representar os identificadores dos termos no sistema.
 */
class Identify : public BasicType {
private:
    /** \fn void validate(const string& value) throw (invalid_argument)
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido.
     */
    void validate(const string& value) throw (invalid_argument);
public:
    /*! \fn Identify() throw (invalid_argument);
     *  \brief Funcao contrutora do identificador quando nao ha paramentros, essa apenas inicia um novo idintificador \n
     *  com todos os termos iquais a null
     *  \exception std::invalid_argument quando a classe nao pode ser vazia.
     */
    Identify() throw (invalid_argument);
    /*! \fn Identify(const string& value) throw (invalid_argument);
     *  \brief Funcao contrutora do indetificador quando todos os termos sao passados no momento da criacao \n
     *  essa ira setar todos o termos passados
     *  \param value : o identificar.
     *  \exception std::invalid_argument o argumeto e invalido.
     */
    Identify(const string& value) throw (invalid_argument);

};

/** \class PostText
 *  \brief Essa e a classe responsavel por reprensentar os textos dos posts no contexto do sistema.
 */
class PostText : public BasicType {
private:
    /** \fn void validate(const string& value) throw (invalid_argument)
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido.
     */
    void validate(const string& value) throw (invalid_argument);
public:
    /*! \fn PostText() throw (invalid_argument);
     *  \brief Funcao contrutora do PostText quando nao ha paramentros, essa apenas inicia um novo texto \n
     *  vazio
     *  \exception std::invalid_argument quando a classe nao pode ser vazia.
     */
    PostText() throw (invalid_argument);
    /*! \fn PostText(const string& value) throw (invalid_argument);
     *  \brief Funcao contrutora do PostText quando todos os termos sao passados no momento da criacao \n
     *  essa ira setar todos o termos passados
     *  \param value : o texto do post.
     *  \exception std::invalid_argument o argumeto e invalido.
     */
    PostText(const string& value) throw (invalid_argument);
};

/** \class ComentText
 *  \brief Essa e a classe responsavel por represnetar os textos do comentarios no contexto do sistema.
 */
class ComentText : public BasicType {
private:
    /** \fn void validate(const string& value) throw (invalid_argument)
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido.
     */
    void validate(const string& value) throw (invalid_argument);
public:
    /*! \fn ComentText() throw (invalid_argument);
     *  \brief Funcao contrutora do CmentText quando nao ha paramentros, essa apenas inicia um texto de comentario vazio.
     *  \exception std::invalid_argument quando a classe nao pode ser vazia.
     */
    ComentText() throw (invalid_argument);
    /*! \fn ComentText(const string& value) throw (invalid_argument);
     *  \brief Funcao contrutora do ComentText quando todos os termos sao passados no momento da criacao \n
     *  essa ira setar todos o termos passados
     *  \param value : o texto do comentario.
     *  \exception std::invalid_argument o argumeto e invalido.
     */
    ComentText(const string& value) throw (invalid_argument);

};

/** \class Date
 *  \brief Essa e a classe responsavel por reprensentar as datas do sistema.
 */
class Date : public BasicType {
private:
    /** \fn void validate(const string& value) throw (invalid_argument)
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido.
     */
    void validate(const string& value) throw (invalid_argument);
public:
    /*! \fn Date() throw (invalid_argument);
     *  \brief Funcao contrutora data quando essa bao e passa logo essa e posta como null;
     *  \exception std::invalid_argument quando a classe nao pode ser vazia.
     */
    Date() throw (invalid_argument);
    /*! \fn Date(const string& value) throw (invalid_argument);
     *  \brief Funcao contrutora do dat quando esta e passada.
     *  \param value : a data.
     *  \exception std::invalid_argument o argumeto e invalido.
     */
    Date(const string& value) throw (invalid_argument);
};

/** \class Evaluation
 *  \brief Essa e a classe responsavel por reprensentatar as avaliaçaoes geradas pelos usuarios para determinada classe
 */
class Evaluation : public BasicType {
private:
    int voteNumber; /**< Este e o numero de votos que foram recebidos por um post*/
    /** \fn void validate(const string& value) throw (invalid_argument)
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido.
     */
    void validate(const string& value) throw (invalid_argument);
public:
    /*! \fn Evaluation() throw (invalid_argument);
     *  \brief Funcao contrutora da Avaliaçao quando nao ha paramentros, essa apenas inicia uma nova Avaliaca \n
     *  com todos os termos iquais a null
     *  \exception std::invalid_argument quando a classe nao pode ser vazia.
     */
    Evaluation() throw (invalid_argument);
    /*! \fn Evaluation(const string& value, int voteNumber) throw (invalid_argument);
     *  \brief Funcao contrutora da avaliacao quando todos os termos sao passados no momento da criacao \n
     *  essa ira setar todos o termos passados
     *  \param value : valor da media.
     *  \param voteNumber : o Numero de votos ate o monneot.
     *  \exception std::invalid_argument o argumeto e invalido.
     */
    Evaluation(const string& value, int voteNumber) throw (invalid_argument);
    /** \fn void setValue(const string& value) throw (invalid_argument);
     *  \brief setar o valor de um novo voto
     *  \param value o valor do voto;
     *  \exception std::invalid_argument o argumeto e invalido.
     */
    void setValue(const string& value) throw (invalid_argument);
    /** \fn void setVoteNumber(const int voteNumber) throw (invalid_argument);
     *  \brief setar o numero de votos
     *  \param voteNumber o numero de votos
     *  \exception std::invalid_argument o argumeto e invalido.
     */
    void setVoteNumber(const int voteNumber) throw (invalid_argument);

    void getVoteNumber();
};

//Metodos Inline
inline void Evaluation::getVoteNumber()
{
    return this->voteNumber;
}

inline void BasicType::setValue(const string& value) throw (invalid_argument) {
    validate(value);
    this->value = value;
}

inline string BasicType::getValue()const {
    return value;
}

#endif


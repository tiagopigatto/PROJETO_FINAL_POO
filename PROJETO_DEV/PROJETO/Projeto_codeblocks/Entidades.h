/**
 * \file   Entidades.h
 * \brief  Este e o cabecalho do modulo das classes entidades que definem as 
 * \n entidades do sistema neste caso estes sao:\n
 * Usuario\n
 * Post\n
 * Comentario\n
 */

#ifndef ENTIDADES_H
#define	ENTIDADES_H
//Includes
#include <string>
#include <stdexcept>
#include "TiposBasicos.h"



using namespace std;

//Defines

//Variaveis Globais

//Declaracoes de Classes

/*! \class User 
 *  \brief Esse e a classe Usuario que reprenta o usuario no contexto deste sistema.
 */
class User {
private:
    UserName name; /**< Variavel que armazena o nome do Usuario*/
    Password password; /**< Variavel que armazena a senha do Usuario*/
    Identify identify; /**< Variavel que armazena o identificador unico do Usuario*/
public:

    /*! \fn User ()
     *  \brief Funcao contrutora do usuario quando nao ha paramentros, essa apenas inicia um novo usuario \n
     *  com todos os termos iquais a null
     */
    User();

    /*! \fn User (UserName userName, Password password, Identify identify)
     *  \brief Funcao contrutora do Usuario quando todos os termos sao passados no momento da criacao \n
     *  essa ira setar todos o termos passados
     *  \param userName : o Nome do Usuario.
     *  \param password : a senha do Usuario.
     *  \param identify : o Identificador unico do Usuario.
     */
    User(UserName, Password, Identify);


    /*! \fn UserName getName();
     *  \brief Pega o valor armazendo no campo nome do usuario.
     *  \return O nome do Usuario.
     */
    UserName getName();

    /*! \fn void setName(UserName userName)
     *  \brief Da set no valor do compo nome do usuario.
     *  \param userName : o nome do Usuario.
     */
    void setName(UserName);


    /*! \fn Password getPassword()
     *  \brief Pega o valor armazenado no campo PassWord.
     *  \return A senha do Usuario.
     */
    Password getPassword();

    /*! \fn void setPassword(Password password)
     *  \brief Da set no valor do campo senha do usuario.
     *  \param password: a senha do Usuario.
     */
    void setPassword(Password);


    /*! \fn Identify getIdentify();
     *  \brief Pega o valor armazenado no campo Identificador do usuario
     *  \return A senha do Usuario.     
     */
    Identify getIdentify();

    /*! \fn void setIdentify(Identify identify)
     *  \brief Da set no valor do campo Identificador do Usuario
     *  \param identify: o Identificador unico do usuario.
     */
    void setIdentify(Identify);

};

/** \class Post
 *  \brief Essa e a classe que repensenta os post dos Usuarios no contexto do Sistema.
 */
class Post {
private:
    Identify authorIdentify; /**< Variavel que armazena o indetificador do usuario dono do post*/
    Identify postIdentify; /**< Variavel que armazena o identificador do post*/
    PostText postText; /**< Variavel que armazena o texto da postagem*/
    Date date; /**< Variavel que armazena a data da postagem*/
    Evaluation evaluation; /**< Variavel que armazena o avaliaçao da postagem*/

public:

    /*! \fn Post ()
     *  \brief Funcao contrutora da Postagem quando nao ha paramentros, essa apenas inicia um novo post \n
     *  com todos os termos iquais a null
     */
    Post();

    /*! \fn Post(Identify authorIdentify, Identify postIdentify, PostText postText, Date date, Evaluation evaluation);
     *  \brief Funcao contrutora do Post quando todos os termos sao passados no momento da criacao \n
     *  essa ira setar todos o termos passados
     *  \param authorIdentify : o identificador do Usuario.
     *  \param postIdentify : o identificador do post.
     *  \param postText : o texto do post.
     *  \param date : a data do post.
     *  \param evaluation : a avaliaçao do post.
     */
    Post(Identify, Identify, PostText, Date, Evaluation);


    /*! \fn Identify getAuthorIdentify()
     *  \brief Pega o valor armazenado no compo do identificador do usuario.
     *  \return o identificar do usario dono do post.
     */
    Identify getAuthorIdentify();

    /*! \fn void setAuthorIdentify(Identify authorIdentify)
     *  \brief Da um set no valor do campo Author Identify
     *  \param authorIdentify : o identificador do author do .    
     */
    void setAuthorIdentify(Identify);


    /*! \fn Identify getPostIdentify()
     *  \brief Pega o valor armazenado no compo do identificador do post.
     *  \return o identificar do usario do post.
     */
    Identify getPostIdentify();

    /*! \fn void setPostIdentify(Identify postIdentify)
     *  \brief Da um set no valor do campo Post Identify
     *  \param postIdentify : o identificador do post.    
     */
    void setPostIdentify(Identify);


    /*! \fn PostText getPostText()
     *  \brief Pega o valor armazenado no compo do texto do post.
     *  \return o texto do post.
     */
    PostText getPostText();

    /*! \fn void void setPostText(PostText postText)
     *  \brief Da um set no valor do campo do texto do post.
     *  \param postText : o texto do post.    
     */
    void setPostText(PostText);

    /*! \fn Date getDate()
     *  \brief Pega o valor armazenado no compo da data.
     *  \return a data do post.
     */
    Date getDate();

    /*! \fn void setDate(Date data)
     *  \brief Da um set no valor do campo data.
     *  \param data : a data do post.    
     */
    void setDate(Date);


    /*! \fn Evaluation getEvaluation();
     *  \brief Pega o valor armazenado no campo avaliacao do post.
     *  \return a avaliaçao atual do post.
     */
    Evaluation getEvaluation();

    /*! \fn void setEvaluation(Evaluation evaluation).
     *  \brief Da um set no valor do campo da avaliaçao.
     *  \param evaluation : o avaliaçao do post.
     */
    void setEvaluation(Evaluation);

};

/*! \class Coment
 *  \brief Essa e a classe que repensenta os cometarios dos Usuarios nos posts no contexto do Sistema.
 */
class Coment {
private:
    Identify authorIdentify; /**< Variavel que armazena o indetificador do usuario dono do comentario*/
    Identify postIdentify; /**< Variavel que armazena o indetificador post a que o comentario pertence*/
    Identify comentIdentify; /**< Variavel que armazena o indetificador do comentario*/
    ComentText comentText; /**< Variavel que armazena o texto fo comentario*/
    Date date; /**< Variavel que armazena a data do comentario*/

public:
    /*! \fn Coment()
     *  \brief Funcao contrutora da comentario quando nao ha paramentros, essa apenas inicia um novo comentario \n
     *  com todos os termos iquais a null
     */
    Coment();

    /*! \fn Coment(Identify authorIdentify, Identify postIdentify, Identify comentIdentify, ComentText comentText, Date date);
     *  \brief Funcao contrutora do Post quando todos os termos sao passados no momento da criacao \n
     *  essa ira setar todos o termos passados
     *  \param authorIdentify : o identificador do Usuario dono do comentario.
     *  \param postIdentify : o identificador do post a que o comentario pertence.
     *  \param comentIdentify : o identificador unico do comentario.
     *  \param comentText : o texto do comentario.
     *  \param date : a data do comentario.
     */
    Coment(Identify, Identify, Identify, ComentText, Date);


    /*! \fn Identify getAuthorIdentify()
     *  \brief Pega o valor armazenado no campo identificador do author do comentario.
     *  \return o identificador do author do comentario.
     */
    Identify getAuthorIdentify();

    /*! \fn void setAuthorIdentify(Identify authorIdentify)
     *  \brief Da um set no valor do indetificador do auhthor do comentario.
     *  \param authorIdentify : o identificador do author do comentario.
     */
    void setAuthorIdentify(Identify);


    /*! \fn Identify getPostIdentify();
     *  \brief Pega o valor armazenado no campo indentificador do post do comentario.
     *  \return o indetificador do post a qual o comentario pertence.
     */
    Identify getPostIdentify();

    /*! \fn void setPostIdentify(Identify postIdentify);
     *  \brief Da um set no valor do campo do indentificador do post do comentario .
     *  \param postIdentify : o indentificador do post do comentariot.
     */
    void setPostIdentify(Identify);

    /*! \fn Identify getComentIdentify()
     *  \brief Pega o valor armazenado no campo do indentificador unico do comentario
     *  \return o indetificador do comentario.
     */
    Identify getComentIdentify();
    
    /*! \fn void setComentIdentify(Identify comentIdentify)
     *  \brief Da um set no valor do campo da avaliaçao.
     *  \param comentIdentify : o identificador unico do comentario.
     */
    void setComentIdentify(Identify);

    /*! \fn ComentText getComentText()
     *  \brief Pega o valor armazenado no campo do texto do comentario.
     *  \return o texto do comentario.
     */
    ComentText getComentText();
    
    /*! \fn setComentText(ComentText comentText)
     *  \brief Da um set no valor do campo de texto do comentario.
     *  \param comentText : o texto do comentario.
     */
    void setComentText(ComentText);

    /*! \fn Date getDate();
     *  \brief Pega o valor armazenado no campo de data do comentario.
     *  \return a data do comentario.
     */
    Date getDate();
    
    /*! \fn setDate(Date date);
     *  \brief Da um set na data do comentario.
     *  \param date : a data do comentario.
     */
    void setDate(Date);
};

//Inline
//of User

inline UserName User::getName() {
    return name;
}

inline Password User::getPassword() {
    return password;
}

inline Identify User::getIdentify() {
    return identify;
}

inline void User::setName(UserName name) {
    this->name = name;
}

inline void User::setPassword(Password password) {
    this->password = password;
}

inline void User::setIdentify(Identify identify) {
    this->identify = identify;
}


//of Post

inline Identify Post::getAuthorIdentify() {
    return authorIdentify;
}

inline Identify Post::getPostIdentify() {
    return postIdentify;
}

inline PostText Post::getPostText() {
    return postText;
}

inline Date Post::getDate() {
    return date;
}

inline Evaluation Post::getEvaluation() {
    return evaluation;
}

inline void Post::setAuthorIdentify(Identify authorIdentify) {
    this->authorIdentify = authorIdentify;
}

inline void Post::setPostIdentify(Identify postIdentify) {
    this->postIdentify = postIdentify;
}

inline void Post::setPostText(PostText postText) {
    this->postText = postText;
}

inline void Post::setDate(Date date) {
    this->date = date;
}

inline void Post::setEvaluation(Evaluation) {
    this->evaluation = evaluation;
}


//of comment

inline Identify Coment::getAuthorIdentify() {
    return authorIdentify;
}

inline Identify Coment::getPostIdentify() {
    return postIdentify;
}

inline Identify Coment::getComentIdentify() {
    return comentIdentify;
}

inline ComentText Coment::getComentText() {
    return comentText;
}

inline Date Coment::getDate() {
    return date;
}

inline void Coment::setAuthorIdentify(Identify authorIdentify) {
    this->authorIdentify = authorIdentify;
}

inline void Coment::setComentIdentify(Identify comentIdentify) {
    this->comentIdentify = comentIdentify;
}

inline void Coment::setPostIdentify(Identify postIdentify) {
    this->postIdentify = postIdentify;
}

inline void Coment::setComentText(ComentText comentText) {
    this->comentText = comentText;
}

inline void Coment::setDate(Date date) {
    this->date = date;
}
#endif	/* ENTIDADES_H */


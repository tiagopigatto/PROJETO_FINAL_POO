#ifdef TESTE
#include "LogNeg.h"

class LNStubUser : UserProtocol
{
private:
    PercistenceProtocol percistence;
public:
    /*! \fn void autenticar(User)
     *  \brief Método responsável por autenticar um usuário
     *  \param User =  objeto de um usuário
     */
    void autenticar(User);
    /*! \fn void cadastrar(User)
     *  \brief Método responsável por cadastar um usuário
     *  \param User =  objeto de um usuário
     */
    void cadastrar(User);
    /*! \fn void update(User)
     *  \brief Método responsável por atualizar um usuário
     *  \param User =  objeto de um usuário
     */
    void update(User);
    /*! \fn void deletar(User)
     *  \brief Método responsável por deletar um usuário
     *  \param User =  objeto de um usuário
     */
    void deletar(User);
    /*! \fn list Listar()
     *  \brief Método responsável por listar os usuários
     */
    list Listar();

    /*! \fn void setPercistence(PercistenceProtocol *)
     *  \brief Método responsável por ativar um protocolo de persitência
     *  \param PercistenceProtocol = protocolo de persitência
     */
    void setPercistence(PercistenceProtocol *);
    /*! \fn LNUser
     *  \brief Método responsável por construir a classe
     */
    LNUser()
    {
    };
    /*! \fn ~LNUser()
     *  \brief Método responsável por descontruir a classe
     */
    ~LNUser()
    {
    };
};
void autenticar(User user)
{
    string nome;
    UserName usuario;
    usuario = user.UserName.getName();
    nome = usuario.getValue();
    if(nome == "Pedro")
    {
        throw new LogicError();
    }
}

void cadastrar(User user) {};

void update(User user) {};

void deletar(User) {};

list Listar()
{
    User user;
    int i;
    std::list<int> lista;
    for(i=0; i<5; i++)
    {
        user.getName().setValue(itoa(i*5));
        user.getPassword().setValue(itoa(i*4));
        user.getIdentify().setValue(itoa(i*3));
        lista.push_back(user);
    }
    return lista;
}

/*! \class LNUser()
 *  \brief Essa é a classe responsável pela lógica de negócios para uma postagems.
 */
class LNStubPost : ComentProtocol
{
public:
    /*! \fn void novo(Post)
     *  \brief Método responsável por criar uma postagem
     *  \param Post =  objeto de um post
     */
    void novo(Post);
    /*! \fn void update(Post)
     *  \brief Método responsável por atualizar uma postagem
     *  \param Post =  objeto de um post
     */
    void update(Post);
    /*! \fn  void deleta(Post)
     *  \brief Método responsável por deletar uma postagem
     *  \param Post =  objeto de um post
     */
    void deleta(Post);
    /*! \fn list listar()
     *  \brief Método responsável por listar todas as postagens
     */
    list listar();
    /*! \fn list listarPorUser(Post)
     *  \brief Método responsável por listar as postagens por usuário
     *  \param Post =  objeto de um post
     */
    list listarPorUser(Post);
    /*! \fn setPercistence(PercistenceProtocol *)
     *  \brief Método responsável por ativar um protocolo de persitência
     *  \param PercistenceProtocol = protocolo de persitência
     */
    void setPercistence(PercistenceProtocol *);
    /*! \fn LNComent()
     *  \brief Método responsável por construir a classe
     */
    LNComent();
    /*! \fn ~LNComent()
     *  \brief Método responsável por construir a classe
     */
    ~LNComent();

};

void novo(Post) {};
void update(Post) {};
void deleta(Post) {};
list listarPorUser(Identify)
{
    std::list<int> lista;

    return lista;
};
list listar()
{
    Post post;
    int i;
    std::list<int> lista;
    for(i=0; i<5; i++)
    {
        post.getAuthorIdentify().setValue(itoa(i*5));
        post.getPostText().setValue(itoa(i*4));
        post.getPostIdentify().setValue(itoa(i*2));
        lista.push_back(post);
    }
    return lista;

};

class LNStubComent : PostProtocol
{
public:
    /*! \fn void novo(Coment)
    *  \brief Método responsável por criar uma comentário
    *  \param Coment =  objeto de um comentário
    */
    void novo(Coment);
    /*! \fn void update(Coment)
    *  \brief Método responsável por atualizar um comentário
    *  \param Coment =  objeto de um comentário
    */
    void update(Coment);
    /*! \fn void deleta(Coment)
    *  \brief Método responsável por deletar uma comentário
    *  \param Coment =  objeto de um comentário
    */
    void deleta(Coment);
    /*! \fn void pegar(Coment)
    *  \brief Método responsável por pegar uma comentário
    *  \param Coment =  objeto de um comentário
    */
    void pegar(Coment);
    /*! \fn  list listar(
    *  \brief Método responsável por listar todos os comentários de um post
    */
    list listar();
    /*! \fn virtual void setPercistence(PercistenceProtocol *)
     *  \brief Método responsável por ativar um protocolo de persitência
     *  \param PercistenceProtocol = protocolo de persitência
     */
    virtual void setPercistence(PercistenceProtocol *);
    /*! \fn LNPost()
     *  \brief Método responsável por construir a classe
     */
    LNPost();
    /*! \fn ~LNPost()
     *  \brief Método responsável por construir a classe
     */
    ~LNPost();

};
    void novo(Coment coment){};
    void update(Coment coment){};
    void deleta(Coment coment) {};
    void pegar(Coment coment){};

    list listar(){
    Coment coment;
    int i;
    std::list<int> lista;
    for(i=0; i<5; i++)
    {
        coment.getAuthorIdentify().setValue(itoa(i*5));
        coment.getComentText().setValue(itoa(i*4));
        coment.getPostIdentify().setValue(itoa(i*2));
        coment.getComentIdentify().setValue(itoa(i*10));
        lista.push_back(coment);
    }
    return lista;



    }

#endif

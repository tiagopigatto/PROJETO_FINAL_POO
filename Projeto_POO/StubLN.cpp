ude "LogNeg.h"

class LNStubUser : UserProtocol
{
private:
    PercistenceProtocol percistence;
public:
    /*! \fn autenticar(User)
     *  \brief M�todo respons�vel por autenticar um usu�rio
     *  \param User =  objeto de um usu�rio
     */
    void autenticar(User) = 0;
    /*! \fn cadastrar(User)
     *  \brief M�todo respons�vel por cadastar um usu�rio
     *  \param User =  objeto de um usu�rio
     */
    void cadastrar(User) = 0;
    /*! \fn update(User)
     *  \brief M�todo respons�vel por atualizar um usu�rio
     *  \param User =  objeto de um usu�rio
     */
    void update(User) = 0;
    /*! \fn deletar(User)
     *  \brief M�todo respons�vel por deletar um usu�rio
     *  \param User =  objeto de um usu�rio
     */
    void deletar(User) = 0;
    /*! \fn Listar()
     *  \brief M�todo respons�vel por listar os usu�rios
     */
    list Listar() = 0;

    /*! \fn setPercistence(PercistenceProtocol *)
     *  \brief M�todo respons�vel por ativar um protocolo de persit�ncia
     *  \param PercistenceProtocol = protocolo de persit�ncia
     */
    void setPercistence(PercistenceProtocol *) = 0;
    /*! \fn LNUser
     *  \brief M�todo respons�vel por construir a classe
     */
    LNUser()
    {
    };
    /*! \fn ~LNUser()
     *  \brief M�todo respons�vel por descontruir a classe
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
 *  \brief Essa � a classe respons�vel pela l�gica de neg�cios para uma postagems.
 */
class LNStubPost : ComentProtocol
{
public:
    /*! \fn novo(Post)
     *  \brief M�todo respons�vel por criar uma postagem
     *  \param Post =  objeto de um post
     */
    void novo(Post) = 0;
    /*! \fn update(Post)
     *  \brief M�todo respons�vel por atualizar uma postagem
     *  \param Post =  objeto de um post
     */
    void update(Post) = 0;
    /*! \fn deleta(Post)
     *  \brief M�todo respons�vel por deletar uma postagem
     *  \param Post =  objeto de um post
     */
    void deleta(Post) = 0;
    /*! \fn listar(Post)
     *  \brief M�todo respons�vel por listar todas as postagens
     *  \param Post =  objeto de um post
     */
    list listar() = 0;
    /*! \fn listarPorUser(Post)
     *  \brief M�todo respons�vel por listar as postagens por usu�rio
     *  \param Post =  objeto de um post
     */
    list listarPorUser(Identify) = 0;
    /*! \fn setPercistence(PercistenceProtocol *)
     *  \brief M�todo respons�vel por ativar um protocolo de persit�ncia
     *  \param PercistenceProtocol = protocolo de persit�ncia
     */
    void setPercistence(PercistenceProtocol *) = 0;
    /*! \fn LNComent()
     *  \brief M�todo respons�vel por construir a classe
     */
    LNComent();
    /*! \fn ~LNComent()
     *  \brief M�todo respons�vel por construir a classe
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
    /*! \fn novo(Coment)
    *  \brief M�todo respons�vel por criar uma coment�rio
    *  \param Coment =  objeto de um coment�rio
    */
    void novo(Coment) = 0;
    /*! \fn update(Coment)
    *  \brief M�todo respons�vel por atualizar um coment�rio
    *  \param Coment =  objeto de um coment�rio
    */
    void update(Coment) = 0;
    /*! \fn deleta(Coment)
    *  \brief M�todo respons�vel por deletar uma coment�rio
    *  \param Coment =  objeto de um coment�rio
    */
    void deleta(Coment) = 0;
    /*! \fn pegar(Coment)
    *  \brief M�todo respons�vel por pegar uma coment�rio
    *  \param Coment =  objeto de um coment�rio
    */
    void pegar(Coment) = 0;
    /*! \fn listar(Post)
    *  \brief M�todo respons�vel por listar todos os coment�rios de um post
    *  \param Coment =  objeto de um coment�rio
    */
    list listar(Post) = 0;
    /*! \fn setPercistence(PercistenceProtocol *)
     *  \brief M�todo respons�vel por ativar um protocolo de persit�ncia
     *  \param PercistenceProtocol = protocolo de persit�ncia
     */
    virtual void setPercistence(PercistenceProtocol *) = 0;
    /*! \fn LNPost()
     *  \brief M�todo respons�vel por construir a classe
     */
    LNPost();
    /*! \fn ~LNPost()
     *  \brief M�todo respons�vel por construir a classe
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

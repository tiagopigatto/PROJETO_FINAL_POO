#ifndef testestiposH
#define testestiposH

#include<iostream>
#include "TiposBasicos.h"
#include "Entidades.h"

class StarTesteTipos
{
public:
    void exec();
};



/** \class TesteBasico
 *  \brief Classe que contem o tipo basico para realizar os testes, estes serão herdados por outras classes
 */
class TesteBasico{
public:
    
    /** \fn virtual void testeValido()
     *  \brief Esse metodo virtual servira para obrigar a todas as classes textes implemtar um teste valido
     */
    virtual void testeValido()=0;

    /** virtual void testeInvalido()
     *  \brief Esse metodo virtual servira para obrigar a todas as classes textes implemtar um teste invalido
     */
    virtual void testeInvalido()=0;

    /** \fn virtual void printCondition()
     *  \brief Esse metodo virtual servira para obrigar a todas as classes testes implemtar um view com as condiçoes que\n
     *   a funçao submente o teste.
     */    
    virtual void printCondition()=0;

    /** \fn virtual void setUp()
     *  \brief Esse metodo virtual servira para obrigar a todas as classes testes implemtar esse metodo que e responsavel por start o test.
     */
    virtual void setUp()=0;

    /** \fn virtual void tearDown()
     *  \brief Esse metodo virtual servira para obrigrar as classe testes a implemetarem o metodo que finalizara os objetos.
     */
    virtual void tearDown()=0;

    /** \fn void run()
     *  \brief Esse metodo ira rodar todo o teste valido e invalido alem de dar um setUp e um tearDown.
     */
    void run();
    
};

/** \class TesteTBUserName
 *  \brief Classe que herda a classe TesteBasico e realiza os testes do tipo básico NomeUsuario
 */
class TesteTBUserName : public TesteBasico{
private:
    UserName *nomeusuario; /**< ponteiro para o nome de usuario que ira quarta o objeto onde os testes rodaram*/
    /** \fn void testeValido();
     *  \brief Esse metodo que fara um teste valido nos objetos;
     */
    void testeValido();
    /** \fn void testeInvalido();
     *  \brief Esse metodo que fara um teste invalido nos objetos;
     */
    void testeInvalido();
    /** \fn void printCondition();
     *  \brief Esse metodo cria um table padra sobre oque o teste se trata e qual a condiçao para o argumento ser valido
     */
    void printCondition();
public:
    /** \fn virtual void setUp()
     *  \brief Esse metodo starta um novo objeto UserName
     */
    void setUp();
    /** \fn virtual void setUp()
     *  \brief Esse metodo virtual servira para obrigar a todas as classes testes implemtar esse metodo que e responsavel por start o test.
     */
    void tearDown();

};

inline void TesteTBUserName::printCondition(){
    cout << endl << "Teste de Nome de Usuario" << endl;
    cout << "Condicao:" << endl;
    cout << "10 cacarteres (letras espacos e ponto)" << endl << endl;
    
}

inline void TesteTBUserName::setUp(){
        nomeusuario = new UserName();
    }
inline void TesteTBUserName::tearDown(){
        delete nomeusuario;
    }


/** \class TesteTBPassword
 *  \brief Classe que herda a classe TesteBasico e realiza os testes do tipo básico Senha
 */

class TesteTBPassword : public TesteBasico{
private:
    Password *senha;
    /** \fn void testeValido();
     *  \brief Esse metodo que fara um teste valido nos objetos;
     */
    void testeValido();
    /** \fn void testeInvalido();
     *  \brief Esse metodo que fara um teste invalido nos objetos;
     */
    void testeInvalido();
    /** \fn void printCondition();
     *  \brief Esse metodo cria um table padra sobre oque o teste se trata e qual a condiçao para o argumento ser valido
     */
    void printCondition();
public:
    /** \fn virtual void setUp()
     *  \brief Esse metodo starta um novo objeto Password
     */
    void setUp();

    /** \fn virtual void setUp()
     *  \brief Esse metodo detroi o objeto criado pondo assim fim ao teste.
     */
    void tearDown();
};
 inline void TesteTBPassword::setUp(){
    senha = new Password();
 }

 inline void TesteTBPassword::tearDown(){
        delete senha;
 }

inline void TesteTBPassword::printCondition(){
    cout << endl << "Teste de Senha" << endl;
    cout << "Condicao:" << endl;
    cout << "6 cacarteres (letras e numeros)" << endl << endl;
    
}

/** \class TesteTBIdentify
 *  \brief Classe que herda a classe TesteBasico e realiza os testes do tipo básico Ident
 */
class TesteTBIdentify : public TesteBasico{
private:
    Identify *ident;
    /** \fn void testeValido();
     *  \brief Esse metodo que fara um teste valido nos objetos;
     */
    void testeValido();
    /** \fn void testeInvalido();
     *  \brief Esse metodo que fara um teste invalido nos objetos;
     */
    void testeInvalido();
    /** \fn void printCondition();
     *  \brief Esse metodo cria um table padra sobre oque o teste se trata e qual a condiçao para o argumento ser valido
     */
    void printCondition();
public:
    /** \fn virtual void setUp()
     *  \brief Esse metodo starta um novo objeto Identify
     */
    void setUp();

    /** \fn virtual void setUp()
     *  \brief Esse metodo detroi o objeto criado pondo assim fim ao teste.
     */
    void tearDown();
};
inline void TesteTBIdentify::setUp(){
        ident = new Identify();
}

inline void TesteTBIdentify::tearDown(){
        delete ident;
}

inline void TesteTBIdentify::printCondition(){
    cout << endl << "Teste de Identificador" << endl;
    cout << "Condicao:" << endl;
    cout << "5 numeros" << endl << endl;
    
}

/** \class TesteTBPostText
 *  \brief Classe que herda a classe TesteBasico e realiza os testes do tipo básico Post
 */
class TesteTBPostText : public TesteBasico{
private:
    PostText *post;
    /** \fn void testeValido();
     *  \brief Esse metodo que fara um teste valido nos objetos;
     */
    void testeValido();
    /** \fn void testeInvalido();
     *  \brief Esse metodo que fara um teste invalido nos objetos;
     */
    void testeInvalido();
    /** \fn void printCondition();
     *  \brief Esse metodo cria um table padra sobre oque o teste se trata e qual a condiçao para o argumento ser valido
     */
    void printCondition();
public:
    /** \fn virtual void setUp()
     *  \brief Esse metodo starta um novo objeto PostText
     */
    void setUp();

    /** \fn virtual void setUp()
     *  \brief Esse metodo detroi o objeto criado pondo assim fim ao teste.
     */
    void tearDown();
};

inline void TesteTBPostText::setUp(){
        post = new PostText();
}

inline void TesteTBPostText::tearDown(){
    delete post;
}

inline void TesteTBPostText::printCondition(){
    cout << endl << "Teste de Texto da Postagem" << endl;
    cout << "Condicao:" << endl;
    cout << "ate 30 cacarteres" << endl << endl;
}

/** \class TesteTBComentText
 *  \brief Classe que herda a classe TesteBasico e realiza os testes do tipo básico Comment
 */
class TesteTBComentText :public TesteBasico{
private:
    ComentText *comment;
    /** \fn void testeValido();
     *  \brief Esse metodo que fara um teste valido nos objetos;
     */
    void testeValido();
    /** \fn void testeInvalido();
     *  \brief Esse metodo que fara um teste invalido nos objetos;
     */
    void testeInvalido();
    /** \fn void printCondition();
     *  \brief Esse metodo cria um table padra sobre oque o teste se trata e qual a condiçao para o argumento ser valido
     */
    void printCondition();
public:
    /** \fn virtual void setUp()
     *  \brief Esse metodo starta um novo objeto ComentText
     */
    void setUp();

    /** \fn virtual void setUp()
     *  \brief Esse metodo detroi o objeto criado pondo assim fim ao teste.
     */
    void tearDown();
};

inline void TesteTBComentText::setUp(){
        comment = new ComentText();
}

inline void TesteTBComentText::tearDown(){
    delete comment;
}

inline void TesteTBComentText::printCondition(){
    cout << endl << "Teste de Texto do Comentario" << endl;
    cout << "Condicao:" << endl;
    cout << "ate 20 caracteres" << endl << endl;
}

/** \class TesteTBDate
 *  \brief Classe que herda a classe TesteBasico e realiza os testes do tipo básico Date
 */
class TesteTBDate : public TesteBasico{
private:
    Date *date;
    /** \fn void testeValido();
     *  \brief Esse metodo que fara um teste valido nos objetos;
     */
    void testeValido();
    /** \fn void testeInvalido();
     *  \brief Esse metodo que fara um teste invalido nos objetos;
     */
    void testeInvalido();
    /** \fn void printCondition();
     *  \brief Esse metodo cria um table padra sobre oque o teste se trata e qual a condiçao para o argumento ser valido
     */
    void printCondition();
public:
    /** \fn virtual void setUp()
     *  \brief Esse metodo starta um novo objeto date
     */
    void setUp();

    /** \fn virtual void setUp()
     *  \brief Esse metodo detroi o objeto criado pondo assim fim ao teste.
     */
    void tearDown();

};

inline void TesteTBDate::setUp(){
        date = new Date();
}

inline void TesteTBDate::tearDown(){
    delete date;
}

inline void TesteTBDate::printCondition(){
    cout << endl << "Teste de Data" << endl;
    cout << "Condicao:" << endl;
    cout << "Formato DD-MM-AAAA" << endl << endl;
}

/** \class TesteTBEvaluation
 *  \brief Classe que herda a classe TesteBasico e realiza os testes do tipo básico Avalia
 */

class TesteTBEvaluation : public TesteBasico{
private:
    Evaluation *avalia;
    /** \fn void testeValido();
     *  \brief Esse metodo que fara um teste valido nos objetos;
     */
    void testeValido();
    /** \fn void testeInvalido();
     *  \brief Esse metodo que fara um teste invalido nos objetos;
     */
    void testeInvalido();
    /** \fn void printCondition();
     *  \brief Esse metodo cria um table padra sobre oque o teste se trata e qual a condiçao para o argumento ser valido
     */
    void printCondition();
public:
    /** \fn virtual void setUp()
     *  \brief Esse metodo starta um novo objeto Evaluation
     */
    void setUp();

    /** \fn virtual void setUp()
     *  \brief Esse metodo detroi o objeto criado pondo assim fim ao teste.
     */
    void tearDown();

};

inline void TesteTBEvaluation::setUp(){
        avalia = new Evaluation();
}

inline void TesteTBEvaluation::tearDown(){
             delete avalia;
}

inline void TesteTBEvaluation::printCondition(){
    cout << endl << "Teste de Avaliacao" << endl;
    cout << "Condicao:" << endl;
    cout << "nota de 1 a 5, numero de votos >= 0" << endl << endl;
}
#endif

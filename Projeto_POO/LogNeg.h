#ifndef LOGICA_NEGOCIO_H
#define	LOGICA_NEGOCIO_H

/*
#ifdef WIN32 || _WIN32  /*Parece que a MS gosta muito de usar o prefixo _ 
    #include <direct.h>
#else 
    #include <sys/stat.h>
#endif
*/

#include "Entidades.h"
#include "PerComent.h"
#include "PerPost.h"
#include "PerUsu.h"
#include "Protocolo.h"

class LNProjeto : ProtocoloUsuario
{
public:
	void cadastrar(User *);
        void update(User *);        
        void deleta(Identify *);
        User pesquisa(Identify *);
        User pesquisa(UserName *);

        LNProjeto(){};
        ~LNProjeto(){};

};

class LNComent : ProtocoloComent
{
public:
    void cadastrar(Coment *);
    void update(Coment *);
    void deleta(Identify *);
    Coment pesquisa(Identify *);

    LNComent();
    ~LNComent();

};

class LNPost : ProtocoloPost{
public:
	void cadastrar(Post *);
	void update(Post *);
	void deleta(Identify *);
	Post pesquisa(Identify *);

	LNPost();
	~LNPost();

};


#endif	/* LOGOCANEGOCIO_H */


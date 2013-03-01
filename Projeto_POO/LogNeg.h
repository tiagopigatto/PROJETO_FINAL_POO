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

class LNProjeto : ProtocoloDeUsuario
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

class LNComment : ProtocoloDeCommet
{
public:
	void cadastrar(Comment *);
    void update(Comment *);
    void deleta(Identify *);
    Comment pesquisa(Indentify *);

    LNComment();
    ~LNComment();

};

class LNPost : ProtocoloDePost{
public:
	void cadastrar(Post *);
	void update(Post *);
	void deleta(Indentify *);
	void pesquisa(Identify *);

	LNPost();
	~LNComment();

};


#endif	/* LOGOCANEGOCIO_H */


/* 
 * File:   controler.h
 * Author: Vitor
 *
 * Created on 21 de Fevereiro de 2013, 01:41
 */

#ifndef PROTOCOLOS_H
#define	PROTOCOLOS_H

#include "TiposBasicos.h"
 
class ProtocoloUsuaria
{
    public:
    	virtual void cadastrar(User *) = 0;
    	virtual void update(User *) = 0;
    	virtual void deleta(Identify *) = 0;
    	virtual User pesquisa(Identify *) = 0;
    	virtual User pesquisa(UserName *) = 0;

    	ProtocoloUsuario(){}
    	~ProtocoloUsuario(){}

};

class ProtocoloComment
{
    public:
    	virtual void cadastrar(Comment *) = 0;
    	virtual void update(Comment *) = 0;
    	virtual void deleta(Identify *) = 0;
    	virtual Comment pesquisa(Indentify *) = 0;

    	ProtocoloComment(){};
    	~ProtocoloComment();

};

class ProtocoloPost
{
	public:
		virtual void cadastrar(Post *) = 0;
		virtual void update(Post *) = 0;
		virtual void deleta(Indentify *) = 0;
		virtual void pesquisa(Identify *) = 0;

		ProtocoloPost(){};
		~ProtocoloPost(){};
};
        

#endif	/* CONTROLER_H */


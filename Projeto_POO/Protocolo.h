/* 
 * File:   controler.h
 * Author: Vitor
 *
 * Created on 21 de Fevereiro de 2013, 01:41
 */

#ifndef PROTOCOLOS_H
#define	PROTOCOLOS_H
 
class ProtocoloUsuaria
{
    public:
    	virtual void cadastrar(User *);
    	virtual void update(User *);
    	virtual void deleta(Identify *);
    	virtual User pesquisa(Identify *);
    	virtual User pesquisa(UserName *);

    	ProtocoloUsuario(){}
    	~ProtocoloUsuario(){}

};

class ProtocoloComment
{
    public:
    	virtual void cadastrar(Comment *);
    	virtual void update(Comment *);
    	virtual void deleta(Identify *);
    	virtual Comment pesquisa(Indentify *);

    	ProtocoloComment(){};
    	~ProtocoloComment();

};

class ProtocoloPost
{
	public:
		virtual void cadastrar(Post *);
		virtual void update(Post *);
		virtual void deleta(Indentify *);
		virtual void pesquisa(Identify *);

		ProtocoloPost(){};
		~ProtocoloPost(){};
};
        

#endif	/* CONTROLER_H */


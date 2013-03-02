#pragma once

class ACommand
{
protected:

	IReciever *pReciever_;

public:

	ACommand(IReciever *reciever)
		:pReciever_(reciever)
	{
	}

	virtual int Execute() = 0;
};

//Usuário
class CadastraUser : public ACommand
{
public:
	CadastraUser(IReciever *reciever)
		: ACommand(reciever)
	{

	}

	int Execute()
	{
		pReciever_->SetAction(TYPES::ACTION_LIST::CADASTRAUSER);
		return pReciever_->GetResult();
	}
};

class UpdateUser : public ACommand
{
public:
	UpdateUser(IReciever *reciever)
		: ACommand(reciever)
	{

	}

	int Execute()
	{
		pReciever_->SetAction(TYPES::ACTION_LIST::UPDATEUSER);
		return pReciever_->GetResult();
	}
};

class DeleteUser : public ACommand
{
public:
	DeleteUser(IReciever *reciever)
		: ACommand(reciever)
	{

	}

	int Execute()
	{
		pReciever_->SetAction(TYPES::ACTION_LIST::DELETEUSER);
		return pReciever_->GetResult();
	}
};

class FindUserN : public ACommand
{
public:
	FindUserN(IReciever *reciever)
		: ACommand(reciever)
	{

	}

	int Execute()
	{
		pReciever_->SetAction(TYPES::ACTION_LIST::FINDUSERN);
		return pReciever_->GetResult();
	}
};

class FindUserID : public ACommand
{
public:
	FindUserID(IReciever *reciever)
		: ACommand(reciever)
	{

	}

	int Execute()
	{
		pReciever_->SetAction(TYPES::ACTION_LIST::FINDUSERID);
		return pReciever_->GetResult();
	}
};
//Comentários

class CadastraComent : public ACommand
{
public:
	CadastraComent(IReciever *reciever)
		: ACommand(reciever)
	{

	}

	int Execute()
	{
		pReciever_->SetAction(TYPES::ACTION_LIST::CADASTRACOMENT);
		return pReciever_->GetResult();
	}
};

class UpdateComent : public ACommand
{
public:
	UpdateComent(IReciever *reciever)
		: ACommand(reciever)
	{

	}

	int Execute()
	{
		pReciever_->SetAction(TYPES::ACTION_LIST::UPDATECOMENT);
		return pReciever_->GetResult();
	}
};

class DeleteComent : public ACommand
{
public:
	DeleteComent(IReciever *reciever)
		: ACommand(reciever)
	{

	}

	int Execute()
	{
		pReciever_->SetAction(TYPES::ACTION_LIST::DELETECOMENT);
		return pReciever_->GetResult();
	}
};

class FindComent : public ACommand
{
public:
	FindComent(IReciever *reciever)
		: ACommand(reciever)
	{

	}

	int Execute()
	{
		pReciever_->SetAction(TYPES::ACTION_LIST::FINDCOMENT);
		return pReciever_->GetResult();
	}
};
//POst
class CadastraPost : public ACommand
{
public:
	CadastraPost(IReciever *reciever)
		: ACommand(reciever)
	{

	}

	int Execute()
	{
		pReciever_->SetAction(TYPES::ACTION_LIST::CADASTRAPOST);
		return pReciever_->GetResult();
	}
};

class UpdatePost : public ACommand
{
public:
	UpdatePost(IReciever *reciever)
		: ACommand(reciever)
	{

	}

	int Execute()
	{
		pReciever_->SetAction(TYPES::ACTION_LIST::UPDATEPOST);
		return pReciever_->GetResult();
	}
};
class DeletePost : public ACommand
{
public:
	DeletePost(IReciever *reciever)
		: ACommand(reciever)
	{

	}

	int Execute()
	{
		pReciever_->SetAction(TYPES::ACTION_LIST::DELETEPOST);
		return pReciever_->GetResult();
	}
};
class FindPost : public ACommand
{
public:
	FindPost(IReciever *reciever)
		: ACommand(reciever)
	{

	}

	int Execute()
	{
		pReciever_->SetAction(TYPES::ACTION_LIST::FINDPOST);
		return pReciever_->GetResult();
	}
};

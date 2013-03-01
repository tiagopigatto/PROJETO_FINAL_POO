#pragma once

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

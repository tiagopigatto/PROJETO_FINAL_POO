#ifndef COMMAND_H
#define	COMMAND_H

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

class IReciver
{
public:
    virtual void set(TYPES::ACTION_LIST action) = 0;
    virtual void exec();
};


class Command : public IReciver
{
private:
    TYPES::ACTION_LIST tipo;
public:
    
};
        


#endif	/* COMMAND_H */


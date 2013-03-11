#ifndef COMANDS
#define COMANDS

#include <list>
#include "Entidades.h"
#include "PercistenceProtocol.h"
#include "sqlite3.h"

/** \class PersistenceControler
 *  \brief Essa e a classe responsavel por criar uma controladora de persitência
 */
class PersistenceControler : public PercistenceProtocol {
public:
    //executa
    /*! \fn void executar(ACommand*)
     *  \brief Método responsável por iniciar a execuçaõ da classe
     *  \param ACommand = Command Abstrato
     */    
    void exec(ACommand*) throw (PercistenceError);
};

    inline void PersistenceControler::exec(ACommand *command) throw (PercistenceError) {
    try
    {
    command->execute();
    }catch(PercistenceError e)
    {
            throw e;
    }
}

#endif
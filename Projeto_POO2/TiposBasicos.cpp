#include "TiposBasicos.h"

//UserName

UserName::UserName() throw (invalid_argument) {
}

UserName::UserName(const string& value)throw (invalid_argument) {
    setValue(value);
}

void UserName::validate(const string& value)throw (invalid_argument) {
    if (value.size() > 10)
        throw invalid_argument("Matrícula deve ter no máximo 10 caracteres");
    for (int i = 0; i < value.size(); i++) {
        if (!isalpha(value.at(i)) && !isspace(value.at(i)) && value.at(i) != '.')
            throw invalid_argument("Apenas LETRAS, ESPACO e PONTO");
    }
}

//Password

Password::Password() throw (invalid_argument) {
}

Password::Password(const string& value) throw (invalid_argument) {
    setValue(value);
}

void Password::validate(const string& value) throw (invalid_argument) {
    if (value.size() > 6)
        throw invalid_argument("A senha deve ter no máximo 6 caracteres");
    for (int i = 0; i < value.size(); i++) {
        if (!isalpha(value.at(i)) && !isdigit(value.at(i)))
            throw invalid_argument("A senha deve possuir apenas LETRAS e NUMEROS");
    }
}

//Identify

Identify::Identify() throw (invalid_argument) {
}

Identify::Identify(const string& value) throw (invalid_argument) {
    setValue(value);
}

void Identify::validate(const string& value) throw (invalid_argument) {
    if (value.size() > 6)
        throw invalid_argument("O identificador deve possuir no maximo 5 digitos");
    for (int i = 0; i < value.size(); i++) {
        if (!isdigit(value.at(i)))
            throw invalid_argument("O identificador deve posuir apenas digitos numericos");
    }
}

//PostText

PostText::PostText() throw (invalid_argument) {
}

PostText::PostText(const string& value) throw (invalid_argument) {
    setValue(value);
}

void PostText::validate(const string& value) throw (invalid_argument) {
    if (value.size() > 30)
        throw invalid_argument("A postagem deve ter no máximo 30 caracteres");

}

//ComentText

ComentText::ComentText() throw (invalid_argument) {
}

ComentText::ComentText(const string& value) throw (invalid_argument) {
    setValue(value);
}

void ComentText::validate(const string& value) throw (invalid_argument) {
    if (value.size() > 20)
        throw invalid_argument("O comentario deve ter no maximo 20 caracteres");
}

//Date

Date::Date() throw (invalid_argument) {
}

Date::Date(const string& value) throw (invalid_argument) {
    setValue(value);
}

void Date::validate(const string& value) throw (invalid_argument) {
        if(value.size() != 10)
        throw invalid_argument("Formato da data incorreto(DD-MM-AAAA)");
}

//Evaluaition

Evaluation::Evaluation() throw (invalid_argument) {
}

Evaluation::Evaluation(const string& value, int numberVote) throw (invalid_argument) {
    setValue(value);
    setVoteNumber(numberVote);
}

void Evaluation::validate(const string& value) throw (invalid_argument) {
    int i = atoi(value.c_str());
    if(i < 0 || i > 5)
        throw invalid_argument("O voto deve ser mair que 0 e menor que 5");
}

void Evaluation::setValue(const string& value) throw (invalid_argument) {
    validate(value);
    this->value = value;
    this->voteNumber++;
}

void Evaluation::setVoteNumber(const int numberVote) throw (invalid_argument) {
    if(numberVote >= 0)
        this->voteNumber = numberVote;
    else
        throw invalid_argument("o numero de votos deve ser um numero natural");
}


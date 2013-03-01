#include "Entidades.h"

User::User() {
}

User::User(UserName name, Password password, Identify identify) {
    setName(name);
    setPassword(password);
    setIdentify(identify);
}

Post::Post() {

}

Post::Post(Identify authorIdentify, Identify postIdentify, PostText postText, Date date, Evaluation evaluation) {
    setAuthorIdentify(authorIdentify);
    setPostIdentify(postIdentify);
    setPostText(postText);
    setDate(date);
    setEvaluation(evaluation);
}

Coment::Coment() {

}

Coment::Coment(Identify authorIdentify, Identify postIdentify, Identify comentIdentify, ComentText comentText, Date date) {
    setAuthorIdentify(authorIdentify);
    setPostIdentify(postIdentify);
    setComentIdentify(comentIdentify);
    setComentText(comentText);
    setDate(date);
}

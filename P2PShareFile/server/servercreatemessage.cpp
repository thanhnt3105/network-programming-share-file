#include "servercreatemessage.h"

RequestProcessing *ServerCreateMessage::getRequestProcessing() const
{
    return requestProcessing;
}

void ServerCreateMessage::setRequestProcessing(RequestProcessing *newRequestProcessing)
{
    requestProcessing = newRequestProcessing;
}

ServerCreateMessage::ServerCreateMessage(QObject *parent)
    : QObject{parent}
{
    this->requestProcessing = new RequestProcessing();
}

QString ServerCreateMessage::createMessage(QString msg)
{
    if(msg.compare("login successfully")==0) {
        LoginServerMessage* serverMsg = new LoginServerMessage(this->requestProcessing->getUser()->getId(),
                                                               this->requestProcessing->getUser()->getUsername(),
                                                               "");
        return serverMsg->toString();
    }
    else if(msg.compare("invalid username")==0) {
        LoginServerMessage* serverMsg = new LoginServerMessage(NULL,
                                                               NULL,
                                                               "invalid username");
        return serverMsg->toString();
    }
    else if(msg.compare("invalid password")==0) {
        LoginServerMessage* serverMsg = new LoginServerMessage(NULL,
                                                               NULL,
                                                               "invalid password");
        return serverMsg->toString();
    }
    else if(msg.compare("username exist")==0) {
        RegisterServerMessage* serverMsg = new RegisterServerMessage(NULL,
                                                               NULL,
                                                               "username exist");
        return serverMsg->toString();
    }
    else if(msg.compare("register successfully")==0) {
        RegisterServerMessage* serverMsg = new RegisterServerMessage(NULL,
                                                                     NULL,
                                                                     "");
        return serverMsg->toString();
    }
    else if(msg.compare("file not found")==0) {
        FileServerMessage* serverMsg = new FileServerMessage("file not found");
        return serverMsg->toString();
    }
    else if(msg.compare("file found")==0) {
//        FileServerMessage* serverMsg = new FileServerMessage(this->requestProcessing->getFile()->getFileName(),"");
        FileServerMessage* serverMsg = new FileServerMessage(this->requestProcessing->getListFile(),"");
        return serverMsg->toString();
    }
    else if(msg.compare("upload file successfully")==0){
        FileServerMessage*serverMsg = new FileServerMessage(this->requestProcessing->getFile()->getFileName(),
                                                            this->requestProcessing->getFile()->getFilePath(),
                                                             this->requestProcessing->getUser()->getId(),"");
        return serverMsg->toString();
    }
}

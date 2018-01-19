#include "loadcontacts.h"
#include <QDebug>

LoadContacts::LoadContacts(QList<std::shared_ptr<Ccontact>> &contact) : contacts(contact)
{
    QFile contactFile("Contact.txt");
    if(contactFile.open(QIODevice::ReadOnly |QIODevice::Text)){
        while(!contactFile.atEnd()){
            //читаем строку
            QString logs = contactFile.readAll();
            QStringList loads =  logs.split("\n");
            foreach (QString str, loads){
               QStringList loadContact = str.split(':');
               std::shared_ptr<Ccontact> cont(new Ccontact(loadContact.front(),loadContact.back()));
               contacts.append(cont);

            }
        }

    }else{
        qDebug()<< "don't open file";
    }

}

LoadContacts::~LoadContacts()
{
    QString fileName("Contact.txt");
    QStringList logsList;
    foreach (std::shared_ptr<Ccontact> ptr , contacts) {
        logsList << ptr->getName()+":"+ptr->getPhone();
    }
    QFile chessFile(fileName);
    if(chessFile.open( QIODevice::WriteOnly )){
        QTextStream textStream( &chessFile );
        textStream << logsList.join('\n');
        chessFile.close();
    }
    contacts.clear();
}

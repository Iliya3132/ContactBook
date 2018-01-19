#include "mainmodel.h"



mainModel::mainModel(QObject *parent) : QAbstractListModel(parent)
{
    loadContacs = new LoadContacts(contacts); //Передача ссылки на массив умных указателей на контакты

}

mainModel::~mainModel()
{
    delete loadContacs;
}



int mainModel::rowCount(const QModelIndex &parent) const{
    if (parent.isValid()) {
        return 0;
    }
    return contacts.size();
}

QVariant mainModel::data(const QModelIndex &modelIndex, int role) const{
    if (!modelIndex.isValid()) {
            return QVariant();
        }
       int index = static_cast<int>(modelIndex.row());
       const Ccontact  &contact = *contacts[index];
        switch (role) {
        case Roles::NameRole:
            return contact.getName();
        case Roles::PhoneRole:
            return contact.getPhone();
        default:
            return QVariant();
        }
}

QHash<int, QByteArray> mainModel::roleNames() const{
        QHash<int, QByteArray> roles;
        roles.insert(Roles::NameRole, "NameRole");
        roles.insert(Roles::PhoneRole, "PhoneRole");
        return roles;
}

bool mainModel::changeContact(QString n_name, QString n_phone, int index){
    if(n_name.isEmpty()||n_phone.isEmpty()) return false;
    contacts.at(index)->setContact(n_name,n_phone);
    endResetModel();
    return true;

}



bool mainModel::createNewContact(QString n_name, QString n_phone){
    if(n_name.isEmpty()||n_phone.isEmpty()) return false;
    beginInsertRows(QModelIndex(), contacts.size(), contacts.size());
    std::shared_ptr<Ccontact> cont(new Ccontact(n_name,n_phone));
    contacts.append(cont);
    endInsertRows();
     return true;
}

void mainModel::delateContact(int id)
{
    beginResetModel();    
    contacts.removeAt(id);
    endResetModel();

}



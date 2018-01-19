#include "ccontact.h"


Ccontact::Ccontact(QString n_name, QString n_phone) : name(n_name),phone(n_phone){

}

Ccontact::Ccontact(const Ccontact &con)
{
    this->name = con.name;
    this->phone = con.phone;
}

Ccontact Ccontact::operator =(const Ccontact  &con){
    this->name = con.name;
    this->phone = con.phone;
    return con;
}
Ccontact::~Ccontact(){

}

void Ccontact::setContact(QString n_name, QString n_phone)
{
    name = n_name;
    phone = n_phone;
}

QString Ccontact::getName() const
{
    return name;
}

QString Ccontact::getPhone() const
{
    return phone;
}



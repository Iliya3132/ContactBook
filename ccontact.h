#pragma once
#ifndef CCONTACT_H
#define CCONTACT_H

#include <QString>
#include <QDebug>

class Ccontact // Класс для хранения информации о контакте
{
public:
    explicit Ccontact(QString n_name = "Empty", QString n_phone = "Empty");
    Ccontact (const Ccontact  &con);
    ~Ccontact();
    Ccontact operator =(const Ccontact  &con);

    void setContact(QString  n_name, QString n_phone);
    QString getName() const;
    QString getPhone() const;
signals:

public slots:

private:
    QString  name;
    QString  phone;
};

#endif // CCONTACT_H

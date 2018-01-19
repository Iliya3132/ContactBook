#pragma once
#ifndef LOADCONTACTS_H
#define LOADCONTACTS_H
#include <QFileDialog>
#include <QFile>
#include <QList>
#include <memory>
#include "ccontact.h"
class LoadContacts //Класс для загрузки(в конструкторе)/сохранени(в деструкторе) контактов в файл
{
public:
    LoadContacts(QList<std::shared_ptr<Ccontact>> &contact);
    ~LoadContacts();
private:
QList<std::shared_ptr<Ccontact>> &contacts;
};

#endif // LOADCONTACTS_H

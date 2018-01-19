#pragma once
#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include <QList>
#include <memory>
#include "ccontact.h"
#include <QList>
#include <QVariant>
#include <QByteArray>
#include <QHash>
#include <QModelIndex>
#include "loadcontacts.h"


class mainModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles {
        NameRole = Qt::UserRole,
        PhoneRole
    };
    explicit mainModel(QObject *parent = nullptr);
    ~mainModel();

protected:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &modelIndex, int role = Qt::DisplayRole) const override;
    virtual QHash<int, QByteArray> roleNames() const override;


signals:

public slots:
    bool changeContact(QString n_name, QString n_phone,int index);
    bool createNewContact(QString n_name, QString n_phone);
    void delateContact(int id);
private:

    QList<std::shared_ptr<Ccontact>> contacts;
    LoadContacts *loadContacs;
};

#endif // MAINMODEL_H

#ifndef GROUPCHAT_H
#define GROUPCHAT_H

#include <QObject>
#include "Message/Message.h"
#include <QIcon>

class CGroupChat : public QObject
{
    Q_OBJECT
public:
    explicit CGroupChat(QObject *parent = 0);
    virtual QString Id() = 0;
    virtual QString ShowName() = 0;
    virtual QString Nick() = 0;
    virtual QString Subject() = 0;
    virtual QStringList Participants() = 0;
    virtual QString ParticipantId(const QString &szId) = 0;
    virtual QString ParticipantNick(const QString &szId) = 0;
    virtual QIcon Icon();

    virtual int Leave() = 0;
    virtual int SendMessage(const QString &szMsg) = 0;
    virtual int Kick(const QString &szId, const QString &reason = QString()) = 0;

    virtual QSharedPointer<CMessage> GetMessage();
signals:
    void sigParticipantAdd(const QString &szId);
    void sigParticipantRemoved(const QString &szId);
    void sigKick(const QString &szId, const QString &reason);

public slots:
private:
    QSharedPointer<CMessage> m_Message;
};

#endif // GROUPCHAT_H
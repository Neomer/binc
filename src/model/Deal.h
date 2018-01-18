#ifndef DEAL_H
#define DEAL_H

#include <core/IJsonSerializable.h>
#include <core/IIdentifyed.h>
#include <core/types/Guid.h>
#include <core/types/Hash.h>

class Deal : public IIdentifyed, public IJsonSerializable
{
public:
    Deal();

    Guid getSender() { return _sender; }
    void setSender(Guid value) { _sender = value; }

    Guid getRecipient() { return _recipient; }
    void setRecipient(Guid value) { _recipient = value; }

    double getAmount() { return _amount; }
    void setAmount(double value) { _amount = value; }

    double getReward() { return _reward; }
    void setReward(double value) { _reward = value; }

    // IJsonSerializable interface
public:
    void serialize(QJsonObject &out) override;
    void deserialize(QJsonObject &in) override;

private:
    Guid _sender, _recipient;
    double _amount, _reward;
};

#endif // DEAL_H

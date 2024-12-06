#include "userprofile.h"

UserProfile::UserProfile()
    : userName("")
    , userAge(0)
{}

void UserProfile::setUserName(const QString &name)
{
    userName = name;
}

void UserProfile::setUserAge(int age)
{
    userAge = age;
}

QString UserProfile::getProfileInfo() const
{
    return QString("Name: %1, Age: %2").arg(userName).arg(userAge);
}

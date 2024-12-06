#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <QString>

class UserProfile
{
public:
    UserProfile();
    void setUserName(const QString &name);
    void setUserAge(int age);
    QString getProfileInfo() const;

private:
    QString userName;
    int userAge;
};

#endif // USERPROFILE_H

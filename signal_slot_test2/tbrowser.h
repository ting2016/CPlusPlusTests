#ifndef TBROWSER_H
#define TBROWSER_H
#include <QObject>
#include <QMainWindow>
#include <string>
class TBrowser: public QMainWindow
{
    Q_OBJECT
protected:
    String s ="sssssss";

public:
    TBrowser();
signals:
    void sendSomething(String);
slots:
    void printSomething(String);

};

#endif // TBROWSER_H

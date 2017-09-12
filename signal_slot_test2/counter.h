#include <QObject>
#include <iostream>
class Counter : public QObject
{
    Q_OBJECT

public:
    void emitSignal(){
        std::cout<<"emit my signal!"<<std::endl;
        emit mysignal();
        for(int i =0;i<100;i++)
            std::cout<<"do the rest in emitSignal."<<std::endl;
    }
public slots:
    void myslot(){
        std::cout<<"my slot is called"<<std::endl;
        for(int i =0;i<100;i++){
            std::cout<<"do something in slot"<<std::endl;
        }
    }

signals:
    void mysignal();
};

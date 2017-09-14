#include "counter.h"
#include <QThread>
//class Func: public QObject{
//    Q_OBJECT
//public slots:
//    void slotInOtherThread(){
//        std::cout<<"my slot is called"<<std::endl;
//        for(int i =0;i<100;i++){
//            std::cout<<"do something in slot in another thread"<<std::endl;
//        }
//    }
//};

int main()
{
    Counter a, b;
//    QObject::connect(&a, SIGNAL(mysignal()),&a, SLOT(myslot()),Qt::AutoConnection);
//    a.emitSignal();

    QThread thread;
    thread.setObjectName("thread");
    b.moveToThread(&thread);
    thread.start();
    QObject::connect(&a, &Counter::mysignal, &b, &Counter::myslot);
    a.emitSignal();
}

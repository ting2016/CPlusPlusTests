#include <QtGui>
#include <QtGui>
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTableView>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;

    QLabel *queryLabel = new QLabel(
        QApplication::translate("nestedlayouts", "Query:"));
    QLineEdit *queryEdit = new QLineEdit();
    QTableView *resultView = new QTableView();

    QHBoxLayout *queryLayout = new QHBoxLayout();
    queryLayout->addWidget(queryLabel);
    queryLayout->addWidget(queryEdit);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(queryLayout);
    mainLayout->addWidget(resultView);
    window.setLayout(mainLayout);

    // Set up the model and configure the view...
    window.setWindowTitle(
        QApplication::translate("nestedlayouts", "Nested layouts"));
    window.show();
    return app.exec();
}

#ifndef GIRIS_H
#define GIRIS_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QDir>



namespace Ui {
class giris;
}

class giris : public QMainWindow
{
    Q_OBJECT

public:

    QSqlDatabase veritabani;


    bool VtAc()
    {

        veritabani=QSqlDatabase::addDatabase("QSQLITE");
        veritabani.setDatabaseName("okumaData.sqlite");

        if(!veritabani.open())
        {
            qDebug() << ("Veritabanına bağlanılamadı...!");
            return false;
        }
        else
        {
            qDebug() << ("Veritabanına bağlanıldı...");
            return true;
        }
    }
    void VtKapat()
    {
        veritabani.close();
        veritabani.removeDatabase(QSqlDatabase::defaultConnection);

    }
    explicit giris(QWidget *parent = 0);
    ~giris();

private slots:
    void on_btnGiris_clicked();

private:
    Ui::giris *ui;
};

#endif // GIRIS_H

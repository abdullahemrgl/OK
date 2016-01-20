#include "giris.h"
#include "ui_giris.h"
#include "anasayfa.h"

giris::giris(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::giris)
{
    ui->setupUi(this);

    if(!VtAc())
    {
        ui->lbDurum->setText("Veritabanına bağlanılamadı...!");
        return;
    }
    else
    {
        ui->lbDurum->setText("Veritabanına bağlanıldı...");
    }
}

giris::~giris()
{
    delete ui;
}

void giris::on_btnGiris_clicked()
{
    VtAc();
    QString kullanici,sifre;
    kullanici=ui->txtKullanici->text();
    sifre=ui->txtSifre->text();

    if(!VtAc())
    {
        qDebug() << "Bağlantı hatası!";
        return;
    }


    VtAc();
    QSqlQuery sorgu;
    sorgu.prepare("SELECT * FROM yetkili WHERE kullaniciAdi='"+kullanici+"' AND sifre='"+sifre+"'");

    if(sorgu.exec())
    {
        int sayac=0;
        while(sorgu.next())
        {
            sayac++;
        }
        if(sayac==1)
        {
            ui->lbDurum->setText("Giriş başarılı...");
            this->hide();
            anasayfa anaForm;
            anaForm.setModal(true);
            anaForm.exec();
        }
        if(sayac<1)
        {
            ui->lbDurum->setText("Kullanıcı yada şifre yanlış!");
        }
        if(sayac>1)
        {
            ui->lbDurum->setText("Fazla giriş var...");
        }
    }

}

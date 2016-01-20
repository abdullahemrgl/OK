#include "anasayfa.h"
#include "ui_anasayfa.h"
#include "giris.h"
#include "okumakayit.h"
#include "kisikayit.h"
#include "kayitduzenle.h"

anasayfa::anasayfa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::anasayfa)
{
    ui->setupUi(this);
    giris baglanti;
    baglanti.VtAc();
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *qry=new QSqlQuery(baglanti.veritabani);

    qry->prepare("SELECT tarih,kitapAdi,SUM(kucukRisaleSayisi),SUM(ortaRisaleSayisi),SUM(buyukRisaleSayisi) FROM kayit ORDER BY ad");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    QSqlQuery *qry2=new QSqlQuery(baglanti.veritabani);
    qry2->prepare("SELECT ad FROM kisiler");
    qry2->exec();
    model->setQuery(*qry2);
    ui->comboKisiler->setModel(model);
}

anasayfa::~anasayfa()
{
    delete ui;
}



void anasayfa::on_txtAra_textChanged(const QString &arg1)
{
    QString aranan;
    aranan=ui->txtAra->text();

    giris baglanti;
    baglanti.VtAc();
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *qry=new QSqlQuery(baglanti.veritabani);

    qry->prepare("SELECT ad,soyad,tarih,kitapAdi,SUM(kucukRisaleSayisi),SUM(ortaRisaleSayisi),SUM(buyukRisaleSayisi) FROM kayit WHERE ad LIKE '"+aranan+"%'");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
}



void anasayfa::on_btnGoster_clicked()
{
    giris baglanti;
    baglanti.VtAc();
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *qry=new QSqlQuery(baglanti.veritabani);

    qry->prepare("SELECT ad,soyad,tarih,kitapAdi,kucukRisaleSayisi,ortaRisaleSayisi,buyukRisaleSayisi FROM kayit WHERE ad='"+ui->comboKisiler->currentText()+"'");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
}

void anasayfa::on_comboGun_currentTextChanged(const QString &arg1)
{
    giris baglanti;
    baglanti.VtAc();
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *qry=new QSqlQuery(baglanti.veritabani);

    qry->prepare("SELECT ad,soyad,tarih,kitapAdi,kucukRisaleSayisi,ortaRisaleSayisi,buyukRisaleSayisi FROM kayit WHERE gun='"+ui->comboGun->currentText()+"'");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
}

void anasayfa::on_comboAy_currentTextChanged(const QString &arg1)
{
    giris baglanti;
    baglanti.VtAc();
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *qry=new QSqlQuery(baglanti.veritabani);

    qry->prepare("SELECT ad,soyad,tarih,kitapAdi,kucukRisaleSayisi,ortaRisaleSayisi,buyukRisaleSayisi FROM kayit WHERE ay='"+ui->comboAy->currentText()+"'");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
}

void anasayfa::on_comboYil_currentTextChanged(const QString &arg1)
{
    giris baglanti;
    baglanti.VtAc();
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *qry=new QSqlQuery(baglanti.veritabani);

    qry->prepare("SELECT ad,soyad,tarih,kitapAdi,kucukRisaleSayisi,ortaRisaleSayisi,buyukRisaleSayisi FROM kayit WHERE yil='"+ui->comboYil->currentText()+"'");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
}

void anasayfa::on_comboKisiler_currentTextChanged(const QString &arg1)
{
    giris baglanti;
    baglanti.VtAc();
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *qry=new QSqlQuery(baglanti.veritabani);

    qry->prepare("SELECT ad,soyad,tarih,kitapAdi,kucukRisaleSayisi,ortaRisaleSayisi,buyukRisaleSayisi FROM kayit WHERE ad='"+ui->comboKisiler->currentText()+"'");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
}

void anasayfa::on_btnOkumaKayit_clicked()
{
    /**/
    if(ui->radioOkumaKayit->isChecked())
    {
        okumaKayit okumaKayitForm;
        okumaKayitForm.setModal(true);
        okumaKayitForm.exec();
    }
    if(ui->radioKisiKayit->isChecked())
    {
        kisiKayit kisiKayitForm;
        kisiKayitForm.setModal(true);
        kisiKayitForm.exec();
    }
    if(ui->radioDuzenle->isChecked())
    {
        kayitDuzenle kayitDuzenleForm;
        kayitDuzenleForm.setModal(true);
        kayitDuzenleForm.exec();
    }

}



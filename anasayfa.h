#ifndef ANASAYFA_H
#define ANASAYFA_H

#include <QDialog>

namespace Ui {
class anasayfa;
}

class anasayfa : public QDialog
{
    Q_OBJECT

public:
    explicit anasayfa(QWidget *parent = 0);
    ~anasayfa();

private slots:

    void on_txtAra_textChanged(const QString &arg1);

    void on_btnGoster_clicked();

    void on_comboGun_currentTextChanged(const QString &arg1);

    void on_comboAy_currentTextChanged(const QString &arg1);

    void on_comboYil_currentTextChanged(const QString &arg1);

    void on_btnOkumaKayit_clicked();

    void on_comboKisiler_currentTextChanged(const QString &arg1);

private:
    Ui::anasayfa *ui;
};

#endif // ANASAYFA_H

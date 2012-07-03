#include "agproperties.h"
#include "ui_agproperties.h"

AgProperties::AgProperties(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgProperties)
{
    ui->setupUi(this);
}

AgProperties::~AgProperties()
{
    delete ui;
}

KRZYZOWANIE AgProperties::krzyzowanie()
{
    if(ui->radioButtonK1->isChecked())
    {
        return P1;
    }else if(ui->radioButtonK2->isChecked())
    {
        return P2;
    }else if(ui->radioButtonKW)
    {
        return R;
    }else
    {
        return K_NONE;
    }
}

MUTACJA AgProperties::mutacja()
{
    if(ui->radioButtonM2->isChecked())
    {
        return INORDER;
    }else if(ui->radioButtonML->isChecked())
    {
        return M_LOSOWA;
    }else
    {
        return M_NONE;
    }
}

SELEKCJA AgProperties::selekcja()
{
    if(ui->radioElitarna->isChecked())
    {
        return ELITARNA;
    }else if(ui->radioTurniejowa->isChecked())
    {
        return TURNIEJOWA;
    }else if(ui->radioLosowa->isChecked())
    {
        return S_LOSOWA;
    }else if(ui->radioProporcjonalna->isChecked())
    {
        return PROPORCJONALNA;
    }
    else
    {
        return S_NONE;
    }
}


int AgProperties::limitEpok()
{
    return ui->lineEditLimitEpok->text().toInt();
}

int AgProperties::proporcjaPopulacji()
{
     return ui->lineEditProportion->text().toInt();
}

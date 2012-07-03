#ifndef AGPROPERTIES_H
#define AGPROPERTIES_H

#include <QDialog>

namespace Ui {
class AgProperties;
}


enum KRZYZOWANIE {K_NONE=-1, P1, P2, R};
enum SELEKCJA {S_NONE=-1, ELITARNA, TURNIEJOWA, PROPORCJONALNA, S_LOSOWA };
enum MUTACJA {M_NONE=-1, M_LOSOWA, INORDER};


class AgProperties : public QDialog
{
    Q_OBJECT
    
public:
    explicit AgProperties(QWidget *parent = 0);
    ~AgProperties();

    KRZYZOWANIE krzyzowanie();
    MUTACJA mutacja();
    SELEKCJA selekcja();

    int limitEpok();
    int proporcjaPopulacji();
    
private:
    Ui::AgProperties *ui;
};

#endif // AGPROPERTIES_H

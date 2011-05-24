// MaFenetre.h

#ifndef DEF_MAFENETRE
#define DEF_MAFENETRE

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>

class MaFenetre : public QWidget
{
    Q_OBJECT

public:
    MaFenetre();

public slots:
    void ouvrirDialoguePseudo();
    void ouvrirDialoguePays();

private:
    QPushButton *m_boutonPseudo;
    QPushButton *m_boutonPays;
};

#endif

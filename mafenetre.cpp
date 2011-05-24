// MaFenetre.cpp

#include "MaFenetre.h"
#include <QStringList>
#include <QInputDialog>

MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(200, 120);

    m_boutonPseudo = new QPushButton("Demande de pseudo", this);
    m_boutonPseudo->move(30, 30);
    QObject::connect(m_boutonPseudo, SIGNAL(clicked()), this, SLOT(ouvrirDialoguePseudo()));

    m_boutonPays = new QPushButton("Demande de pays", this);
    m_boutonPays->move(30, 60);
    QObject::connect(m_boutonPays, SIGNAL(clicked()), this, SLOT(ouvrirDialoguePays()));

}

void MaFenetre::ouvrirDialoguePseudo()
{
    bool ok = false;
        QString pseudo = QInputDialog::getText(this, "Pseudo", "Quel est votre pseudo ?", QLineEdit::Normal, QString(), &ok);

        if (ok && !pseudo.isEmpty())
        {
            QMessageBox::information(this, "Pseudo", "Bonjour " + pseudo + ", ça va ?");
            this->setWindowTitle("Bienvenue "+pseudo+ " !");
        }
        else
        {
            QMessageBox::critical(this, "Pseudo", "Vous n'avez pas voulu donner votre nom... snif.");
        }


}

void MaFenetre::ouvrirDialoguePays(){
    QStringList pays;
        pays << "France" << "Zombieland" << "Wonderland" << "Neverland" << "Lamaland" << "Autre";
        QString choix = QInputDialog::getItem(this, "Votre pays", "De quel pays êtes vous ?", pays);
        m_boutonPays->setText("Vous venez de "+choix);

}

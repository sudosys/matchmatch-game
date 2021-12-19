#ifndef DIFFICULTYMENU_H
#define DIFFICULTYMENU_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class DifficultyMenu; }
QT_END_NAMESPACE

class DifficultyMenu : public QDialog {
    Q_OBJECT

    public:
        DifficultyMenu(QWidget *parent = nullptr);
        ~DifficultyMenu();

private slots:
        void on_easy_button_clicked();

        void on_medium_button_clicked();

        void on_hard_button_clicked();

private:
        Ui::DifficultyMenu* ui;
};

#endif // DIFFICULTYMENU_H

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

private:
    Ui::DifficultyMenu *ui;
};

#endif // DIFFICULTYMENU_H

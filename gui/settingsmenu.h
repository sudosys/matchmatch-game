#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class SettingsMenu; }
QT_END_NAMESPACE

class SettingsMenu : public QDialog {
    Q_OBJECT

public:
    SettingsMenu(QWidget *parent = nullptr);
    ~SettingsMenu();
    void save_settings();

private slots:
    void on_save_button_clicked();
    void on_cancel_button_clicked();

private:
    Ui::SettingsMenu *ui;
};

#endif // SETTINGSMENU_H

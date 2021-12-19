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
        void load_settings();
        void save_settings();
        Ui::SettingsMenu* ui;

    private slots:
        void on_save_button_clicked();
        void on_cancel_button_clicked();
        void on_card_back_combo_currentTextChanged(const QString &arg1);
        void on_card_front_preview_clicked();
        void on_bg_preview_clicked();

private:


};

#endif // SETTINGSMENU_H

#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <QDialog>
#include "gui/preview_window/previewwindow.h"
#include <map>

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
        void fill_dropbox();
        std::string get_key_from_value(std::map<std::string, std::string>, int index);

    private slots:
        void on_save_button_clicked();
        void on_cancel_button_clicked();
        void on_card_back_combo_currentTextChanged(const QString &arg1);
        void on_card_front_preview_clicked();
        void on_bg_preview_clicked();

    private:
        PreviewWindow preview_window;
        std::map<std::string, std::string> card_back_combobox, card_front_combobox, background_combobox;
        std::map<std::string,std::string>::iterator mapIter;

};

#endif // SETTINGSMENU_H

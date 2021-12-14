#include "settingsmenu.h"
#include "ui_settingsmenu.h"

SettingsMenu::SettingsMenu(QWidget *parent) : QDialog(parent), ui(new Ui::SettingsMenu) {
    ui->setupUi(this);
}

SettingsMenu::~SettingsMenu() {
    delete ui;
}

void save_settings() {}

void SettingsMenu::on_cancel_button_clicked() {
    close();
}

void SettingsMenu::on_save_button_clicked() {
    //save method
    close();
}


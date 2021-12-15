#include "settingsmenu.h"
#include "ui_settingsmenu.h"
#include <fstream>
#include <iostream>
#include <string>

SettingsMenu::SettingsMenu(QWidget *parent) : QDialog(parent), ui(new Ui::SettingsMenu) {
    ui->setupUi(this);
}

SettingsMenu::~SettingsMenu() {
    delete ui;
}

void SettingsMenu::load_settings() {

    QString file_content[4];
    std::string temp;
    int row_num = 0;

    std::ifstream cfg_file("game_settings.cfg");

    while (getline(cfg_file, temp)) {
        file_content[row_num] = QString::fromStdString(temp);
        std::cout << file_content[row_num].toStdString() << std::endl;
        row_num++;
    }

    ui->card_back_combo->setCurrentText(file_content[0]);
    ui->card_front_combo->setCurrentText(file_content[1]);
    ui->bg_combo->setCurrentText(file_content[2]);

    if (file_content[3] == "1") {
        ui->music_on->setChecked(true);
    } else {
        ui->music_off->setChecked(true);
    }

}

void SettingsMenu::save_settings() {

    QString card_back_texture = ui->card_back_combo->currentText();
    QString card_front_texture = ui->card_front_combo->currentText();
    QString bg_texture = ui->bg_combo->currentText();
    QString music_status = "0";

    if (ui->music_on->isChecked()) {
        music_status = "1";
    }

    std::ofstream cfg_file("game_settings.cfg");

    cfg_file << card_back_texture.toStdString() << "\n";
    cfg_file << card_front_texture.toStdString() << "\n";
    cfg_file << bg_texture.toStdString() << "\n";
    cfg_file << music_status.toStdString();

    cfg_file.close();

}

void SettingsMenu::on_save_button_clicked() {
    save_settings();
    close();
}

void SettingsMenu::on_cancel_button_clicked() {
    close();
}

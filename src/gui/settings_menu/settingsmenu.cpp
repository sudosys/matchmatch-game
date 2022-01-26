#include "settingsmenu.h"
#include "ui_settingsmenu.h"
#include "gui/preview_window/previewwindow.cpp"
#include "gui/about_window/aboutwindow.cpp"
#include <fstream>
#include <QPixmap>

SettingsMenu::SettingsMenu(QWidget *parent) : QDialog(parent), ui(new Ui::SettingsMenu) {
    ui->setupUi(this);
    fill_dropbox();
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
        row_num++;
    }

    for (mapIter = card_back_combobox.begin(); mapIter != card_back_combobox.end(); mapIter++) {
        if (mapIter->second == file_content[0].toStdString()) {
            ui->card_back_combo->setCurrentText(QString::fromStdString(mapIter->first));
        }
    }

    for (mapIter = card_front_combobox.begin(); mapIter != card_front_combobox.end(); mapIter++) {
        if (mapIter->second == file_content[1].toStdString()) {
            ui->card_front_combo->setCurrentText(QString::fromStdString(mapIter->first));
        }
    }

    for (mapIter = background_combobox.begin(); mapIter != background_combobox.end(); mapIter++) {
        if (mapIter->second == file_content[2].toStdString()) {
            ui->bg_combo->setCurrentText(QString::fromStdString(mapIter->first));
        }
    }

    if (file_content[3] == "1") { ui->music_on->setChecked(true); }
    else { ui->music_off->setChecked(true); }

}

void SettingsMenu::save_settings() {

    std::string card_back_texture = card_back_combobox[ui->card_back_combo->currentText().toStdString()];
    std::string card_front_texture = card_front_combobox[ui->card_front_combo->currentText().toStdString()];
    std::string bg_texture = background_combobox[ui->bg_combo->currentText().toStdString()];
    std::string music_status = "0";

    if (ui->music_on->isChecked()) { music_status = "1"; }

    std::ofstream cfg_file("game_settings.cfg");

    cfg_file << card_back_texture << "\n";
    cfg_file << card_front_texture << "\n";
    cfg_file << bg_texture << "\n";
    cfg_file << music_status;

    cfg_file.close();

}

void SettingsMenu::on_save_button_clicked() {
    save_settings();
    close();
}

void SettingsMenu::on_cancel_button_clicked() {
    close();
}

void SettingsMenu::on_about_button_clicked() {
    AboutWindow about_window;
    about_window.exec();
}

void SettingsMenu::on_card_back_combo_currentTextChanged(const QString &arg1) {
    std::string current_selection = card_back_combobox[arg1.toStdString()] + ".png";
    ui->card_back_preview->setPixmap(QPixmap("../textures/card_back_textures/texture_previews/" + QString::fromStdString(current_selection)));
}

void SettingsMenu::on_card_front_preview_clicked() {
    preview_window.setWindowTitle("Card Front Texture Preview");
    std::string current_selection = card_front_combobox[ui->card_front_combo->currentText().toStdString()] + ".png";
    preview_window.setMinimumSize(500,320);
    preview_window.setMaximumSize(500,320);
    preview_window.ui->texture->setGeometry(0,0,500,320);
    preview_window.ui->texture->setPixmap(QPixmap("../textures/card_front_textures/texture_previews/" + QString::fromStdString(current_selection)));
    preview_window.exec();
}

void SettingsMenu::on_bg_preview_clicked() {
    preview_window.setWindowTitle("Background Texture Preview");
    std::string current_selection = background_combobox[ui->bg_combo->currentText().toStdString()] + ".png";
    preview_window.setMinimumSize(1280,720);
    preview_window.setMaximumSize(1280,720);
    preview_window.ui->texture->setGeometry(0,0,1280,720);
    preview_window.ui->texture->setPixmap(QPixmap("../textures/background_textures/" + QString::fromStdString(current_selection)));
    preview_window.exec();
}

void SettingsMenu::fill_dropbox() {

    std::map<std::string,std::string>::iterator mapIter;

    // Card Back Combobox

    card_back_combobox.insert(std::pair<std::string, std::string>("Card Back 1", "card_back_1"));
    card_back_combobox.insert(std::pair<std::string, std::string>("Card Back 2", "card_back_2"));
    card_back_combobox.insert(std::pair<std::string, std::string>("Card Back 3", "card_back_3"));

    for (mapIter = card_back_combobox.begin(); mapIter != card_back_combobox.end(); mapIter++) {
        ui->card_back_combo->addItem(QString::fromStdString(mapIter->first));
    }

    // Card Front Combobox

    card_front_combobox.insert(std::pair<std::string, std::string>("Dota Characters", "card_front_1"));
    card_front_combobox.insert(std::pair<std::string, std::string>("Flowers", "card_front_2"));
    card_front_combobox.insert(std::pair<std::string, std::string>("Memes", "card_front_3"));

    for (mapIter = card_front_combobox.begin(); mapIter != card_front_combobox.end(); mapIter++) {
        ui->card_front_combo->addItem(QString::fromStdString(mapIter->first));
    }

    // Background

    background_combobox.insert(std::pair<std::string, std::string>("Background 1", "bg_1"));
    background_combobox.insert(std::pair<std::string, std::string>("Background 2", "bg_2"));
    background_combobox.insert(std::pair<std::string, std::string>("Background 3", "bg_3"));

    for (mapIter = background_combobox.begin(); mapIter != background_combobox.end(); mapIter++) {
        ui->bg_combo->addItem(QString::fromStdString(mapIter->first));
    }

}

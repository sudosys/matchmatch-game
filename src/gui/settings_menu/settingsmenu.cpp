#include "settingsmenu.h"
#include "ui_settingsmenu.h"
#include "gui/preview_window/previewwindow.h"
#include "gui/preview_window/previewwindow.cpp"
#include <fstream>
#include <QPixmap>

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

void SettingsMenu::on_card_back_combo_currentTextChanged(const QString &arg1) {
    QString current_selection = arg1 + QString::fromStdString(".png");
    ui->card_back_preview->setPixmap(QPixmap("../textures/card_back_textures/texture_previews/" + current_selection));
}

void SettingsMenu::on_card_front_preview_clicked() {
    PreviewWindow preview_window;
    preview_window.setWindowTitle("Card Front Texture Preview");
    QString current_selection = ui->card_front_combo->currentText() + QString::fromStdString(".png");
    preview_window.ui->texture->setPixmap(QPixmap("../textures/card_front_textures/texture_previews/" + current_selection));
    preview_window.exec();
}

void SettingsMenu::on_bg_preview_clicked() {
    PreviewWindow preview_window;
    preview_window.setWindowTitle("Background Texture Preview");
    QString current_selection = ui->bg_combo->currentText() + QString::fromStdString(".png");
    preview_window.ui->texture->setPixmap(QPixmap("../textures/background_textures/" + current_selection));
    preview_window.exec();
}


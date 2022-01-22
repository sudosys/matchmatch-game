#include "difficultymenu.h"
#include "ui_difficultymenu.h"

DifficultyMenu::DifficultyMenu(QWidget *parent) : QDialog(parent), ui(new Ui::DifficultyMenu) {
    ui->setupUi(this);
}

DifficultyMenu::~DifficultyMenu() {
    delete ui;
}

void DifficultyMenu::on_easy_button_clicked() {
    close();
    gametable_window.set_background();
    gametable_window.init_music();
    gametable_window.draw_card_grid(4,3);
    gametable_window.setWindowTitle("Match Match Game [Easy Difficulty]");
    gametable_window.exec();
}

void DifficultyMenu::on_medium_button_clicked() {
    close();
    gametable_window.set_background();
    gametable_window.init_music();
    gametable_window.draw_card_grid(4,4);
    gametable_window.setWindowTitle("Match Match Game [Medium Difficulty]");
    gametable_window.exec();
}

void DifficultyMenu::on_hard_button_clicked() {
    close();
    gametable_window.set_background();
    gametable_window.init_music();
    gametable_window.draw_card_grid(4,5);
    gametable_window.setWindowTitle("Match Match Game [Hard Difficulty]");
    gametable_window.exec();
}

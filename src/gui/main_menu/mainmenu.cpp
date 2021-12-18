#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "gui/difficulty_menu/difficultymenu.h"
#include "gui/settings_menu/settingsmenu.h"
#include <stdlib.h>

MainMenu::MainMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);
}

MainMenu::~MainMenu() {
    delete ui;
}

void MainMenu::on_play_button_clicked() {
    DifficultyMenu difficulty_menu;
    difficulty_menu.setModal(true);
    difficulty_menu.exec();
}

void MainMenu::on_settings_button_clicked() {
    SettingsMenu settings_menu;
    settings_menu.load_settings();
    settings_menu.setModal(true);
    settings_menu.exec();
}

void MainMenu::on_exit_button_clicked() {
    exit(EXIT_SUCCESS);
}

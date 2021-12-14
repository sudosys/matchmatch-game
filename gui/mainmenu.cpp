#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "difficultymenu.h"
#include "settingsmenu.h"
#include <stdlib.h>

MainMenu::MainMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);
}

MainMenu::~MainMenu() {
    delete ui;
}

void MainMenu::on_play_button_clicked() {
    DifficultyMenu diff_menu;
    diff_menu.setModal(true);
    diff_menu.exec();
}

void MainMenu::on_settings_button_clicked() {
    SettingsMenu set_menu;
    set_menu.setModal(true);
    set_menu.exec();
}

void MainMenu::on_exit_button_clicked() {
    exit(EXIT_SUCCESS);
}

#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "gui/difficulty_menu/difficultymenu.h"
#include "gui/settings_menu/settingsmenu.h"
#include "gui/statistics_window/statisticswindow.h"
#include <cstdlib>
#include <fstream>
#include <filesystem>

MainMenu::MainMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);
    load_default_settings();
}

MainMenu::~MainMenu() {
    delete ui;
}

void MainMenu::on_play_button_clicked() {
    DifficultyMenu difficulty_menu;
    difficulty_menu.exec();
}

void MainMenu::on_settings_button_clicked() {
    SettingsMenu settings_menu;
    settings_menu.load_settings();
    settings_menu.exec();
}

void MainMenu::on_statistics_button_clicked() {
    StatisticsWindow statistics_window;
    statistics_window.fill_table();
    statistics_window.exec();
}

void MainMenu::on_exit_button_clicked() {
    exit(EXIT_SUCCESS);
}

void MainMenu::load_default_settings() {

    if (std::filesystem::exists("game_settings.cfg")) { return; }

    std::ofstream cfg_file("game_settings.cfg");

    cfg_file << "card_back_1" << "\n";
    cfg_file << "card_front_1" << "\n";
    cfg_file << "bg_1" << "\n";
    cfg_file << "0" << "\n";
    cfg_file << "0";

    cfg_file.close();
}

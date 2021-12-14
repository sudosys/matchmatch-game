#include "difficultymenu.h"
#include "ui_difficultymenu.h"

DifficultyMenu::DifficultyMenu(QWidget *parent) : QDialog(parent), ui(new Ui::DifficultyMenu) {
    ui->setupUi(this);
}

DifficultyMenu::~DifficultyMenu() {
    delete ui;
}


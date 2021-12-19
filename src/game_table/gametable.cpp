#include "game_table/gametable.h"
#include "ui_gametable.h"
#include <fstream>
#include <iostream>
#include <QPixmap>
#include <QGridLayout>
#include <QPushButton>
#include <vector>

std::vector<QPushButton*>* cards = new std::vector<QPushButton*>;
QGridLayout* card_layout = new QGridLayout();

GameTable::GameTable(QWidget *parent) : QDialog(parent), ui(new Ui::GameTable) {
    ui->setupUi(this);
}

GameTable::~GameTable() {
    delete ui;
    delete cards;
    delete card_layout;
}

void GameTable::set_background() {

    std::string current_bg;
    int row_num = 0;

    std::ifstream cfg_file("game_settings.cfg");

    while (getline(cfg_file, current_bg)) {
        if (row_num == 2) { break; }
        row_num++;
    }

    current_bg += ".png";

    ui->background->setPixmap(QPixmap("../textures/background_textures/" + QString::fromStdString(current_bg)));

}

QString GameTable::get_card_back() {

    std::string current_card_back;

    std::ifstream cfg_file("game_settings.cfg");

    getline(cfg_file, current_card_back);

    current_card_back += ".png";

    return QString::fromStdString(current_card_back);

}

void GameTable::draw_card_grid(int rows, int columns) {

    QString current_card_back = get_card_back();

    int card_index = 0;

    create_cards(rows*columns);

    for (int j = 0; j < rows; j++) {

        for (int i = 0; i < columns; i++) {

            cards->at(card_index)->setFlat(true);

            cards->at(card_index)->setIcon(QPixmap("../textures/card_back_textures/" + current_card_back));

            cards->at(card_index)->setIconSize(QSize(100,160));

            QPushButton::connect(cards->at(card_index), &QPushButton::clicked, this, &GameTable::flip_card);

            card_layout->addWidget(cards->at(card_index), j, i);

            card_index++;

        }

    }

    this->setLayout(card_layout);

}

void GameTable::flip_card() {
    QPushButton* clicked_card = qobject_cast<QPushButton*>(sender());
    int card_index = find_card_index(clicked_card);
    clicked_card->setIcon(QPixmap("../textures/card_front_textures/0.png"));
    clicked_card->setIconSize(QSize(100,160));
    std::cout << card_index << std::endl;
}

void GameTable::create_cards(int number_of_cards) {

    for (int i = 0; i < number_of_cards; i++) {
        cards->push_back(new QPushButton());
    }

}

int GameTable::find_card_index(QPushButton* card) {

    auto iterator = std::find(cards->begin(), cards->end(), card);

    if (iterator != cards->end()) {
        return iterator - cards->begin();
    }

    return -1;
}

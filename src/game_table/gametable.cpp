#include "game_table/gametable.h"
#include "ui_gametable.h"
#include <fstream>
#include <iostream>
#include <QPixmap>
#include <QPushButton>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

GameTable::GameTable(QWidget *parent) : QDialog(parent), ui(new Ui::GameTable), cards(new std::vector<QPushButton*>),
                                        card_fronts(new std::vector<int>), card_layout(new QGridLayout()) {
    ui->setupUi(this);
    srand(time(NULL));
}

GameTable::~GameTable() {
    delete ui;
    delete cards;
    delete card_fronts;
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
    card_front_generator(rows*columns);

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
    QString card_front_file = QString::fromStdString(std::to_string(card_fronts->at(card_index))) + ".png";
    clicked_card->setIcon(QPixmap("../textures/card_front_textures/" + card_front_file));
    clicked_card->setIconSize(QSize(100,160));
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

void GameTable::card_front_generator(int number_of_cards) {

    std::random_device rnd_dev;
    std::mt19937 prng(rnd_dev());

    int index_val = 0;

    for (int i = 0; i < number_of_cards; i++) {

        if ((i % 2 == 0) && i != 0) {
            index_val++;
        }

        card_fronts->insert(card_fronts->begin() + i, index_val);

    }

    std::shuffle(card_fronts->begin(), card_fronts->end(), prng);

}

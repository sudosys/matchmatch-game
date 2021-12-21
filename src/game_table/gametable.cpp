#include "game_table/gametable.h"
#include "ui_gametable.h"
#include <fstream>
#include <iostream>
#include <QPixmap>
#include <QPushButton>
#include <QTime>
#include <vector>
#include <random>
#include <cstdlib>

GameTable::GameTable(QWidget *parent) : QDialog(parent), ui(new Ui::GameTable), card_backs(new std::vector<QPushButton*>),
                                        card_fronts(new std::vector<QPushButton*>), card_front_indices(new std::vector<int>),
                                        card_layout(new QGridLayout()), is_first(true), flipped_cards(0), first_card_index(-1), second_card_index(-1) {
    ui->setupUi(this);
}

GameTable::~GameTable() {
    delete ui;
    delete card_backs;
    delete card_fronts;
    delete card_front_indices;
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

void GameTable::draw_card_grid(int rows, int columns) {

    int card_index = 0;

    card_front_generator(rows*columns);
    create_cards(rows*columns);

    for (int j = 0; j < rows; j++) {

        for (int i = 0; i < columns; i++) {

            card_layout->addWidget(card_backs->at(card_index), j, i);
            card_layout->addWidget(card_fronts->at(card_index), j, i);
            card_fronts->at(card_index)->hide();

            card_index++;

        }

    }

    this->setLayout(card_layout);

}

QString GameTable::get_card_back() {

    std::string current_card_back;

    std::ifstream cfg_file("game_settings.cfg");

    getline(cfg_file, current_card_back);

    current_card_back += ".png";

    return QString::fromStdString(current_card_back);

}

void GameTable::match_cards() {

        std::cout << first_card_index << "  " << second_card_index << std::endl;

        if (card_front_indices->at(first_card_index) == card_front_indices->at(second_card_index)) {
            std::cout << "Cards match!" << std::endl;
            delay(1);
            card_fronts->at(first_card_index)->hide();
            card_fronts->at(second_card_index)->hide();
            flipped_cards = 0;
            is_first = true;
        } else {
            std::cout << "Cards don't match!" << std::endl;
            delay(1);
            flip_front();
            is_first = true;
            flipped_cards = 0;
        }

}

void GameTable::create_cards(int number_of_cards) {

    QString card_front_texture;

    for (int i = 0; i < number_of_cards; i++) {
        card_backs->push_back(new QPushButton());
        card_backs->at(i)->setFlat(true);
        card_backs->at(i)->setIcon(QPixmap("../textures/card_back_textures/" + get_card_back()));
        card_backs->at(i)->setIconSize(QSize(100,160));
        QPushButton::connect(card_backs->at(i), &QPushButton::clicked, this, &GameTable::flip_back);
        card_fronts->push_back(new QPushButton());
        card_fronts->at(i)->setFlat(true);
        card_front_texture = QString::fromStdString(std::to_string(card_front_indices->at(i))) + ".png";
        card_fronts->at(i)->setIcon(QPixmap("../textures/card_front_textures/" + card_front_texture));
        card_fronts->at(i)->setIconSize(QSize(100,160));
    }

}

int GameTable::find_card_index(QPushButton* card, std::vector<QPushButton*>* vector_to_check) {

    auto iterator = std::find(vector_to_check->begin(), vector_to_check->end(), card);

    if (iterator != vector_to_check->end()) {
        return iterator - vector_to_check->begin();
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

        card_front_indices->push_back(index_val);

    }

    std::shuffle(card_front_indices->begin(), card_front_indices->end(), prng);

}

void GameTable::flip_front() {

    card_fronts->at(first_card_index)->hide();
    card_fronts->at(second_card_index)->hide();

    card_backs->at(first_card_index)->show();
    card_backs->at(second_card_index)->show();

}

void GameTable::flip_back() {

    QPushButton* clicked_card = qobject_cast<QPushButton*>(sender());

    int card_front_index = find_card_index(clicked_card, card_backs);

    clicked_card->hide();
    card_fronts->at(card_front_index)->show();

    if (is_first) {
        first_card_index = find_card_index(clicked_card, card_backs);
        is_first = false;
    } else {
        second_card_index = find_card_index(clicked_card, card_backs);
    }

    flipped_cards++;

    if (flipped_cards == 2) {
        match_cards();
    }

}

void GameTable::delay(int seconds) {

    QTime die_time = QTime::currentTime().addSecs(seconds);

    while (QTime::currentTime() < die_time) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }

}

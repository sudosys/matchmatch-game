#include "endgamewindow.h"
#include "../../game_table/gametable.h"
#include "ui_endgamewindow.h"
#include <fstream>
#include <QPixmap>
#include <iostream>

EndGameWindow::EndGameWindow(int game_time, int err_flips, QWidget *parent) : QDialog(parent), ui(new Ui::EndGameWindow), elapsed_game_time(game_time) {
    ui->setupUi(this);
    time_elapsed_label_builder(elapsed_game_time, err_flips);
}

EndGameWindow::~EndGameWindow() {
    delete ui;
}

void EndGameWindow::on_ok_button_clicked() {
    close();
}

void EndGameWindow::time_elapsed_label_builder(int elapsed_game_time, int err_flips) {

    int minutes = (elapsed_game_time/1000)/60;
    int seconds = (elapsed_game_time/1000)%60;

    ui->time_elapsed->setText(QString("Time elapsed: " + QString::number(minutes) + " minutes " + QString::number(seconds) + " seconds"));

    ui->err_flips->setText(QString("Erroneous flips: ") + QString::number(err_flips));

}

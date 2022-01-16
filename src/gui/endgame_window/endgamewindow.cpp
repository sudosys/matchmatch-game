#include "endgamewindow.h"
#include "../../game_table/gametable.h"
#include "ui_endgamewindow.h"
#include <fstream>
#include <QPixmap>
#include <QDateTime>

EndGameWindow::EndGameWindow(int game_time, int err_flips, std::string difficulty, QWidget *parent) : QDialog(parent), ui(new Ui::EndGameWindow),
                                                                                                      elapsed_game_time(game_time), erroneous_flips(err_flips),
                                                                                                      difficulty_level(difficulty) {
    ui->setupUi(this);
    game_info_label_builder(elapsed_game_time, err_flips);
}

EndGameWindow::~EndGameWindow() {
    delete ui;
}

void EndGameWindow::on_ok_button_clicked() {
    close();
    save_statistics(elapsed_game_time, erroneous_flips, difficulty_level);
}

void EndGameWindow::game_info_label_builder(int elapsed_game_time, int err_flips) {

    int minutes = (elapsed_game_time/1000)/60;
    int seconds = (elapsed_game_time/1000)%60;

    ui->time_elapsed->setText(QString("Time elapsed: " + QString::number(minutes) + " minutes " + QString::number(seconds) + " seconds"));

    ui->err_flips->setText(QString("Erroneous flips: ") + QString::number(err_flips));

}

void EndGameWindow::save_statistics(int elapsed_game_time, int err_flips, std::string difficulty) {

    int minutes = (elapsed_game_time/1000)/60;
    int seconds = (elapsed_game_time/1000)%60;

    std::fstream stat_file("player_statistics.txt", std::fstream::in | std::fstream::out | std::fstream::app);

    stat_file << difficulty << "," << QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss").toStdString()
              << "," << minutes << " minute(s) " << seconds << " second(s)" << "," << err_flips << "\n";

}

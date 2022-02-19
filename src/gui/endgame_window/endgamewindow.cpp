#include "endgamewindow.h"
#include "../../game_table/gametable.h"
#include "ui_endgamewindow.h"
#include <fstream>
#include <filesystem>
#include <sstream>
#include <QPixmap>

EndGameWindow::EndGameWindow(int game_time, int err_flips, std::string difficulty, std::string game_start_dtime, QWidget *parent)
                                                                                                      : QDialog(parent), ui(new Ui::EndGameWindow),
                                                                                                      elapsed_game_time(game_time), erroneous_flips(err_flips),
                                                                                                      difficulty_level(difficulty), game_start_date_time(game_start_dtime) {
    ui->setupUi(this);
    game_info_label_builder();
}

EndGameWindow::~EndGameWindow() {
    delete ui;
}

void EndGameWindow::on_ok_button_clicked() {
    close();
    save_statistics();
}

void EndGameWindow::game_info_label_builder() {

    minutes = (elapsed_game_time/1000)/60;
    seconds = (elapsed_game_time/1000)%60;
    score = (1.0/(((minutes*60)+seconds)*erroneous_flips))*10000;

    ui->time_elapsed->setText(QString("Time elapsed: " + QString::number(minutes) + " minute(s) " + QString::number(seconds) + " second(s)"));
    ui->err_flips->setText(QString("Erroneous flips: ") + QString::number(erroneous_flips));
    ui->score->setText(QString("Score: ") + QString::number(score));
    if (high_score_check(score)) {
        ui->highest_score->setText(QString("Hey! You scored the highest score on ") + QString::fromStdString(difficulty_level) + QString(" difficulty 🥳"));
    }

}

void EndGameWindow::save_statistics() {

    std::fstream stat_file("player_statistics.txt", std::fstream::in | std::fstream::out | std::fstream::app);

    stat_file << difficulty_level << "," << game_start_date_time << "," << minutes << " min(s) "
              << seconds << " sec(s)" << "," << erroneous_flips << "," << score << "\n";

}

bool EndGameWindow::high_score_check(int score) {

    std::ifstream highest_scores_read("highest_scores.txt");
    std::ofstream highest_scores_write;

    if (!std::filesystem::exists("highest_scores.txt")) {
        highest_scores_write.open("highest_scores.txt");
        highest_scores_write << "0" << " " << "0" << " " << "0";
        highest_scores_write.close();
    }

    int difficulty_index = 0;
    int row_index = 0;
    int scores[] = {0,0,0};
    bool isHighest = false;
    std::string row;

    getline(highest_scores_read, row);

    std::istringstream row_split(row);
    std::string score_in_file;

    if (difficulty_level == "Easy") { difficulty_index = 0; }
    else if (difficulty_level == "Medium") { difficulty_index = 1; }
    else if (difficulty_level == "Hard") { difficulty_index = 2; }

    while(getline(row_split, score_in_file, ' ')) {

        scores[row_index] = std::stoi(score_in_file);

        row_index++;

    }

    highest_scores_read.close();

    if (score > scores[difficulty_index]) {

        if (scores[difficulty_index] != 0) { isHighest = true; }

        scores[difficulty_index] = score;
        highest_scores_write.open("highest_scores.txt");
        highest_scores_write << scores[0] << " " << scores[1] << " " << scores[2];
        highest_scores_write.close();

    }

    return isHighest;

}

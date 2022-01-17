#ifndef ENDGAMEWINDOW_H
#define ENDGAMEWINDOW_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class EndGameWindow; }
QT_END_NAMESPACE

class EndGameWindow : public QDialog {
    Q_OBJECT

    public:
        EndGameWindow(int elapsed_game_time, int err_flips, std::string difficulty, std::string game_start_dtime, QWidget *parent = nullptr);
        ~EndGameWindow();
        Ui::EndGameWindow* ui;
        void game_info_label_builder(int game_time, int err_flips);
        void save_statistics(int elapsed_game_time, int err_flips, std::string difficulty);

    private slots:
        void on_ok_button_clicked();

    private:
        int elapsed_game_time;
        int erroneous_flips;
        std::string difficulty_level;
        std::string game_start_date_time;
        int minutes, seconds;

};

#endif // ENDGAMEWINDOW_H

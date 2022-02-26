#ifndef ENDGAMEWINDOW_H
#define ENDGAMEWINDOW_H

#include <QDialog>
#include <QSoundEffect>

QT_BEGIN_NAMESPACE
namespace Ui { class EndGameWindow; }
QT_END_NAMESPACE

class EndGameWindow : public QDialog {
    Q_OBJECT

    public:
        EndGameWindow(int elapsed_game_time, int err_flips, std::string difficulty, std::string game_start_dtime,
                      std::vector<int>* combos_achieved, std::string sound_effect_setting, QWidget *parent = nullptr);
        ~EndGameWindow();
        Ui::EndGameWindow* ui;
        void end_game_stat_builder();
        void save_statistics();
        bool high_score_check(int score);
        void play_new_record_sound();

    private slots:
        void on_ok_button_clicked();

    private:
        int elapsed_game_time;
        int erroneous_flips;
        std::string difficulty_level;
        std::string game_start_date_time;
        int minutes, seconds, score;
        std::vector<int>* combos;
        QSoundEffect new_record_sound;
        std::string is_sound_effect_enabled;

};

#endif // ENDGAMEWINDOW_H

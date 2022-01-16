#ifndef GAMETABLE_H
#define GAMETABLE_H

#include <QDialog>
#include <QGridLayout>
#include <QElapsedTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class GameTable; }
QT_END_NAMESPACE

class GameTable : public QDialog {
    Q_OBJECT

    public:
        GameTable(QWidget *parent = nullptr);
        ~GameTable();
        std::string get_game_setting(int row_number);
        void set_background();
        void draw_card_grid(int rows, int columns);
        QString get_card_back();
        void match_cards();
        void create_cards(int number_of_cards);
        int find_card_index(QPushButton* card, std::vector<QPushButton*>* vector_to_check);
        void card_front_generator(int number_of_cards);
        void flip_front();
        void flip_back();
        void delay(int seconds);


    private:
         Ui::GameTable* ui;
         std::vector<QPushButton*>* card_backs;
         std::vector<QPushButton*>* card_fronts;
         std::vector<int>* card_front_indices;
         QGridLayout* card_layout;
         bool is_first;
         bool is_second;
         int flipped_cards;
         int first_card_index;
         int second_card_index;
         int number_of_cards;
         int erroneous_flips;
         std::string difficulty;
         QElapsedTimer game_timer;
};

#endif // GAMETABLE_H

#ifndef GAMETABLE_H
#define GAMETABLE_H

#include <QDialog>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class GameTable; }
QT_END_NAMESPACE

class GameTable : public QDialog {
    Q_OBJECT

    public:
        GameTable(QWidget *parent = nullptr);
        ~GameTable();
        void set_background();
        void draw_card_grid(int rows, int columns);
        QString get_card_back();
        void flip_card();
        void create_cards(int number_of_cards);
        int find_card_index(QPushButton* card);

    private:
         Ui::GameTable* ui;
         std::vector<QPushButton*>* cards;
         QGridLayout* card_layout;
};

#endif // GAMETABLE_H

#ifndef GAMETABLE_H
#define GAMETABLE_H

#include <QDialog>

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
};

#endif // GAMETABLE_H

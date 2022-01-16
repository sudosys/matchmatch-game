#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow {
    Q_OBJECT

    public:
        MainMenu(QWidget *parent = nullptr);
        ~MainMenu();

    private slots:
        void on_play_button_clicked();
        void on_settings_button_clicked();
        void on_statistics_button_clicked();
        void on_exit_button_clicked();

    private:
        Ui::MainMenu* ui;
};

#endif // MAINMENU_H

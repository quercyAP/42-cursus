#include <QApplication>
#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel *label = new QLabel("Bienvenue dans le gestionnaire de projet");
    QPushButton *button = new QPushButton("Créer un nouveau projet");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(button);

    QWidget *window = new QWidget;
    window->setLayout(layout);
    window->show();

    return app.exec();
}
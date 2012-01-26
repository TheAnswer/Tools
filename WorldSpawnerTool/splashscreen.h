#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QSplashScreen>

class SplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    SplashScreen(const QString &imagePath);

signals:
    
public slots:
    void showMessage(const QString &message, int alignment = Qt::AlignLeft, const QColor &color = Qt::lightGray);
};

#endif // SPLASHSCREEN_H

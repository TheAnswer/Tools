#include "splashscreen.h"

SplashScreen::SplashScreen(const QString& imagePath) : QSplashScreen(NULL, QPixmap(imagePath))
{

}
void SplashScreen::showMessage(const QString &message, int alignment, const QColor &color) {
     QSplashScreen::showMessage(message, alignment, color);
}

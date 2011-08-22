#include "console.h"

Console::Console(QWidget *parent)
    : QWidget(parent) {
	ui.setupUi(this);
}

Console::~Console() {

}

void Console::printLine(const QString& str) {
    ui.textBrowser->append(str);
}

void Console::printError(const QString& err) {
    ui.textBrowser->append("ERROR:" + err);
}


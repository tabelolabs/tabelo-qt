/**
 * Copyright 2022 Tabelo, <https://github.com/tabeloapp>.
 *
 * This file is part of Tabelo-Qt, <https://github.com/tabeloapp/tabelo-qt>.
 *
 * Tabelo-Qt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Tabelo-Qt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Tabelo-Qt.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "about_dialog.h"

#include <QApplication>
#include <QDialogButtonBox>
#include <QTextBrowser>
#include <QVBoxLayout>


AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent)
{
    setMinimumSize(320, 160);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle(tr("About %1").arg(QApplication::applicationName()));

    auto *textBox = new QTextBrowser;
    textBox->setFrameStyle(QFrame::NoFrame);
    textBox->setStyleSheet(QStringLiteral("background-color:transparent;"));
    textBox->setOpenExternalLinks(true);
    textBox->setHtml(tr("<html><body>"
        "<p>%1 is an open source table editor based on Qt.</p>"
        "<p>Copyright &copy; 2022 <a href=\"%2\" title=\"Visit organization's homepage\">%3</a>.</p>"
        "<p>This application is licensed under the terms of the <a href=\"https://www.gnu.org/licenses/gpl-3.0.en.html\" title=\"Visit license's homepage\">GNU General Public License, version 3</a>.</p>"
        "</body></html>").arg(QApplication::applicationName(), QApplication::organizationDomain(), QApplication::organizationName()));

    auto *buttonBox = new QDialogButtonBox(QDialogButtonBox::Close);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &AboutDialog::close);

    // Main layout
    auto *layout = new QVBoxLayout(this);
    layout->addWidget(textBox);
    layout->addWidget(buttonBox);
}

AboutDialog::~AboutDialog()
{

}
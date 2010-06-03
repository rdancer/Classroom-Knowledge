/*
 * Copyright © 2010 Jan Minář <rdancer@rdancer.org>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 (two),
 * as published by the Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "mainwindow.h"
#include "quiz.h"


#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLayout>
#include <QLabel>
#include <QScrollArea>

Quiz::~Quiz(){}

Quiz::Quiz(QWidget *parent)
    : QWidget(parent)
{
    /*
     * Make sure the questions are laid out nicely
     */
    setLayout(new QVBoxLayout());

    /*
     * Add the questions
     */
    addQuestions();
}

/*
 * Add questions to the (likely empty) quiz
 *
 * TODO: XML backend
 */
void Quiz::addQuestions()
{
    /* Just a simple question to show we can */

    const int CORRECT_ANSWER = 1;
    QString questionText[2] = {
        "1. What does 1 + 1 equal?",
        "1. <span style=\"color: green\"><strong>1 + 1</strong> = <strong>2</strong></span>"
    };

    QLabel *question = new QLabel(questionText[CORRECT_ANSWER]);
    QLineEdit *answer = new QLineEdit;

    Q_ASSERT_X(this->layout(), "generating quiz", "parent widget has no associated layout");

    this->layout()->addWidget(question);
    this->layout()->addWidget(answer);
}

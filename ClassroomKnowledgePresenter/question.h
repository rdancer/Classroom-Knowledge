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

#ifndef QUESTION_H
#define QUESTION_H

#include <QLabel>
#include <QLayout>
#include <QList>
#include <QSet>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>


class Question : public QWidget
{
public:
    Question(QWidget *parent);
    void setQuestion(QString s);
    void setQuestionOk(QString s);
// Unimplemented
//    QString questionInitial();
//    QString questionIfCorrect();
    bool guess(QString guess);
    bool guess(int guess);
    void insertCorrectAnswer(QString value);
    void insertCorrectAnswer(int value);
    void insertOption(QString value);
    void insertOption(int value);
    void guessedRight();
    void guessedWrong();
    void setQuestionNumber(int questionNumber);

private:
    QSet<QString> correctAnswersStrings;
    QSet<int> correctAnswersInts;
    QSet<QString> optionPoolStrings;
    QSet<int> optionPoolInts;
    QString question;
    QString questionOk;
    bool guessed;
    int questionNumber;

    QLabel *questionLabel;

    void updateUi();

    // Used in a kludge
    QWidget *myParent;
};

#endif // QUESTION_H

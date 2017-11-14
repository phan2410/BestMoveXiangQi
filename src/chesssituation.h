#ifndef CHESSSITUATION_H
#define CHESSSITUATION_H

#include "anLogger/src/anlogger.h"
#include "chessman.h"
#include "QTime"

///6-4-3-3-3-3-7-7-7-7-7-7-7-7-7-7-7-4-3-3-3-3-7-7-7-7-7-7-7-7-7-7-7
class ChessSituation
{
public:
    ChessSituation(const QByteArray &sourceData);

    static const QByteArray brandnewData();

    QByteArray srcData;
    bool isDestined;//xxOxxx
    bool doesRedWin;//xxxOxx
    bool isItRedTurn;//xxxxOx
    bool isBlackRedCoded;//xxxxxO

    QHash<QString,ChessMan> RedMen;
    QHash<QString,ChessMan> BlackMen;

    ChessMan King;
    ChessMan king;
    ChessMan Adviser;
    ChessMan adviser;
    ChessMan Elephant;
    ChessMan elephant;
};

#endif // CHESSSITUATION_H

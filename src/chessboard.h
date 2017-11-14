#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#define ChessBoardDbgEn 1

#include "anLogger/src/anlogger.h"
#include "chessman.h"
#include <QHash>

class ChessBoard
{
public:
    ChessBoard();

    QPair<QList<ChessMan::Position>,QList<bool>> getOccupiedPositionsWithTeamFlags(bool inRedView = true);
    bool adaptRawNextPositions();
    QHash<QString,ChessMan> RedMen;
    QHash<QString,ChessMan> BlackMen;

};

#endif // CHESSBOARD_H

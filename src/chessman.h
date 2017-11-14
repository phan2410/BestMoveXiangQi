#ifndef CHESSMAN_H
#define CHESSMAN_H

#define ChessManDbgEn

#include "anLogger/src/anlogger.h"
#include <QPair>
#include <QList>

class ChessMan
{
public:

    typedef QPair<quint8,quint8> Position;

    enum Piece
    {
        InValid = 0,
        King,
        Adviser,
        Elephant,
        Horse,
        Cannon,
        ChaRiot,
        Pawn
    };

    ChessMan();
    ChessMan(const Piece &chessPiece, const Position &chessPosition, bool isRedColored = true);

    static bool isValid(const ChessMan &aChessMan);
    static bool isValid(const Piece &chessPiece, const Position &chessPosition);
    static Position getPositionInOpponentCoordinate(const ChessMan &aChessMan);
    static Position getPositionInOpponentCoordinate(const Position &pos);

    Position getPositionInOpponentCoordinate();
    bool calcRawNextPositions(const QPair<QList<Position>,QList<bool>> &occupiedPositionsWithTeamFlagsOnChessBoard);
    bool addRawNextPositionsForNonCannonPiece(const Position &nextPosition, const QPair<QList<Position>,QList<bool>> &occupiedPositionsWithTeamFlagsOnChessBoard);
    Piece piece;
    Position position;
    QList<Position> nextMovements;
    QList<Position> nextAttacks;
    bool red;
};

#endif // CHESSMAN_H

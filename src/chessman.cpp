#include "chessman.h"

ChessMan::ChessMan()
{

}

ChessMan::ChessMan(const Piece &chessPiece, const Position &chessPosition, bool isRedColored) :
    piece(chessPiece),
    position(chessPosition),
    red(isRedColored)
{

}

bool ChessMan::isValid(const ChessMan &aChessMan)
{
    return isValid(aChessMan.piece,aChessMan.position);
}

bool ChessMan::isValid(const ChessMan::Piece &chessPiece, const ChessMan::Position &chessPosition)
{
    quint8 x = chessPosition.first;
    quint8 y = chessPosition.second;
    if (x > 0 && x < 10 && y < 10)
    {
        switch (chessPiece) {
        case King:
        {
            if (x > 3 && x < 7 && y < 3)
                return true;
            break;
        }
        case Adviser:
        {
            if (((x == 4 || x == 6) && (y == 0 || y == 2))
                    || (x == 5 && y == 1))
                return true;
            break;
        }
        case Elephant:
        {
            if (((x == 3 || x == 7) && (y == 0 || y == 4))
                    || ((x == 1 || x == 5 || x == 9) && y == 2))
                return true;
            break;
        }
        case Horse:
        case Cannon:
        case ChaRiot:
        {
            return true;
        }
        case Pawn:
        {
            if ((y > 2 && y < 5 && (x % 2) == 1)
                    || y > 4)
                return true;
            break;
        }
        default:
            break;
        }
    }
    return false;
}

ChessMan::Position ChessMan::getPositionInOpponentCoordinate(const ChessMan &aChessMan)
{
    return getPositionInOpponentCoordinate(aChessMan.position);
}

ChessMan::Position ChessMan::getPositionInOpponentCoordinate(const ChessMan::Position &pos)
{
    return Position(10 - pos.first,9 - pos.second);
}

ChessMan::Position ChessMan::getPositionInOpponentCoordinate()
{
    return getPositionInOpponentCoordinate(position);
}

bool ChessMan::calcRawNextPositions(const QPair<QList<Position>,QList<bool>> &occupiedPositionsWithTeamFlagsOnChessBoard)
{
    nextMovements.clear();
    nextAttacks.clear();
    if (isValid(piece,position))
    {
        quint8 x = position.first;
        quint8 y = position.second;
        switch (piece) {
        case King:
        {
            if (x == 4)
            {
                if (y == 0)
                {
                    addRawNextPositionsForNonCannonPiece(Position(5,0),occupiedPositionsWithTeamFlagsOnChessBoard);
                    addRawNextPositionsForNonCannonPiece(Position(4,1),occupiedPositionsWithTeamFlagsOnChessBoard);
                }
                else if (y == 1)
                {
                    addRawNextPositionsForNonCannonPiece(Position(4,0),occupiedPositionsWithTeamFlagsOnChessBoard);
                    addRawNextPositionsForNonCannonPiece(Position(5,1),occupiedPositionsWithTeamFlagsOnChessBoard);
                    addRawNextPositionsForNonCannonPiece(Position(4,2),occupiedPositionsWithTeamFlagsOnChessBoard);
                }
                else
                {
                    addRawNextPositionsForNonCannonPiece(Position(5,2),occupiedPositionsWithTeamFlagsOnChessBoard);
                    addRawNextPositionsForNonCannonPiece(Position(4,1),occupiedPositionsWithTeamFlagsOnChessBoard);
                }
            }
            else if (x == 5)
            {
                if (y == 0)
                {
                    addRawNextPositionsForNonCannonPiece(Position(4,0),occupiedPositionsWithTeamFlagsOnChessBoard);
                    addRawNextPositionsForNonCannonPiece(Position(5,1),occupiedPositionsWithTeamFlagsOnChessBoard);
                    addRawNextPositionsForNonCannonPiece(Position(6,0),occupiedPositionsWithTeamFlagsOnChessBoard);
                }
                else if (y == 1)
                {
                    addRawNextPositionsForNonCannonPiece(Position(5,0),occupiedPositionsWithTeamFlagsOnChessBoard);
                    addRawNextPositionsForNonCannonPiece(Position(6,1),occupiedPositionsWithTeamFlagsOnChessBoard);
                    addRawNextPositionsForNonCannonPiece(Position(5,2),occupiedPositionsWithTeamFlagsOnChessBoard);
                    addRawNextPositionsForNonCannonPiece(Position(4,1),occupiedPositionsWithTeamFlagsOnChessBoard);
                }
                else
                {
                    addRawNextPositionsForNonCannonPiece(Position(6,2),occupiedPositionsWithTeamFlagsOnChessBoard);
                    addRawNextPositionsForNonCannonPiece(Position(5,1),occupiedPositionsWithTeamFlagsOnChessBoard);
                    addRawNextPositionsForNonCannonPiece(Position(4,2),occupiedPositionsWithTeamFlagsOnChessBoard);
                }
            }
            return true;
        }
        case Adviser:
        {
            if (x == 5)
            {
                addRawNextPositionsForNonCannonPiece(Position(4,0),occupiedPositionsWithTeamFlagsOnChessBoard);
                addRawNextPositionsForNonCannonPiece(Position(6,0),occupiedPositionsWithTeamFlagsOnChessBoard);
                addRawNextPositionsForNonCannonPiece(Position(6,2),occupiedPositionsWithTeamFlagsOnChessBoard);
                addRawNextPositionsForNonCannonPiece(Position(4,2),occupiedPositionsWithTeamFlagsOnChessBoard);
            }
            else
            {
                addRawNextPositionsForNonCannonPiece(Position(5,1),occupiedPositionsWithTeamFlagsOnChessBoard);
            }
            return true;
        }
        case Elephant:
        {
            if (x == 1)
            {
                if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(2,1)))
                    addRawNextPositionsForNonCannonPiece(Position(3,0),occupiedPositionsWithTeamFlagsOnChessBoard);
                if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(2,3)))
                    addRawNextPositionsForNonCannonPiece(Position(3,4),occupiedPositionsWithTeamFlagsOnChessBoard);
            }
            else if (x == 3)
            {
                if (y == 0)
                {
                    if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(2,1)))
                        addRawNextPositionsForNonCannonPiece(Position(1,2),occupiedPositionsWithTeamFlagsOnChessBoard);
                    if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(4,1)))
                        addRawNextPositionsForNonCannonPiece(Position(5,2),occupiedPositionsWithTeamFlagsOnChessBoard);
                }
                else
                {
                    if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(2,3)))
                        addRawNextPositionsForNonCannonPiece(Position(1,2),occupiedPositionsWithTeamFlagsOnChessBoard);
                    if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(4,3)))
                        addRawNextPositionsForNonCannonPiece(Position(5,2),occupiedPositionsWithTeamFlagsOnChessBoard);
                }
            }
            else if (x == 5)
            {
                if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(4,3)))
                    addRawNextPositionsForNonCannonPiece(Position(3,4),occupiedPositionsWithTeamFlagsOnChessBoard);
                if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(4,1)))
                    addRawNextPositionsForNonCannonPiece(Position(3,0),occupiedPositionsWithTeamFlagsOnChessBoard);
                if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(6,3)))
                    addRawNextPositionsForNonCannonPiece(Position(7,4),occupiedPositionsWithTeamFlagsOnChessBoard);
                if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(6,1)))
                    addRawNextPositionsForNonCannonPiece(Position(7,0),occupiedPositionsWithTeamFlagsOnChessBoard);
            }
            else if (x == 7)
            {
                if (y == 0)
                {
                    if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(6,1)))
                        addRawNextPositionsForNonCannonPiece(Position(5,2),occupiedPositionsWithTeamFlagsOnChessBoard);
                    if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(8,1)))
                        addRawNextPositionsForNonCannonPiece(Position(9,2),occupiedPositionsWithTeamFlagsOnChessBoard);
                }
                else
                {
                    if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(6,3)))
                        addRawNextPositionsForNonCannonPiece(Position(5,2),occupiedPositionsWithTeamFlagsOnChessBoard);
                    if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(8,3)))
                        addRawNextPositionsForNonCannonPiece(Position(9,2),occupiedPositionsWithTeamFlagsOnChessBoard);
                }

            }
            else
            {
                if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(8,1)))
                    addRawNextPositionsForNonCannonPiece(Position(7,0),occupiedPositionsWithTeamFlagsOnChessBoard);
                if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(8,3)))
                    addRawNextPositionsForNonCannonPiece(Position(7,4),occupiedPositionsWithTeamFlagsOnChessBoard);
            }
            return true;
        }
        case Horse:
        {
            Position nextPos;

            if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(x-1,y)))
            {
                nextPos.first = x - 2;
                nextPos.second = y - 1;
                if (isValid(piece,nextPos))
                {
                    addRawNextPositionsForNonCannonPiece(nextPos,occupiedPositionsWithTeamFlagsOnChessBoard);
                }

                nextPos.first = x - 2;
                nextPos.second = y + 1;
                if (isValid(piece,nextPos))
                {
                    addRawNextPositionsForNonCannonPiece(nextPos,occupiedPositionsWithTeamFlagsOnChessBoard);
                }
            }

            if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(x,y+1)))
            {
                nextPos.first = x - 1;
                nextPos.second = y + 2;
                if (isValid(piece,nextPos))
                {
                    addRawNextPositionsForNonCannonPiece(nextPos,occupiedPositionsWithTeamFlagsOnChessBoard);
                }

                nextPos.first = x + 1;
                nextPos.second = y + 2;
                if (isValid(piece,nextPos))
                {
                    addRawNextPositionsForNonCannonPiece(nextPos,occupiedPositionsWithTeamFlagsOnChessBoard);
                }
            }

            if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(x+1,y)))
            {
                nextPos.first = x + 2;
                nextPos.second = y + 1;
                if (isValid(piece,nextPos))
                {
                    addRawNextPositionsForNonCannonPiece(nextPos,occupiedPositionsWithTeamFlagsOnChessBoard);
                }

                nextPos.first = x + 2;
                nextPos.second = y - 1;
                if (isValid(piece,nextPos))
                {
                    addRawNextPositionsForNonCannonPiece(nextPos,occupiedPositionsWithTeamFlagsOnChessBoard);
                }
            }

            if (!occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(Position(x,y-1)))
            {
                nextPos.first = x + 1;
                nextPos.second = y - 2;
                if (isValid(piece,nextPos))
                {
                    addRawNextPositionsForNonCannonPiece(nextPos,occupiedPositionsWithTeamFlagsOnChessBoard);
                }

                nextPos.first = x - 1;
                nextPos.second = y - 2;
                if (isValid(piece,nextPos))
                {
                    addRawNextPositionsForNonCannonPiece(nextPos,occupiedPositionsWithTeamFlagsOnChessBoard);
                }
            }
            return true;
        }
        case Cannon:
        {
            Position nextPos;

            for (quint8 i = (x-1); i > 0; --i)
            {
                nextPos = Position(i,y);
                if (occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(nextPos))
                {
                    for (quint8 j = (i-1); j > 0; --j)
                    {
                        Position atkPos = Position(j,y);
                        if (occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(atkPos))
                        {
                            if (occupiedPositionsWithTeamFlagsOnChessBoard.second.at(occupiedPositionsWithTeamFlagsOnChessBoard.first.indexOf(atkPos)) != red)
                                nextAttacks.append(atkPos);
                            break;
                        }
                    }
                    break;
                }
                else
                {
                    nextMovements.append(nextPos);
                }
            }

            for (quint8 i = (x+1); i < 10; ++i)
            {
                nextPos = Position(i,y);
                if (occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(nextPos))
                {
                    for (quint8 j = (i+1); j < 10; ++j)
                    {
                        Position atkPos = Position(j,y);
                        if (occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(atkPos))
                        {
                            if (occupiedPositionsWithTeamFlagsOnChessBoard.second.at(occupiedPositionsWithTeamFlagsOnChessBoard.first.indexOf(atkPos)) != red)
                                nextAttacks.append(atkPos);
                            break;
                        }
                    }
                    break;
                }
                else
                {
                    nextMovements.append(nextPos);
                }
            }

            for (qint8 j = (y-1); j > -1; --j)
            {
                nextPos = Position(x,j);
                if (occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(nextPos))
                {
                    for (qint8 i = (j-1); i > -1; --i)
                    {
                        Position atkPos = Position(x,i);
                        if (occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(atkPos))
                        {
                            if (occupiedPositionsWithTeamFlagsOnChessBoard.second.at(occupiedPositionsWithTeamFlagsOnChessBoard.first.indexOf(atkPos)) != red)
                                nextAttacks.append(atkPos);
                            break;
                        }
                    }
                    break;
                }
                else
                {
                    nextMovements.append(nextPos);
                }
            }

            for (qint8 j = (y+1); j < 10; ++j)
            {
                nextPos = Position(x,j);
                if (occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(nextPos))
                {
                    for (qint8 i = (j+1); i < 10; ++i)
                    {
                        Position atkPos = Position(x,i);
                        if (occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(atkPos))
                        {
                            if (occupiedPositionsWithTeamFlagsOnChessBoard.second.at(occupiedPositionsWithTeamFlagsOnChessBoard.first.indexOf(atkPos)) != red)
                                nextAttacks.append(atkPos);
                            break;
                        }
                    }
                    break;
                }
                else
                {
                    nextMovements.append(nextPos);
                }
            }
            return true;
        }
        case ChaRiot:
        {
            for (quint8 i = (x-1); i > 0; --i)
            {
                if (addRawNextPositionsForNonCannonPiece(Position(i,y),occupiedPositionsWithTeamFlagsOnChessBoard))
                {
                    break;
                }
            }
            for (quint8 i = (x+1); i < 10; ++i)
            {
                if (addRawNextPositionsForNonCannonPiece(Position(i,y),occupiedPositionsWithTeamFlagsOnChessBoard))
                {
                    break;
                }
            }
            for (qint8 j = (y-1); j > -1; --j)
            {
                if (addRawNextPositionsForNonCannonPiece(Position(x,j),occupiedPositionsWithTeamFlagsOnChessBoard))
                {
                    break;
                }
            }
            for (qint8 j = (y+1); j < 10; ++j)
            {
                if (addRawNextPositionsForNonCannonPiece(Position(x,j),occupiedPositionsWithTeamFlagsOnChessBoard))
                {
                    break;
                }
            }
            return true;
        }
        case Pawn:
        {
            if (y < 5)
            {
                addRawNextPositionsForNonCannonPiece(Position(x,y+1),occupiedPositionsWithTeamFlagsOnChessBoard);
            }
            else
            {
                Position nextPos;

                nextPos.first = x - 1;
                nextPos.second = y;
                if (isValid(piece,nextPos))
                    addRawNextPositionsForNonCannonPiece(nextPos,occupiedPositionsWithTeamFlagsOnChessBoard);

                nextPos.first = x + 1;
                nextPos.second = y;
                if (isValid(piece,nextPos))
                    addRawNextPositionsForNonCannonPiece(nextPos,occupiedPositionsWithTeamFlagsOnChessBoard);

                nextPos.first = x;
                nextPos.second = y + 1;
                if (isValid(piece,nextPos))
                    addRawNextPositionsForNonCannonPiece(nextPos,occupiedPositionsWithTeamFlagsOnChessBoard);
            }
            return true;
        }
        default:
            break;
        }
    }
    return false;
}

bool ChessMan::addRawNextPositionsForNonCannonPiece(const ChessMan::Position &nextPosition, const QPair<QList<Position>,QList<bool>> &occupiedPositionsWithTeamFlagsOnChessBoard)
{
    if (occupiedPositionsWithTeamFlagsOnChessBoard.first.contains(nextPosition))
    {
        if (occupiedPositionsWithTeamFlagsOnChessBoard.second.at(occupiedPositionsWithTeamFlagsOnChessBoard.first.indexOf(nextPosition)) != red)
            nextAttacks.append(nextPosition);
        return true;
    }
    else
    {
        nextMovements.append(nextPosition);
    }
    return false;
}

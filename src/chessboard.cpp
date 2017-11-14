#include "chessboard.h"

ChessBoard::ChessBoard()
{
    RedMen.insert(QStringLiteral("K"),ChessMan(ChessMan::King,ChessMan::Position(5,0)));
    RedMen.insert(QStringLiteral("A4"),ChessMan(ChessMan::Adviser,ChessMan::Position(4,0)));
    RedMen.insert(QStringLiteral("A6"),ChessMan(ChessMan::Adviser,ChessMan::Position(6,0)));
    RedMen.insert(QStringLiteral("E3"),ChessMan(ChessMan::Elephant,ChessMan::Position(3,0)));
    RedMen.insert(QStringLiteral("E7"),ChessMan(ChessMan::Elephant,ChessMan::Position(7,0)));
    RedMen.insert(QStringLiteral("H2"),ChessMan(ChessMan::Horse,ChessMan::Position(2,0)));
    RedMen.insert(QStringLiteral("H8"),ChessMan(ChessMan::Horse,ChessMan::Position(8,0)));
    RedMen.insert(QStringLiteral("C2"),ChessMan(ChessMan::Cannon,ChessMan::Position(2,2)));
    RedMen.insert(QStringLiteral("C8"),ChessMan(ChessMan::Cannon,ChessMan::Position(8,2)));
    RedMen.insert(QStringLiteral("R1"),ChessMan(ChessMan::ChaRiot,ChessMan::Position(1,0)));
    RedMen.insert(QStringLiteral("R9"),ChessMan(ChessMan::ChaRiot,ChessMan::Position(9,0)));
    RedMen.insert(QStringLiteral("P1"),ChessMan(ChessMan::Pawn,ChessMan::Position(1,3)));
    RedMen.insert(QStringLiteral("P3"),ChessMan(ChessMan::Pawn,ChessMan::Position(3,3)));
    RedMen.insert(QStringLiteral("P5"),ChessMan(ChessMan::Pawn,ChessMan::Position(5,3)));
    RedMen.insert(QStringLiteral("P7"),ChessMan(ChessMan::Pawn,ChessMan::Position(7,3)));
    RedMen.insert(QStringLiteral("P9"),ChessMan(ChessMan::Pawn,ChessMan::Position(9,3)));

    BlackMen.insert(QStringLiteral("K"),ChessMan(ChessMan::King,ChessMan::Position(5,0),false));
    BlackMen.insert(QStringLiteral("A4"),ChessMan(ChessMan::Adviser,ChessMan::Position(4,0),false));
    BlackMen.insert(QStringLiteral("A6"),ChessMan(ChessMan::Adviser,ChessMan::Position(6,0),false));
    BlackMen.insert(QStringLiteral("E3"),ChessMan(ChessMan::Elephant,ChessMan::Position(3,0),false));
    BlackMen.insert(QStringLiteral("E7"),ChessMan(ChessMan::Elephant,ChessMan::Position(7,0),false));
    BlackMen.insert(QStringLiteral("H2"),ChessMan(ChessMan::Horse,ChessMan::Position(2,0),false));
    BlackMen.insert(QStringLiteral("H8"),ChessMan(ChessMan::Horse,ChessMan::Position(8,0),false));
    BlackMen.insert(QStringLiteral("C2"),ChessMan(ChessMan::Cannon,ChessMan::Position(2,2),false));
    BlackMen.insert(QStringLiteral("C8"),ChessMan(ChessMan::Cannon,ChessMan::Position(8,2),false));
    BlackMen.insert(QStringLiteral("R1"),ChessMan(ChessMan::ChaRiot,ChessMan::Position(1,0),false));
    BlackMen.insert(QStringLiteral("R9"),ChessMan(ChessMan::ChaRiot,ChessMan::Position(9,0),false));
    BlackMen.insert(QStringLiteral("P1"),ChessMan(ChessMan::Pawn,ChessMan::Position(1,3),false));
    BlackMen.insert(QStringLiteral("P3"),ChessMan(ChessMan::Pawn,ChessMan::Position(3,3),false));
    BlackMen.insert(QStringLiteral("P5"),ChessMan(ChessMan::Pawn,ChessMan::Position(5,3),false));
    BlackMen.insert(QStringLiteral("P7"),ChessMan(ChessMan::Pawn,ChessMan::Position(7,3),false));
    BlackMen.insert(QStringLiteral("P9"),ChessMan(ChessMan::Pawn,ChessMan::Position(9,3),false));
    if (!adaptRawNextPositions())
    {
        anIf(ChessBoardDbgEn, anError("ERROR !!!"));
    }
}

QPair<QList<ChessMan::Position>,QList<bool>> ChessBoard::getOccupiedPositionsWithTeamFlags(bool inRedView)
{
    QList<ChessMan::Position> occupiedPositions;
    QList<bool> accompaniedREDFlags;

    QHash<QString,ChessMan>::ConstIterator i;

    if (inRedView)
    {
        for (i = RedMen.constBegin(); i != RedMen.constEnd(); ++i)
        {
            occupiedPositions.append(i.value().position);
            accompaniedREDFlags.append(true);
        }
        for (i = BlackMen.constBegin(); i != BlackMen.constEnd(); ++i)
        {
            occupiedPositions.append(ChessMan::getPositionInOpponentCoordinate(i.value()));
            accompaniedREDFlags.append(false);
        }
    }
    else
    {
        for (i = RedMen.constBegin(); i != RedMen.constEnd(); ++i)
        {
            occupiedPositions.append(ChessMan::getPositionInOpponentCoordinate(i.value()));
            accompaniedREDFlags.append(true);
        }
        for (i = BlackMen.constBegin(); i != BlackMen.constEnd(); ++i)
        {
            occupiedPositions.append(i.value().position);
            accompaniedREDFlags.append(false);
        }
    }
    return QPair<QList<ChessMan::Position>,QList<bool>>(occupiedPositions,accompaniedREDFlags);
}

bool ChessBoard::adaptRawNextPositions()
{
    QHash<QString,ChessMan>::Iterator i;

    QPair<QList<ChessMan::Position>,QList<bool>> occupiedPositionsWithTeamFlags = getOccupiedPositionsWithTeamFlags();

    for (i = RedMen.begin(); i != RedMen.end(); ++i)
    {
        if (!(i.value().calcRawNextPositions(occupiedPositionsWithTeamFlags)))
        {
            return false;
        }
    }

    occupiedPositionsWithTeamFlags = getOccupiedPositionsWithTeamFlags(false);

    for (i = BlackMen.begin(); i != BlackMen.end(); ++i)
    {
        if (!(i.value().calcRawNextPositions(occupiedPositionsWithTeamFlags)))
        {
            return false;
        }
    }

    return true;
}

#include "chesssituation.h"

ChessSituation::ChessSituation(const QByteArray &sourceData)
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

///6-4-3-3-3-3-7-7-7-7-7-7-7-7-7-7-7-4-3-3-3-3-7-7-7-7-7-7-7-7-7-7-7
// 0000x00010 001 010 001 010 0010100 1010000 0010110 1010010 0001010 1011010 0001101 0100001 0110101 1001001 1011101 0010 001 010 001 010 0010100 1010000 0010110 1010010 0001010 1011010 0001101 0100001 0110101 1001001 1011101
const QByteArray ChessSituation::brandnewData()
{
    return QByteArray().append(QTime::currentTime().msec()%2?9:1);
}

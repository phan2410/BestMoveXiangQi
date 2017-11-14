#include <QCoreApplication>
#include "src/chessboard.h"
#include "src/chesssituation.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //-6-4-3-3-3-3-7-7-7-7-7-7-7-7-7-7-7-4-3-3-3-3-7-7-7-7-7-7-7-7-7-7-7

    QString srcInfo = "213122080228210901333537393|213122080228210901333537395";
    QString srcInfo2 = "K2A1A3E1E2H20H80C22C82R10R90P13P33P53P73P95k2a1a3e1e2h20h80c22c82r10r90p13p33p53p73p93";

    anAck((-6-4-3-3-3-3-7-7-7-7-7-7-7-7-7-7-7-4-3-3-3-3-7-7-7-7-7-7-7-7-7-7-7)/8);

    anAck(ChessSituation::brandnewStart().toHex());

    anAck((QTime::currentTime().msec()%2?"ok":"no"));
    return a.exec();
}

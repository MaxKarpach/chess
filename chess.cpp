#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Move{
    public:
    Move(char name, int positionX, int positionY);
    char GetName() const;
    int GetPositionX() const;
    int GetPositionY() const;
    void SetPositionX(int newPositionX);
    void SetPositionY(int newPositionY);
    private:
    int positionX;
    int positionY;
    char name;
};
Move::Move(char name, int positionX, int positionY) : name(name), positionX(positionX), positionY(positionY) {};
class Figure
{
public:
    Figure(char name, int positionX, int positionY, char color, char board[8][8], vector<Figure *> figures, char field, string lastMove);
    char GetName() const;
    char GetColor() const;
    int GetPositionX() const;
    int GetPositionY() const;
    list<pair<int, int> > GetMoves() const;
    void SetPositionX(int newPositionX);
    void SetName(char newName);
    void SetPositionY(int newPositionY);
    list<pair<int, int> > moves;
    virtual void SetMoves(int positionX, int positionY, char board[8][8], vector<Figure *> figures, string lastMove);
    int GetMovesCount() const;
    void SetMovesCount();
    char GetField() const;
    void SetLastMove(string newLastMove);
    string GetLastMove() const;
private:
    int movesCount;
    char name;
    char color;
    int positionX;
    char field;
    int positionY;
    string lastMove;
};
char Figure::GetField() const {
    return field;
}
string Figure::GetLastMove() const{
    return lastMove;
}
void Figure::SetLastMove(string newLastMove){
    lastMove = newLastMove;
}
int Figure::GetMovesCount() const {
    return movesCount;
}
void Figure::SetMovesCount(){
    movesCount+=1;
}
char Move::GetName() const
{
    return name;
}
int Move::GetPositionX() const
{
    return positionX;
}
int Move::GetPositionY() const
{
    return positionY;
}
void Move::SetPositionX(int newPositionX){
        positionX = newPositionX;
    }
void Move::SetPositionY(int newPositionY){
    positionX = newPositionY;
}
Figure::Figure(char name, int positionX, int positionY, char color, char board[8][8], vector<Figure*> figures, char field, string lastMove) : field(field), name(name), positionX(positionX), positionY(positionY), color(color), lastMove(lastMove) { SetMoves(positionX, positionY, board, figures, lastMove);
};
char Figure::GetName() const
{
    return name;
}
void Figure::SetName(char newName)
{
    name = newName;
}
    char Figure::GetColor() const {
        return color;
    }
    int Figure::GetPositionX() const{
        return positionX;
    }
    list<pair<int, int> > Figure::GetMoves() const{
            return moves;
    }
    int Figure::GetPositionY() const{
        return positionY;
    }
    void Figure::SetPositionX(int newPositionX){
        positionX = newPositionX;
    }
    void Figure::SetPositionY(int newPositionY){
        positionY = newPositionY;
    }
    void Figure::SetMoves(int positionX, int positionY, char board[8][8], vector<Figure*> figures, string lastMove){
    }
class King : public Figure{
        public:
        King(char name, int positionX, int positionY, char color, char board[8][8], vector<Figure*> figures, char field, string lastMove);
        virtual void SetMoves(int positionX, int positionY, char board[8][8], vector<Figure*> figures, string lastMove);
};
King::King(char name, int positionX, int positionY, char color, char board[8][8], vector<Figure*> figures, char field, string lastMove): Figure(name, positionX, positionY, color, board, figures, field, lastMove)
{
    SetMoves(positionX, positionY, board, figures, lastMove);
}
class Queen : public Figure{
        public:
        Queen(char name, int positionX, int positionY, char color, char  board[8][8], vector<Figure*> figures, char field, string lastMove);
        virtual void SetMoves(int positionX, int positionY, char  board[8][8], vector<Figure*> figures, string lastMove);
};
Queen::Queen(char name, int positionX, int positionY, char color, char  board[8][8], vector<Figure*> figures, char field, string lastMove): Figure(name, positionX, positionY, color, board, figures, field, lastMove)
{
    SetMoves(positionX, positionY, board, figures, lastMove);
}
bool findSameColorFigureMove(char color, int positionX, int positionY, vector<Figure *> figures);
void updateBoard(char board[8][8], vector<Figure *> figures);
void updateBoardForFunction(char board[8][8], vector<Figure *> &figures);
void move(string userStr, char board[8][8], vector<Figure *> &figures, string& lastMove, char& moveColor);
void moveAfterCheck(string userStr, char board[8][8], vector<Figure *> &figures, bool& isCheck, vector<Move *>& movesAfterCheck, char& moveColor);
bool findMoveFromOppositeFigure(int posX, int posY, char color, vector<Figure *> figures);
Figure *findFigure(int posX, int posY, vector<Figure *> figures);
void isCheckOnTheBoard(vector<Figure *> figures, bool& isChecked, vector<Move *>& movesAfterCheck);
void isStalemateOnTheBoard(vector<Figure *> figures, bool& isStalemate);
void isDrawOnTheBoard(vector<Figure *> figures, bool& isDraw);
bool findFigureMove(int positionX, int positionY, vector<Figure *> figures);
void findMovesAfterCheck(vector<Figure *> figures, char color, int kingPosX, int kingPosY, int attackingFigPosX, int attackingFigPosY, char attackingFigName, vector<Move *> &movesAfterCheck, int figuresCount);
void Queen::SetMoves(int positionX, int positionY, char  board[8][8], vector<Figure*> figures, string lastMove) {
    moves.clear();
    int l1 = 1;
    while (l1 < 8 && board[positionX+l1][positionY] == '*' && positionX + l1 < 8){
        moves.push_back(make_pair(positionX + l1, positionY));
        l1++;
    }
    if (positionX + l1 < 8 && board[positionX+l1][positionY] != '*' && findSameColorFigureMove(GetColor(), positionX+l1, positionY, figures) == 0){
    moves.push_back(make_pair(positionX + l1, positionY));
    }
    int l2 = 1;
    while (l2 < 8 && board[positionX - l2][positionY] == '*' && positionX - l2 >=0)
    {
        moves.push_back(make_pair(positionX - l2, positionY));
        l2++;
    }
     if (positionX - l2 >= 0 && board[positionX-l2][positionY] != '*' && findSameColorFigureMove(GetColor(), positionX-l2, positionY, figures) == 0){
    moves.push_back(make_pair(positionX - l2, positionY));
     }
    int l3 = 1;
    while (l3  < 8 && board[positionX][positionY+l3] == '*' && positionY + l3 < 8){
        moves.push_back(make_pair(positionX, positionY+l3));
        l3++;
    }
    if (positionY + l3 < 8 && board[positionX][positionY+l3] != '*' && findSameColorFigureMove(GetColor(), positionX, positionY+l3, figures) == 0){
    moves.push_back(make_pair(positionX, positionY+l3));
    }
    int l4 = 1;
    while (l4 < 8 && board[positionX][positionY-l4] == '*' && positionY - l4 >= 0){
        moves.push_back(make_pair(positionX, positionY-l4));
        l4++;
    }
     if (positionY - l4 >= 0 && board[positionX][positionY-l4] != '*' && findSameColorFigureMove(GetColor(), positionX, positionY-l4, figures) == 0){
    moves.push_back(make_pair(positionX, positionY-l4));
     }
int d1 = 1;
while (d1  < 8 && positionX + d1 < 8 && positionY + d1 < 8 && board[positionX + d1][positionY + d1] == '*') {
    moves.push_back(make_pair(positionX + d1, positionY + d1));
    d1++;
}
if (positionX + d1 < 8 && positionY + d1 < 8 && board[positionX + d1][positionY + d1] != '*' && findSameColorFigureMove(GetColor(), positionX + d1, positionY + d1, figures) == 0)
{
    moves.push_back(make_pair(positionX + d1, positionY + d1));
}
int d2 = 1;
while (d2 < 8 && positionX + d2 < 8 && positionY - d2 >= 0 && board[positionX + d2][positionY - d2] == '*') {
    moves.push_back(make_pair(positionX + d2, positionY - d2));
    d2++;
}
if (positionX + d2 < 8 && positionY - d2 >= 0 && board[positionX + d2][positionY - d2] != '*' && findSameColorFigureMove(GetColor(), positionX+d2, positionY-d2, figures) == 0) {
    moves.push_back(make_pair(positionX + d2, positionY - d2));
}
int d3 = 1;
while (d3  < 8 && positionX - d3 >= 0 && positionY + d3 < 8 && board[positionX - d3][positionY + d3] == '*') {
    moves.push_back(make_pair(positionX - d3, positionY + d3));
    d3++;
}
if (positionX - d3 >= 0 && positionY + d3 < 8 && board[positionX - d3][positionY + d3] != '*' && findSameColorFigureMove(GetColor(), positionX-d3, positionY+d3, figures) == 0) {
    moves.push_back(make_pair(positionX - d3, positionY + d3));
}
int d4 = 1;
while (d4 < 8 && positionX - d4 >= 0 && positionY - d4 >= 0 && board[positionX - d4][positionY - d4] == '*') {
    moves.push_back(make_pair(positionX - d4, positionY - d4));
    d4++;
}
if (positionX - d4 >= 0 && positionY - d4 >= 0 && board[positionX - d4][positionY - d4] != '*' && findSameColorFigureMove(GetColor(), positionX-d4, positionY-d4, figures) == 0) {
    moves.push_back(make_pair(positionX - d4, positionY - d4));
}
}
class Knight : public Figure{
        public:
        Knight(char name, int positionX, int positionY, char color, char  board[8][8], vector<Figure*> figures, char field, string lastMove);
        virtual void SetMoves(int positionX, int positionY, char  board[8][8], vector<Figure*> figures, string lastMove);
};
Knight::Knight(char name, int positionX, int positionY, char color, char  board[8][8], vector<Figure*> figures, char field, string lastMove) : Figure(name, positionX, positionY, color, board, figures, field, lastMove)
{SetMoves(positionX, positionY, board, figures, lastMove);}
void Knight::SetMoves(int positionX, int positionY, char  board[8][8], vector<Figure*> figures, string lastMove) {
    moves.clear();
    if (positionX-2 >= 0 && positionY + 1 < 8 && findSameColorFigureMove(GetColor(), positionX-2, positionY+1, figures) == 0){
    moves.push_back(make_pair(positionX-2, positionY+1));
    }
    if (positionX-2 >= 0 && positionY - 1 >= 0 && findSameColorFigureMove(GetColor(), positionX-2, positionY-1, figures) == 0){
    moves.push_back(make_pair(positionX-2, positionY-1));
    }
    if (positionX+2 < 8 && positionY + 1 < 8 && findSameColorFigureMove(GetColor(), positionX+2, positionY+1, figures) == 0){
    moves.push_back(make_pair(positionX+2, positionY+1));
    }
    if (positionX+2 < 8 && positionY - 1 >= 0 && findSameColorFigureMove(GetColor(), positionX+2, positionY-1, figures) == 0){
    moves.push_back(make_pair(positionX+2, positionY-1));
    }
    if (positionX-1 >= 0 && positionY + 2 < 8 && findSameColorFigureMove(GetColor(), positionX-1, positionY+2, figures) == 0){
    moves.push_back(make_pair(positionX-1, positionY+2));
    }
    if (positionX-1 >= 0 && positionY - 2 >= 0 && findSameColorFigureMove(GetColor(), positionX-1, positionY-2, figures) == 0){
    moves.push_back(make_pair(positionX-1, positionY-2));
    }
    if (positionX+1 < 8 && positionY + 2 < 8 && findSameColorFigureMove(GetColor(), positionX+1, positionY+2, figures) == 0){
    moves.push_back(make_pair(positionX+1, positionY+2));
    }
    if (positionX+1 < 8 && positionY - 2 >= 0 && findSameColorFigureMove(GetColor(), positionX+1, positionY-2, figures) == 0){
    moves.push_back(make_pair(positionX+1, positionY-2));
    }
}
class Bishop : public Figure{
        public:
        Bishop(char name, int positionX, int positionY, char color, char  board[8][8], vector<Figure*> figures, char field, string lastMove);
        virtual void SetMoves(int positionX, int positionY, char  board[8][8], vector<Figure*> figures, string lastMove);
};
Bishop::Bishop(char name, int positionX, int positionY, char color, char  board[8][8], vector<Figure*> figures, char field, string lastMove): Figure(name, positionX, positionY, color, board, figures, field, lastMove)
{
    SetMoves(positionX, positionY, board, figures, lastMove);
}
class Rock : public Figure{
        public:
        Rock(char name, int positionX, int positionY, char color, char  board[8][8], vector<Figure*> figures, char field, string lastMove);
        virtual void SetMoves(int positionX, int positionY, char  board[8][8], vector<Figure*> figures, string lastMove);
};
Rock::Rock(char name, int positionX, int positionY, char color, char  board[8][8], vector<Figure*> figures, char field, string lastMove): Figure(name, positionX, positionY, color, board, figures, field, lastMove)
{
    SetMoves(positionX, positionY, board, figures, lastMove);
}
void Rock::SetMoves(int positionX, int positionY, char board[8][8], vector<Figure*> figures, string lastMove) { 
    moves.clear();
    int l1 = 1;
    while (l1 < 8 && board[positionX+l1][positionY] == '*' && positionX + l1 < 8){
        moves.push_back(make_pair(positionX + l1, positionY));
        l1++;
    }
    if (positionX + l1 < 8 && board[positionX+l1][positionY] != '*' && findSameColorFigureMove(GetColor(), positionX+l1, positionY, figures) == 0){
    moves.push_back(make_pair(positionX + l1, positionY));
    }
    int l2 = 1;
    while (l2 < 8 && board[positionX - l2][positionY] == '*' && positionX - l2 >=0)
    {
        moves.push_back(make_pair(positionX - l2, positionY));
        l2++;
    }
     if (positionX - l2 >= 0 && board[positionX-l2][positionY] != '*' && findSameColorFigureMove(GetColor(), positionX-l2, positionY, figures) == 0){
    moves.push_back(make_pair(positionX - l2, positionY));
     }
    int l3 = 1;
    while (l3  < 8 && board[positionX][positionY+l3] == '*' && positionY + l3 < 8){
        moves.push_back(make_pair(positionX, positionY+l3));
        l3++;
    }
    if (positionY + l3 < 8 && board[positionX][positionY+l3] != '*' && findSameColorFigureMove(GetColor(), positionX, positionY+l3, figures) == 0){
    moves.push_back(make_pair(positionX, positionY+l3));
    }
    int l4 = 1;
    while (l4 < 8 && board[positionX][positionY-l4] == '*' && positionY - l4 >= 0){
        moves.push_back(make_pair(positionX, positionY-l4));
        l4++;
    }
     if (positionY - l4 >= 0 && board[positionX][positionY-l4] != '*' && findSameColorFigureMove(GetColor(), positionX, positionY-l4, figures) == 0){
    moves.push_back(make_pair(positionX, positionY-l4));
     }
}
void Bishop::SetMoves(int positionX, int positionY, char board[8][8], vector<Figure*> figures, string lastMove) {
    moves.clear();
    int d1 = 1;
while (d1  < 8 && positionX + d1 < 8 && positionY + d1 < 8 && board[positionX + d1][positionY + d1] == '*') {
    moves.push_back(make_pair(positionX + d1, positionY + d1));
    d1++;
}
if (positionX + d1 < 8 && positionY + d1 < 8 && board[positionX + d1][positionY + d1] != '*' && findSameColorFigureMove(GetColor(), positionX + d1, positionY + d1, figures) == 0)
{
    moves.push_back(make_pair(positionX + d1, positionY + d1));
}
int d2 = 1;
while (d2 < 8 && positionX + d2 < 8 && positionY - d2 >= 0 && board[positionX + d2][positionY - d2] == '*') {
    moves.push_back(make_pair(positionX + d2, positionY - d2));
    d2++;
}
if (positionX + d2 < 8 && positionY - d2 >= 0 && board[positionX + d2][positionY - d2] != '*' && findSameColorFigureMove(GetColor(), positionX+d2, positionY-d2, figures) == 0) {
    moves.push_back(make_pair(positionX + d2, positionY - d2));
}
int d3 = 1;
while (d3  < 8 && positionX - d3 >= 0 && positionY + d3 < 8 && board[positionX - d3][positionY + d3] == '*') {
    moves.push_back(make_pair(positionX - d3, positionY + d3));
    d3++;
}
if (positionX - d3 >= 0 && positionY + d3 < 8 && board[positionX - d3][positionY + d3] != '*' && findSameColorFigureMove(GetColor(), positionX-d3, positionY+d3, figures) == 0) {
    moves.push_back(make_pair(positionX - d3, positionY + d3));
}
int d4 = 1;
while (d4 < 8 && positionX - d4 >= 0 && positionY - d4 >= 0 && board[positionX - d4][positionY - d4] == '*') {
    moves.push_back(make_pair(positionX - d4, positionY - d4));
    d4++;
}
if (positionX - d4 >= 0 && positionY - d4 >= 0 && board[positionX - d4][positionY - d4] != '*' && findSameColorFigureMove(GetColor(), positionX-d4, positionY-d4, figures) == 0) {
    moves.push_back(make_pair(positionX - d4, positionY - d4));
}
}
class Pawn : public Figure{
        public:
        Pawn(char name, int positionX, int positionY, char color, char board[8][8], vector<Figure*> figures, char field, string lastMove);
        virtual void SetMoves(int positionX, int positionY, char board[8][8], vector<Figure*> figures, string lastMove);
};
void Pawn::SetMoves(int positionX, int positionY, char board[8][8], vector<Figure*> figures, string lastMove) {
    moves.clear();
    switch (GetColor())
    {
    case 'W':
    if (positionX == 3) {
    size_t positionDefis = lastMove.find("-");
    string oldFigurePos = lastMove.substr(0, positionDefis);
    string newFigurePos = lastMove.substr(positionDefis + 1);
    char oldFigurePosVerticalLetter = oldFigurePos[1];
    char oldFigurePosNumber = oldFigurePos[2];
    char newFigurePosVerticalLetter = newFigurePos[1];
    char newFigurePosNumber = newFigurePos[2];
    int intOldFigurePosY, intOldFigurePosX, intNewFigurePosY, intNewFigurePosX;
    switch (oldFigurePosVerticalLetter)
    {
    case 'A':
        intOldFigurePosY = 0;
        break;
    case 'B':
        intOldFigurePosY = 1;
        break;
    case 'C':
        intOldFigurePosY = 2;
        break;
    case 'D':
        intOldFigurePosY = 3;
        break;
    case 'E':
        intOldFigurePosY = 4;
        break;
    case 'F':
        intOldFigurePosY = 5;
        break;
    case 'G':
        intOldFigurePosY = 6;
        break;
    case 'H':
        intOldFigurePosY = 7;
        break;
    default:
        break;
    }
    switch (oldFigurePosNumber)

    {
    case '1':
        intOldFigurePosX = 7;
        break;
    case '2':
        intOldFigurePosX = 6;
        break;
    case '3':
        intOldFigurePosX = 5;
        break;
    case '4':
        intOldFigurePosX = 4;
        break;
    case '5':
        intOldFigurePosX = 3;
        break;
    case '6':
        intOldFigurePosX = 2;
        break;
    case '7':
        intOldFigurePosX = 1;
        break;
    case '8':
        intOldFigurePosX = 0;
        break;
    default:
        break;
    }
    switch (newFigurePosVerticalLetter)
            {
            case 'A':
                intNewFigurePosY = 0;
                break;
            case 'B':
                intNewFigurePosY = 1;
                break;
            case 'C':
                intNewFigurePosY = 2;
                break;
            case 'D':
                intNewFigurePosY = 3;
                break;
            case 'E':
                intNewFigurePosY = 4;
                break;
            case 'F':
                intNewFigurePosY = 5;
                break;
            case 'G':
                intNewFigurePosY = 6;
                break;
            case 'H':
                intNewFigurePosY = 7;
                break;
            default:
                break;
            }
    switch (newFigurePosNumber)
            {
            case '1':
                intNewFigurePosX = 7;
                break;
            case '2':
                intNewFigurePosX = 6;
                break;
            case '3':
                intNewFigurePosX = 5;
                break;
            case '4':
                intNewFigurePosX = 4;
                break;
            case '5':
                intNewFigurePosX = 3;
                break;
            case '6':
                intNewFigurePosX = 2;
                break;
            case '7':
                intNewFigurePosX = 1;
                break;
            case '8':
                intNewFigurePosX = 0;
                break;
            default:
                break;
            }
    if (intOldFigurePosX == 1 && (intOldFigurePosY - 1 == positionY || intOldFigurePosY + 1 == positionY) && lastMove[0] == 'P' && board[positionX-1][positionY] == '*'){
        moves.push_back(make_pair(positionX-1, positionY));
        moves.push_back(make_pair(positionX - 1, intOldFigurePosY));
        break;
    }
    else if (intOldFigurePosX == 1 && (intOldFigurePosY - 1 == positionY || intOldFigurePosY + 1 == positionY) && lastMove[0] == 'P' && board[positionX - 1][positionY] != '*')
    {
        moves.push_back(make_pair(positionX - 1, intOldFigurePosY));
        break;
    }
    }
    if (positionX == 6 && board[positionX-1][positionY+1] == '*' && board[positionX-1][positionY-1] == '*' && board[positionX-1][positionY] == '*' && board[positionX-2][positionY] == '*'){
    moves.push_back(make_pair(positionX-1, positionY));
    moves.push_back(make_pair(positionX-2, positionY));
    } else if (positionX == 6 && board[positionX-1][positionY+1] != '*' && board[positionX-1][positionY-1] == '*' && board[positionX-1][positionY] == '*' && board[positionX-2][positionY] == '*'){
    moves.push_back(make_pair(positionX-1, positionY));
    moves.push_back(make_pair(positionX-2, positionY));
    moves.push_back(make_pair(positionX-1, positionY+1));
    } else if (positionX == 6 && board[positionX-1][positionY+1] == '*' && board[positionX-1][positionY-1] != '*' && board[positionX-1][positionY] == '*' && board[positionX-2][positionY] == '*'){
    moves.push_back(make_pair(positionX-1, positionY));
    moves.push_back(make_pair(positionX-2, positionY));
    moves.push_back(make_pair(positionX-1, positionY-1));
    } else if (positionX == 6 && board[positionX-1][positionY+1] != '*' && board[positionX-1][positionY-1] != '*' && board[positionX-1][positionY] == '*' && board[positionX-2][positionY] == '*'){
    moves.push_back(make_pair(positionX-1, positionY));
    moves.push_back(make_pair(positionX-2, positionY));
    moves.push_back(make_pair(positionX-1, positionY-1));
    moves.push_back(make_pair(positionX-1, positionY+1));
    }  else if(board[positionX-1][positionY+1] != '*' && board[positionX-1][positionY-1] != '*' && board[positionX-1][positionY] == '*'){
     moves.push_back(make_pair(positionX-1, positionY));
    moves.push_back(make_pair(positionX-1, positionY-1));
    moves.push_back(make_pair(positionX-1, positionY+1));
    }  else if(board[positionX-1][positionY+1] == '*' && board[positionX-1][positionY-1] != '*' && board[positionX-1][positionY] == '*'){
     moves.push_back(make_pair(positionX-1, positionY));
    moves.push_back(make_pair(positionX-1, positionY-1));
    }  else if(board[positionX-1][positionY+1] != '*' && board[positionX-1][positionY-1] == '*' && board[positionX-1][positionY] == '*'){
     moves.push_back(make_pair(positionX-1, positionY));
    moves.push_back(make_pair(positionX-1, positionY+1));
    } else if(board[positionX-1][positionY+1] == '*' && board[positionX-1][positionY-1] == '*' && board[positionX-1][positionY] == '*'){
     moves.push_back(make_pair(positionX-1, positionY));
    } else if (board[positionX-1][positionY+1] != '*' && board[positionX-1][positionY-1] != '*' && board[positionX-1][positionY] != '*'){
          moves.push_back(make_pair(positionX-1, positionY+1));
          moves.push_back(make_pair(positionX-1, positionY-1));
    } else if (board[positionX-1][positionY+1] != '*' && board[positionX-1][positionY-1] == '*' && board[positionX-1][positionY] != '*'){
            moves.push_back(make_pair(positionX-1, positionY+1));
    } else if (board[positionX-1][positionY+1] == '*' && board[positionX-1][positionY-1] != '*' && board[positionX-1][positionY] != '*'){
            moves.push_back(make_pair(positionX-1, positionY-1));
    }
        break;
    case 'B':
        if (positionX == 4) {
    size_t positionDefis = lastMove.find("-");
    string oldFigurePos = lastMove.substr(0, positionDefis);
    string newFigurePos = lastMove.substr(positionDefis + 1);
    char oldFigurePosVerticalLetter = oldFigurePos[1];
    char oldFigurePosNumber = oldFigurePos[2];
    char newFigurePosVerticalLetter = newFigurePos[1];
    char newFigurePosNumber = newFigurePos[2];
    int intOldFigurePosY, intOldFigurePosX, intNewFigurePosY, intNewFigurePosX;
    switch (oldFigurePosVerticalLetter)
    {
    case 'A':
        intOldFigurePosY = 0;
        break;
    case 'B':
        intOldFigurePosY = 1;
        break;
    case 'C':
        intOldFigurePosY = 2;
        break;
    case 'D':
        intOldFigurePosY = 3;
        break;
    case 'E':
        intOldFigurePosY = 4;
        break;
    case 'F':
        intOldFigurePosY = 5;
        break;
    case 'G':
        intOldFigurePosY = 6;
        break;
    case 'H':
        intOldFigurePosY = 7;
        break;
    default:
        break;
    }
    switch (oldFigurePosNumber)

    {
    case '1':
        intOldFigurePosX = 7;
        break;
    case '2':
        intOldFigurePosX = 6;
        break;
    case '3':
        intOldFigurePosX = 5;
        break;
    case '4':
        intOldFigurePosX = 4;
        break;
    case '5':
        intOldFigurePosX = 3;
        break;
    case '6':
        intOldFigurePosX = 2;
        break;
    case '7':
        intOldFigurePosX = 1;
        break;
    case '8':
        intOldFigurePosX = 0;
        break;
    default:
        break;
    }
    switch (newFigurePosVerticalLetter)
            {
            case 'A':
                intNewFigurePosY = 0;
                break;
            case 'B':
                intNewFigurePosY = 1;
                break;
            case 'C':
                intNewFigurePosY = 2;
                break;
            case 'D':
                intNewFigurePosY = 3;
                break;
            case 'E':
                intNewFigurePosY = 4;
                break;
            case 'F':
                intNewFigurePosY = 5;
                break;
            case 'G':
                intNewFigurePosY = 6;
                break;
            case 'H':
                intNewFigurePosY = 7;
                break;
            default:
                break;
            }
    switch (newFigurePosNumber)
            {
            case '1':
                intNewFigurePosX = 7;
                break;
            case '2':
                intNewFigurePosX = 6;
                break;
            case '3':
                intNewFigurePosX = 5;
                break;
            case '4':
                intNewFigurePosX = 4;
                break;
            case '5':
                intNewFigurePosX = 3;
                break;
            case '6':
                intNewFigurePosX = 2;
                break;
            case '7':
                intNewFigurePosX = 1;
                break;
            case '8':
                intNewFigurePosX = 0;
                break;
            default:
                break;
            }
    if (intOldFigurePosX == 6 && (intOldFigurePosY - 1 == positionY || intOldFigurePosY + 1 == positionY) && lastMove[0] == 'P' && board[positionX+1][positionY] == '*'){
        moves.push_back(make_pair(positionX+1, positionY));
        moves.push_back(make_pair(positionX+ 1, intOldFigurePosY));
        break;
    }
    else if (intOldFigurePosX == 6 && (intOldFigurePosY - 1 == positionY || intOldFigurePosY + 1 == positionY) && lastMove[0] == 'P' && board[positionX + 1][positionY] != '*')
    {
        moves.push_back(make_pair(positionX + 1, intOldFigurePosY));
        break;
    }
    }
    if (positionX == 1 && board[positionX+1][positionY+1] == '*' && board[positionX+1][positionY-1] == '*' && board[positionX+1][positionY] == '*' && board[positionX+2][positionY] == '*'){
    moves.push_back(make_pair(positionX+1, positionY));
    moves.push_back(make_pair(positionX+2, positionY));
    } else if (positionX == 1 && board[positionX+1][positionY+1] != '*' && board[positionX+1][positionY-1] == '*' && board[positionX+1][positionY] == '*' && board[positionX+2][positionY] == '*'){
    moves.push_back(make_pair(positionX+1, positionY));
    moves.push_back(make_pair(positionX+2, positionY));
    moves.push_back(make_pair(positionX+1, positionY+1));
    } else if (positionX == 1 && board[positionX+1][positionY+1] == '*' && board[positionX+1][positionY-1] != '*' && board[positionX+1][positionY] == '*' && board[positionX+2][positionY] == '*'){
    moves.push_back(make_pair(positionX+1, positionY));
    moves.push_back(make_pair(positionX+2, positionY));
    moves.push_back(make_pair(positionX+1, positionY-1));
    } else if (positionX == 1 && board[positionX+1][positionY+1] != '*' && board[positionX+1][positionY-1] != '*' && board[positionX+1][positionY] == '*' && board[positionX+2][positionY] == '*'){
    moves.push_back(make_pair(positionX+1, positionY));
    moves.push_back(make_pair(positionX+2, positionY));
    moves.push_back(make_pair(positionX+1, positionY-1));
    moves.push_back(make_pair(positionX+1, positionY+1));
    }  else if(board[positionX+1][positionY+1] != '*' && board[positionX+1][positionY-1] != '*' && board[positionX+1][positionY] == '*'){
     moves.push_back(make_pair(positionX+1, positionY));
    moves.push_back(make_pair(positionX+1, positionY-1));
    moves.push_back(make_pair(positionX+1, positionY+1));
    }  else if(board[positionX+1][positionY+1] == '*' && board[positionX+1][positionY-1] != '*' && board[positionX+1][positionY] == '*'){
     moves.push_back(make_pair(positionX+1, positionY));
    moves.push_back(make_pair(positionX+1, positionY-1));
    }  else if(board[positionX+1][positionY+1] != '*' && board[positionX+1][positionY-1] == '*' && board[positionX+1][positionY] == '*'){
     moves.push_back(make_pair(positionX+1, positionY));
    moves.push_back(make_pair(positionX+1, positionY+1));
    } else if(board[positionX+1][positionY+1] == '*' && board[positionX+1][positionY-1] == '*' && board[positionX+1][positionY] == '*'){
     moves.push_back(make_pair(positionX+1, positionY));
    } else if (board[positionX+1][positionY+1] != '*' && board[positionX+1][positionY-1] != '*' && board[positionX+1][positionY] != '*'){
          moves.push_back(make_pair(positionX+1, positionY+1));
          moves.push_back(make_pair(positionX+1, positionY-1));
    } else if (board[positionX+1][positionY+1] != '*' && board[positionX+1][positionY-1] == '*' && board[positionX+1][positionY] != '*'){
            moves.push_back(make_pair(positionX+1, positionY+1));
    } else if (board[positionX+1][positionY+1] == '*' && board[positionX+1][positionY-1] != '*' && board[positionX+1][positionY] != '*'){
            moves.push_back(make_pair(positionX+1, positionY-1));
    }
    break;
    default:
        break;
    }
}
void King::SetMoves(int positionX, int positionY, char board[8][8], vector<Figure*> figures, string lastMove) {
    moves.clear();
    if (positionX + 1 < 8) {
        if (findMoveFromOppositeFigure(positionX + 1, positionY, GetColor(), figures) == 0 && findSameColorFigureMove(GetColor(), positionX+1, positionY, figures) == 0) {
            moves.push_back(make_pair(positionX + 1, positionY));
        }
    }

    if (positionX - 1 >= 0) {
        if (findMoveFromOppositeFigure(positionX - 1, positionY, GetColor(), figures) == 0 && findSameColorFigureMove(GetColor(), positionX-1, positionY, figures) == 0) {
            moves.push_back(make_pair(positionX - 1, positionY));
        }
    }

    if (positionY + 1 < 8) {
        if (findMoveFromOppositeFigure(positionX, positionY + 1, GetColor(), figures) == 0 && findSameColorFigureMove(GetColor(), positionX, positionY+1, figures) == 0) {
            moves.push_back(make_pair(positionX, positionY + 1));
        }
    }
    if (positionY - 1 >= 0) {
        if (findMoveFromOppositeFigure(positionX, positionY - 1, GetColor(), figures) == 0 && findSameColorFigureMove(GetColor(), positionX, positionY-1, figures) == 0) {
            moves.push_back(make_pair(positionX, positionY - 1));
        }
    }
    if (positionX + 1 < 8 && positionY + 1 < 8) {
        if (findMoveFromOppositeFigure(positionX + 1, positionY + 1, GetColor(), figures) == 0 && findSameColorFigureMove(GetColor(), positionX+1, positionY+1, figures) == 0) {
            moves.push_back(make_pair(positionX + 1, positionY + 1));
        }
    }
    if (positionX + 1 < 8 && positionY - 1 >= 0) {
        if (findMoveFromOppositeFigure(positionX + 1, positionY - 1, GetColor(), figures) == 0 && findSameColorFigureMove(GetColor(), positionX+1, positionY-1, figures) == 0) {
            moves.push_back(make_pair(positionX + 1, positionY - 1));
        }
    }
    if (positionX - 1 >= 0 && positionY + 1 < 8) {
        if (findMoveFromOppositeFigure(positionX - 1, positionY + 1, GetColor(), figures) == 0 && findSameColorFigureMove(GetColor(), positionX-1, positionY+1, figures) == 0) {
            moves.push_back(make_pair(positionX - 1, positionY + 1));
        }
    }
    if (positionX - 1 >= 0 && positionY - 1 >= 0) {
        if (findMoveFromOppositeFigure(positionX - 1, positionY - 1, GetColor(), figures) == 0 && findSameColorFigureMove(GetColor(), positionX-1, positionY-1, figures) == 0) {
            moves.push_back(make_pair(positionX - 1, positionY - 1));
        }
    }
}
Pawn::Pawn(char name, int positionX, int positionY, char color, char board[8][8], vector<Figure*> figures, char field, string lastMove) : Figure(name, positionX, positionY, color, board, figures, field, lastMove) { 
    SetMoves(positionX, positionY, board, figures, lastMove); };
int main()
{
    cout << "Welcome to chess redactor" << endl;
    cout << "Write figure name and position, then -, then figure name and new position" << endl;
    cout << "K is king, Q is queen, R is rock, B is bishop, N is knight, P is pawn" << endl;
    cout << "111 for short white castling, 1111 for long white castling, 222 for short black castling, 2222 for long black castling" << endl;
    char board[8][8] = {{
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                        },
                        {
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                        },
                        {
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                        },
                        {
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                        },
                        {
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                        },
                        {
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                        },
                        {
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                        },
                        {
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                            '*',
                        }};
    vector<Figure*> figures;
    string userStr = "";
    Rock* rockA8 = new Rock('R', 0, 0, 'B', board, figures, 'W', "");
    figures.push_back(rockA8);
    Knight* knightB8 = new Knight('N', 0, 1, 'B', board, figures, 'B', "");
    figures.push_back(knightB8);
    Bishop* bishopC8= new Bishop('B', 0, 2, 'B', board, figures, 'W', "");
    figures.push_back(bishopC8);
    Queen* queenD8 = new Queen('Q', 0, 3, 'B', board, figures, 'B', "");
    figures.push_back(queenD8);
    King* kingE8 = new King('K', 0, 4, 'B', board, figures, 'W', "");
    figures.push_back(kingE8);
    Bishop* bishopF8 = new Bishop('B', 0, 5, 'B', board, figures, 'B', "");
    figures.push_back(bishopF8);
    Knight* knightG8= new Knight('N', 0, 6, 'B', board, figures, 'W', "");
    figures.push_back(knightG8);
    Rock* rockH8 = new Rock('R', 0, 7, 'B', board, figures, 'B', "");
    figures.push_back(rockH8);
    Rock* rockA1 = new Rock('R', 7, 0, 'W', board, figures, 'B', "");
    figures.push_back(rockA1);
    Knight* knightB1 = new Knight('N', 7, 1, 'W', board, figures, 'W', "");
    figures.push_back(knightB1);
    Bishop* bishopC1 = new Bishop('B', 7, 2, 'W', board, figures, 'B', "");
    figures.push_back(bishopC1);
    Queen* queenD1 = new Queen('Q', 7, 3, 'W', board, figures, 'W', "");
    figures.push_back(queenD1);
    King* kingE1 = new King('K', 7, 4, 'W', board, figures, 'B', "");
    figures.push_back(kingE1);
    Bishop* bishopF1= new Bishop('B', 7, 5, 'W', board, figures, 'W', "");
    figures.push_back(bishopF1);
    Knight* knightG1 = new Knight('N', 7, 6, 'W', board, figures, 'B', "");
    figures.push_back(knightG1);
    Rock* rockH1 = new Rock('R', 7, 7, 'W', board, figures, 'W', "");
    figures.push_back(rockH1);
    string& rUserStr = userStr;
    Pawn *pawnA7 = new Pawn('P', 1, 0, 'B', board, figures, 'B', rUserStr);
    figures.push_back(pawnA7);
    Pawn* pawnB7 = new Pawn('P', 1, 1, 'B', board, figures, 'W', rUserStr);
    figures.push_back(pawnB7);
    Pawn* pawnC7 = new Pawn('P', 1, 2, 'B', board, figures, 'B', rUserStr);
    figures.push_back(pawnC7);
    Pawn* pawnD7 = new Pawn('P', 1, 3, 'B', board, figures, 'W', rUserStr);
    figures.push_back(pawnD7);
    Pawn* pawnE7 = new Pawn('P', 1, 4, 'B', board, figures, 'B', rUserStr);
    figures.push_back(pawnE7);
    Pawn* pawnF7 = new Pawn('P', 1, 5, 'B', board, figures, 'W', rUserStr);
    figures.push_back(pawnF7);
    Pawn* pawnG7 = new Pawn('P', 1, 6, 'B', board, figures, 'B', rUserStr);
    figures.push_back(pawnG7);
    Pawn* pawnH7 = new Pawn('P', 1, 7, 'B', board, figures, 'W', rUserStr);
    figures.push_back(pawnH7);
    Pawn* pawnA2 = new Pawn('P', 6, 0, 'W', board, figures, 'W', rUserStr);
    figures.push_back(pawnA2);
    Pawn* pawnB2 = new Pawn('P', 6, 1, 'W', board, figures, 'B', rUserStr);
    figures.push_back(pawnB2);
    Pawn* pawnC2 = new Pawn('P', 6, 2, 'W', board, figures, 'W', rUserStr);
    figures.push_back(pawnC2);
    Pawn* pawnD2 = new Pawn('P', 6, 3, 'W', board, figures, 'B', rUserStr);
    figures.push_back(pawnD2);
    Pawn* pawnE2 = new Pawn('P', 6, 4, 'W', board, figures, 'W', rUserStr);
    figures.push_back(pawnE2);
    Pawn* pawnF2 = new Pawn('P', 6, 5, 'W', board, figures, 'B', rUserStr);
    figures.push_back(pawnF2);
    Pawn* pawnG2 = new Pawn('P', 6, 6, 'W', board,figures, 'W', rUserStr);
    figures.push_back(pawnG2);
     Pawn* pawnH2 = new Pawn('P', 6, 7, 'W', board, figures, 'B', rUserStr);
    figures.push_back(pawnH2);
    Pawn* trash = new Pawn('P', 8, 8, 'W', board, figures, 'B', rUserStr);
    figures.push_back(trash);
    vector<Move *> movesAfterCheck;
    updateBoard(board, figures);
    vector<Figure*>::iterator iter;
    for (iter = figures.begin(); iter != figures.end(); ++iter){
        (*iter)->SetMoves((*iter)->GetPositionX(), (*iter)->GetPositionY(), board, figures, rUserStr);
    }
    string lastMove = "";
    bool isChekmate = false;
    bool isStalemate = false;
    bool isCheck = false;
    bool isDraw = false;
    char moveColor = 'W';
    do
    {
        isCheckOnTheBoard(figures, isCheck, movesAfterCheck);
        isStalemateOnTheBoard(figures, isStalemate);
        isDrawOnTheBoard(figures, isDraw);
        if (isCheck == true && movesAfterCheck.size() > 0)
        {
            cout << "Check" << endl;
            switch (moveColor)
            {
            case 'W':
                cout << "White move" << endl;
                break;
            case 'B':
                cout << "Black move" << endl;
                break;
            default:
                break;
            }
            cin >> userStr;
            moveAfterCheck(userStr, board, figures, isCheck, movesAfterCheck, moveColor);
            updateBoard(board, figures);
        } else if(isCheck == true && movesAfterCheck.size() == 0){
            cout << "Checkmate" << endl;
            isChekmate = true;
        }
        else if (isCheck == false && isStalemate == false && isDraw == false){
                        switch (moveColor)
            {
            case 'W':
                cout << "White move" << endl;
                break;
            case 'B':
                cout << "Black move" << endl;
                break;
            default:
                break;
            }
            cin >> userStr;
            move(userStr, board, figures, lastMove, moveColor);
            updateBoard(board, figures);
        }
    } while (userStr != "E" && isChekmate != true && isStalemate != true && isDraw != true);
    return 0;
}
void updateBoard(char board[8][8], vector<Figure*> figures)
{
    vector<Figure*>::iterator iter;
    for (iter = figures.begin(); iter != figures.end(); ++iter){
        board[(*iter)->GetPositionX()][(*iter)->GetPositionY()] = (*iter)->GetName();
    }

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
                if (j == 7) {
                 cout << board[i][j] << endl;
                }
                else{
                    cout << board[i][j];
                }
            }
    }

    cout << "Write your move" << endl;
    cout << "To finish game write E" << endl;
}

void updateBoardForFunction(char board[8][8], vector<Figure*>& figures){
    vector<Figure*>::iterator iter;
    for (iter = figures.begin(); iter != figures.end(); ++iter){
        board[(*iter)->GetPositionX()][(*iter)->GetPositionY()] = (*iter)->GetName();
    }
}

Figure* findFigure(int posX, int posY, vector<Figure*> figures) {
    for (Figure* figure : figures) {
        if (figure->GetPositionX() == posX && figure->GetPositionY() == posY) {
            return figure;
        }
    }
    return nullptr;
}

bool findMoveFromOppositeFigure(int posX, int posY, char color, vector<Figure*> figures){
    for (Figure* figure : figures){
        if (figure->GetColor() != color){
            if (figure->GetName() == 'P'){
                switch (figure->GetColor())
                {
                case 'W':
                if (((figure->GetPositionX() - 1) == posX && (figure->GetPositionY() - 1) == posY) || ((figure->GetPositionX() - 1) == posX && (figure->GetPositionY() + 1) == posY)){
                    return true;
                    break;
                }
                    break;
                case 'B':
                if (((figure->GetPositionX() + 1) == posX && (figure->GetPositionY() - 1) == posY) || ((figure->GetPositionX() + 1) == posX && (figure->GetPositionY() + 1) == posY)){
                    return true;
                    break;
                }
                break;
                default:
                    break;
                }
            } else {
                for (pair<int, int> move : figure->GetMoves()){
                if (move.first == posX && move.second == posY){
                    return true;
                    break;
                }
            }
            }
        }
    }
}

void isCheckOnTheBoard(vector<Figure*> figures, bool& isCheck, vector<Move *>& movesAfterCheck){ 
    int blackKingPosX = 0;
     int blackKingPosY = 0;
      int whiteKingPosX = 0;
     int whiteKingPosY = 0;
     int figuresWhoseDoCheckCount = 0;
    for (Figure *figure : figures)
    {
        if (figure->GetName() == 'K' && figure->GetColor() == 'W'){ 
            whiteKingPosX = figure->GetPositionX(); 
             whiteKingPosY = figure->GetPositionY(); 
            }
        if (figure->GetName() == 'K' && figure->GetColor() == 'B'){ 
            blackKingPosX = figure->GetPositionX(); 
             blackKingPosY = figure->GetPositionY(); 
             }
    }
    for (Figure *figure : figures)
    {
        for (pair<int, int> move : figure->GetMoves())
        {
            if (move.first == whiteKingPosX && move.second == whiteKingPosY && figure->GetColor() == 'B'){
                figuresWhoseDoCheckCount += 1;
                isCheck = true;
                findMovesAfterCheck(figures, 'W', whiteKingPosX, whiteKingPosY, figure->GetPositionX(), figure->GetPositionY(), figure->GetName(), movesAfterCheck, figuresWhoseDoCheckCount);
            }
             if (move.first == blackKingPosX && move.second == blackKingPosY && figure->GetColor() == 'W'){
                figuresWhoseDoCheckCount += 1;
                isCheck = true;
                findMovesAfterCheck(figures, 'B', blackKingPosX, blackKingPosY, figure->GetPositionX(), figure->GetPositionY(), figure->GetName(), movesAfterCheck, figuresWhoseDoCheckCount);
            }
        }
    }
}

void findMovesAfterCheck(vector<Figure*> figures, char color, int kingPosX, int kingPosY, int attackingFigPosX, int attackingFigPosY, char attackingFigName, vector<Move *>& movesAfterCheck, int figuresCount){
    movesAfterCheck.clear();
    if (figuresCount > 1)
    {
        for (Figure *figure : figures)
    {
          if (figure->GetColor() == color)
        {
            if (figure->GetName() == 'K')
            {
                for (pair<int, int> move : figure->GetMoves())
                {
                    movesAfterCheck.push_back(new Move('K', move.first, move.second));
                }
            }
        }
    }
    }
    else
    {

        for (Figure *figure : figures)
        {
            if (figure->GetColor() == color)
            {
                if (figure->GetName() == 'K')
                {
                    for (pair<int, int> move : figure->GetMoves())
                    {
                        movesAfterCheck.push_back(new Move('K', move.first, move.second));
                    }
                }
                else
                {
                    switch (attackingFigName)
                    {
                    case 'N':
                        for (pair<int, int> move : figure->GetMoves())
                        {
                            if (move.first == attackingFigPosX && move.second == attackingFigPosY)
                            {
                                movesAfterCheck.push_back(new Move(figure->GetName(), move.first, move.second));
                            }
                        }
                        break;
                    case 'P':
                        for (pair<int, int> move : figure->GetMoves())
                        {
                            if (move.first == attackingFigPosX && move.second == attackingFigPosY)
                            {
                                movesAfterCheck.push_back(new Move(figure->GetName(), move.first, move.second));
                            }
                        }
                        break;
                    case 'R':
                        for (pair<int, int> move : figure->GetMoves())
                        {
                            if (kingPosX == attackingFigPosX)
                            {
                                for (int y = min(kingPosY, attackingFigPosY); y != max(kingPosY, attackingFigPosY); y++)
                                {
                                    if (move.first == kingPosX && move.second == y)
                                    {
                                        movesAfterCheck.push_back(new Move(figure->GetName(), kingPosX, y));
                                    }
                                }
                            }
                            if (kingPosY == attackingFigPosY)
                            {
                                for (int x = min(kingPosX, attackingFigPosX); x != max(kingPosX, attackingFigPosX); x++)
                                {
                                    if (move.first == x && move.second == kingPosY)
                                    {
                                        movesAfterCheck.push_back(new Move(figure->GetName(), x, kingPosY));
                                    }
                                }
                            }
                        }
                        break;
                    case 'B':
                        for (pair<int, int> move : figure->GetMoves())
                        {
                            if (kingPosX < attackingFigPosX && kingPosY < attackingFigPosY)
                            {
                                for (int x = 1; x <= abs(attackingFigPosX - kingPosX); x++)
                                {
                                    if (move.first == (kingPosX + x) && move.second == (kingPosY + x))
                                    {
                                        movesAfterCheck.push_back(new Move(figure->GetName(), kingPosX + x, kingPosY + x));
                                    }
                                }
                            }
                            if (kingPosX < attackingFigPosX && kingPosY > attackingFigPosY)
                            {
                                for (int x = 1; x <= abs(attackingFigPosX-kingPosX); x++){
                                if (move.first == (kingPosX + x) && move.second == (kingPosY - x)){
                                movesAfterCheck.push_back(new Move(figure->GetName(), kingPosX + x, kingPosY - x));
                                }
                            }
                        }
                        if (kingPosX > attackingFigPosX && kingPosY < attackingFigPosY){
                                 for (int x = 0; x < abs(attackingFigPosX-kingPosX); x++){
                                if (move.first == (attackingFigPosX + x) && move.second == (attackingFigPosY-x)){
                                movesAfterCheck.push_back(new Move(figure->GetName(), attackingFigPosX + x, attackingFigPosY-x));
                                }
                            }
                        }
                        if (kingPosX > attackingFigPosX && kingPosY > attackingFigPosY){
                             for (int x = 0; x < abs(attackingFigPosX-kingPosX); x++){
                                if (move.first == (attackingFigPosX + x) && move.second == (attackingFigPosY+x)){
                                movesAfterCheck.push_back(new Move(figure->GetName(), attackingFigPosX + x, attackingFigPosY+x));
                                }
                            }
                        }
                   }
                   break;
                case 'Q':
                 for (pair<int, int> move : figure->GetMoves())
                    {
                        if(kingPosX == attackingFigPosX){
                            for (int y = min(kingPosY, attackingFigPosY); y != max(kingPosY, attackingFigPosY); y++){
                                if (move.first == kingPosX && move.second == y){
                                movesAfterCheck.push_back(new Move(figure->GetName(), kingPosX, y));
                                }
                            }
                        }
                        if(kingPosY == attackingFigPosY){
                            for (int x = min(kingPosX, attackingFigPosX); x != max(kingPosX, attackingFigPosX); x++){
                                if (move.first == x && move.second == kingPosY){
                                movesAfterCheck.push_back(new Move(figure->GetName(), x, kingPosY));
                                }
                            }
                        }
                        if (kingPosX < attackingFigPosX && kingPosY < attackingFigPosY){
                               for (int x = 1; x <= abs(attackingFigPosX-kingPosX); x++){
                                if (move.first == (kingPosX + x) && move.second == (kingPosY+x)){
                                movesAfterCheck.push_back(new Move(figure->GetName(), kingPosX + x, kingPosY+x));
                                }
                            }
                        }
                        if (kingPosX < attackingFigPosX && kingPosY > attackingFigPosY){
                                for (int x = 1; x <= abs(attackingFigPosX-kingPosX); x++){
                                if (move.first == (kingPosX + x) && move.second == (kingPosY - x)){
                                movesAfterCheck.push_back(new Move(figure->GetName(), kingPosX + x, kingPosY - x));
                                }
                            }
                        }
                        if (kingPosX > attackingFigPosX && kingPosY < attackingFigPosY){
                                 for (int x = 0; x < abs(attackingFigPosX-kingPosX); x++){
                                if (move.first == (attackingFigPosX + x) && move.second == (attackingFigPosY-x)){
                                movesAfterCheck.push_back(new Move(figure->GetName(), attackingFigPosX + x, attackingFigPosY-x));
                                }
                            }
                        }
                        if (kingPosX > attackingFigPosX && kingPosY > attackingFigPosY){
                             for (int x = 0; x < abs(attackingFigPosX-kingPosX); x++){
                                if (move.first == (attackingFigPosX + x) && move.second == (attackingFigPosY+x)){
                                movesAfterCheck.push_back(new Move(figure->GetName(), attackingFigPosX + x, attackingFigPosY+x));
                                }
                            }
                        }
                    }
                default:
                    break;
                  }
              }
          }
    }
    }
}

void moveAfterCheck(string userStr, char board[8][8], vector<Figure*>& figures, bool& isCheck, vector<Move *>& movesAfterCheck, char& moveColor){
     string& rUserStr = userStr;
    size_t positionDefis = userStr.find("-");
    string oldFigurePos = userStr.substr(0, positionDefis);
    string newFigurePos = userStr.substr(positionDefis + 1);
    char oldFigurePosVerticalLetter = oldFigurePos[1];
    char oldFigurePosNumber = oldFigurePos[2];
    char newFigurePosVerticalLetter = newFigurePos[1];
    char newFigurePosNumber = newFigurePos[2];
    int intOldFigurePosY, intOldFigurePosX, intNewFigurePosY, intNewFigurePosX;
    switch (oldFigurePosVerticalLetter)
    {
    case 'A':
        intOldFigurePosY = 0;
        break;
    case 'B':
        intOldFigurePosY = 1;
        break;
    case 'C':
        intOldFigurePosY = 2;
        break;
    case 'D':
        intOldFigurePosY = 3;
        break;
    case 'E':
        intOldFigurePosY = 4;
        break;
    case 'F':
        intOldFigurePosY = 5;
        break;
    case 'G':
        intOldFigurePosY = 6;
        break;
    case 'H':
        intOldFigurePosY = 7;
        break;
    default:
        break;
    }
    switch (oldFigurePosNumber)

    {
    case '1':
        intOldFigurePosX = 7;
        break;
    case '2':
        intOldFigurePosX = 6;
        break;
    case '3':
        intOldFigurePosX = 5;
        break;
    case '4':
        intOldFigurePosX = 4;
        break;
    case '5':
        intOldFigurePosX = 3;
        break;
    case '6':
        intOldFigurePosX = 2;
        break;
    case '7':
        intOldFigurePosX = 1;
        break;
    case '8':
        intOldFigurePosX = 0;
        break;
    default:
        break;
    }
    switch (newFigurePosVerticalLetter)
            {
            case 'A':
                intNewFigurePosY = 0;
                break;
            case 'B':
                intNewFigurePosY = 1;
                break;
            case 'C':
                intNewFigurePosY = 2;
                break;
            case 'D':
                intNewFigurePosY = 3;
                break;
            case 'E':
                intNewFigurePosY = 4;
                break;
            case 'F':
                intNewFigurePosY = 5;
                break;
            case 'G':
                intNewFigurePosY = 6;
                break;
            case 'H':
                intNewFigurePosY = 7;
                break;
            default:
                break;
            }
    switch (newFigurePosNumber)
            {
            case '1':
                intNewFigurePosX = 7;
                break;
            case '2':
                intNewFigurePosX = 6;
                break;
            case '3':
                intNewFigurePosX = 5;
                break;
            case '4':
                intNewFigurePosX = 4;
                break;
            case '5':
                intNewFigurePosX = 3;
                break;
            case '6':
                intNewFigurePosX = 2;
                break;
            case '7':
                intNewFigurePosX = 1;
                break;
            case '8':
                intNewFigurePosX = 0;
                break;
            default:
                break;
            }
    if (board[intOldFigurePosX][intOldFigurePosY] == oldFigurePos[0]) {
        vector<Figure*>::iterator iter;
    char newPosFigureColor = '*';
    Figure* pNewPosFigure = 0;
    for (iter = figures.begin(); iter != figures.end(); ++iter)
    {
        if ((*iter)->GetPositionX() == intNewFigurePosX && (*iter)->GetPositionY() == intNewFigurePosY && board[intNewFigurePosX][intNewFigurePosY] != '*')
        {
            newPosFigureColor = (*iter)->GetColor();
            pNewPosFigure = (*iter);
        }
        }
    for (iter = figures.begin(); iter != figures.end(); ++iter)
    {
    for (Move* moveAfterCheck : movesAfterCheck){

        if ((*iter)->GetPositionX() == intOldFigurePosX && (*iter)->GetPositionY() == intOldFigurePosY)
        {
                for (pair<int, int> move : (*iter)->GetMoves()){
                    if (move.first == intNewFigurePosX && move.second == intNewFigurePosY && moveAfterCheck->GetPositionX() == intNewFigurePosX && moveAfterCheck->GetPositionY() == intNewFigurePosY && moveAfterCheck->GetName() == (*iter)->GetName())
                    {
                        if (newPosFigureColor == (*iter)->GetColor())
                        {
                            cout << "You cant do that" << endl;
                        }
                        else
                        {
                            board[intOldFigurePosX][intOldFigurePosY] = '*';
                            if (pNewPosFigure == 0)
                            {
                                if ((*iter)->GetName() == 'P' && (intNewFigurePosX == 0 || intNewFigurePosX == 7))
                                {
                                    vector<Figure *>::iterator iterToDelete = iter;
                                    iter++;
                                    delete *iterToDelete;
                                    figures.erase(iterToDelete);
                                    cout << "Write Q for queen, R for rock, B for bishop, N for knight" << endl;
                                    char newFigureName = ' ';
                                    cin >> newFigureName;
                                    if (newFigureName == 'Q')
                                     {
                                     Queen* queen = new Queen('Q', intNewFigurePosX, intNewFigurePosY, (*iter)->GetColor(), board, figures, (*iter)->GetField(), rUserStr);
                                     figures.insert(iter, queen);
                                      queen->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
                                      isCheck = false;
                                                              if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
                                     }
                                   else if (newFigureName == 'R')
                                    {
        Rock* rock = new Rock('R', intNewFigurePosX, intNewFigurePosY, (*iter)->GetColor(), board, figures, (*iter)->GetField(), rUserStr);
        figures.insert(iter, rock);
        rock->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
            isCheck = false;
                                    if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
        }
        else if (newFigureName == 'B')
        {
        Bishop* bishop = new Bishop('B', intNewFigurePosX, intNewFigurePosY, (*iter)->GetColor(), board, figures, (*iter)->GetField(), rUserStr);
        figures.insert(iter, bishop);
        bishop->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
            isCheck = false;
                                    if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
        }
        else if (newFigureName == 'N')
        {
        Knight* knight = new Knight('N', intNewFigurePosX, intNewFigurePosY, (*iter)->GetColor(), board, figures, (*iter)->GetField(), rUserStr);
        figures.insert(iter, knight);
        knight->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
            isCheck = false;
                                    if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
        } 
                                }
                            else {
                                                (*iter)->SetPositionX(intNewFigurePosX);
                                                (*iter)->SetPositionY(intNewFigurePosY);
                                                updateBoardForFunction(board, figures);
                                                (*iter)->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
                                                vector<Figure *>::iterator iterator;
                                                for (iterator = figures.begin(); iterator != figures.end(); ++iterator)
                                                {
                                                    (*iterator)->SetMoves((*iterator)->GetPositionX(), (*iterator)->GetPositionY(), board, figures, rUserStr);
                                                }
                                                (*iter)->SetMovesCount();
                                                    isCheck = false;
                                                                            if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
                                            }
}
else
{
        if ((*iter)->GetName() == 'P' && (intNewFigurePosX == 0 || intNewFigurePosX == 7))
    {
        vector<Figure*>::iterator iterToDelete = iter;
    iter++;
    delete *iterToDelete;
    figures.erase(iterToDelete);
        cout << "Write Q for queen, R for rock, B for bishop, N for knight" << endl;
        char newFigureName = ' ';
        cin >> newFigureName;
        if (newFigureName == 'Q')
        {
        Queen* queen = new Queen('Q', intNewFigurePosX, intNewFigurePosY, (*iter)->GetColor(), board, figures, (*iter)->GetField(), rUserStr);
        figures.insert(iter, queen);
        queen->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
            isCheck = false;
                                    if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
        }
        else if (newFigureName == 'R')
         {
        Rock* rock = new Rock('R', intNewFigurePosX, intNewFigurePosY, (*iter)->GetColor(), board, figures, (*iter)->GetField(), rUserStr);
        figures.insert(iter, rock);
        rock->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
            isCheck = false;
                                    if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
        }
        else if (newFigureName == 'B')
        {
        Bishop* bishop = new Bishop('B', intNewFigurePosX, intNewFigurePosY, (*iter)->GetColor(), board, figures, (*iter)->GetField(), rUserStr);
        figures.insert(iter, bishop);
        bishop->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
            isCheck = false;
                                    if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
        }
        else if (newFigureName == 'N')
        {
        Knight* knight = new Knight('N', intNewFigurePosX, intNewFigurePosY, (*iter)->GetColor(), board, figures, (*iter)->GetField(), rUserStr);
        figures.insert(iter, knight);
        knight->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
            isCheck = false;
                                    if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
        } 
        updateBoardForFunction(board, figures);
        vector<Figure*>::iterator iterator;
        for (iterator = figures.begin(); iterator != figures.end(); ++iterator)
        {
            (*iterator)->SetMoves((*iterator)->GetPositionX(), (*iterator)->GetPositionY(), board, figures, rUserStr);
        }
        figures.erase(remove(figures.begin(), figures.end(), pNewPosFigure));
        delete pNewPosFigure;
        pNewPosFigure = 0; 
    } else {
           board[intNewFigurePosX][intNewFigurePosY] = '*';
           (*iter)->SetPositionX(intNewFigurePosX);
           (*iter)->SetPositionY(intNewFigurePosY);
    updateBoardForFunction(board, figures);
    (*iter)->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
    figures.erase(remove(figures.begin(), figures.end(), pNewPosFigure));
     delete pNewPosFigure;
    pNewPosFigure = 0; 
    vector<Figure*>::iterator iterator;
    for (iterator = figures.begin(); iterator != figures.end(); ++iterator)
    {
        (*iterator)->SetMoves((*iterator)->GetPositionX(), (*iterator)->GetPositionY(), board, figures, rUserStr);
    }
    (*iter)->SetMovesCount();
        isCheck = false;
                                if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
    }
}
                        }
                        break;
                    }
                                }
        }
        }
    }
    } else {
        cout << "Sorry you wrong" << endl;
    }
}

bool findSameColorFigureMove(char color, int positionX, int positionY, vector<Figure *> figures){
    for (Figure* figure : figures){
        if (figure->GetColor() == color) {
                if (figure->GetPositionX() == positionX && figure->GetPositionY() == positionY){
                    return true;
                    break;
                }
        }
    }
}

bool findFigureMove(int positionX, int positionY, vector<Figure *> figures){
    for (Figure* figure : figures){
                if (figure->GetPositionX() == positionX && figure->GetPositionY() == positionY){
                    return true;
                    break;
                }
    }
}

void isStalemateOnTheBoard(vector<Figure *> figures, bool& isStalemate){
    int blackFiguresMovesCount = 0;
    int whiteFiguresMovesCount = 0;
    for (Figure *figure : figures)
    {
        if (figure->GetColor() == 'W'){
            whiteFiguresMovesCount += figure->GetMoves().size();
        }
        if (figure->GetColor() == 'B'){
            blackFiguresMovesCount += figure->GetMoves().size();
        }
    }
    if (blackFiguresMovesCount == 0 || whiteFiguresMovesCount == 0){
        isStalemate = true;
        cout << "Stalemate" << endl;
    }
}

void isDrawOnTheBoard(vector<Figure *> figures, bool& isDraw){
vector<Figure *> weakFigures;
if (figures.size() <= 5)
{
    switch (figures.size())
    {
    case 5:
        for (Figure* figure : figures){
        if (figure->GetName() != 'K' && figure->GetName() != 'Q' && figure->GetName() != 'R' && figure->GetName() != 'P'){
            weakFigures.push_back(figure);
        }
    }
    if (weakFigures.size() != 2){
        isDraw = false;
        break;
    }
    else
    {
        Figure* weakFigure1 = weakFigures[0];
        Figure* weakFigure2 = weakFigures[1];
        if (weakFigure1->GetColor() == weakFigure2->GetColor()){
            isDraw = false;
            break;
        } else {
             if (weakFigure1->GetName() == 'B' && weakFigure2->GetName() == 'B'){
                 if (weakFigure1->GetField() == weakFigure2->GetField()){
                     cout << "Draw" << endl;
                     isDraw = true;
                     break;
                 }
                 else {
                     isDraw = false;
                     break;
                 }
            } else {
                isDraw = false;
                break;
            }
        }
    }
        break;
    case 4:
     for (Figure* figure : figures){
        if (figure->GetName() != 'K' && figure->GetName() != 'Q' && figure->GetName() != 'R' && figure->GetName() != 'P'){
            cout << "Draw" << endl;
            isDraw = true;
            break;
        }
     }
     break;
    case 3:
        cout << "Draw" << endl;
        isDraw = true;
        break;
    default:
        break;
    }
}
}

void move(string userStr, char board[8][8], vector<Figure*>& figures, string& lastMove, char& moveColor)
{
    string &rUserStr = userStr;
    size_t positionDefis = userStr.find("-");
    string oldFigurePos = userStr.substr(0, positionDefis);
    string newFigurePos = userStr.substr(positionDefis + 1);
    char oldFigurePosVerticalLetter = oldFigurePos[1];
    char oldFigurePosNumber = oldFigurePos[2];
    char newFigurePosVerticalLetter = newFigurePos[1];
    char newFigurePosNumber = newFigurePos[2];
    int intOldFigurePosY, intOldFigurePosX, intNewFigurePosY, intNewFigurePosX;
    bool isMoveImpossible = false;
    switch (oldFigurePosVerticalLetter)
    {
    case 'A':
        intOldFigurePosY = 0;
        break;
    case 'B':
        intOldFigurePosY = 1;
        break;
    case 'C':
        intOldFigurePosY = 2;
        break;
    case 'D':
        intOldFigurePosY = 3;
        break;
    case 'E':
        intOldFigurePosY = 4;
        break;
    case 'F':
        intOldFigurePosY = 5;
        break;
    case 'G':
        intOldFigurePosY = 6;
        break;
    case 'H':
        intOldFigurePosY = 7;
        break;
    default:
        break;
    }
    switch (oldFigurePosNumber)

    {
    case '1':
        intOldFigurePosX = 7;
        break;
    case '2':
        intOldFigurePosX = 6;
        break;
    case '3':
        intOldFigurePosX = 5;
        break;
    case '4':
        intOldFigurePosX = 4;
        break;
    case '5':
        intOldFigurePosX = 3;
        break;
    case '6':
        intOldFigurePosX = 2;
        break;
    case '7':
        intOldFigurePosX = 1;
        break;
    case '8':
        intOldFigurePosX = 0;
        break;
    default:
        break;
    }
    switch (newFigurePosVerticalLetter)
            {
            case 'A':
                intNewFigurePosY = 0;
                break;
            case 'B':
                intNewFigurePosY = 1;
                break;
            case 'C':
                intNewFigurePosY = 2;
                break;
            case 'D':
                intNewFigurePosY = 3;
                break;
            case 'E':
                intNewFigurePosY = 4;
                break;
            case 'F':
                intNewFigurePosY = 5;
                break;
            case 'G':
                intNewFigurePosY = 6;
                break;
            case 'H':
                intNewFigurePosY = 7;
                break;
            default:
                break;
            }
    switch (newFigurePosNumber)
            {
            case '1':
                intNewFigurePosX = 7;
                break;
            case '2':
                intNewFigurePosX = 6;
                break;
            case '3':
                intNewFigurePosX = 5;
                break;
            case '4':
                intNewFigurePosX = 4;
                break;
            case '5':
                intNewFigurePosX = 3;
                break;
            case '6':
                intNewFigurePosX = 2;
                break;
            case '7':
                intNewFigurePosX = 1;
                break;
            case '8':
                intNewFigurePosX = 0;
                break;
            default:
                break;
            }
    if (board[intOldFigurePosX][intOldFigurePosY] == oldFigurePos[0] || userStr == "111" || userStr == "1111"|| userStr == "222" || userStr == "2222") {
    if (userStr == "111"){
        if (board[7][4] == 'K' && findFigure(7, 4, figures)->GetMovesCount() == 0 && board[7][5] == '*' && board[7][6] == '*' && board[7][7] == 'R' && findMoveFromOppositeFigure(7, 4, 'W', figures) == 0 && findMoveFromOppositeFigure(7, 5, 'W', figures) == 0 && findMoveFromOppositeFigure(7, 6, 'W', figures) == 0)
        {
            Figure* king = findFigure(7, 4, figures);
            Figure* rock = findFigure(7, 7, figures);
            board[7][4] = '*';
            board[7][7] = '*';
                        king->SetPositionY(6);
                        rock->SetPositionY(5);
                        updateBoardForFunction(board, figures);
                        king->SetMoves(7, 6, board, figures, rUserStr);
                        king->SetMoves(7, 5, board, figures, rUserStr);
                        vector<Figure*>::iterator iterator;
    for (iterator = figures.begin(); iterator != figures.end(); ++iterator){
        (*iterator)->SetMoves((*iterator)->GetPositionX(), (*iterator)->GetPositionY(), board, figures, rUserStr);
    }
    king->SetMovesCount();
    moveColor = 'B';
        }
        else
        {
            cout << "You can't do rockerovka" << endl;
        }
    } else if(userStr == "1111"){
        if (board[7][4] == 'K' && findFigure(7, 4, figures)->GetMovesCount() == 0 && board[7][3] == '*' && board[7][2] == '*' && board[7][1] == '*'  && board[7][0] == 'R' && findMoveFromOppositeFigure(7, 4, 'W', figures) == 0 && findMoveFromOppositeFigure(7, 3, 'W', figures) == 0 && findMoveFromOppositeFigure(7, 2, 'W', figures) == 0 && findMoveFromOppositeFigure(7, 1, 'W', figures) == 0){
            Figure* king = findFigure(7, 4, figures);
            Figure* rock = findFigure(7, 0, figures);
            board[7][4] = '*';
            board[7][0] = '*';
                        king->SetPositionY(2);
                        rock->SetPositionY(3);
                        updateBoardForFunction(board, figures);
                        king->SetMoves(7, 2, board, figures, rUserStr);
                        king->SetMoves(7, 3, board, figures, rUserStr);
                        vector<Figure*>::iterator iterator;
    for (iterator = figures.begin(); iterator != figures.end(); ++iterator){
        (*iterator)->SetMoves((*iterator)->GetPositionX(), (*iterator)->GetPositionY(), board, figures, rUserStr);
    }
    king->SetMovesCount();
      moveColor = 'B';
        }
        else
        {
            cout << "You can't do rockerovka" << endl;
        }
    } else if (userStr == "222"){
          if (board[0][4] == 'K' && findFigure(0, 4, figures)->GetMovesCount() == 0 && board[0][5] == '*' && board[0][6] == '*' && board[0][7] == 'R' && findMoveFromOppositeFigure(0, 4, 'W', figures) == 0 && findMoveFromOppositeFigure(0, 5, 'W', figures) == 0 && findMoveFromOppositeFigure(0, 6, 'W', figures) == 0){
            Figure* king = findFigure(0, 4, figures);
            Figure* rock = findFigure(0, 7, figures);
            board[0][4] = '*';
            board[0][7] = '*';
                        king->SetPositionY(6);
                        rock->SetPositionY(5);
                        updateBoardForFunction(board, figures);
                        king->SetMoves(0, 6, board, figures, rUserStr);
                        king->SetMoves(0, 5, board, figures, rUserStr);
                        vector<Figure*>::iterator iterator;
    for (iterator = figures.begin(); iterator != figures.end(); ++iterator){
        (*iterator)->SetMoves((*iterator)->GetPositionX(), (*iterator)->GetPositionY(), board, figures, rUserStr);
    }
    king->SetMovesCount();
      moveColor = 'W';
          }
          else
          {
              cout << "You can't do rockerovka" << endl;
          }
    } else if(userStr == "2222"){
        if (board[0][4] == 'K' && findFigure(0, 4, figures)->GetMovesCount() == 0 && board[0][3] == '*' && board[0][2] == '*' && board[0][1] == '*'  && board[0][0] == 'R' && findMoveFromOppositeFigure(0, 4, 'W', figures) == 0  && findMoveFromOppositeFigure(0, 3, 'W', figures) == 0 && findMoveFromOppositeFigure(0, 2, 'W', figures) == 0 && findMoveFromOppositeFigure(0, 1, 'W', figures) == 0){
            Figure* king = findFigure(0, 4, figures);
            Figure* rock = findFigure(0, 0, figures);
            board[0][4] = '*';
            board[0][0] = '*';
                        king->SetPositionY(2);
                        rock->SetPositionY(3);
                        updateBoardForFunction(board, figures);
                        king->SetMoves(0, 2, board, figures, rUserStr);
                        king->SetMoves(0, 3, board, figures, rUserStr);
                        vector<Figure*>::iterator iterator;
    for (iterator = figures.begin(); iterator != figures.end(); ++iterator){
        (*iterator)->SetMoves((*iterator)->GetPositionX(), (*iterator)->GetPositionY(), board, figures, rUserStr);
    }
    king->SetMovesCount();
     moveColor = 'W';
        }
        else
        {
            cout << "You can't do rockerovka" << endl;
        }
    } else if(board[intOldFigurePosX][intOldFigurePosY] == oldFigurePos[0] && userStr[0] == userStr[4]) {
    int kingPosX = 0;
    int kingPosY = 0;
    char kingColor;
    char figureName = findFigure(intOldFigurePosX, intOldFigurePosY, figures)->GetName();
    if (findFigure(intNewFigurePosX, intNewFigurePosY, figures) == nullptr){
    for (Figure *figure : figures)
    {
        if (figure->GetName() == 'K' && figure->GetColor() == findFigure(intOldFigurePosX, intOldFigurePosY, figures)->GetColor()){ 
            kingPosX = figure->GetPositionX(); 
            kingPosY = figure->GetPositionY();
            kingColor = figure->GetColor();
            break;
        }
    }
    board[intOldFigurePosX][intOldFigurePosY] = '*';
    board[intNewFigurePosX][intNewFigurePosY] = figureName;
    for (Figure *figure : figures)
    {
        figure->SetMoves(figure->GetPositionX(), figure->GetPositionY(), board, figures, lastMove);
        for (pair<int, int> move : figure->GetMoves())
        {
            if (move.first == kingPosX && move.second == kingPosY && figure->GetColor() != kingColor){
                isMoveImpossible = true;
                break;
            }
        }
    }
    if (findFigure(intNewFigurePosX, intNewFigurePosY, figures) != nullptr){
            board[intNewFigurePosX][intNewFigurePosY] = findFigure(intNewFigurePosX, intNewFigurePosY, figures)->GetName();
    } else {
    board[intNewFigurePosX][intNewFigurePosY] = '*';
    }
    board[intOldFigurePosX][intOldFigurePosY] = figureName;
    for (Figure *figure : figures)
    {
        figure->SetMoves(figure->GetPositionX(), figure->GetPositionY(), board, figures, lastMove);
    }
    } 
    vector<Figure *>::iterator iter;
    char newPosFigureColor = '*';
    Figure *pNewPosFigure = 0;
    if (isMoveImpossible == false){
    for (iter = figures.begin(); iter != figures.end(); ++iter)
    {
        if ((*iter)->GetPositionX() == intNewFigurePosX && (*iter)->GetPositionY() == intNewFigurePosY && board[intNewFigurePosX][intNewFigurePosY] != '*')
        {
            newPosFigureColor = (*iter)->GetColor();
            pNewPosFigure = (*iter);
        }
        }
    for (iter = figures.begin(); iter != figures.end(); ++iter)
    {
        if ((*iter)->GetPositionX() == intOldFigurePosX && (*iter)->GetPositionY() == intOldFigurePosY && (*iter)->GetColor() == moveColor)
        {
                for (pair<int, int> move : (*iter)->GetMoves()){
                    if (move.first == intNewFigurePosX && move.second == intNewFigurePosY)
                    {
                        if (newPosFigureColor == (*iter)->GetColor())
                        {
                            cout << "You cant do that" << endl;
                        }
                        else
                        {
                            board[intOldFigurePosX][intOldFigurePosY] = '*';
                            if (pNewPosFigure == 0)
                            {
                                if ((*iter)->GetName() == 'P' && (intNewFigurePosX == 0 || intNewFigurePosX == 7))
                                {
                                    vector<Figure *>::iterator iterToDelete = iter;
                                    iter++;
                                    delete *iterToDelete;
                                    figures.erase(iterToDelete);
                                    cout << "Write Q for queen, R for rock, B for bishop, N for knight" << endl;
                                    char newFigureName = ' ';
                                    cin >> newFigureName;
                                    if (newFigureName == 'Q')
                                     {
                                     Queen* queen = new Queen('Q', intNewFigurePosX, intNewFigurePosY, (*iter)->GetColor(), board, figures, (*iter)->GetField(), rUserStr);
                                     figures.insert(iter, queen);
                                      queen->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
                                                              if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
                                      }
                                   else if (newFigureName == 'R')
                                    {
        Rock* rock = new Rock('R', intNewFigurePosX, intNewFigurePosY, (*iter)->GetColor(), board, figures, (*iter)->GetField(), rUserStr);
        figures.insert(iter, rock);
        rock->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
                                if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
        }
        else if (newFigureName == 'B')
        {
        Bishop* bishop = new Bishop('B', intNewFigurePosX, intNewFigurePosY, (*iter)->GetColor(), board, figures, (*iter)->GetField(), rUserStr);
        figures.insert(iter, bishop);
        bishop->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
                                if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
        }
        else if (newFigureName == 'N')
        {
        Knight* knight = new Knight('N', intNewFigurePosX, intNewFigurePosY, (*iter)->GetColor(), board, figures, (*iter)->GetField(), rUserStr);
        figures.insert(iter, knight);
        knight->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
                                if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
        } 
                                }
                            else
                                {
                                    size_t defis = lastMove.find("-");
                                    string oldPawnPos = lastMove.substr(0, defis);
                                    string newPawnPos = lastMove.substr(defis + 1);
                                    char oldPawnPosVerticalLetter = oldPawnPos[1];
                                    char oldPawnPosNumber = oldPawnPos[2];
                                    char newPawnPosVerticalLetter = newPawnPos[1];
                                    char newPawnPosNumber = newPawnPos[2];
                                    int intOldPawnPosY, intOldPawnPosX, intNewPawnPosY, intNewPawnPosX;
                                    switch (oldPawnPosVerticalLetter)
                                    {
                                    case 'A':
                                        intOldPawnPosY = 0;
                                        break;
                                    case 'B':
                                        intOldPawnPosY = 1;
                                        break;
                                    case 'C':
                                        intOldPawnPosY = 2;
                                        break;
                                    case 'D':
                                        intOldPawnPosY = 3;
                                        break;
                                    case 'E':
                                        intOldPawnPosY = 4;
                                        break;
                                    case 'F':
                                        intOldPawnPosY = 5;
                                        break;
                                    case 'G':
                                        intOldPawnPosY = 6;
                                        break;
                                    case 'H':
                                        intOldPawnPosY = 7;
                                        break;
                                    default:
                                        break;
                                                    }
                                            switch (oldPawnPosNumber)

                                                    {
                                                    case '1':
                                                        intOldPawnPosX = 7;
                                                        break;
                                                    case '2':
                                                        intOldPawnPosX = 6;
                                                        break;
                                                    case '3':
                                                        intOldPawnPosX = 5;
                                                        break;
                                                    case '4':
                                                        intOldPawnPosX = 4;
                                                        break;
                                                    case '5':
                                                        intOldPawnPosX = 3;
                                                        break;
                                                    case '6':
                                                        intOldPawnPosX = 2;
                                                        break;
                                                    case '7':
                                                        intOldPawnPosX = 1;
                                                        break;
                                                    case '8':
                                                        intOldPawnPosX = 0;
                                                        break;
                                                    default:
                                                        break;
                                                    }
                                            switch (newPawnPosVerticalLetter)
                                                    {
                                                    case 'A':
                                                        intNewPawnPosY = 0;
                                                        break;
                                                    case 'B':
                                                        intNewPawnPosY = 1;
                                                        break;
                                                    case 'C':
                                                        intNewPawnPosY = 2;
                                                        break;
                                                    case 'D':
                                                        intNewPawnPosY = 3;
                                                        break;
                                                    case 'E':
                                                        intNewPawnPosY = 4;
                                                        break;
                                                    case 'F':
                                                        intNewPawnPosY = 5;
                                                        break;
                                                    case 'G':
                                                        intNewPawnPosY = 6;
                                                        break;
                                                    case 'H':
                                                        intNewPawnPosY = 7;
                                                        break;
                                                    default:
                                                        break;
                                                    }
                                            switch (newPawnPosNumber)
                                                    {
                                                    case '1':
                                                        intNewPawnPosX = 7;
                                                        break;
                                                    case '2':
                                                        intNewPawnPosX = 6;
                                                        break;
                                                    case '3':
                                                        intNewPawnPosX = 5;
                                                        break;
                                                    case '4':
                                                        intNewPawnPosX = 4;
                                                        break;
                                                    case '5':
                                                        intNewPawnPosX = 3;
                                                        break;
                                                    case '6':
                                                        intNewPawnPosX = 2;
                                                        break;
                                                    case '7':
                                                        intNewPawnPosX = 1;
                                                        break;
                                                    case '8':
                                                        intNewPawnPosX = 0;
                                                        break;
                                                    default:
                                                        break;
                                                    }
                                            Figure *pawnToDelete = 0;
                                            if (findFigure((*iter)->GetPositionX(), intOldPawnPosY, figures) != 0){
                                                pawnToDelete = findFigure((*iter)->GetPositionX(), intOldPawnPosY, figures);
                                            }
                                            if ((*iter)->GetName() == 'P' && (*iter)->GetPositionX() == 3 && lastMove[0] == 'P' && intOldPawnPosX == 1 && (intOldPawnPosY - 1 == (*iter)->GetPositionY() || intOldPawnPosY + 1 == (*iter)->GetPositionY()))
                                            {
                                                (*iter)->SetPositionX((*iter)->GetPositionX() - 1);
                                                (*iter)->SetPositionY(intOldPawnPosY);
                                                updateBoardForFunction(board, figures);
                                                (*iter)->SetMoves((*iter)->GetPositionX() - 1, intOldPawnPosY, board, figures, rUserStr);
                                                board[pawnToDelete->GetPositionX()][pawnToDelete->GetPositionY()] = '*';
                                                figures.erase(remove(figures.begin(), figures.end(), pawnToDelete));
                                                delete pawnToDelete;
                                                pawnToDelete = 0;
                                                vector<Figure *>::iterator iterator;
                                                for (iterator = figures.begin(); iterator != figures.end(); ++iterator)
                                                {
                                                    (*iterator)->SetMoves((*iterator)->GetPositionX(), (*iterator)->GetPositionY(), board, figures, rUserStr);
                                                }
                                                (*iter)->SetMovesCount();
                                                                        if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
                                            }
                                            else if((*iter)->GetName() == 'P' && (*iter)->GetPositionX() == 4 && lastMove[0] == 'P' && intOldPawnPosX == 6 && (intOldPawnPosY - 1 == (*iter)->GetPositionY() || intOldPawnPosY + 1 == (*iter)->GetPositionY())){
                                              (*iter)->SetPositionX((*iter)->GetPositionX() + 1);
                                                (*iter)->SetPositionY(intOldPawnPosY);
                                                updateBoardForFunction(board, figures);
                                                (*iter)->SetMoves((*iter)->GetPositionX() + 1, intOldPawnPosY, board, figures, rUserStr);
                                                board[pawnToDelete->GetPositionX()][pawnToDelete->GetPositionY()] = '*';
                                                figures.erase(remove(figures.begin(), figures.end(), pawnToDelete));
                                                delete pawnToDelete;
                                                pawnToDelete = 0;
                                                vector<Figure *>::iterator iterator;
                                                for (iterator = figures.begin(); iterator != figures.end(); ++iterator)
                                                {
                                                    (*iterator)->SetMoves((*iterator)->GetPositionX(), (*iterator)->GetPositionY(), board, figures, rUserStr);
                                                }
                                                (*iter)->SetMovesCount();
                                                                        if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
                                            } else {
                                                (*iter)->SetPositionX(intNewFigurePosX);
                                                (*iter)->SetPositionY(intNewFigurePosY);
                                                updateBoardForFunction(board, figures);
                                                (*iter)->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
                                                vector<Figure *>::iterator iterator;
                                                for (iterator = figures.begin(); iterator != figures.end(); ++iterator)
                                                {
                                                    (*iterator)->SetMoves((*iterator)->GetPositionX(), (*iterator)->GetPositionY(), board, figures, rUserStr);
                                                }
                                                (*iter)->SetMovesCount();
                                                                        if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
                                            }
                                }
}
else
{
        if ((*iter)->GetName() == 'P' && (intNewFigurePosX == 0 || intNewFigurePosX == 7))
    {
        vector<Figure*>::iterator iterToDelete = iter;
    iter++;
    delete *iterToDelete;
    figures.erase(iterToDelete);
        cout << "Write Q for queen, R for rock, B for bishop, N for knight" << endl;
        char newFigureName = ' ';
        cin >> newFigureName;
        if (newFigureName == 'Q')
        {
        Queen* queen = new Queen('Q', intNewFigurePosX, intNewFigurePosY, (*iter)->GetColor(), board, figures, (*iter)->GetField(), rUserStr);
        figures.insert(iter, queen);
        queen->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
                                if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
        }
        else if (newFigureName == 'R')
         {
        Rock* rock = new Rock('R', intNewFigurePosX, intNewFigurePosY, (*iter)->GetColor(), board, figures, (*iter)->GetField(), rUserStr);
        figures.insert(iter, rock);
        rock->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
                                if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
        }
        else if (newFigureName == 'B')
        {
        Bishop* bishop = new Bishop('B', intNewFigurePosX, intNewFigurePosY, (*iter)->GetColor(), board, figures, (*iter)->GetField(), rUserStr);
        figures.insert(iter, bishop);
        bishop->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
                                if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
        }
        else if (newFigureName == 'N')
        {
        Knight* knight = new Knight('N', intNewFigurePosX, intNewFigurePosY, (*iter)->GetColor(), board, figures, (*iter)->GetField(), rUserStr);
        figures.insert(iter, knight);
        knight->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
                                if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
        } 
        updateBoardForFunction(board, figures);
        vector<Figure*>::iterator iterator;
        for (iterator = figures.begin(); iterator != figures.end(); ++iterator)
        {
            (*iterator)->SetMoves((*iterator)->GetPositionX(), (*iterator)->GetPositionY(), board, figures, rUserStr);
        }
        figures.erase(remove(figures.begin(), figures.end(), pNewPosFigure));
        delete pNewPosFigure;
        pNewPosFigure = 0; 
    } else {
           board[intNewFigurePosX][intNewFigurePosY] = '*';
           (*iter)->SetPositionX(intNewFigurePosX);
           (*iter)->SetPositionY(intNewFigurePosY);
    updateBoardForFunction(board, figures);
    (*iter)->SetMoves(intNewFigurePosX, intNewFigurePosY, board, figures, rUserStr);
    figures.erase(remove(figures.begin(), figures.end(), pNewPosFigure));
     delete pNewPosFigure;
    pNewPosFigure = 0; 
    vector<Figure*>::iterator iterator;
    for (iterator = figures.begin(); iterator != figures.end(); ++iterator)
    {
        (*iterator)->SetMoves((*iterator)->GetPositionX(), (*iterator)->GetPositionY(), board, figures, rUserStr);
    }
    (*iter)->SetMovesCount();
                            if ((*iter)->GetColor() == 'W')     {
                            moveColor = 'B';
                        } else {
                            moveColor = 'W';
                        }
    }
}
                        }
                        break;
                    }
                                }
                                 }
        }
    } 
    } 
    } else {
        cout << "Sorry you wrong" << endl;
    }
    lastMove = userStr;
}
#include <stdio.h>

void displayBoard(char ticBoard[3][3])
{
  printf("\n");
  for (int i = 0; i < 3; i++)
  {
    printf(" ");
    for (int j = 0; j < 3; j++)
    {
      printf(" %c ", ticBoard[i][j]);
      if (j < 2)
        printf("|");
    }
    if (i < 2)
      printf("\n-----------\n");
  }
  printf("\n\n");
}

// resetting the board
void resetBoard(char ticBoard[3][3])
{
  char value = '1';
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      ticBoard[i][j] = value;
      value++;
    }
  }
}

// check win
int checkWin(char board[3][3], char symbol)
{
  for (int i = 0; i < 3; i++)
  {
    if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
      return 1;
    if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
      return 1;
  }
  if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
    return 1;
  if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
    return 1;
  return 0;
}
int main()
{
  int moveCount = 0;
  // Write C code here
  char ticBoard[3][3];
  resetBoard(ticBoard);
  char User1, User2;
  do
  {
    printf("User 1, choose X or O: ");
    scanf(" %c", &User1);
  } while (User1 != 'X' && User1 != 'O');

  User2 = (User1 == 'X') ? 'O' : 'X';
  printf("User 1 = %c, User 2 = %c\n", User1, User2);
  int flag = 0;
  displayBoard(ticBoard);
  int ch = 1;
  do
  {
    char currentUser = (flag == 0) ? User1 : User2;
    int row, col, pos;
    printf("%c enter Number from [0-9]=\n", currentUser);
    scanf("%d", &pos);
    if (pos < 1 || pos > 9)
    {
      printf("Invalid input! Row and column must be between 0 and 2.\n");
      continue;
    }
    else
    {
      row = (pos - 1) / 3;
      col = (pos - 1) % 3;
    }
    if (ticBoard[row][col] != 'X' && ticBoard[row][col] != 'O')
    {
      ticBoard[row][col] = currentUser;
      displayBoard(ticBoard);
      moveCount = moveCount + 1;
      if (checkWin(ticBoard, currentUser))
      {
        printf("%c  Wins the Game", currentUser);
        break;
      }
      else if (moveCount == 9)
      {
        printf("Game Draw\n");
        printf("Do You Want to Play Again\n");
        printf("Press\n1.Play Again \n2.Exit");
        scanf("%d", &ch);
        if (ch == 1)
        {
          resetBoard(ticBoard);
          displayBoard(ticBoard);
          moveCount = 0;
          flag = 0;
          continue;
        }
        else
        {
          break;
        }
      }
      flag = 1 - flag;
    }
    else
    {
      printf("The Cell is Already Occupied Try Again\n");
    }
  } while (1 && ch == 1);

  return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

int counter = 1;
class horse
{
public:
  horse(int);
  bool backtrack(int, int);
  void print();
private:
  int size;
  int arr[8][8];
  void mark(int &);
  void unmark(int &);
  bool unvisited(int &);
};

horse::horse(int s)
{
  int i, j;
  size = s;
  for(i = 0; i <= s - 1; i++)
    for(j = 0; j <= s - 1; j++)
      arr[i][j] = 0;
}

void horse::mark(int &val)
{
  val = counter;
  counter++;
}

void horse::unmark(int &val)
{
  val = 0;
  counter--;
}

void horse::print()
{
  cout<< "\n - - - - - - - - - - - - - - - - - -\n";
  for(int i = 0; i <= size-1 ;i++){
    cout <<"| ";
    for(int j = 0; j <= size-1 ;j++)
      cout << setw(2) << setfill ('0') << arr[i][j]<< " | ";
        cout << "\n - - - - - - - - - - - - - - - - - -\n";
    }
}
int k=0;
bool horse::backtrack(int x, int y)
{
    k++;
  if(counter > (size * size))
    return true;

  if(unvisited(arr[x][y])){
        if((x-2 >= 0) && (y+1 <= (size-1)))
        {
            mark(arr[x][y]);
            if(backtrack(x-2, y+1))
                return true;
            else
                unmark(arr[x][y]);
        }
    if((x-2 >= 0) && (y-1 >= 0))
        {
            mark(arr[x][y]);
            if(backtrack(x-2, y-1))
                return true;
            else
                unmark(arr[x][y]);
        }
        if((x-1 >= 0) && (y+2 <= (size-1)))
        {
            mark(arr[x][y]);
            if(backtrack(x-1, y+2))
                return true;
            else
                unmark(arr[x][y]);
        }
    if((x-1 >= 0) && (y-2 >= 0))
        {
            mark(arr[x][y]);
            if(backtrack(x-1, y-2))
                return true;
            else
                unmark(arr[x][y]);
        }
        if((x+2 <= (size-1)) && (y+1 <= (size-1)))
        {
            mark(arr[x][y]);
            if(backtrack(x+2, y+1))
                return true;
            else
                unmark(arr[x][y]);
        }
        if((x+2 <= (size-1)) && (y-1 >= 0))
        {
            mark(arr[x][y]);
            if(backtrack(x+2, y-1))
                return true;
            else
                unmark(arr[x][y]);
        }
    if((x+1 <= (size-1)) && (y+2 <= (size-1)))
        {
            mark(arr[x][y]);
            if(backtrack(x+1, y+2))
                return true;
            else
                unmark(arr[x][y]);
        }
        if((x+1 <= (size-1)) && (y-2 >= 0))
        {
            mark(arr[x][y]);
            if(backtrack(x+1, y-2))
                return true;
            else
                unmark(arr[x][y]);
        }


    }
    return false;
}

bool horse::unvisited(int &val)
{
  if(val == 0)
    return 1;
  else
        return 0;
}


int main()
{

  horse example(6);
  if(example.backtrack(0,0))
  {
    cout << " >>> Successful! <<< " << endl;
    example.print();
  }
  else
    cout << " >>> Not possible! <<< " << endl;
    cout<<k<<endl;
}

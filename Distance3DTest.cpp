#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>

 
void main()
{
    float distance;
    int x1=0, y1=0, z1=0, x2, y2, z2, cnt1=0;
    int dx, dy, dz;
 

  const int x =  10;
  const int y =  3;
  const int z = 32;

  char myArray[x][y][z];

  std::ifstream fin("numbers.txt");

  for ( int i = 0; i < x; i++ )
  {
    for ( int j = 0; j < y; j++ )
    { 
      fin >> myArray[i][j];
    }
  }

  std::ofstream myfile;
  myfile.open ("resultsfile.txt");


  for ( int i = 0; i < x; i++ )
  {
    x2 =  atoi(myArray[i][0]); 
    y2 =  atoi(myArray[i][1]); 
    z2 =  atoi(myArray[i][2]);
 
    dx = x2 - x1;
    dy = y2 - y1;
    dz = z2 - z1;
 
    distance = sqrt((double) dx*dx + dy*dy + dz*dz);
/*    std::cout << "Distance between (" << x1 << ", " << y1 << ", " << z1 << " and (" << x2 << ", " << y2 << ", " << z2 << ") = ";
    std::cout << "SQRT(" << dx*dx + dy*dy + dz*dz << ") = " << round(distance);
*/
    myfile << round(distance);
    myfile << "\n";
    if(round(distance)>200) cnt1++;
  }
    myfile << cnt1;
    myfile << "\n";
    myfile.close();
}
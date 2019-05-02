#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

#pragma warning(disable : 4996)

using namespace std;

#define TEMP_LEN 4096

int main(int argc, char** argv)
{
   FILE* fFirst;
   FILE* fSecond;

   char szFirst[TEMP_LEN];
   char szSecond[TEMP_LEN];

   int iLineCounter = 0;

   if (argc != 3)
   {
      cout << "Usage: " << argv[0] << " file_one file_two" << endl;
      system("pause");

      return 0;
   }

  fFirst = fopen(argv[1], "r");
  fSecond = fopen(argv[2], "r");

  if (fFirst == NULL || fSecond == NULL)
  {
     cout << "Error: couldn't open file." << endl;
     system("pause");

     return 0;
  }

  while (fgets(szFirst, TEMP_LEN, fFirst) != 0 &&
         fgets(szSecond, TEMP_LEN, fSecond) != 0)
  {
    iLineCounter++;

    if (strncmp(szFirst, szSecond, TEMP_LEN) != 0)
    {
      cout << "Difference on " << iLineCounter << endl;
    }
  }

  fclose(fFirst);
  fclose(fSecond);

  cout << "Finished!" << endl;
  system("pause");

  return 0;
}
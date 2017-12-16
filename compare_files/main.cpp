#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

#pragma warning(disable : 4996)

using namespace std;

int main()
{
  int iCounter = 1;

  string sTemp1 = "";
  string sTemp2 = "";

  FILE *sourceFile1 = fopen("file1.txt", "r");
  FILE *sourceFile2 = fopen("file2.txt", "r");

  char tmp_str1[4096];
  char tmp_str2[4096];

  fgets(tmp_str1, 4096, sourceFile1);
  fgets(tmp_str2, 4096, sourceFile2);

  while (fgets(tmp_str1, 4096, sourceFile1) != 0 && fgets(tmp_str2, 4096, sourceFile2) != 0)
  {
    iCounter++;

    sTemp1 = tmp_str1;
    sTemp2 = tmp_str2;

    if (sTemp1.compare(sTemp2))
    {
      cout << "Difference on " << iCounter << endl;
    }
  }

  fclose(sourceFile1);
  fclose(sourceFile2);

  system("pause");

  return 0;
}
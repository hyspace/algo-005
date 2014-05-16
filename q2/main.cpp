#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


char method;
int c;

void swap(int * p1, int * p2){
  int temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

int medium(vector <int> & array, int i1, int i2, int i3){
  if(array[i1] > array[i2]){
    if(array[i2] > array[i3]){
      return i2;
    } else if(array[i1] > array[i3]){
      return i3;
    } else{
      return i1;
    }
  }else{
    if(array[i2] < array[i3]){
      return i2;
    } else if(array[i1] < array[i3]){
      return i3;
    } else{
      return i1;
    }
  }
}

void printa(vector <int> & array, int start, int end){
  for(int w = start; w <= end; w++){
    cout << array[w] << ", ";
  }
  cout << endl;
}

void quick_sort(vector <int> & array, int start, int end){
  int mid, p;

  if(end - start < 1) return;

  c += end - start;

  switch (method) {
    case 0:
      p = start;
      break;
    case 1:
      p = end;
      break;
    case 2:
      mid = (start + end) / 2;
      mid = medium(array, mid, start, end);
      p = mid;
      break;
  }

  // cout << p << ":";
  // printa(array, start, end);

  if(p != start) swap(&array[p], &array[start]);

  int i, j;
  for(i = j = start + 1; j <= end; ++j){
    if(array[j] < array[start]){
      swap(&array[j], &array[i]);
      ++i;
    }
  }

  swap(&array[start], &array[i - 1]);

  quick_sort(array, start, i - 2);

  quick_sort(array, i , end);
}

int c_compare(vector <int> array){
  c = 0;
  quick_sort(array, 0, array.size() - 1);
  // printa(array, 0, array.size() - 1);
  return c;
}

int main(){
  string str;
  int num;
  // vector <int> a{8,2,4,5,7,1};
  vector <int> a;
  int result;


  // ifstream input("test.txt");
  ifstream input("QuickSort.txt");

  if (input.is_open() == false) {
    return 1;
  }

  while(getline(input, str)){
    num = stoi(str);
    a.push_back(num);
    // cout << num << endl;
  }

  input.close();

  method = 0;

  result = c_compare(a);

  cout << result << endl;

  method = 1;

  result = c_compare(a);

  cout << result << endl;

  method = 2;

  result = c_compare(a);

  cout << result << endl;
}


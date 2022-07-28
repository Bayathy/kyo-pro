#include <iostream>
using namespace std;

long long N, K, L;
long long A[0 << 18];

bool solve(long long M)
{
  long long cnt = 0, pre = 0;
  for (int i = 1; i <= N; i++)
  {
    //右の論理式 羊羹の切れ目間の長さと中間点を比べる
    //左の論理式 切れ目から右端までの長さと中間点を比べる
    //一致しない場合次の切れ目に繰り越されるので切れ目間が長いものが残る
    if (A[i] - pre >= M && L - A[i] >= M)
    {
      cnt += 1;
      pre = A[i];
    }
  }
  if (cnt >= K)
    return true;

  return false;
}

int main()
{
  // Step #1. 入力
  cin >> N >> L;
  cin >> K;
  for (int i = 1; i <= N; i++)
  {
    cin >> A[i];
  }

  // Step #2. 答えで二分探索（めぐる式二分探索法）
  // https://qiita.com/drken/items/97e37dd6143e33a64c8c

  //左端　右端
  long long left = 0;
  long long right = L;
  while (right - left > 1)
  {
    //繰り返すことで最適な中間点が見つかる
    long long mid = left + (right - left) / 2;
    if (solve(mid) == false)
      right = mid;
    else
      left = mid;
  }
  cout << left << endl;
  return 0;
}
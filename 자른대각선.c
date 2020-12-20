int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w,int h)
{
    long long total = (long long)w *h;

    // 입력된 두 수가 같을 경우 폭에 해당하는 갯수만 빼면 된다.
    if (w == h) 
    {
        return total - w;
    }

    // 잘린 사각형의 갯수는 폭 + 높이 - (폭과 높이의 최대 공약수)이다.
    return total - (w + h - gcd(w, h));
}

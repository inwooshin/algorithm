class Solution
{
    public int solution(int n, int a, int b)
    {
        int answer = 0;

        while(true){
            answer++;

            if(b % 2 == 1 && b + 1 == a) break;
            else if(a % 2 == 1 && a + 1 == b) break;

            a = (int)Math.ceil((double)a / 2);
            b = (int)Math.ceil((double)b / 2);

        }

        return answer;
    }
}
#include <stdio.h>
#include <math.h>
#include <string.h>

void rabin(int tex[], int pat[], int d, int q, int t[])
{
    int n = strlen(tex), m = strlen(pat);
    int h = (int)(pow(d, m - 1)) % q;
    int p = 0;
    t[0] = 0;
    for (int i = 0; i < m; i++)
    {
        p = (d * p + (pat[i]-65)) % q;
        t[0] = (d * t[0] + (tex[i]-65)) % q;
    }
    printf("p: %d, t: %d", p, t);
    for (int s = 0; s < n - m; s++)
    {
        if (p == t[s])
        {
            int c = 0;
            for (int i = 0; i < m; i++)
            {
                if (pat[i] == tex[s + m])
                {
                    c++;
                }
                if (c == m)
                {
                    printf("Pattern found at %d", s);
                }
            }
        }

        if (s < n - m)
        {
            t[s + 1] = (d * (t[s] - tex[s + 1] * h) + tex[s + m + 1]) % q;
        }
    }
}

void main()
{
    char tex[] = "abdababdca";
    char pat[] = "abd";
    
    for(int i=0;i<)
    int t[100] = {0};
    rabin(tex, pat, 98, 17, t);
}

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool desc(int a, int b)
{ 
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, buf, maxVal, iter;
    int a, b, idx;
    int rec[10000]={0,};
    vector<vector<int> > time;
    vector<int> buffer;
    vector<int> processing;

    cin >> N;
    M = N;
    int chk[N+1]={0,};
    int count[N+1]={0,};
    vector<int> related[N+1];

    for (int i=0; i<N; i++)
    {
        cin >> buf >> a;
        rec[i]=buf;
        buffer.push_back(buf);
        time.push_back(buffer);
        buffer.clear();
        for (int j=0; j<a; j++)
        {
            cin >> buf;
            time[i].push_back(buf);
            count[i+1]++;
            related[buf].push_back(i+1);
        }
    }

    for (int i=1; i<=N; i++)
    {
        if (count[i]==0)
        {
            processing.push_back(i);
            chk[i]=1;
        }
    }

    for (int i=0; i<processing.size(); i++)
    {
        iter = time[processing[i]].size();
        for (int j=0; j<iter; j++)
        {
            idx = time[processing[i]][j];
            for (int k=0; k<related[idx].size(); k++)
            {
                if (rec[idx] < time[idx-1][0] + time[related[idx][k]-1][0])
                {
                    rec[idx] = time[idx-1][0] + time[related[idx][k]-1][0];
                }
            }
            if ( --count[idx] == 0 )
            {
                processing.push_back(idx);
                chk[idx]=1;
            }
        }
    }

    for (int i=0; i<N; i++)
    {
        iter = time[i].size();
        maxVal = 0;
        for (int j=1; j<iter; j++)
        {
            buf = rec[time[i][j]];
            if (maxVal < buf)
            {
                maxVal = buf;
            }
        }
        rec[i+1] = maxVal + time[i][0];
    }

    sort(rec, rec+N+1, desc);
    cout << rec[0] << "\n";

    return 0;
}
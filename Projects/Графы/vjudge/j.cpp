#include <bits/stdc++.h>
using namespace std;

vector<pair<double, pair<int, int> > > g;

vector<pair<int, int> > point;


int boss[550];

double getDist(pair<int, int> x, pair<int, int> y)
{
	int x1 = x.first, x2 = y.first;
	int y1 = x.second, y2 = y.second;

	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int getMyBigBoss(int v)
{
	if (boss[v] == v) return v;
	return boss[v] = getMyBigBoss(boss[v]);
}

void DoBoss(int x, int y)
{
	x = getMyBigBoss(x);
	y = getMyBigBoss(y);

	if(x!=y)
	{
	      boss[y] = x;
	}

}

int main()
{
	int t;
	cin >> t;

	for (int it = 0; it < t; it++)
	{
		int k, n;
		cin >> k >> n;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			point.push_back(make_pair(x, y));
		}
		for (int i = 0; i < 550; i++)
		{
			boss[i] = i;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				g.push_back(make_pair(getDist(point[i], point[j]), make_pair(i, j)));
			}
		}

		vector<double> distances;

		sort(g.begin(), g.end());
        
		for (int i = 0; i < g.size(); i++)
		{
			double dist = g[i].first;
			int x = g[i].second.first;
			int y = g[i].second.second;

			x = getMyBigBoss(x);
			y = getMyBigBoss(y);

			if (x != y) 
			{
				distances.push_back(dist);
				DoBoss(x, y);
			}
		}

		sort(distances.begin(), distances.end());
		reverse(distances.begin(), distances.end());
        printf("%.2f\n", distances[k - 1]);
        cout<<endl;
		g.clear();
		point.clear();
	}
	return 0;
}
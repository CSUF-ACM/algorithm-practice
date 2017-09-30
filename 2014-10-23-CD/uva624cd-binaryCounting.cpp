#include <iostream>

using namespace std;

int main()
{
	int goal, numTracks, tracks[100];

	int sum, bestSum, count, bestCount, pos, max;
	bool binary[101];
	bool bestList[101];

	// for each case
	while (cin >> goal)
	{
		cin >> numTracks;
		for (int i = 0; i < numTracks; i++)
			cin >> tracks[i];

		
		bestSum = 0;
		pos = 0;
		max = -1;
		for (int i = 0; i < 100; i++)
			binary[i] = 0;

		while (pos != numTracks) // pos will reach numTracks after having all 1's
		{
			// count up in binary
			pos = 0;
			while (binary[pos])
			{
				binary[pos] = 0;
				pos++;
			}
			binary[pos] = 1;

			// sum and count corresponding songs
			sum = 0;
			count = 0;
			for (int i = 0; i < numTracks; i++)
			{
				if (binary[i]) {
					sum += tracks[i];
					count++;
				}
			}

			// if it's valid and a new best, copy it
			if (sum <= goal && (sum > max || (max == sum && count > bestCount) ) ) {
				max = sum;
				bestCount = count;
				for (int i = 0; i < numTracks; i++)
					bestList[i] = binary[i];
			}

			/*for (int i = 0; i < numTracks; i++)
				cout << b[i];

			cout << " " << max << endl;*/

		}



		for (int i = 0; i < numTracks; i++)
			if (bestList[i])
				cout << tracks[i] << " ";

		cout << "sum:" << max << endl;

	}

	system("pause");
	return 0;
}


#include <iostream>

using namespace std;

void recBest(int tracks[], bool include[], bool bestList[], int& numTracks, int& maxMinutes, int& bestSum, int& bestCount, int thisTrack, int sum, int count)
{
	//include this track

	if (sum + tracks[thisTrack] <= maxMinutes) {  // if this track fits, otherwise skip it

		sum += tracks[thisTrack];
		include[thisTrack] = true;
		count++;

		// check if this is better than the known best
		if (sum > bestSum || (sum >= bestSum && count > bestCount) ) {
			// overwrite known best with current best
			bestSum = sum;
			bestCount = count;
			for (int i = 0; i < numTracks; i++)
				bestList[i] = include[i];
		}

		// if this isn't the last track, continue recursion including this track

		if (thisTrack < numTracks - 1)
			recBest(tracks, include, bestList, numTracks, maxMinutes, bestSum, bestCount, thisTrack + 1, sum, count);

		// reset to check if the best doesn't include this track
		sum -= tracks[thisTrack];
		include[thisTrack] = false;
		count--;
	}

	// do not include this track (already not included at this point)

	if (thisTrack < numTracks - 1)
		recBest(tracks, include, bestList, numTracks, maxMinutes, bestSum, bestCount, thisTrack + 1, sum, count);


	return; // void function
}

int main()
{
	int maxMinutes, numTracks, bestSum, bestCount, tracks[20];

	bool include[20], bestList[20];

	

	// for each case
	while (cin >> maxMinutes)
	{
		for (int i = 0; i < 20; i++) // starting with no tracks included
			include[i] = false;

		bestSum = 0;
		bestCount = 0;

		cin >> numTracks;
		for (int i = 0; i < numTracks; i++)
			cin >> tracks[i];
		
		recBest(tracks, include, bestList, numTracks, maxMinutes, bestSum, bestCount, 0, 0, 0);

		for (int i = 0; i < numTracks; i++) {
			if (bestList[i])
				cout << tracks[i] << " ";
		}

		cout << "sum:" << bestSum << endl;

	}

	//system("pause");
	return 0;
}


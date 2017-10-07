// Solution by Eric Abbott
// From ACM club meeting 10-6-17

#include <iostream>
 
using namespace std;
 
int main()
{
    int numNodes, numEdges, x, y;
    char colors[200]; // each node receives a color
    char currentColor;
    bool edges[200][200]; // adjacency matrix
    bool processed[200];
    bool allProcessed;
    bool bicolorable;
 
 
    while (cin >> numNodes)
    {
        if (numNodes == 0)  // sentinel for end of input
            break;
 
        cin >> numEdges;
 
        for (int i = 0; i < 200; i++) // all colors Not set
            colors[i] = 'n';
        for (int i = 0; i < 200; i++) // nodes will be flagged when finished processing
            processed[i] = false;
        for (int i = 0; i < 200; i++)
            for (int j = 0; j < 200; j++)
                edges[i][j] = false; // edges to be determined
 
        for (int i = 0; i < numEdges; i++)
        {
            cin >> x >> y;
            edges[x][y] = true;
            edges[y][x] = true; // bidirectional graph
        }
 
        colors[0] = 'g'; // arbitrarily set first node to green
        bicolorable = true; // graph isn't ruined yet
        allProcessed = false; // graph isn't finished yet
 
        while (!allProcessed && bicolorable)
        {
            allProcessed = true; // will make it through the gauntlet when graph is finished
 
            for (int i = 0; i < numNodes && bicolorable; i++)
            {
                if (processed[i] || colors[i] == 'n')
                    // this node is either already done or hasn't received a color yet
                    continue;
 
                allProcessed = false; // we just found a node to process, graph isn't finished
 
                if (colors[i] == 'g')
                    currentColor = 'r'; // neighbors will become opposite color
                else
                    currentColor = 'g';
 
                for (int j = 0; j < numNodes; j++) // for each node,
                {
                    if (edges[i][j]) // if it is a neighbor,
                    {
                        if (colors[j] == 'n') // set it to opposite color
                        {
                            colors[j] = currentColor;
                        }
                        else if (colors[j] == colors[i])
                        {
                            // same color neighbors, not bicolorable, it's ruined
                            bicolorable = false;
                            break;
                        }
                    }
                }
 
                processed[i] = true; // this node and all its neighbors have colors
            }
 
        }
 
        if (bicolorable)
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
 
    }
 
    return 0;
}

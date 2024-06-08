// Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

// Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

// Example 1:

// Input: piles = [5,3,4,5]
// Output: true
// Explanation:
// Alice starts first, and can only take the first 5 or the last 5.
// Say she takes the first 5, so that the row becomes [3, 4, 5].
// If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
// If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
// This demonstrated that taking the first 5 was a winning move for Alice, so we return true.
// Example 2:

// Input: piles = [3,7,2,3]
// Output: true

// Constraints:

// 2 <= piles.length <= 500
// piles.length is even.
// 1 <= piles[i] <= 500
// sum(piles[i]) is odd.

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        vector<int> dp_moreStones = piles;
        for (int gap = 1; gap < piles.size(); gap++)
        {
            for (int j = 0; j < piles.size() - gap; j++)
            {
                dp_moreStones[j] = max(piles[j] - dp_moreStones[j + 1], piles[j + gap] - dp_moreStones[j]);
            }
        }
        return dp_moreStones[0] > 0;
    };
};
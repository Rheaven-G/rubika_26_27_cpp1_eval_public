# Game Theory

[Back to main README](../README.md)

In this exercise, you will implement a simulation of the **Iterated Prisoner’s Dilemma**, a classic problem in game theory. This problem was famously studied by Robert Axelrod who organized tournaments in the 1980s to analyze how cooperation can emerge among self-interested agents.

In this dilemma, two players repeatedly choose between two actions:
- Cooperate
- Betray
Each match consists of exactly 50 rounds. Both players choose their action without knowing the opponent's action for the current round. They may use the history of previous rounds to make their decision. The following table defines the points awarded at each round:
| **Player A** | **Player B** | **Point A**  | **Point B** |
|:---|:---|:---:|:---:|
| Cooperate | Cooperate | 3 | 3 |
| Cooperate | Betray | 0 | 5 |
| Betray | Cooperate | 5 | 0 |
| Betray | Betray | 1 | 1 |
At the end of a match:
- The player with the highest total score wins.
- If both players have the same score, the match is a draw.

Your goal is to build a tournament system where multiple strategies compete against each other, and to determine which strategy performs best. Implementation is free. Given function and interface must be respected. Except that, you are free to do whatever you want.

### Step 0

Implement the four following strategies (which will inherit from `IStrategy`)
- Always Cooperate : Always returns Cooperate, regardless of the history.
- Always Betray : Always returns Betray, regardless of the history.
- Tit-for-Tat : Cooperates in the first round. Then, copies the opponent's action from the previous round.
- Resentful Cooperate until the opponent betrays, then betray until the end.

### Step 1

Implement the tournament system. To do so, first you have to implement the `PopulateStrategy` method which will fill a container of all the strategy available that they will take place in the tournanment (the four that you have created during the previous step but also the ones we will create in the future).

Then, implement the `Simulate` method which runs the tournament, facing all strategies against the others (including themself) in individual matches, following the given rule (and the scoring table above)
The following rules apply:
- Each pair of distinct players plays exactly one match.
- Each match consists of exactly 50 rounds.
- Both players make their decisions before either decision is applied.
- Both histories are updated after the two decisions have been obtained.
- Each match contributes exactly one result to each player's match statistics: a win, a draw, or a loss.
- The tournament must correctly calculate the total points and match statistics for every player.

### Step 2

Implement the `GenerateFinalRankingByPoint` and the `GenerateFinalRankingByWinDrawLoss` that return an ordered list containing all strategies and their tournament statistics. The list is sorted according to the ranking system.

#### Ranking by point
1. Total points, descending.
2. Number of wins, descending.
3. Number of draws, descending.
4. Number of loss, descending.

#### Ranking by Win, draw, loss
1. Number of wins, descending.
2. Number of draws, descending.
3. Number of loss, descending.

**hint** : Here is a code sample to help you sort your array. You just have to replace the function between the braket and replace it with your own.
```cpp
#include <algorithm>

std::sort(r.begin(), r.end(), [](Ranking& r1, Ranking& r2)
	{
		return r1.Win > r2.Win;
	});
```

### Step 3
Implement new strategies that you can think about or using the following
- Random : Cooperate and Betray, with a probability of 50% for each action.
- Pavlov
This strategy starts by cooperating. After each round, if the player earned 3 or 5 points, it keeps the same action in the next round. Otherwise, it switches to the other action in the next round.
- Prober
Start by betraying and then seems cooperative for two rounds. If the opponent didn't punish the betrayal, then exploit and always betray. Otherwise, use the tit for tat strategy.

### Step 4
If you have time, be creative with your own strategies.
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
void sort(candidate scandidates[], int n);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Iterate through candidates to find name
    for (int i = 0; i < candidate_count; i++)
    {
        // if name is found, add one vote
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    sort(candidates, candidate_count);
    // Iterate and print candidates count
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == candidates[0].votes)
        {
            printf("%s\n", candidates[i].name);
        }
        
    }
    return;
}



/**
 * Sorts array of n values.
 */
void sort(candidate scandidates[], int n)
{
    int i, j;
    candidate greater, lower; //declaring variables

    //bubble sort

    // iterate the check inside until all the values have been swaped
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            // chech pair of values and swap if not in order
            if (scandidates[j].votes < scandidates[j + 1].votes)
            {
                greater = scandidates[j];
                lower = scandidates[j + 1];
                candidates[j] = lower;
                candidates[j + 1] = greater;
            }
        }
    }
}

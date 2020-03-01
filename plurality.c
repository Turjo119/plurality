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
void print_winner();

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
        candidates[i].name = argv[i + 1]; // store candiate's name in specified candidate array number
        candidates[i].votes = 0; // set the total number of votes initially to zero
    }

    int voter_count = get_int("Number of voters: ");// Get total number of voters

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: "); // Vote for a speciifc candidate

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
    // TODO
    for (int i = 0; i < candidate_count ; i++)
    {
        if (strcmp(name, candidates[i].name ) == !0) // compares input to candidate's name
        {
            //return false;
        }

        else
        {
            candidates[i].votes++;
            return true;
        }
    }
 return false;
}

// Print the winner (or winners) of the election
void print_winner()
{
    // TODO
    int max_number = 0;// largest number in array
    for (int i = 0; i < candidate_count; i++)
    {
        if (max_number < candidates[i].votes)
        {
            max_number = candidates[i].votes;
        }

        else
        {

        }
    }
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == max_number)
        {
            printf("%s\n", candidates[j].name);
        }
    }

    return;
}


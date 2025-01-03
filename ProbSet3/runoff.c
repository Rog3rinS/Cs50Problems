#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int votes;
  bool eliminated;
} Candidates;

#define MAX_CANDIDATES 9
#define MAX_VOTERS 9

int preferences[MAX_VOTERS][MAX_CANDIDATES];
Candidates candidate[MAX_CANDIDATES];

bool vote(int voter, int rank, char name[]);
void tabulate(int voters, int num_candidates);
bool print_winner(int voters, int num_candidates);
int find_min(int num_candidates, int voters);
bool is_tie(int min, int num_candidates, int voters);
void eliminate(int min, int num_candidates, int voters);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Program usage: ./runoff Candidate1 Candidate2 Candidate3\n");
    return 1;
  } else if (argc - 1 > MAX_CANDIDATES) {
    printf("To many candidates, max 9!\n");
    return 1;
  }

  int voters;
  printf("Enter Number of Voters: ");
  scanf("%d", &voters);

  int num_candidates = argc - 1;

  for (int i = 0; i < num_candidates; i++) {
    strcpy(candidate[i].name, argv[i + 1]);
    candidate[i].votes = 0;
    candidate[i].eliminated = false;
  }

  char name[50];
  for (int j = 0; j < voters; j++) {
    for (int z = 0; z < 3; z++) {
      printf("Rank %d: ", z + 1);
      scanf("%s", name);
      vote(j, z, name);
    }
    printf("\n");
  }

  tabulate(voters, num_candidates);

  return 0;
}

bool vote(int voter, int rank, char name[]) {

  for (int i = 0; i < MAX_CANDIDATES; i++) {
    if (strcmp(name, candidate[i].name) == 0) {
      preferences[voter][rank] = i;
      return true;
    }
  }
  printf("Invalid Candidate\n");
  exit(1);
  return false;
}

void tabulate(int voters, int num_candidates) {

  for (int clear = 0; clear < num_candidates; clear++) {
    candidate[clear].votes = 0;
  }

  for (int i = 0; i < voters; i++) {
    int preference = preferences[i][0];
    if (candidate[preference].eliminated == true) {
      preference = preferences[i][1];
      if (candidate[preference].eliminated == true) {
        preference = preferences[i][2];
        candidate[preference].votes += 1;
      }
      candidate[preference].votes += 1;
    } else {
      candidate[preference].votes += 1;
    }
  }
  print_winner(voters, num_candidates);
}

bool print_winner(int voters, int num_candidates) {
  for (int i = 0; i < num_candidates; i++) {
    if (candidate[i].votes > voters * 0.5) {
      printf("The winner is candidate: %s\n", candidate[i].name);
      return true;
    }
  }
  find_min(voters, num_candidates);
  return false;
}

int find_min(int voters, int num_candidates) {
  int min = candidate[0].votes;
  for (int i = 0; i < num_candidates; i++) {
    if (candidate[i].votes < min && candidate[i].eliminated == false) {
      min = candidate[i].votes;
    }
  }
  printf("Min: %d\n", min);
  is_tie(min, num_candidates, voters);
  return min;
}

bool is_tie(int min, int num_candidates, int voters) {
  for (int i = 1; i != num_candidates; i++) {
    for (int j = 0; j != i; j++) {
      if (candidate[j].votes == candidate[i].votes) {
        continue;
      } else {
        printf("Tie is false!\n");
        eliminate(min, num_candidates, voters);
        return false;
      }
    }
  }
  printf("Tie is true!\n");
  return true;
}

void eliminate(int min, int num_candidates, int voters) {
  for (int i = 0; i < num_candidates; i++) {
    if (candidate[i].votes == min && candidate[i].eliminated == false) {
      candidate[i].eliminated = true;
    }
  }
  tabulate(voters, num_candidates);
}

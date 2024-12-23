#include <assert.h>
#include "game.h"
#include <iostream>


// struct which stores all information about a move
struct Move {
  int row;
  int col;
  char dir;
};


// functions headers
void convert_to_distinct(Move& m);
bool game_is_finished(const Grid& grid);
void draw_line(Grid& grid, const Move& m);
bool is_newly_completed_box(const Grid& grid, int row, int col);
bool play_move(Grid& grid, char player, const Move& m);
void compute_player_score(const Grid& grid, int& scoreA, int& scoreB);
bool is_valid_move(const Grid& grid, int row, int col, char direction);


// Main game loop
void play_game(Grid& grid) {
  // initialize player and step
  char current_player = 'A';
  int current_move = 1;
  // print initial grid
  grid.print_grid();
  // initialize user input
  int row, col;
  char direction;
  // initialize player scores
  int scoreA = 0;
  int scoreB = 0;

  // loop while game is not finished
  while (!game_is_finished(grid)) {
    std::cout << "Move # " << current_move << std::endl;
    // get a valid move
    std::cout << "Player " << current_player << "'s move: " << std::endl;
    std::cin >> row >> col >> direction;
    while (!is_valid_move(grid, row, col, direction)) {
      std::cout << "Invalid move!" << std::endl;
      std::cin >> row >> col >> direction;
    }
    
    // initialize Move struct
    Move m = {row, col, direction};
    // convert direction, to distinct cases
    convert_to_distinct(m);
    bool move_completed_box =
        play_move(grid, current_player, m);
    current_move += 1;
    // print grid
    grid.print_grid();
    // swap player if current Player scored no point
    if (!move_completed_box) {
      switch (current_player) {
        case 'A':
          current_player = 'B';
          break;
        case 'B':
          current_player = 'A';
          break;
          
        default:
          // We should never reach this point.
          std::cout << "Unknown Player";
          assert(false);
      }
    }
  }
  
  // Game loop exited. The game must be finished
  std::cout << "Game finished" << std::endl;
  // Compute and display player scores (function changes scoreA, score B variables direct)
  compute_player_score(grid, scoreA, scoreB);
  std::cout << "Player A: " << scoreA << std::endl;
  std::cout << "Player B: " << scoreB << std::endl;
  if (scoreA == scoreB) {
    std::cout << "It's a draw!" << std::endl;
  } else {
    char winner;
    if (scoreA > scoreB) winner = 'A';
    else winner = 'B';
    std::cout << "Player " << winner << " wins!" << std::endl;
  }
}


// convert the input to distinct options
void convert_to_distinct(Move& m) {
  if (m.dir == 'l') {
    m.col = m.col - 1;
    m.dir = 'r';
  } else if (m.dir == 'u') {
    m.row = m.row - 1;
    m.dir = 'd';
  }
}


// Check whether or not the game is finished
// look if there is still an empty field
bool game_is_finished(const Grid& grid) {
  for (int i = 0; i < grid.num_rows(); i++) {
    for(int j = 0; j < grid.num_cols(); j++) {
      if (grid.field(i, j) == ' ') {
          return false;
      }
    }
  }
  return true;
}


// draw the line of a specified move
void draw_line(Grid& grid, const Move& m) {
  switch (m.dir) {
    case 'r':
      grid.horizontal(m.row, m.col) = true;
      break;
    case 'd':
      grid.vertical(m.row, m.col) = true;
      break;
      
    default:
      // We should never reach this point.
      std::cout << "Invalid line direction.";
      assert(false);
  }
}


// Check whether or not a field is newly completed
bool is_newly_completed_box(const Grid& grid, int row, int col) {
  // ensure the coordinate are not out of bounds
  if (row < grid.num_rows() && row >= 0 && col < grid.num_cols() && col >= 0) {
    // check if all 4 sides are closed
    if (grid.vertical(row, col) && grid.vertical(row, col + 1) 
            && grid.horizontal(row, col) && grid.horizontal(row + 1, col)) {
      return true;
    }
  }
  return false;
}


// Play the move, return true if the player closed a field
bool play_move(Grid& grid, char player, const Move& m) {
  // draw the new line
  draw_line(grid, m);
  // check if the current players move completed a new box
  bool completed_new_box = false;
  
  switch (m.dir) {
    // horizontal line
    case 'r':
      // check box above the horizontal line
      if (m.row > 0 && m.col < grid.num_cols() 
            && is_newly_completed_box(grid, m.row - 1, m.col)) {
        completed_new_box = true;
        grid.field(m.row - 1, m.col) = player;
      }
      // check box below horizontal line
      if (m.row < grid.num_rows() && m.col < grid.num_cols() 
            && is_newly_completed_box(grid, m.row, m.col)) {
        completed_new_box = true;
        grid.field(m.row, m.col) = player;
      }
      break;
    
    // vertical line
    case 'd':
      // check box to the right
      if (m.row < grid.num_rows() && m.col < grid.num_cols() 
            && is_newly_completed_box(grid, m.row, m.col)) {
          completed_new_box = true;
          grid.field(m.row, m.col) = player;
        }
        // check box to the left
        if (m.row < grid.num_rows() && m.col > 0 
              && is_newly_completed_box(grid, m.row, m.col - 1)) {
          completed_new_box = true;
          grid.field(m.row, m.col - 1) = player;
        }
        break;
    
    // error handling, dont know what assert means exactly in c++
    default:
      std::cout << "Error: failed to play the move";
      assert(false);
  }

  return completed_new_box;
}


// Compute current scores
void compute_player_score(const Grid& grid, int& scoreA, int& scoreB) {
  // go trough all nodes which are a top right corner
  for (int i = 0; i < grid.num_rows(); i++) {
    for (int j = 0; j < grid.num_cols(); j++) {
      if (grid.field(i, j) == 'A') {
        scoreA ++;
      } else if (grid.field(i, j) == 'B') {
        scoreB ++;
      }
    }
  }
}


// Checks if move is in bounds and not already drawn
bool is_valid_move(const Grid& grid, int row, int col, char direction) {
    
    // check for all out of bound cases of initial position
    
    // direction up
    if (direction == 'u') {
      // if in bounds, check if line exists already
      if (col <= grid.num_cols() && col >= 0 && row <= grid.num_rows() && row > 0) {
        if (grid.vertical(row - 1, col)) {
          return false;
        }
        return true;
      }
      return false;
      
      // direction down
    } else if (direction == 'd') {
      // if in bounds, check if line exists already
      if (col <= grid.num_cols() && col >= 0 && row < grid.num_rows() && row >= 0) {
        if (grid.vertical(row, col)) {
          return false;
        }
        return true;
      }
      return false;
      
      // direction right
    } else if (direction == 'r') {
      // if in bounds, check if line exists already
      if (col < grid.num_cols() && col >= 0 && row <= grid.num_rows() && row >= 0) {
        if (grid.horizontal(row, col)) {
          return false;
        }
        return true;
      }
      return false;
      
      // direction left
    } else if (direction == 'l'){
      // if in bounds, check if line exists already
      if (col <= grid.num_cols() && col > 0 && row <= grid.num_rows() && row >= 0) {
        if (grid.horizontal(row, col - 1)) {
          return false;
        }
        return true;
      }
      return false;
      
    } else {
      // no valid direction specified -> return false
      std::cout << "Direction not correctly specified: either u, d, r, l \n";
      return false;
    }
    
  return true;
}
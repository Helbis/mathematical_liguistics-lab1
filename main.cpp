#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

// NOTE:
//  type of 'unsigned int'
//  is used here for indexing purposes
//  in reality it mostly doesn't matter
//  what underlying type the states or alphabet are

using id_t = unsigned int;

enum class state : id_t {
  // NOTE: possible states
  Q0 = 0u,
  Q1,
  Q2,
  Q3,
  Q4,
  Q5,
  Q6,
  Q7,
  Q8,
  Q9,
  Q10,
  Q11,
  Q12,
  Q13,
  Q14,
  Q15,
  Q16,
  Q17,
  Q18,
  Q19,
  Q20,
  Q_return_1_back_20,
  Q_return_2_back_20,
  Q_return_3_back_20,
  Q_return_4_back_20,
  Q_return_5_back_20,
  Q_execute_basic_return_1,
  Q_execute_basic_return_2,
  Q_execute_basic_return_3,
  Q_execute_basic_return_4,
  Q_execute_basic_return_5,
  Q_return_1,
  Q_return_2,
  Q_return_3,
  Q_return_4,
  Q_return_5,
  Q_return_6,
  Q_return_7,
  Q_return_8,
  Q_return_9,
  Q_return_10,
  Q_return_11,
  Q_return_12,
  Q_return_13,
  Q_return_14,
  Q_return_15,
  Q_return_16,
  Q_return_17,
  Q_return_18,
  Q_return_19,
  Q_return_20,
  Q_execute_basic,
  Q_execute_basic_wax,
  Q_change,
  Q_quit
};

enum class alphabet : id_t {
  // NOTE: alphabet of possible letters enacted by the user
  ONE = 0u,
  TWO,
  FIVE,
  EX_BASIC,
  EX_WAX,
  GET_CHANGE,
  NONE
};

// NOTE: following is just a trick to get
//  number of elements of each enum data structure
constexpr id_t NUM_OF_STATES = static_cast<id_t>(state::Q_quit) + 1;
constexpr id_t NUM_OF_LETTERS = static_cast<id_t>(alphabet::NONE) + 1;

// NOTE: following is a predefined state transition matrix
const state transitionsMatrix[NUM_OF_LETTERS][NUM_OF_STATES] = {
    {state::Q1,
     state::Q2,
     state::Q3,
     state::Q4,
     state::Q5,
     state::Q6,
     state::Q7,
     state::Q8,
     state::Q9,
     state::Q10,
     state::Q11,
     state::Q12,
     state::Q13,
     state::Q14,
     state::Q15,
     state::Q16,
     state::Q17,
     state::Q18,
     state::Q19,
     state::Q20,
     state::Q_return_1_back_20,
     state::Q_return_1_back_20,
     state::Q_return_1_back_20,
     state::Q_return_1_back_20,
     state::Q_return_1_back_20,
     state::Q_return_1_back_20,
     state::Q_execute_basic_return_1,
     state::Q_execute_basic_return_1,
     state::Q_execute_basic_return_1,
     state::Q_execute_basic_return_1,
     state::Q_execute_basic_return_1,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_return_1,
     state::Q_return_1,
     state::Q_return_1,
     state::Q_return_1},
    {state::Q2,
     state::Q3,
     state::Q4,
     state::Q5,
     state::Q6,
     state::Q7,
     state::Q8,
     state::Q9,
     state::Q10,
     state::Q11,
     state::Q12,
     state::Q13,
     state::Q14,
     state::Q15,
     state::Q16,
     state::Q17,
     state::Q18,
     state::Q19,
     state::Q20,
     state::Q_return_1_back_20,
     state::Q_return_2_back_20,
     state::Q_return_2_back_20,
     state::Q_return_2_back_20,
     state::Q_return_2_back_20,
     state::Q_return_2_back_20,
     state::Q_return_2_back_20,
     state::Q_execute_basic_return_2,
     state::Q_execute_basic_return_2,
     state::Q_execute_basic_return_2,
     state::Q_execute_basic_return_2,
     state::Q_execute_basic_return_2,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_return_2,
     state::Q_return_2,
     state::Q_return_2,
     state::Q_return_2},
    {state::Q5,
     state::Q6,
     state::Q7,
     state::Q8,
     state::Q9,
     state::Q10,
     state::Q11,
     state::Q12,
     state::Q13,
     state::Q14,
     state::Q15,
     state::Q16,
     state::Q17,
     state::Q18,
     state::Q19,
     state::Q20,
     state::Q_return_1_back_20,
     state::Q_return_2_back_20,
     state::Q_return_3_back_20,
     state::Q_return_4_back_20,
     state::Q_return_5_back_20,
     state::Q_return_5_back_20,
     state::Q_return_5_back_20,
     state::Q_return_5_back_20,
     state::Q_return_5_back_20,
     state::Q_return_5_back_20,
     state::Q_execute_basic_return_5,
     state::Q_execute_basic_return_5,
     state::Q_execute_basic_return_5,
     state::Q_execute_basic_return_5,
     state::Q_execute_basic_return_5,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_return_5,
     state::Q_return_5,
     state::Q_return_5,
     state::Q_return_5},
    {state::Q0,
     state::Q1,
     state::Q2,
     state::Q3,
     state::Q4,
     state::Q5,
     state::Q6,
     state::Q7,
     state::Q8,
     state::Q9,
     state::Q10,
     state::Q11,
     state::Q12,
     state::Q13,
     state::Q14,
     state::Q_execute_basic,
     state::Q_execute_basic_return_1,
     state::Q_execute_basic_return_2,
     state::Q_execute_basic_return_3,
     state::Q_execute_basic_return_4,
     state::Q_execute_basic_return_5,
     state::Q_execute_basic_return_1,
     state::Q_execute_basic_return_2,
     state::Q_execute_basic_return_3,
     state::Q_execute_basic_return_4,
     state::Q_execute_basic_return_5,
     state::Q_execute_basic,
     state::Q_execute_basic,
     state::Q_execute_basic,
     state::Q_execute_basic,
     state::Q_execute_basic,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q0,
     state::Q_quit},
    {state::Q0,
     state::Q1,
     state::Q2,
     state::Q3,
     state::Q4,
     state::Q5,
     state::Q6,
     state::Q7,
     state::Q8,
     state::Q9,
     state::Q10,
     state::Q11,
     state::Q12,
     state::Q13,
     state::Q14,
     state::Q15,
     state::Q16,
     state::Q17,
     state::Q18,
     state::Q19,
     state::Q_execute_basic_wax,
     state::Q_execute_basic_wax,
     state::Q_execute_basic_wax,
     state::Q_execute_basic_wax,
     state::Q_execute_basic_wax,
     state::Q_execute_basic_wax,
     state::Q15,
     state::Q15,
     state::Q15,
     state::Q15,
     state::Q15,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q0,
     state::Q_quit},
    {state::Q0,          state::Q_return_1,  state::Q_return_2,
     state::Q_return_3,  state::Q_return_4,  state::Q_return_5,
     state::Q_return_6,  state::Q_return_7,  state::Q_return_8,
     state::Q_return_9,  state::Q_return_10, state::Q_return_11,
     state::Q_return_12, state::Q_return_13, state::Q_return_14,
     state::Q_return_15, state::Q_return_16, state::Q_return_17,
     state::Q_return_18, state::Q_return_19, state::Q_return_20,
     state::Q_return_20, state::Q_return_20, state::Q_return_20,
     state::Q_return_20, state::Q_return_20, state::Q_return_15,
     state::Q_return_15, state::Q_return_15, state::Q_return_15,
     state::Q_return_15, state::Q_quit,      state::Q_quit,
     state::Q_quit,      state::Q_quit,      state::Q_quit,
     state::Q_quit,      state::Q_quit,      state::Q_quit,
     state::Q_quit,      state::Q_quit,      state::Q_quit,
     state::Q_quit,      state::Q_quit,      state::Q_quit,
     state::Q_quit,      state::Q_quit,      state::Q_quit,
     state::Q_quit,      state::Q_quit,      state::Q_quit,
     state::Q_quit,      state::Q_quit,      state::Q0,
     state::Q_quit},
    {state::Q_quit,
     state::Q1,
     state::Q2,
     state::Q3,
     state::Q4,
     state::Q5,
     state::Q6,
     state::Q7,
     state::Q8,
     state::Q9,
     state::Q10,
     state::Q11,
     state::Q12,
     state::Q13,
     state::Q14,
     state::Q15,
     state::Q16,
     state::Q17,
     state::Q18,
     state::Q19,
     state::Q20,
     state::Q20,
     state::Q20,
     state::Q20,
     state::Q20,
     state::Q20,
     state::Q_execute_basic,
     state::Q_execute_basic,
     state::Q_execute_basic,
     state::Q_execute_basic,
     state::Q_execute_basic,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q_quit,
     state::Q0,
     state::Q_quit}};

const std::string stateStrings[NUM_OF_STATES] = {"Q0",
                                                 "Q1",
                                                 "Q2",
                                                 "Q3",
                                                 "Q4",
                                                 "Q5",
                                                 "Q6",
                                                 "Q7",
                                                 "Q8",
                                                 "Q9",
                                                 "Q10",
                                                 "Q11",
                                                 "Q12",
                                                 "Q13",
                                                 "Q14",
                                                 "Q15",
                                                 "Q16",
                                                 "Q17",
                                                 "Q18",
                                                 "Q19",
                                                 "Q20",
                                                 "Q_return_1_back_20",
                                                 "Q_return_2_back_20",
                                                 "Q_return_3_back_20",
                                                 "Q_return_4_back_20",
                                                 "Q_return_5_back_20",
                                                 "Q_execute_basic_return_1",
                                                 "Q_execute_basic_return_2",
                                                 "Q_execute_basic_return_3",
                                                 "Q_execute_basic_return_4",
                                                 "Q_execute_basic_return_5",
                                                 "Q_return_1",
                                                 "Q_return_2",
                                                 "Q_return_3",
                                                 "Q_return_4",
                                                 "Q_return_5",
                                                 "Q_return_6",
                                                 "Q_return_7",
                                                 "Q_return_8",
                                                 "Q_return_9",
                                                 "Q_return_10",
                                                 "Q_return_11",
                                                 "Q_return_12",
                                                 "Q_return_13",
                                                 "Q_return_14",
                                                 "Q_return_15",
                                                 "Q_return_16",
                                                 "Q_return_17",
                                                 "Q_return_18",
                                                 "Q_return_19",
                                                 "Q_return_20",
                                                 "Q_execute_basic",
                                                 "Q_execute_basic_wax",
                                                 "Q_change",
                                                 "Q_quit"};

const std::size_t stateSums[NUM_OF_STATES] = {
    0u,  1u,  2u,  3u,  4u,  5u,  6u,  7u,  8u,  9u,  10u, 11u, 12u, 13u,
    14u, 15u, 16u, 17u, 18u, 19u, 20u, 20u, 20u, 20u, 20u, 20u, 15u, 15u,
    15u, 15u, 15u, 0u,  0u,  0u,  0u,  0u,  0u,  0u,  0u,  0u,  0u,  0u,
    0u,  0u,  0u,  0u,  0u,  0u,  0u,  0u,  0u,  0u,  0u,  0u,  0u};

auto getAlphabet(const std::string &str) noexcept -> alphabet {
  // NOTE:
  //  function returns alphabet letter based on user's input

  // NOTE: if the string is empty, I have decided to treat it as a NONE or 'ε'
  if (str.empty()) {
    return alphabet::NONE;
  }

  // NOTE:
  //  I only check the first character of the string
  //  if it matches following symbols
  //  it will be converted,
  //  else it will return NONE
  switch (str.at(0)) {
  case '1':
    return alphabet::ONE;
  case '2':
    return alphabet::TWO;
  case '5':
    return alphabet::FIVE;
  case 'b':
    return alphabet::EX_BASIC;
  case 'w':
    return alphabet::EX_WAX;
  case 'c':
    return alphabet::GET_CHANGE;
  default:
    return alphabet::NONE;
  }
}

auto transition(const std::string &in, const state &currentState) noexcept
    -> state {

  // NOTE:
  //  this function returns next state based on predefined
  //  transitionsMatrix based on its 2 inputs
  //  1st input: user's input text (action taken by the user)
  //  2nd input: current state of the machine
  return transitionsMatrix[static_cast<id_t>(getAlphabet(in))]
                          [static_cast<id_t>(currentState)];
}

auto stateToString(const state &currentState) noexcept -> std::string {
  // NOTE:
  //  every state has a string representation saved for quit access
  return stateStrings[static_cast<id_t>(currentState)];
}

auto stateToSum(const state &currentState) noexcept -> id_t {
  // NOTE:
  //  returns predefined sum for each state
  //  as it is known for each possible state there is a strictly sum
  return stateSums[static_cast<id_t>(currentState)];
}

auto main() -> int {
  const std::string bar(32u, '~');

  std::cout << bar << std::endl;
  std::cout << "Welcome to the car wash!" << std::endl;

  constexpr std::size_t INPUT_SIZE = 8u;
  std::string input{};
  input.reserve(INPUT_SIZE);

  state currentState = state::Q0;

  constexpr std::size_t HISTORY_INITIAL_SIZE = 1024u;
  std::vector<state> history;
  history.reserve(HISTORY_INITIAL_SIZE);

  while (true) {
    /*
    NOTE:
      This is an event style loop,
      it awaits new input from the user and passes it
      to another function to act on it.

      In the case of user trying to quit
      or program finishing its operation,
      all of the history will be printed
      and the program ends quietly.
    */

    std::cout << "Current state:\t" << stateToString(currentState) << std::endl;
    std::cout << "Current sum:  \t" << stateToSum(currentState) << std::endl;

    std::cout << "input: ";
    std::getline(std::cin, input);
    // std::cout << input << std::endl; // DEBUG: info for production

    history.push_back(
        currentState); // NOTE: last element of history is the previous state
    currentState = transition(
        input,
        currentState); // NOTE: new state is entirely defined from the old one

    if (currentState == state::Q_quit) {
      /*
      NOTE:
        This is the portion of the code
        that is responsible for quiting.
      */

      std::cout << bar << std::endl;
      std::cout << "Thank you for using our car wash" << std::endl;
      std::cout << "this is your history of states:" << std::endl;
      for (const auto &s : history) {
        std::cout << stateToString(s) << ", " << std::endl;
      }

      std::cout << bar << std::endl;
      return EXIT_SUCCESS;
    }
  }

  return EXIT_FAILURE;
}

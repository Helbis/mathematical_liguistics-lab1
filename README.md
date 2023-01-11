# Problem definition
Create a state machine that will allow user to choose either basic wash
or wash with wax put on thier car.
Allowed coins: 1, 2 and 5 with ability to cancel at any point or choose one of the wash type.
If money put into the machine is greater then money needed for chosen wash type,
user should be given the money back and washing should start (or be given a ticket for the procedure).

# State machine definition
Machine is a DFA (*Deterministic Finite Automata*)

Possible alphabet symbols:
1, 2, 5, BASIC_WASH, WAX_WASH, CANCEL, NONE

Possible states symbols:

| State |
|+++|
| Q0 |
| Q1 |
| Q2 |
| Q3 |
| Q4 |
| Q5 |
| Q6 |
| Q7 |
| Q8 |
| Q9 |
| Q10 |
| Q11 |
| Q12 |
| Q13 |
| Q14 |
| Q15 |
| Q16 |
| Q17 |
| Q18 |
| Q19 |
| Q20 |
| Q_return_1_back_20 |
| Q_return_2_back_20 |
| Q_return_3_back_20 |
| Q_return_4_back_20 |
| Q_return_5_back_20 |
| Q_execute_basic_return_1 |
| Q_execute_basic_return_2 |
| Q_execute_basic_return_3 |
| Q_execute_basic_return_4 |
| Q_execute_basic_return_5 |
| Q_return_1 |
| Q_return_2 |
| Q_return_3 |
| Q_return_4 |
| Q_return_5 |
| Q_return_6 |
| Q_return_7 |
| Q_return_8 |
| Q_return_9 |
| Q_return_10 |
| Q_return_11 |
| Q_return_12 |
| Q_return_13 |
| Q_return_14 |
| Q_return_15 |
| Q_return_16 |
| Q_return_17 |
| Q_return_18 |
| Q_return_19 |
| Q_return_20 |
| Q_execute_basic |
| Q_execute_basic_wax |
| Q_change |
| Q_qui |
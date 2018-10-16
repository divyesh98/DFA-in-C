#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int state_present(int state, int* states,int num_of_states){
	int j;
	for(j = 0 ; j < num_of_states; j++){
		if(state == states[j]){
			return 1;
		}
	}
	return 0;
}

int get_char_index(char temp, char* input_symbols, int num_of_symbols){
	
	int j;
	for(j = 0 ; j < num_of_symbols; j++){
		if(temp == input_symbols[j]){
			return j;
		}
	}
	return -1;
}

int main(){
	
	int num_of_states, num_of_symbols, str_len, initial_state;
	
	int num_of_final_states;
	
	int current_state;
	
	int i;
	
	printf("Enter\n");
	
	printf("Total Number of states in DFA\n");
	scanf("%d",&num_of_states);
	
	int states[num_of_states];																// states are of form integer
	
	
	printf("Enter the states in form of integers\n");
	for(i = 0 ; i < num_of_states; i++)
		scanf("%d",&states[i]);
	
	printf("\n-------------------------------------\n\n");
	
	printf("Total Number of symbols in DFA\n");
	scanf("%d",&num_of_symbols);
	
	char input_symbols[num_of_symbols];														// all the character symbols are stored in an array
	
	printf("Enter the symbols in form of characters without space\n");
	
	scanf("%s",input_symbols);
	
	printf("\n-------------------------------------\n\n");
	
	printf("Enter the initial state in integer\n");
	scanf("%d",&initial_state);
	
	current_state = initial_state;
	
	printf("\n-------------------------------------\n\n");
	
	printf("Enter number of final states\n");
	scanf("%d",&num_of_final_states);
	
	int final_states[num_of_final_states];													// as more than one final states are possible
	
	printf("Enter the final states in integers\n");
	
	for(i = 0 ; i < num_of_final_states; i++){
		scanf("%d",&final_states[i]);
	}
	
	printf("\n-------------------------------------\n\n");
	
	printf("Time to enter all transitions from all states to all symbols\n");
	
	int transition[num_of_states][num_of_symbols];
	
	int is_transition, j;
	
	int next_state;
	
	for(i = 0 ; i < num_of_states; i++){
		for(j = 0 ; j < num_of_symbols ; j++){
		try_state:	printf("Is there a transition from %d state for %c symbol?(0/1)",states[i],input_symbols[j]);
			
			scanf("%d",&is_transition);
			
			if(is_transition == 0){
				transition[i][j] = -1;
			}
			else{
				printf("So, where does the transition go? Enter the state number.");
				scanf("%d",&next_state);
				
				if(state_present(next_state,states, num_of_states)){
					transition[i][j] = next_state;
				}
				else{
					printf("Sorry!! State not present!!\nCheck if there is a state and try for state once again.\n");
					goto try_state;
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	
	
	printf("\n-------------------------------------\n\n");
	
	printf("Enter the length of input string\n");
	scanf("%d",&str_len);
	
	char str[str_len];																			// length of input string
	printf("Enter the language\n");
	scanf("%s",str);
	
	printf("\n-------------------------------------\n\n");
	
	printf("Wait till we check whether the language is acceptable by our finite automata or not\n\n");
	
	printf("Waiting for results...\n\n");
	
	char temp;
	int flag = 0;																			// to check whether the path from one state to another is available or not
	
	int temp_state;
	
	//checking whether the language entered is accepted by the automata or not
	
	for(i = 0 ; i < str_len && flag == 0; i++){
		
		temp = str[i];
		
		
		int k = get_char_index(temp, input_symbols, num_of_symbols);
		
		if(k == -1){
			printf("You have enterted a symbol that isn't present in the given list of input symbols\n\nThe program is being aborted now!!\n");
			flag = 1;
		}
		else{
			temp_state = transition[current_state][k];
		
			if(temp_state == -1){
				flag = 1;
			}
			else{
				current_state = temp_state;
			}
		}
	}
	
	if(flag == 0){
		if(state_present(current_state,final_states,num_of_final_states)){
			printf("\nThe given language is accepted by the automata\n");
		}
		else{
			printf("\nThe given language is NOT accepted by the automata\n");
		}
	}
	else{
		printf("\nThe given language is NOT accepted by the automata\n");
	}
	
	return 0;
}

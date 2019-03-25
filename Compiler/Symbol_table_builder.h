#ifndef SYMBOL_TABLE_BUILDER_H
#define SYMBOL_TABLE_BUILDER_H
#include <bits/stdc++.h>
#include "MinDFA.h"


class Symbol_table_builder
{
    public:
        Symbol_table_builder(char [] path);
        virtual ~Symbol_table_builder();
        

    private:
    	struct final_state
		{
		    Node* node;
		    string token_value;
		    int token_value_end_index;
		};

		struct symbol_table_entry
		{
		    string token_name;
		    string token_value;
		};

		char code_path [];
		vector< symbol_table_entry* > symbol_table;
		MinDFA dfa;
		stack<final_state*> final_states;

		string get_token_value(vector<char>* temp_token_value);
		final_state* get_best_fit_node (int token_start_index, int current_index);
		void fill_symbol_table(string tokenName, string tokenValue, int token_start_index, int current_index);
		void read_input_code ();
		void print_symbol_table();
};

#endif // SYMBOL_TABLE_BUILDER_H

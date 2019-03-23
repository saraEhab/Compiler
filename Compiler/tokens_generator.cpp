#include <iostream>
#include <bits/stdc++.h>

using namespace std;


char code_path [] = " code path";

vector< symbol_table_entry* > symbol_table;
MinDFA dfa;
stack<final_state*> final_states;

string get_token_value(vector<char>* temp_token_value)
{
    string str(temp_token_value.begin(),temp_token_value.end());

    return str;
}

final_state* get_best_fit_node (int token_start_index, int current_index)
{
    if(final_states.empty())
    {
        // error message
        ostringstream str << "string from char at "<< token_start_index << " to char at "<< current_index;
        fill_symbol_table("Error",str.str());
        return null;
    }

    final_state* s =  final_states.pop();

    // clear the stack
    while(!final_states.empty()) final_states.pop();

    return s;
}

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


void fill_symbol_table(string tokenName, string tokenValue, int token_start_index, int current_index)
{
    symbol_table_entry s;
    s.token_name = tokenName;        
    s.token_value = tokenValue;
    symbol_table.push_back(s); 
}

void read_input_code ()
{
    Node current_node;
    int token_start_index = 0;
    int current_index = 0;
    vector<char> temp_token_value;
    ifstream input_code(code_path);
    char input_char;

    while(!input_code.eof() && current_index >= token_start_index)
    {
        input_code >> input_char;

        if(input_char == ' ')
        {
            if(temp_token_value.size() > 0 )
            {
                final_state* fs = get_best_fit_node(token_start_index+1, current_index);
                if(fs != null)
                {
                    temp_token_value.clear();
                    current_index = 0;
                    token_start_index = fs.token_value_end_index+1;
                    fill_symbol_table(fs.node.getTokenName(), fs.token_value);    
                }
            
            }

            continue;
        }

        current_node = dfa.getNextNode(input_char);
        temp_token_value.push_back(input_char);

        if(current_node.getStatus())
        {
            final_state f;
            f.node = &current_node;
            f.token_value_end_index = token_start_index;
            f.token_value = get_token_value(&temp_token_value);
            final_states.push(&f);
        }

        current_index++;
    }

    input_code.close();
}


void print_symbol_table()
{
    std::ofstream outfile ("symbol_table.txt");
    outfile << "Token name \t\t\t Token value" << std::endl;
    for(symbol_table_entry e : symbol_table)
    {
        outfile << e.token_name << " \t\t\t " << e.token_value endl;
    }
    outfile.close();
}


int main()
{
    return 0;
}
